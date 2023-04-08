#include <iostream>
using namespace std;
struct bucket{
    int data;
    bucket*next=nullptr;
};

int key(int x, int div){return x%div;}

void probing(int slots[], int x, int div , int numslots){
    if (!slots[key(x, div)]) slots[key(x, div)]=x;
    else {
        int n=key(x, div);
        while (slots[n]){
            n++;
            if (n==numslots) n=0;
        } slots[n]=x;
    }
}

void chainning(bucket*bk[], int x, int div){
    if (!bk[key(x, div)]) bk[key(x, div)]->data=x;
    else {
        bucket*temp=new bucket;
        temp->data=x;
        temp->next=bk[key(x, div)];
        bk[key(x, div)]=temp;
    }
}

bool search_prob(int slots[], int x, int div, int numslots){
    if (slots[key(x, div)]==x) return true;
    else {
        int n=key(x, div);
        while (slots[n]){
            n++;
            if (n==numslots) n=0;
            if (slots[n]==x) return true;
        } return false;
    }
}

bool search_chain(bucket*bk[], int x, int div){
    if (bk[key(x, div)]->data==x) return true;
    else {
        bucket*cur=bk[key(x, div)];
        while (cur->next){
            if (cur->next->data==x) return true;
            else cur=cur->next;
        } return false;
    }
}

bool remove_prob(int slots[], int x, int div, int numslots){
    if (!search_prob(slots, x, div, numslots)) return false;
    if (slots[key(x, div)]==x) {slots[key(x, div)]=0; return true;}
    else {
        int n=key(x, div);
        while (slots[n]!=x){
            n++;
        } slots[n]=0;
        return true;
    }
}

bool remove_chain(bucket*bk[], int x, int div){
    if (!search_chain(bk, x, div)) return false;
    if (bk[key(x, div)]->data==x) {
        bucket*target=bk[key(x, div)];
        bk[key(x, div)]=bk[key(x, div)]->next;
        delete target;
        return true;
    }
    else {
        bucket*cur=bk[key(x, div)];
        while (cur->next && cur->next->data!=x){
            cur=cur->next;
        } bucket*target=cur->next;
        cur->next=cur->next->next;
        delete target;
        return true;
    }
}

int main(){
    int div;
    int numslots;
    int*slots=new int[numslots];
    bucket**bk=new bucket*[numslots];
    return 0;
}