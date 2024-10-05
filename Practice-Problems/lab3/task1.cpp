#include <iostream>
using namespace std;

struct Fraction{
int numerator;
int denominator;

};
struct Calculator{
    Fraction operand1;
    Fraction operand2;
    Fraction result;
    char op;
};
void add(Calculator &num){
    int a = num.operand1.numerator;
    int b = num.operand1.denominator;
    int c = num.operand2.numerator;
    int d = num.operand2.denominator;
    num.result.denominator = b*d;
    num.result.numerator = (a*d) + (b*c);

}
void sub(Calculator &num){
    int a = num.operand1.numerator;
    int b = num.operand1.denominator;
    int c = num.operand2.numerator;
    int d = num.operand2.denominator;
    num.result.denominator = b*d;
    num.result.numerator = (a*d) - (b*c);

}
void mul(Calculator &num){
    int a = num.operand1.numerator;
    int b = num.operand1.denominator;
    int c = num.operand2.numerator;
    int d = num.operand2.denominator;
    num.result.denominator = b*d;
    num.result.numerator = a*c;

}
void div(Calculator &num){
    int a = num.operand1.numerator;
    int b = num.operand1.denominator;
    int c = num.operand2.numerator;
    int d = num.operand2.denominator;
    num.result.denominator = a*d;
    num.result.numerator = b*c;

}
int gcd (int a, int b){
    while(b!=0){
        cout<<a<<" "<<b<<endl;
        int temp =b;
        b = a % b;
        a = temp;
    }
    cout<<a<<" "<<b<<endl;
    return a;

}


int main(){
char str1[20];
char str2[20];
int hcf;
Calculator c1;
cout<<"enter first fraction : ";
cin>> str1;
cout<<"enter second fraction: ";
cin >>str2;
int i =0;
int temp1 = 0;
int temp2 = 0;
bool value = false;
while( str1[i] != '\0'){
    if(str1[i] == '/')
    value = true;
else if (value){
    temp2 = temp2 * 10 + str1[i] -'0';
}
else{
    temp1 = temp1 * 10 + str1[i] -'0';
}
i++;
}
if(!value){
    temp2 =1;
}

cout<<temp1<<endl;
cout<<temp2<<endl;
if(temp2== 0){
    cout<<"denominator can't be zero";
    return 1;
}
c1.operand1.numerator = temp1;
c1.operand1.denominator = temp2;

 i =0;
temp1 = 0;
temp2 = 0;
 value = false;
while( str2[i] != '\0'){
    if(str2[i] == '/')
    value = true;
else if (value){
    temp2 = temp2 * 10 + str2[i] -'0';
}
else{
    temp1 = temp1 * 10 + str2[i]- '0';
}
i++;
}
if(!value){
    temp2 =1;
}
cout<<temp1<<endl;
cout<<temp2<<endl;
if(temp2 == 0){
    cout<<"denominator can't be zero";
    return 1;
}
c1.operand2.numerator = temp1;
c1.operand2.denominator = temp2;

cout<<"1.  Addition"<<endl;
cout<<"2.  Subtraction"<<endl;
cout<<"3.  Multiplication"<<endl;
cout<<"4.  Division"<<endl;
cout<<"enter your choices : ";

cin >> c1.op;

switch(c1.op){
    case '+': add(c1);
    break;
    case '-': sub(c1);
    break;
    case '*': mul(c1);
    break;
   case '/' : div(c1);
   default: cout <<"Invalid Chocies";
}

cout<<"Before Smplification Result :"<<c1.result.numerator <<"/"<< c1.result.denominator<<endl;
hcf = gcd (c1.result.numerator,c1.result.denominator );
 c1.result.numerator = c1.result.numerator/hcf ;
 c1.result.denominator = c1.result.denominator/hcf;
cout<<"After Smplification Result :"<< c1.result.numerator <<"/"<<c1.result.denominator <<"="<< (float)c1.result.numerator/c1.result.denominator<<endl;

return 0;

}