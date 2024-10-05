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


int main(){
char str1[20];
char str2[20];
Calculator c1;
cout<<"enter first fraction";
cin>> str1;
cout<<"enter second fraction";
cin >>str2;
int i =0;
int temp = 0;
while(str1[i] != '/'  && str1[i] != '\0'){
temp = temp * 10 + str2[i] - '0';
i++;
}
c1.operand1.numerator = temp;
temp =0;
i++;
while(str1[i] != '\0'){
    temp = temp * 10 + str1[i] - '0';
    i++;
}

c1.operand1.denominator = temp;

while(str2[i] != '/'&& str1[i] != '\0'){
temp = temp * 10 + str2[i] - '0';
i++;
}
c1.operand2.numerator = temp;
temp =0;
i++;
while(str2[i] != '\0'){
    temp = temp * 10 + str2[i] - '0';
    i++;
}

c1.operand2.denominator = temp;


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
}

return 0;
}