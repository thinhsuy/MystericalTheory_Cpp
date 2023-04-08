#include <iostream>
using namespace std;
#define maximum 100


//Hàm nhập vào n phần tử
void insert_value_for_array(int Arr[], int &n){ 
    for (int i=0; i<n; i++){
        int t;
        cout << "insert value of " << "array [" << i << "] = ";
        cin >> t;
        Arr[i]=t;
    }
}

//Ham xuat n gia tri
void export_the_value_of_array(int Arr[], int &n){
    for (int i=0; i<n; i++){
        cout << "Arr[" << i << "] = " << Arr[i];
        cout << endl;
     }
} 

//Hàm tính tổng giá trị mảng
void sum_of_value_in_array(int Arr[], int n){
   int sum = 0;
   for (int i=0; i<n; i++){
      sum = sum + Arr[i];
   }
    cout << "Total value = " << sum;
}


//Hàm tìm min của mảng 
void find_min_in_array(int Arr[], int n){
    int min = Arr[0];
    for (int i=1; i<n; i++){
        if (Arr[i]<=min){
            min = Arr[i];
        }
    }
    cout << "The minimun value is: " << min;
}


//Hàm kiểm tra số nguyên tố
void count_prime_numbers(int Arr[], int n){
   
    int count = 0;
    for (int i=0; i<n; i++){
        int cd = 0; //cd is common devisor
          for (int j=1; j<=Arr[i]; j++) {
            if (Arr[i] % j == 0) {
                cd++;
            }
          }
          if (cd==2){
          count = count + 1;
          }
    }
    cout << "There is/are " << count << " prime number(s)";
}
    
//Hàm kiểm tra tăng dần
void check_increasing(int Arr[], int n){
    int max=Arr[0];
    int count = 0;
    for (int i=1; i<n; i++){
        if (Arr[i]>=max){
            max = Arr[i];
            count = count + 1;
        }
    }
    if (count == n-1){
        cout << "This array is increasing";
    } else {
        cout << "This array is not increasing";
    }
}


//Hàm đếm số lần xuất hiện
void count_appearences(int Arr[], int n, int x){
    int count = 0;
    for (int i=0; i<n; i++){
        if (Arr[i]== x){
            count = count + 1;
        }
    }
    cout << "There is/are " << count << " times that number " << x << " appeares in array"; 
}

//Hàm xóa phần tử y
void delete_value_in_array(int Arr[], int n, int y) {
    for (int j=0; j<n; j++){
        if (Arr[j]==y){
          for (int i=j; i<n; i++){
             Arr[i]=Arr[i+1];
          }
        n--;
        }
    }
    export_the_value_of_array(Arr, n);
}

//Hàm xóa tất cả giá trị từ vị trí nào đó
void delete_all_value_from_target(int Arr[], int n, int idx) {
    for (int i=idx-1; i<n; i++){
        n--;
    }
    export_the_value_of_array(Arr, n);
}



int main ()
{
    int Arr[maximum];
    int n;
    // 0. Xác định n
    cout << "how many factors that you want: ";
    cin >> n;
    // 1. nhập giá trị mảng
    cout << "\t\t\tArray has " << n << " factors: " << endl;
    insert_value_for_array(Arr, n);
    cout << endl;
    // 2. xuat gia tri mảng
    cout<<"\t\t\tThe value(s) of your array is/are: " << endl;
    export_the_value_of_array(Arr, n);
    cout << endl;
    // 3. tổng giá trị
    sum_of_value_in_array(Arr, n);
    // 4. tìm giá trị nhỏ nhất
    cout << "\n\n";
    find_min_in_array(Arr, n);
    // 5. đếm số nguyên tố
    cout << "\n\n";
    count_prime_numbers(Arr, n);
    // 6. kiểm tra tăng dần ?
    cout << "\n\n";
    check_increasing(Arr, n);
    // 7. đếm số lần xuất hiện x
    cout << "\n\n";
    int x;
    cout << "Insert value that needs to be checked: ";
    cin >> x;
    count_appearences(Arr, n, x);
    // 8. Hàm xóa giá trị y trong mảng
    cout << "\n\n";
    int y;
    cout << "Insert value that needs to be deleted: ";
    cin >> y;
    delete_value_in_array(Arr, n, y);
    // 9. Hàm xóa tất cả giá trị từ vị trí index
    cout << "\n\n";
    int idx;
    cout << "Insert position that you wanna delete: ";
    cin >> idx;
    delete_all_value_from_target(Arr, n, idx);
    




    return 0;
}
