#include <iostream>
#include <string>
#include <cstring>
#define max 100;
using namespace std;

int main() {
    string a = "Nguyen";
    string b = "Duy";
    string c = "Thinh";
    //connect strings
    string d = a+b+c;
    cout << d << endl;
    //find position of letter(s)
    cout << "possition of T: " << d.find('T') << endl;
    cout << "possition of Duy: " << d.find("Duy") << endl;
    //find letter(s) of possition
    char letter = 'u';
    for (int i=0; i<d.length(); i++){
        if (d[i]==letter){
            cout << "posstion " << i << ": "<< d[i] << endl;}
    } cout << endl;
    //find possition of a funciton
    cout << "possition of string b:" << d.find(b) << endl;
    string e= "DuyyyThinhhh";
    cout << "possition: " << e.find("yy") << endl;
    string h="yy";
    int found=e.find(h);
    if (found >= 0) {cout << "yes";} else {cout << "no";}
    cout << endl;
    string k;
    for (int i=0; i<d.length(); i++){
        k = d[i];
    } cout << k;
    //insert variable to a string or an array string
    string str[3];
    for (int i=0; i<3; i++){
        str[i]=to_string(i);
    } for (int i=0; i<3; i++){
        cout << str[i] << " ";
    }
    //convert datatype from int to string
    int n=105;
    string f=to_string(n);
    //convert datatype from string to int|float
    string g="15";
    string r="15.5";
    int t= stoi(g);
    cout << t << endl;
    string::size_type sz;
    float p= stof(r, &sz);
    cout << p << endl;
    //find string B (or char) in string A
    string strA = "HelloworldHelloworld";
    string strB = "ll";
    size_t found = 0;
    for (int i=0; i<strA.length(); i++){
        found = strA.find(strB, found+i);
        if (found==string::npos) break;
        else cout << found << endl;
    }
    //convert string to char[]
    char* ch = new char[strA.length()];
    strcpy(ch, strA.c_str());
    delete []ch;
    return 0;
}