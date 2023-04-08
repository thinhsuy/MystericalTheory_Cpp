#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stdarg.h>
#include <memory>
#include <math.h>
#include <sstream>
#include <initializer_list>
using namespace std;
//Basic Class
class Random{
    private: int start;
    private: int end;
    private: inline static shared_ptr<Random> _instance = NULL;
    private: Random(){
        this->start = 0;
        this->end = 100000;
        srand(time(NULL));
    }
    public: static shared_ptr<Random> instance(){
        if (_instance==NULL){
            Random*temp = new Random();
            _instance = make_shared<Random>(*temp);
        } return _instance;
    }
    public: void setValue(int s, int e) {this->start=s; this->end=e;}
    public: int getValue(){
        return rand()%(this->end-this->start+1)+this->start;
    }
    public: float getFValue(){
        int a = rand()%(this->end-this->start+1)+this->start;
        int b = rand()% 10;
        string str = to_string(a)+"."+to_string(b);
        return stof(str);
    }
    public: char getCValue(){
        string str = {"abcdefghijklmnopqrstuvwxyz"};
        int a = rand()%(this->end-this->start+1)+this->start;
        return str[a];
    }
    ~Random(){}
};



//Class with unknown type of value
template <typename Type>
class heckor {
private:
	Type *arr;
    int size;
    int capacity;
public:
	heckor();
    void push_back(Type);
	void print();
    int Size();
    int Capacity();
    Type getValue(int);
    Type operator[](int index) {return getValue(index);}
    ~heckor(){delete []arr;}
};
template <typename Type>
heckor<Type>::heckor(){
    this->size=0;
    this->capacity=0;
    this->arr=new Type[this->capacity];
}
template <typename Type>
void heckor<Type>::push_back(Type value){
    if (this->size >= this->capacity){
        Type*temp=new Type[this->size+1];
        for (int i=0; i<this->size; i++) temp[i]=arr[i];
        delete []arr;
        arr=temp;
    } 
    arr[this->size]=value;
    this->size++;
    this->capacity=this->size;
}
template <typename Type>
void heckor<Type>::print() {
    for (int i=0; i<this->size; i++){
        cout << arr[i] << " ";
    } cout << endl;
}
template <typename Type>
int heckor<Type>::Size(){return this->size;}
template <typename Type>
int heckor<Type>::Capacity(){return this->capacity;}
template <typename Type>
Type heckor<Type>::getValue(int index) {return this->arr[index];}

//Variadic Arguement
void PrintFloats (int n, ...)
{
  int i;
  double val;
  printf ("Printing floats:\n");
  va_list vl;
  va_start(vl,n);
  for (i=0;i<n;i++)
  {
    val=va_arg(vl,double);
    cout << val << endl;
  }
  va_end(vl);
}
template <typename T>
void func(T t) 
{
    std::cout << t << std::endl ;
}
template<typename T, typename... Args>
void func(T t, Args... args) // recursive variadic function
{
    std::cout << t <<std::endl ;

    func(args...) ;
}
template <class T>
void func2( initializer_list<T> list )
{
    for( auto elem : list )
    {
        cout << elem << std::endl ;
    }
}


template <typename Type>
class heckor {
private:
	Type *arr;
    int size;
    int capacity;
public:
	heckor();
    void push_back(Type);
    int Size();
    int Capacity();
    Type getValue(int);
    Type operator[](int index) {return getValue(index);}
    ~heckor(){delete []arr;}
};

template <typename Type>
heckor<Type>::heckor(){
    this->size=0;
    this->capacity=0;
    this->arr=new Type[this->capacity];
}
template <typename Type>
void heckor<Type>::push_back(Type value){
    if (this->size == this->capacity){
        Type*temp=new Type[this->size+1];
        for (int i=0; i<this->size; i++) temp[i]=this->arr[i];
        delete []arr;
        this->arr=temp; 
        arr[this->size]=value;
        this->size++;
        this->capacity=this->size;
    } else {
        arr[this->size]=value;
        this->size++;
    }
}
template <typename Type>
int heckor<Type>::Size(){return this->size;}
template <typename Type>
int heckor<Type>::Capacity(){return this->capacity;}
template <typename Type>
Type heckor<Type>::getValue(int index) {return this->arr[index];}


//SHARED_POINTER
class Point {
private:
    int _x;
    int _y;
public:
    int x() const { return _x;}
    int y() const { return _y;}
public:
    Point() {  
        cout << "Constructor" << endl;
    }
    
    Point(int a, int b): _x(a), _y(b) {
        _x = a;
        _y = b;
        cout << "Parameterized constructor" << endl;
    }
    
    ~Point() {
        cout << "Destructor" << endl;
    }
};

class PointToStringUIConverter {
public:
    string convert(const Point& p) {
        stringstream builder;
        
        builder << p.x() << ", " << p.y();
        
        string result = builder.str();
        return result;
    }
};

// Khai báo 2 lớp
class Car;
class Passenger;

// Bỏ qua getter / setter;
// cài đặt cụ thể
class Car {
private:

public:
    queue<weak_ptr<Passenger>> passengers;
public:
    ~Car() { cout << "Car destructor" << endl; }
};


class Passenger {
    
public:
    weak_ptr<Car> car; 
public:
    ~Passenger() { cout << "Passenger's destructor" << endl; }
};


typedef int (*MyType)(int);

int calc1(int number) {
    return number * 2;
}

int calc2(int number) {
    return number / 2;
}

typedef bool (*Predicate)(int);

bool isOdd(int number) {
    bool result = number % 2 == 1;
    return result;
}

bool isEven(int number) {
    bool result = number % 2 == 0;
    return result;
}

bool isPrime(int number){
    if (number<2) return false;
    else if (number==2) return true;
    for (int i=2; i<=sqrt(double(number)); i++){
        if (number%i==0) {return false;}
    } return true;
}


bool isSquare(int number){
    int s = sqrt(number);
    if (pow(s,2)==number) return true;
    else return false;
}

queue<int> reduce(queue<int> data, Predicate f) {
    queue<int> result;
    
    for(int i = 0; i < data.size(); i++) {
        if (f(data[i])) {
            result.push_back(data[i]);
        }
    }
    
    return result;
}
