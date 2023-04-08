#include <iostream>
using namespace std;
#define maximum 100

struct Time_1{
    int sec1;
    int min1;
    int hour1;
};

struct Time_2{
    int sec2;
    int min2;
    int hour2;
};

struct Time_g{
    int secg;
    int ming;
    int hourg;
};

struct fraction_1{
    int num1;
    int deno1;
};

struct fraction_2{
    int num2;
    int deno2;
};

struct fraction_total{
    int numt;
    int denot;
};

struct fraction{
    int num;
    int deno;
};

struct fraction f;
struct Time_1 t1;
struct Time_2 t2;
struct Time_g tg;
struct fraction_1 f1;
struct fraction_2 f2;
struct fraction_total ft;

void the_gap_of_time();
void the_sum_of_fractions();
void add_fraction();
void add_more_fractions();
void out();
void out_list();
void smallizing_fraction();



//Cau 1:
void the_gap_of_time(Time_1 t1, Time_2 t2, Time_g tg){
    cout << "\n\nThe disparity of 2 times is: " << endl;
    if (t1.sec1 - t2.sec2 >=0){
        tg.secg = t1.sec1 - t2.sec2;
    } else {
        tg.secg = t2.sec2 - t1.sec1;
    }
    if  (t1.min1 - t2.min2 >= 0){
        tg.ming = t1.min1 - t2.min2;
    } else {
        tg.ming = t2.min2 - t1.min1;
    }
    if (t1.hour1 - t2.hour2 >= 0){
        tg.hourg = t1.hour1 - t2.hour2;
    } else {
        tg.hourg = t2.hour2 - t1.hour1;
    }
    cout << tg.hourg << "h" << tg.ming << "m" << tg.secg << "s";
}


//Cau 2:
void the_sum_of_fractions(fraction_1 f1, fraction_2 f2, fraction_total ft){
    if (f1.deno1 == 0 || f2.deno2 == 0){
        cout << "This is not a fraction, NaN";
    }else {
        cout << "The sum of 2 fractions is: ";
        ft.numt = (f1.num1 * f2.deno2) + (f2.num2 * f1.deno1);
        ft.denot = f1.deno1 * f2.deno2;
        cout << ft.numt << "/" << ft.denot;

    }
}


//Cau3.1:
void add_fraction(fraction &f){
    cout<< "Insert value of num: ";
    cin >> f.num;
    cout << "Insert value of deno: ";
    cin >> f.deno;
}

//Cau 3.2
void add_more_fraction(fraction Arr[],int n){
    for (int i=0; i<n; i++){
        cout << "Insert value of fraction: " << i+1 << endl;
        cout << "Fraction " << i+1;
        add_fraction(Arr[i]);
    }
}


//cau 3.3:
void out(fraction &f, int x){
     if (f.num > f.deno){
         x = f.deno;
     } else {
         x = f.num;
     }
     for (int i=x; i>1; i--){
         if (f.deno%x == 0 && f.num%x == 0){
             f.num = f.num/x;
             f.deno = f.deno/x;
         } 
         break;
     }
    cout << f.num << "/" << f.deno;
    cout << endl;
}

//Cau 3.4:
 void out_list(fraction Arr[],int n, int x, fraction f){
     for (int i=0; i<n; i++){
         cout << "Fraction " << i + 1 << " ";
         out(Arr[i], x);
     }
 }

 



int main(){
    
    
    
   

    //Cau 3:
    struct fraction Arr[maximum];
    int n;
    int x;
    cout << "Insert the number of fractions: ";
    cin >> n;
    add_more_fraction(Arr, n);
    out_list(Arr, n, f);
    cout << endl;    

    return 0;

}