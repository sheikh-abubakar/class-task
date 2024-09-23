#include <iostream>
using namespace std;

char* strcopy(const char* arr){
    int l =0;
    while(arr[l] !='\0'){
        l++;
    }
   
    char* str = new char[l + 1];
    for(int i = 0; i < l; i++ ){
        str[i] = arr[i];
    }
    str[l] = '\0';
    
    return str;
}


int main(){
    
    char* mystr = strcopy("Hy I am Abubakar");
    cout<<mystr<<endl;
    delete [] mystr;

    
    return 0;
}