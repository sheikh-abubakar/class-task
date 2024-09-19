#include <iostream>
using namespace std;

int main(){
    int n;
    cout<< "enter number of rows : ";
    cin>> n;
    int num = 1;
    int* *ptr_row = new int*[n];

    for(int i =0; i < n; i++){
        ptr_row[i] = new int[i+1];
    }

    for(int i= 0; i <n; i++){
        for(int j =0; j<=i; j++){
            ptr_row[i][j]= num++;
        }
    }
    for(int i= 0; i <n; i++){
        for(int j =0; j<=i; j++){
            cout<< ptr_row[i][j] << " ";
        }
        cout<<endl;
    }
    for(int i =0; i < n; i++){
    delete [] ptr_row[i];
    }
    delete [] ptr_row;
        



    return 0;
}