#include <iostream>
#include <ctime>   //time() libary
#include <cstdlib> //rand() and srand() libary
#include <random>  //C++ vers 11.0 
#include <string>
#include <Windows.h>
using namespace std;

int random_number(){
    int arr[100];
    int n;
    cout << "n= ";
    cin >> n;
    int a;
    srand(time(NULL));
    a = rand() % 100 + 1; //random from 1 to 100
    return a;
}

void realTime(){
    time_t now = time(NULL);
    cout << "now = " << now << endl;
    //định dạng thời gian bằng con trỏ
    string strA= ctime(&now);
    cout << "string A = " << strA << endl;
    //định dạng thời gian bằng cấu trúc tm
    tm* t= localtime(&now);
    string strB = asctime(t);
    cout << "string B = " << strB << endl;
    //định dạng thời gian tự chọn (mon phải +1 và year phải +1900)
    cout << "Day/Mon/Year + Hr/Min/Sec : " << endl;
    cout << t->tm_mday<<"/"<<1+t->tm_mon<<"/"<<1900+t->tm_year<<" + ";
    cout << t->tm_hour<<":"<<t->tm_min<<":"<<t->tm_sec<<endl;
}

void count_time(int h, int m, int s){
    for (int k=1; k<255; k++){
      for (int i=s; i>=0; i--){
        // HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        // SetConsoleTextAttribute(hConsole, k);
        if (s==0){
            m = m - 1;
        }
        cout << h << ":" << m << ":" << s << endl;
        s=60;
        Sleep(1000);
      }
    }
}


int main(){
    realTime();
    return 0;
}
