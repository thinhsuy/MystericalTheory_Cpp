#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Graph{
    private:
        int**matrix;
        int n;
    public: 
        void Input(int**value, int a){
            this->matrix = value;
            this->n = a;
        }
        void Redundancy(){
            for(int i=0;i<n;i++) delete []matrix[i];
            delete []matrix;
        }
        void rehearse(vector<int>&path, vector<bool>&check, int i){
            path.push_back(i);
            check[i]=true;
            for (int j=0;j<n;j++){
                if (matrix[i][j] && !check[j]) this->rehearse(path, check, j);
                return;
            }
        }
        void AllPathFromTo(int start, int end){
            vector<int>path;
            vector<bool>check;
            for (int i=0;i<n;i++) check[i]=false;
            check[start] = true;
            for (int i=start; i<n; i++){
                if (matrix[start][i]) this->rehearse(path, check, i);
                break;
            }
            for (int i=0;i<n;i++) cout << path[i]+1 << " ";
        }
};

int main(){
    ifstream ifs;
    ifs.open("text.txt");
    int n; ifs>>n;

    int**matrix = new int*[n];
    for(int i=0; i<n; i++) matrix[i] = new int[n];

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            ifs>>matrix[i][j];
        }
    } ifs.close();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        } cout << endl;
    }
    Graph g;
    g.Input(matrix, n);
    g.AllPathFromTo(0,3);

    for(int i=0;i<n;i++) delete []matrix[i];
    delete []matrix;

    return 0;
}