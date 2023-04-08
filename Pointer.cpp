#include <iostream>
using namespace std;

void Basic_of_Pointer(int &x){
    x=10;
    cout << x << endl; //xuất giá trị của x
    cout << &x << endl; //xuất ĐỊA CHỈ trên thanh RAM của x
    cout << *&x << endl; //xuất GIÁ TRỊ tại ĐỊA CHỈ thanh ram của x
    *&x = 20;
    cout << x << endl; //thay đổi giá trị tại địa chỉ, cũng thay đổi giá trị của biến x

//iPrt là địa chỉ
//*iPrt là giá trị tại địa chỉ

    int *iPrt; //khai báo CON TRỎ chỉ tới ĐỊA CHỈ số nguyên
    int *iPrt2 = &x; //con trỏ chỉ để lưu ĐỊA CHỈ chứ ko lưu giá trị
    //hoặc ghi *iPrt2 = &x;
    cout << iPrt2 << endl; //xuất ra ĐỊA CHỈ trên thanh ram của x
    cout << *iprt2 << endl; //Xuất giá trị tại ĐỊA CHỈ đó (hiện tại là địa chỉ của x, nên sẽ = 20)
    *iPrt2 = 30; //xuất ra giá trị là 30 vì địa chỉ x đang bị iprt2 nắm giữa cùng địa chỉ,
    cout << &x << endl;  //và nếu 1 trong 2 thay đổi, thì cả 2 đều thay đổi
}

void Null_Pointer(int &x){
    //ĐN: là con trỏ chưa chỉ đến bất kì địa chỉ nào và mang giá trị rỗng
    x=10;
    int *prt{ 0 };  //khởi tạo con trỏ NULL
    int *prt2;  //đây là con trỏ rác => truy cập con trỏ rác hoặc NULL sẽ làm dừng CT lập tức
    prt2 = 0; //bây giờ nó là con trỏ NULL 
}

void Array_Pointer(int &x){
    //ĐN: mảng mang tính chất giống pointer nhưng thực chất nó khác nhau
    int arr[4] { 5, 8, 2, 7}; 
    x=10;
    cout << "Giá trị Array" << *arr << endl; //giá trị tại địa chỉ array cũng tức là giá trị arr[0]
    int *prt = *array;
    cout << *prt << endl; //xuất giá trị tại địa chỉ array tức là arr[0]
    *prt = 6;
    for (int i=0; i<n; i++){
        cin >> *(ptr+i); //change the value of array respectively or cin>>prt[i]
    }
    char name[] = "Thinh"; 
    cout << *name << endl; //xuất giá trị là T vì T ở vị trí index = 0;
    //Lưu ý: Mảng được truyền vào hàm sẽ đc chuyển ngầm định về con trỏ để tiết kiệm bộ nhớ
    //size of array = numbers of factor * 4bit
    //size of Pointer = 4bit (always)
    //do đó khi thay đổi array trong hàm sẽ thay đổi array ngoài hàm   
}

int main(){
    int x;
    Basic_of_Pointer(x);
    Null_Pointer(x);
    Array_Pointer(x);
    return 0;
}