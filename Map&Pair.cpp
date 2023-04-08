#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <queue>
#include <iterator>
using namespace std;

int main(){
    pair <int, string> pa;
    map<int, string> map;
    queue<pair<int, string>> que;

    //insert
    int count = 0;
    pa = make_pair(count, "Hulk");
    map.insert(pa);
    que.push(pa);
    
    //display
    std::map<int, string>::iterator it;
    cout << pa.first << " " << pa.second << " ";
    for (auto it=map.begin(); it!=map.end(); it++){
        cout << it->first << " " << it->second << " ";
    }
    for (auto i=que.front(); !que.empty(); que.pop(),i=que.front()){
        cout << i.first << " " << i.second << " "; //printPair(i);
    }


    return 0;
}