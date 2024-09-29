#include <iostream>
 using namespace std;

 int main(){

    const int SIZE = 10;
    char buffer[100];
    int read_item = 0; //index in todolist, to read next item from
    int add_item = 0; //index in todolist, to add next item to
    char* todolist[SIZE];
    int n;
    int i = 0;
    int count = 0;
   

    cout<<"Press 0 : Exit :"<<endl;
    cout << "Press 1: Add new item" << endl;
    cout << "Press 2: Read and remove next item on list" << endl;
    cout << "Press 3: Show all items on list" << endl;
  
   

    do{
          cout << "Enter an option" << endl;
          cin>> n;
         cin.ignore();
        switch(n){
            case 0: 
            cout<<"Exit";
            break;

            case 1:
            
            if(count == SIZE){
                 
                cout<< "List is full" << endl;
            }
           cout<< "Enter a todo list.. " << endl;

            cin.getline(buffer, sizeof(buffer));
            todolist[add_item] = new char [100];
           
            while(buffer[i] != '\0'){
                todolist[add_item][i] = buffer[i];
                i++;
            }
            todolist[add_item][i] = '\0';

            //Manage circular array

            add_item = (add_item + 1) % SIZE;

            if(count < SIZE){
                count++;
            }
            else{
                read_item = (read_item + 1) % SIZE;
            }
             break;
            // Case 2

            case 2: 
                if(count == 0){
                    cout<<"List is empty"<<endl;
                }
                else{
                
                    cout<< "Removed item : "<< todolist[read_item]<<endl;
                    delete [] todolist[read_item];
                    read_item = (read_item + 1) % SIZE;
                    count--;
                }
            break;

            case 3:
            
                if (count == 0) {
                cout << "Todo list is empty." << endl;
            } else {
                cout << "All tasks in todo list:" << endl;
                
                for (int i = 0; i < count; i++) {
                    int x = (read_item + i) % SIZE;  
                    cout << i + 1 << ". " << todolist[x] << endl; 
                
                    
                }
                 
            }
            
            break;

        }

        
    }while(n != 0);

    for(int i = 0; i < count; i++){
        delete [] todolist[(read_item + i) % SIZE];
    }




    return 0;
 }