#include<iostream>
using namespace std;

struct Cell{
bool isOn;


};

int main()
{

int rows = 0, col = 0;
cout<<"enter rows :";
cin>>rows;
cout<<"enter col : ";
cin >> col;

Cell** matrix = new Cell*[rows];
for(int i =0; i < rows; i++){
    matrix[i] = new Cell[col];
}

for(int i = 0 ;  i < rows; i++){
    for(int j = 0; j < col; j++){
        matrix[i][j].isOn = false;

    }
}

for(int i = 0 ;  i < rows; i++){
    for(int j = 0; j < col; j++){
        cout<<matrix[i][j].isOn<<" ";

    }
 cout<<endl;
}
int c1, c2;
while(1){
    cout<<"enter coordinates: ";
    cin >> c1 >> c2;
    if(c1 == -1 || c2 == -1){
        return 0;

    }
    matrix[c1][c2].isOn = ! matrix[c1][c2].isOn;
    for(int i = 0 ;  i < rows; i++){
    for(int j = 0; j < col; j++){
      cout<<  matrix[i][j].isOn<<" ";

    }
    cout<<endl;
}
// for(int i = 0 ;  i < rows; i++){
    
//        delete [] matrix[i];
//     }
//     delete [] matrix;
// for(int i = 0 ;  i < rows; i++){
//     for(int j = 0; j < col; j++){
//         matrix[i][j].isOn = false;
//     }
//     }
Cell*** ptr = Cell*[rows];
for(int i =0; i , rows; i++){
    ptr[i] = new Cell*[col];

}
    for(int i =0; i< rows; i++){
        for(int j = 0; j< col; j++){
            ptr[i][j] = new Cell;
            ptr[i][j] ->isOn =0; 
        }
    }
    for(int i =0; i< rows; i++){
        for(int j = 0; j< col; j++){
            ptr[i][j] = new Cell;
           if (ptr[i][j] ->isOn =0) 
        delete [] ptr[i][j];
        }
    }
}

return 0;
}