#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

void InsertionSort(int*a, int n){
    for (int i=0; i<n; i++){
        for (int j=i-1; j>=0; j--) {
            if (a[j+1]<a[j]) swap(a[j],a[j+1]);
            else break;
        }
    }
}

void SelectionSort(int*a, int n){
    for (int i=0; i<n-1; i++){
        int min=i;
        for (int j=i+1; j<n; j++){
            if (a[j]<a[min]) min=j;
        } swap(a[i], a[min]);
    }
}

void BubleSort(int*a, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]) swap(a[j], a[j+1]);
        }
    }
}

void Sort(int*a, int l, int r){
    for (int i=l; i<=r-1; i++){
        int min=i;
        for (int j=i+1; j<=r; j++){
            if (a[j]<a[min]) min=j;
        } swap(a[i], a[min]);
    }
}

void mergeSort(int*a, int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;
        Sort(a, l, m);
        Sort(a , m+1, r);
        Divide(a, l, m, r);
    }
}

void Divide(int a[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    int* L = new int[n1];
    int* R = new int[n2];
    for(int i = 0;i < n1; i++) L[i] = a[l+i];
    for(int i = 0;i < n2; i++) R[i] = a[m+1+i];
    int i = 0, j = 0, k =l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
    delete []L;
    delete []R;
}

void ShellSort(int*a, int n){
	int interval, i, j, temp;
	for(interval = n/2; interval>0; interval /= 2){
		for(i=interval; i<n; i++){
			temp = a[i];
			for(j=i; j>=interval && a[j-interval]>temp; j-=interval){
				a[j] = a[j-interval];				
			} a[j] = temp;
		}
    }
}

int partition(int*a, int low, int high) {
    int pivot = a[high];
    int left = low, right = high-1;
    while(left < right) {
        while(a[left]<pivot) left++;
        while(a[right]>pivot) right--; 
        if(left >= right) break;
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
    }
    int temp = a[left];
    a[left] = a[high];
    a[high] = temp;
    return left;
}

void quicksort(int*a, int low, int high) {
    if(low >= high) return;
    int pivotPosition = partition(a, low, high);
    quicksort(a,low, pivotPosition-1);
    quicksort(a, pivotPosition+1, high);
}



int main(){
    int n=19;
    int*a=new int[n];
    ifstream ifs;
    ifs.open("text.txt");
    int i=0;
    while (!ifs.eof()){
        ifs>>a[i];
        i++;
    } ifs.close();

    SelectionSort(a, n);

    for (int i=0; i<n; i++) cout << a[i] << " ";


    delete []a;
    return 0;
}