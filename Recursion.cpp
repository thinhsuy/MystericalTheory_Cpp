#include <iostream>
using namespace std;

void permutation();
void FillSlotK_permute(int k, int* arr, int n, bool* notUsed);
void display_permute(int* arr, int n);
void OpertionMatch(int n);
void fillOp(int k, int* arr, int* op, int n, int total);
int evaluate(int a, int b, int o, bool& divZero);
int caculate(int* arr, int* op, int n, bool& divZero);
void display_operator(int* arr, int* op, int n, int total);
void QueensChess();
void display_Queens(int* a, int n);
void fillSlotK_Queens(int k, int* a, int n, bool* notCol, bool* notD1, bool* notD2);

void simpleEx(){
    int t;
    cin>>t;
    if (t!=0){
        simpleEx();
        cout << t << " ";
    } 
}
///////////////////////////////
void permutation(){
    int n;
    cin>>n;
    int* arr = new int[n];
    bool* notUsed = new bool[n];
    for (int i=0; i<n; ++i) {
        notUsed[i]=true;
    }

    FillSlotK_permute(0, arr, n, notUsed);

    delete []arr;
    delete []notUsed;
}

void FillSlotK_permute(int k, int* arr, int n, bool* notUsed){
    if (k>=n) display_permute(arr, n);
    else {
        for (int i=0; i<n; ++i){
            if (notUsed[i]){
                arr[k] = i;
                notUsed[i]=false;
                FillSlotK_permute(k+1, arr, n, notUsed);
                notUsed[i]=true;
            }
        }
    }
}
void display_permute(int* arr, int n){
    for (int i=0; i<n; ++i){
        cout << arr[i]+1 << " ";
    } cout << endl;
}
////////////////////////////
int factorial(int n){
    if (n<=1) return 1;
    else return n*factorial(n-1);
}
////////////////////////////
void OpertionMatch(int n){
    int total; 
    cout << "Total: "; cin>>total;
    int* arr = new int[n];
    for (int i=0; i<n; i++) cin>>arr[i];
    int* op = new int[n-1];
    
    fillOp(0, arr, op, n, total);
    delete []arr;
    delete []op;
}

void fillOp(int k, int* arr, int* op, int n, int total){
    if (k==n-1) {
        bool divZero = false;
        if (caculate(arr, op, n, divZero)==total) display_operator(arr, op, n, total);
    }
    for (int i=0; i<4; i++){
        op[k] = i;
        fillOp(k+1, arr, op, n, total);
    }
}

int evaluate(int a, int b, int o, bool& divZero){
    divZero=false;
    switch (o) {
        case 0: return a+b;
        case 1: return a-b;
        case 2: return a*b;
        default: 
        if (b==0) {
            divZero=true;
            return -1;
        } return a/b;
    };
}

int caculate(int* arr, int* op, int n, bool& divZero){
    if (n==1) return arr[0];
    if (n==2) return evaluate(arr[1], arr[0], op[0], divZero);
    
    int* x = new int[n];
    int* o = new int[n-1];
    
    for (int i=n-2; i>=0; i--){   //coppy reverse
        x[n-1-i] = arr[i];
        o[n-2-i] = op[i];
    } x[0] = arr[n-1];    // coppy last number
    
    for (int i=n-2; i>=0; i--){
        if (o[i]==2 || o[i]==3 || o[i-1]==0 || o[i-1]==1){
            x[i] = evaluate(x[i+1], x[i], o[i], divZero);
            if (divZero) break;
        } else {
            x[i-1] = evaluate(x[i], x[i-1], o[i-1], divZero);
            x[i] = x[i+1]; //shrink
            o[i-1] = o[i]; //shrink
        }
    }
    int result = evaluate(x[1], x[0], o[0], divZero);
    
    delete []x;
    delete []o;
    
    return result;
}

void display_operator(int* arr, int* op, int n, int total){
    char o[4] = {'+', '-', '*', '/'};
    for (int i=0; i<n-1; i++){
        cout << arr[i] << o[op[i]];
    } cout << endl;
}
////////////////////////////////////
void QueensChess() {
    int n;
    cout << "N = ";
    cin >> n;
    
    int* a;
    a = new int[n];
    bool* notCol, *notD1, *notD2;
    notCol = new bool[n];
    for (int i=0; i<n; ++i)
        notCol[i] = true;
    notD1 = new bool[2*n-1];
    notD2 = new bool[2*n-1];
    for (int i=0; i<2*n-1; ++i)
        notD1[i] = notD2[i] = true;
    
    fillSlotK_Queens(0, a, n, notCol, notD1, notD2); //try row 0
    
    delete [] a;
    delete [] notCol;
    delete [] notD1;
    delete [] notD2;
}

void fillSlotK_Queens(int k, int* a, int n, bool* notCol, bool* notD1, bool* notD2) {
    if (k>=n) displayQueens(a, n);
    else for (int i=0; i<n; ++i)
        if (notCol[i] && notD1[k+i] && notD2[k-i+n-1]) {
            a[k] = i; //column i used
            notCol[i] = false;
            notD1[k+i] = false;
            notD2[k-i+n-1] = false;
            fillSlotK_Queens(k+1, a, n, notCol, notD1, notD2);
            notCol[i] = true; //uncheck i, to try (i+1)
            notD1[k+i] = true;
            notD2[k-i+n-1] = true;
        }
}
void displayQueens(int* a, int n) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j)
            if (a[i]==j) cout << " Q";
            else cout << " .";
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n;
    //bai 1
    simpleEx();
    //bai 2
    permutation();
    //bai 3
    OpertionMatch(n);
    //bai 4
    QueensChess(n);
    return 0;
}