#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
struct node{
    int data;
    node*left;
    node*right;
};

bool insertion(node*&root, int x);
node* searching(node*root, int x);
int height(node*root);
void display(node*root);
void leaf(node*root);
void levelK(node*root, int k);
void PathRootToX(node*root, int x);
int ComonAncestor(node*root, int x, int y);
void deleteTree(node*&root);
void PathRootToX_RightToLeft(node*root, int x);

node* ConvertArrayToBST(int*a, int start, int end){
    if (start > end) return nullptr;
    int mid = (start + end)/2;
    node *root = new node;
    root->data=a[mid];
    root->left = ConvertArrayToBST(a, start,mid - 1);
    root->right = ConvertArrayToBST(a, mid + 1, end);
    return root;
}

bool insertion(node*&root, int x){
    if (!root) {
        root=new node;
        root->data=x;
        root->left=NULL;
        root->right=NULL;
        return true;
    } else {
        if (root->data==x) return false;
        if (x>root->data) insertion(root->right, x);
        else insertion(root->left, x);
    }
}

node* searching(node*root, int x){
    if (!root) return nullptr;
    if (root->data==x) return root;
    else if (x>root->data) return searching(root->right, x);
    else return searching(root->left, x);
}

int height(node*root){
    if (!root) return 0;
    else return 1 + max(height(root->left), height(root->right));
}

void display(node*root){
    if (!root) return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

void leaf(node*root){
    if (!root) return;
    leaf (root->left);
    if (!root->left && !root->right) cout << root->data << " ";
    leaf (root->right);
}

void levelK(node*root, int k){
    //print out all the node in level of k
    if (!root || height(root)<k || k<=0) return;
    if (k==1){
        cout << root->data << " ";
        return;
    }
    levelK(root->left, k-1);
    levelK(root->right, k-1);
}


void PathRootToX(node*root, int x) {
    //print our all the node path from root to random x
    cout << root->data;
    if (x<root->data) PathRootToX(root->left, x);
    if (x>root->data) PathRootToX(root->right, x);
}

int ComonAncestor(node*root, int x, int y) {
    //find out the closest node that share same parent with x and y
    int i, pathX[100], pathY[100];

    PathRootToX_Array(root, x, 0, pathX);
    PathRootToX_Array(root, y, 0, pathY);

    for (int i=0; i<100; i++){
        if (pathX[i]==pathY[i]){
            return pathX[i-1];
        }

        if (!pathX[i] || !pathY[i]) return NULL;
    }
}

void PathRootToX_Array(node*root, int x, int i, int path[]) {
    //print our all the node path from root to random x
    path[i]=root->data;
    i++;
    if (x<root->data) PathRootToX_Array(root->left, x, i, path);
    if (x>root->data) PathRootToX_Array(root->right, x, i, path);
}

node* CommonAncestor_2(node*root, int x, int y){
    if (x>root->data && y>root->data) return CommonAncestor_2(root->right, x, y);
    if (x<root->data && y<root->data) return CommonAncestor_2(root->left, x, y);
    return root;
}

void checkXbefore(node*root, int x, int y){
    if (searching(root, x)) PathRootToX(root, x);
    if (searching(root, x) && searching(root, y)) {
        ComonAncestor(root, x, y);
        CommonAncestor_2(root, x, y);
    }
}

node* removeX(node*root, int x) {
    //if x is leaf => just remove it
    //if x has 1 child => link over
    //if x has 2 children => find y which is smallest of right (or the biggest of left) subtree to swap, connect the link before delete x
    if (!root) return NULL;
    if (x<root->data) removeX(root->left, x);
    else removeX(root->right, x);

    if (!root->left && !root->right) {
        delete root;
        root=nullptr;
        return root;
    }

    if (!root->left && root->right){
        node* temp=root->right;
        delete root;
        root=temp;
        return root;
    } 
    if (root->left && !root->right) {
        node* temp=root->left;
        delete root;
        root=temp;
        return root;
    }

    if (root->left && root->right){
        node*link=root->right;
        while (link->left) link=link->left;
        root->data=link->data;
        root->right = removeX(root->right, link->data);
    }
}

bool SameValTree(node* root){
    if (!root) return;
    else if (root->left && root->left->data!=root->data) return false;
    else if (root->right && root->right->data!=root->data) return false;
    return SameValTree(root->left) && SameValTree(root->right);
}

void LevelTravel(node*root){
    queue<node*> que;
    node*cur=root;
    que.push(root);
    while (!que.empty()){
        cout << cur->data << " ";
        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
        que.pop();
        cur=que.front();
    }
}

void TopView(node*root){
    queue<pair<int, node*>> que;
    map<int, node*> m;
    que.push(make_pair(0, root));
    for (auto i=que.front(); !que.empty();){
        if (!i.second) continue;
        else {
            m.insert(i);
            que.push(make_pair(i.first+1, root->right));
            que.push(make_pair(i.first-1, root->left));
            que.pop();
            i=que.front();
        }
    }
    for (auto i: m){
        cout << i.second->data << " ";
    }
}

void deleteTree(node*&root) { 
    if (root == NULL) return; 
    deleteTree(root->left); 
    deleteTree(root->right); 
    delete root;
}


int main(){
    node*root=nullptr;
    int x, y;
    return 0;
}
