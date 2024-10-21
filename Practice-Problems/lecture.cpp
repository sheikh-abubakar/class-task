#include <iostream>
using namespace std;

class student{
private:
    int id;
    char name[15];
    double* gpa;
    int num_of_courses;
   // static int count;
public:
    student(){
      //  count++;
        id = 0;
        name[0] = '\0';
        num_of_courses = 0;
        gpa = NULL;
    }

    student(const int i, const int c, const char n[] ){
      //  count++;
        this->id = i;
        int j = 0;
        for(;j <14 && n[j] !='\0'; j++){
            name[j] = n[j];
        }
        name[j] = '\0';
        num_of_courses = c;
        gpa = new double[c];
        for(int i = 0; i<c; i++){
            gpa[i] = 0.0;
        }

    }

    student(student& obj){
     //   count++;
        id = obj.id;
        num_of_courses = obj.num_of_courses;
        gpa = new double[num_of_courses];
        for(int i =0; i < num_of_courses; i++){
            gpa[i] = obj.gpa[i];
        }

        for(int i =0; i < 14; i++){
            name[i] = obj.name[i];
        }
    }

    void std_info(){
        cout<<"std info"<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"name :  "<<name<<endl;
        // for(int i =0; i < 14 && i !='\0'; i++){
        //     cout<<name[i];
        // }
        // cout<<endl;
        for(int i =0; i < num_of_courses; i++){
            cout<<"gpa: "<<gpa[i]<<" ";
        }
    }
};

int main(){

    student s1(2, 3, "ali");
    s1.std_info();

}