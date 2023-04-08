#include <iostream>
using namespace std;


void func1(){
    int a = 5;
    int b = 10;
    int x = a > b ? a : b;
    //toán tử 3 ngôi với a>b if true a else return b
}

void func2(){
    int a=1;
    int b=2;
    int x = --a || ++b;
    int y = ++a || --b;
    //x and y will return 1 and 0 in case true false if first statement true, conduct state 1   
    //else if statement 1 is false but statement 2 is true, return true and conduct state 2
    //else return false if both 2 statements are false
}

int main(){
    return 0;
}