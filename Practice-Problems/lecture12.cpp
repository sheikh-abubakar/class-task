#include <iostream>
using namespace std;


// Week Composition
// class Engine{
//     int id;
//     public:
//     Engine(){
//         cout<<"engine default ctor"<<endl;
//     }
//     void start(){
//         cout<<"engine starts"<<endl;
//     }

//     ~Engine(){
//         cout<<"engine  dtor"<<endl;
//     }
// };

// class Car{
// int id;
// Engine e;
// public:
//     Car(){
//         cout<<"car default ctor"<<endl;
//     }
//     void start(){
//         e.start();
//     }

//     ~Car(){
//         cout<<"car dtor"<<endl;
//     }
// };
// int main(){
//     Car c;
//     c.start();

// return 0;
// }


// Srong Composition
// class Engine{
//     int id;
//     public:
//     Engine(){
//         cout<<"engine default ctor"<<endl;
//     }
//     void start(){
//         cout<<"engine starts"<<endl;
//     }

//     ~Engine(){
//         cout<<"engine  dtor"<<endl;
//     }
// };

// class Car{
// int id;
// Engine* e;
// public:
//     Car(){
//         cout<<"car default ctor"<<endl;
//     }
//     Car(Engine* e){
//         cout<<"car para ctor"<<endl;
//         this -> e = e;
//     }
//     void start(){
//         e->start();
//     }

//     ~Car(){
//         cout<<"car dtor"<<endl;
//     }
// };
// int main(){
//     Engine eng;
//     Car c(&eng);
//     c.start();

// return 0;
// }

//library example
class Book{
    int id;
public:
    Book(int id){
        cout<<"book para ctor"<<endl;
        this->id = id; 
    }

    int getid(){
        return id;
    }
    ~Book(){
        cout<<"book dtor"<<endl;
    }
};
class Library{
int id;
int size = 0;
Book* arr[10];

public:     
    Library(){
        cout<<"library default ctor"<<endl;
        for(int i = 0; i < 10; i++){
            arr[i] = NULL;
        }
    }

    bool addBook(Book& b){
       for(int i = 0; i < size; i++){
        if(arr[i] != NULL && arr[i]->getid() == b.getid()){
            return false;// book already exist
        }
       }
//add book
       for(int i = 0; i <10; i++){
        if(arr[i] == NULL){
            arr[i]=&b;
            size++;
            return true;
        }
       }
       return false;
    }

    void printBook(){
         for(int i = 0; i < size; i++){
        if(arr[i] != NULL){
            cout<<"book id "<<arr[i]->getid()<<endl;
        }
         }
    }

    ~Library(){
        cout<<"library  dtor"<<endl;
    }
};

int main(){
    Library L;
    Book b1(100);
    Book b2(110);
    L.addBook(b1);
    L.addBook(b2);
    L.printBook();
}