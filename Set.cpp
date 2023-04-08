#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    unordered_set<string> set = {"facebook", "gmail", "goole", "youtube", "sportify"};
    //insert
    set.insert("netflix");

    //display
    unordered_set<string>::iterator str;
    for (str=set.begin(); str!=set.end(); str++) cout << *str << " ";
    cout << endl;

    //count
    int count = set.count("facebook");

    //clear - erase
    set.clear();
    set.erase("netflix");

    //find
    if (set.find("gmail")!=set.end()) cout << "Found" << endl;
    else cout << "Not found" << endl;

    //bucket
    int Bcount = set.bucket_count();
    cout << set.bucket_size(3);


    return 0;
}