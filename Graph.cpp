#include <iostream>
#include <utility>
#include <queue>
#include <fstream>
#define max 513755
using namespace std;

//Check connection of graph
void rehearse(int*matrix[], int j, bool check[], int n){
    check[j]=true;
    for (int i=0; i<n; i++){
        if (matrix[j][i]==1 && check[i]==false) rehearse(matrix, i, check, n);
    }
}
bool isConnected(int*matrix[], int n){
    bool*check=new bool[n];
    for (int i=0;i<n; i++){
        for (int j=0; j<n; j++) check[j]=false;
        for (int j=0; j<n; j++) if (matrix[i][j]) rehearse(matrix, j, check, n);
        for (int j=0; j<n; j++) if (check[j]==false) return false;
    } delete []check;
    return true;
}

//Print out each cluster of graph if not connected
void rehearseCluster(int*matrix[], int j, int checked[], int n, int numb){
    checked[j]=numb;
    for (int i=0; i<n; i++){
        if (matrix[j][i]==1 && !checked[i]) rehearseCluster(matrix, i, checked, n, numb);
    }
}
void Clusters(int*matrix[], int n){
    int*check=new int[n];
    int numb=1;
    for (int i=0;i<n; i++){
        if (check[i]) continue;
        for (int j=0; j<n; j++) if (matrix[i][j]) rehearseCluster(matrix, j, check, n, numb);
        for (int j=0; j<n; j++) {
            if (check[j]==numb) cout << j+1 << " ";
        } cout << endl;
        numb++;
    } delete []check;
}

//MST (Prim and Kruskal)
bool isCycle(int*matrix[], int n){
    int*subset=new int[n];
    int mark=1;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (matrix[i][j]) {
                if (!subset[i] && !subset[j]) {
                    subset[i]=mark;
                    subset[j]=mark;
                    mark++;
                } else if (subset[i] && !subset[j]) subset[j]=subset[i];
                else if (!subset[i] && subset[j]) subset[i]=subset[j];
                else if (subset[i] != subset[j]) for (int k=0; k<n; k++) if (subset[k]==subset[i]) subset[k]=subset[j];
                else if (subset[i] == subset[j]) return false;
            }
        }
    } return true;
}
void MinimumSpanning(int*matrix[], int n){
    int row, col, min, cost=0;
    bool*vertex=new bool[n];
    vertex[0]=true;
    for (int i=1; i<n; i++) vertex[i]=false;
    for (int i=0; i<n-1; i++){
        min=max;
        for (int j=0; j<n; j++){
            if (vertex[j]){
                for (int k=0; k<n; k++){
                    if (!vertex[k] && matrix[j][k]!=0 && matrix[j][k]<min){
                        min=matrix[j][k];
                        row=j;
                        col=k;
                    }
                }
            }
        } cout << row << "->" << col << "\t= " << min << endl;
        vertex[col]=true;
        cost+=matrix[row][col];
    } cout << "Total: " << cost << endl;
    delete []vertex;
}

//Shortest path algorithms
void PrintPathSP(int arr[],int x, int y){
    int t = arr[y];
    if (y!=x){
        y=arr[y];
        PrintPathSP(arr, x, y);
        cout << t << " -> ";
    } 
}
void Dijkstra(int*matrix[], int n, int x, int y){
    //x is start point and y is destination 
    int*dis=new int[n] {0};
    int*prev=new int[n] {0};
    bool*checked=new bool[n] {false};
    int key=x, min, index;
    for (int i=0; i<n; i++){
        if (key==y) break;
        min=max;
        checked[key]=true;
        for (int j=0; j<n; j++){
            if (matrix[key][j]>0 && !checked[j]){
                int sum = dis[key] + matrix[key][j];
                if (dis[j]==0 || dis[j]>sum){ 
                    dis[j]=sum;
                    prev[j]=key;
                }
            }
        } 
        for (int k=0; k<n; k++) {
            if (dis[k]<min && dis[k]!=0 && !checked[k]){
                min=dis[k];
                index=k;
            }
        }
        key=index;
    } 
    for (int i=0; i<n; i++) cout << dis[i] << " "; cout << endl;
    for (int i=0; i<n; i++) cout << prev[i] << " "; cout << endl;
    if (!prev[y]) return; 
    else {
        cout << "\t value: " << dis[y] << endl;
        PrintPathSP(prev, x, y);
        cout << y << endl;
    } 
    delete []prev;
    delete []checked;
    delete []dis;
}
void BellmanFord(int**matrix, int n, int start, int end){
    int*value=new int[n];
    for (int i=0; i<n; i++) value[i]=9999;
    value[start]=0;
    int*track=new int[n];
    bool*check=new bool[n];
    queue<pair<int, int>> que;
    for (int i=0; i<n-1; i++){
        bool relaxation=false;
        que.push(make_pair(start, start));
        while (!que.empty()){
            for (int i=0; i<n; i++) check[i]=false;
            for (int j=0; j<n; j++){ 
                if(matrix[que.front().second][j]!=0 && !check[que.front().second]) que.push(make_pair(que.front().second, j));
            } check[que.front().second]=true;
            //relaxation
            if (value[que.front().first] + matrix[que.front().first][que.front().second] < value[que.front().second]){
                value[que.front().second] = value[que.front().first] + matrix[que.front().first][que.front().second];
                track[que.front().second]=que.front().first;
                relaxation=true;
            } que.pop();
        } 
        if (!relaxation) break;
    }
    if (!track[end]) return; 
    else {
        cout << "\t value: " << track[end] << endl;
        PrintPathSP(track, start, end);
        cout << end << endl;
    } 
    delete []check;
    delete []value;
    delete []track;
}
void FloyedWarshall(int**a, int n, int start, int end){
    //generate path[][]
    int**path=new int*[n];
    for (int i=0; i<n; i++) path[i]=new int[n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j]) path[i][j]=i;
            else path[i][j]=-1;
        }
    } 
    //custom matrix a[][]
    for (int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            if (i==j) a[i][j]=0;
            else if (a[i][j]==0) a[i][j]=9999;
        }
    }
    //loop matrix
    for (int k=0; k<n; k++){
        int**b=new int*[n];
        for (int i=0; i<n; i++) b[i]=new int[n];
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i==j) {
                    b[i][j]=0;
                    continue;
                }
                else if (a[i][j] > a[i][k] + a[k][j]) {
                    b[i][j] = a[i][k]+a[k][j];
                    path[i][j]=path[k][j];
                } else b[i][j]=a[i][j];
            }
        }
        for (int i=0; i<n; i++) for(int j=0; j<n; j++) a[i][j]=b[i][j];
        for (int i=0; i<n; i++) delete []b[i];
        delete []b;
    }
    int*pathx=new int[n];
    for (int i=0; i<n; i++) pathx[i]=path[start][i];
    if (!pathx[end]) return; 
    else {
        cout << "\t value: " << a[start][end] << endl;
        PrintPathSP(pathx, start, end);
        cout << end << endl;
    } 
    for (int i=0; i<n; i++) delete []path[i];
    delete []path;
    delete []pathx;
}

//Hamiltonian - travel all node without repeating path and comeback
bool isExist(int*a, int n, int x, int dis){
    for (int i=0; i<dis; i++) if(a[i]==x) return true;
    return false;
}
void TrackBacking(int*track, int n, int val, int i, int**matrix){
    while (isExist(track, n, val, i) || !matrix[track[i-1]][val]) 
    {
        val++;
        if (val==n) break;
    }
    if (val<n) track[i]=val;
    else if (val==n || (track[n-1]!=-1 && !matrix[track[n-1]][0])) {
        track[i]=-1;
        if (track[n-1]!=-1 && !matrix[track[n-1]][0]) {
            cout << "LAG??" << endl;
            return;
        }
        TrackBacking(track, n, track[i-1]+1, i-1, matrix);
    }
}
bool isHamiltonian(int**matrix, int n){
    int*track=new int[n];
    for (int i=0; i<n; i++) track[i]=-1;
    track[0]=0;
    int i=0;
    
    while (track[1]!=n){
        i++;
        TrackBacking(track, n, 0, i, matrix);
        if (i==n-1) {
            for (int i=0; i<n; i++) cout << track[i] << " ";
            return true;
        }
    } 
    
    delete []track;
    return false;
}

//Euler Circuit - travel all path without repeating path and comeback
bool isEulerianCircuit(int*matrix[], int n){
    if (!isConnected(matrix,n)) return false;
    for (int i=0; i<n; i++){
        int count=0;
        for (int j=0; j<n; j++) count++;
        if (count%2!=0) return false;
    } return true;
}

//Searching (DFS and BFS)
void BFS(int*a[], int n, int start){
    queue<int> que;
    bool*check=new bool[n] {false};
    que.push(start);
    check[start]=true;
    while (!que.empty()){
        cout << que.front() << " ";
        for (int i=0; i<n; i++){
            if (a[que.front()][i] && !check[i]){
                que.push(i);
                check[i]=true;
            }
        } que.pop();
    } delete []check;
}
void rehearseDFS(int*matrix[], int i, bool check[], int n){
    check[i]=true;
    cout << i << " ";
    for (int j=0; j<n; j++){
        if (matrix[i][j]!=0 && !check[j]) rehearse(matrix, j, check, n);
    }
}
void DFS(int**matrix, int n, int start){
    bool*check=new bool[n]{false};
    check[start]=true;
    for (int i=0; i<n; i++) if (matrix[start][i]) rehearseDFS(matrix, i, check, n);
    delete []check;
}


int main(){
    int n=10;
    int**matrix=new int*[n] {0};
    for (int i=0; i<n; i++) matrix[i]=new int[n] {0};
    ifstream ifs;
    ifs.open("text.txt");
    while (!ifs.eof()){
        int a, b, c;
        ifs>>a>>b>>c;
        matrix[a-1][b-1]=c;
        matrix[b-1][a-1]=c;
    } ifs.close();

    Dijkstra(matrix, n, 2, 7);
    
    for (int i=0; i<n; i++) delete []matrix[i];
    delete []matrix;

    return 0;
}