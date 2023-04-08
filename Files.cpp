#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

void BinaryFile(){
    ofstream ofs;
    //Writing
    int n=4;
    int a[] = {1,2,3,4};
    ofs.open("BinaryOut.dat", ios::binary);
    if (ofs.is_open()){
        //ofs.write( <convertChar><directOfVariable>, <sizeOfByte>);
        ofs.write((char*)&n, 4);
        ofs.write((char*)a, n*4);
    } ofs.close();
    //Reading
    ifstream ifs;
    ifs.open("BinaryOut.dat", ios::binary);
    if (ifs.is_open()){
        int x;
        ifs.read((char*)&x, 4);
        cout << x;
        //Jump
        int j;
        //possition * size of byte
        ifs.seekg(12);
        ifs.seekg(-4, ios::end); //start from last of array of bytes
        ifs.read((char*)&j, 4);
        cout << j;
        //whole array
        int *a=new int[n];
        ifs.read((char*)a, n*4);
        for (int i=0; i<n; i++) cout << a[i];
        delete []a;
    }
}

/*REGULAR EXPRESSION*/
//ktra các ký tự có hay trong 1 chuỗi
bool checkChar(){
    string str = "123fsd";
    //gán điều kiện ký tự cần ktra, ở đây là int có trong 1 từ
    regex check = regex("\\b\\d+\\b");
    //ktra và trả về yes no nếu có
    bool mark = regex_match(str, check);
    //thực thi
    if (mark) return true;
    else return false;
}

//xử lý mảng
void treatString(){
    string buffer = "12/13";
    //return index of value char
    int firstIndex = buffer.find_first_of("/");
    //track the hole substring from a->b
    string numerator = buffer.substr(0, firstIndex);
}

int main() {
    //thu tu thao tac Mo File -> Doc File -> Ghi File -> Dong File
    //co 3 cu phap chinh cua doc file
    fstream fst; 
    ifstream fstin;
    ofstream fstout;
    //MO 1 file tu 1 dia chi hoac ten file cu the
    fstin.open("C:\\Users\\ACER\\Desktop\\input.txt");
    //fstream fst("C:\\Users\\ACER\\Desktop\\input.txt", ios::in);
    int n;
    int* arr;
    //DOC 1 file
    fstin >> n;
    arr = new int[n];
    for (int i=0; i<n; i++){
        fstin >> arr[i];
    } cout << n << endl; 
    for (int i=0; i<n; i++){cout << arr[i] << " ";}\
    fstin.close(); //nhớ đóg ko thì chương trình sau ko chạy đc
    //GHI 1 file, neu ko co se tu tao
    //tạo file tại 1 địa chỉ cụ thể
    fstout.open("C:\\Users\\ACER\\Desktop\\output.txt", ios::out);
    //tạo file tại resourse của chương trình
    fstout.open("output.txt", ios::out);
    //NOTE: ios::out dùng để ghi file mới, ios::ap dùng để ghi đè lên 1 file có sẵn
    fstout << n << endl;
    for (int i=0; i<n; i++){
        fstout << arr[i] << " ";
    } fstout.close();

    return 0;
}

