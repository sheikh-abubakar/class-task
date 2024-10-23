#include <iostream>
using namespace std;

class Name{
    char fname[15];
    char lname[15];
public:
    Name(){
        cout<<"default ctor called"<<endl;
        fname[0] = '\0';
        lname[0] = '\0';
    }    
    Name(const char fname[], const char lname[]){
        cout<<"parameterized  name ctor called"<<endl;
        int j =0;
        for(; j < 14 && fname[j] != '\0';j++){
         this->fname[j] = fname[j];
        }
        this->fname[j] = '\0';
        j =0;
        for(; j < 14 && lname[j] != '\0'; j++){
             this->lname[j] =lname[j];
        }
        this->lname[j] = '\0';
    }

    void setfname(const char* fname){
        int j =0;
        for(; j < 15 && fname[j] != '\0'; j++){
            this-> fname[j] = fname[j];

        }
        this->fname[j] = '\0';
    }

    void setlname(const char* lname){
        int j =0;
        for(; j < 15 && lname[j] != '\0'; j++){
            this-> lname[j] = lname[j];

        }
        this->lname[j] = '\0';
    }

    const char* getfname(){
        return fname;
    }
    const char* getlname(){
        return lname;
    }

    void print(){
        cout<<fname<<" "<<lname<<endl;
    }
   ~Name(){
    cout<<"name  dtor called"<<endl;
   }
};

class Laptop{
    int id;
    int status;
public:
    Laptop(){
        cout<<"lap default ctor called"<<endl;
        id = 0;
        status = 0;
    }    
    Laptop(int id){
        cout<<"lap para ctor called"<<endl;
        this->id = id;
        status = 0;
    }
    int getStatus(){
        return status;
    }
    void setStatus(int val){
        status = val;
    }
    void Lprint(){
        cout<<"lap id "<<id<<endl;
        cout<<status<<endl;
    }
    ~Laptop(){
        cout<<"lap  dtor called"<<endl;
    }
};

class Student{
    const int id;
    Name name; 
    Laptop* ptr;
public:
    Student(): id(0){
        cout<<"std ctor  default called"<<endl;
        ptr = 0;
    }
    Student(const int id, Name name):id(id), name(name){
        cout<<"std  para ctor called"<<endl;
        ptr = 0;
        //this->id = id;
    }
    void stdPrint(){
        cout<<"std id : "<<id<<endl;
       name.print();
       if(ptr != NULL){
        ptr->Lprint();
       }
    }
    void allocateLaptop(Laptop* ptr){
        this->ptr = ptr;
        this->ptr->setStatus(1);
    }

    ~Student(){
        cout<<"std dtor called"<<endl;
        if(ptr!= NULL){
            ptr->setStatus(0);
        }
    }

};
int main(){
    Laptop L(10);
    {
    Name n1("ali", "aslam");
    n1.print();
    cout<<"--------"<<endl;
    Student s1(1,n1);
    s1.stdPrint();
    cout<<"--------"<<endl;
    s1.allocateLaptop(&L);
    s1.stdPrint();
    L.Lprint();

    }
    
    L.Lprint();

return 0;
}