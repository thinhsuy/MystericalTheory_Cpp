#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* pNext;
    Node* pLast;
};

void insert(Node* &pHead){
    Node* pCur=nullptr;
    int t; 
    cout << "Insert data (0 to end list): ";
    cin>>t;

    while(t!=0){
        //tạo node đầu tiên cũng là pHead và pCur
        if (pHead==nullptr){
            pHead=new Node;
            pCur=pHead;
        } // trường hợp node 1 có giá trị thì tạo node 2 và đưa Cur theo
        else {
            pCur->pNext = new Node;
            pCur = pCur->pNext;
        }
        pCur->data = t;
        //đóng pNext ở node cuối
        pCur->pNext=nullptr;
        cout << "Insert data: ";
        cin>>t;
    }
}

void display(Node* pHead){
    cout << endl;
    cout << "This is the list: ";
    while (pHead!=nullptr){
        cout << pHead->data << " ";
        pHead=pHead->pNext;
    }
    cout << endl << endl;
}

void reduncy(Node* &pHead){
    Node* pCur=pHead;
    while (pHead!=nullptr){
        //pHead ko null thì pHead nhảy
        //xóa pCur tại chổ trc khi nhảy của pHead
        pHead=pHead->pNext;
        delete pCur;
        pCur=pHead;
    }
}

void addBegin(Node* &pHead, int &value){
    cout << "Value that need to be added: ";
    cin>>value;
    Node* pTemp=new Node;
    pTemp->data=value;
    pTemp->pNext=pHead; //đuôi pTemp sẽ gán cho đầu pHead
    pHead=pTemp; //pHead mới sẽ là pTemp
    display(pHead);
}

void addXBeforeK(Node*&pHead, int x){
    int k;
    cout << "Value of x that need to add: ";
    cin>>x;
    cout << "The value of k that is added before: ";
    cin>>k;

    if (pHead==nullptr){return;}  //list null
    if (pHead->data==k){addBegin(pHead, x);} //before first node
    else {
        Node* pCur = pHead;
        //pCur sẽ ngưng khi trc mặt nó là k
        while (pCur->pNext!=nullptr && pCur->pNext->data!=k){
            pCur=pCur->pNext;
        }
        if (pCur->pNext!=nullptr){
            Node* pTemp = new Node;
            pTemp->data = x;
            pTemp->pNext = pCur->pNext; //nối cuối pTemp vào đầu của Node chứa k
            pCur->pNext = pTemp; //nối cuối pCur vào đầu pTemp
        }
    }display(pHead);
}

void addXAfterK(Node*&pHead, int x){
    int k;
    cout << "Value of x that need to add: ";
    cin >> x;
    cout << "Value of k that need to be added after: ";
    cin>>k;

    Node*pCur=pHead;
    while (pCur!=nullptr && pCur->data!=k){
        pCur=pCur->pNext; //bước nhảy tìm k
    }
    if (pCur!=nullptr){ //pCur của data k
        Node* pTemp=new Node;
        pTemp->data=x;
        pTemp->pNext=pCur->pNext;
        pCur->pNext=pTemp;
    }display(pHead);
}

void remove_x(Node* &pHead, int x){
    cout << "Value of X that need to delete: ";
    cin>>x;
    if (pHead==nullptr){return;}
    Node* pCur = pHead;
    //trường hợp x ở node đầu tiên
    if (pHead->data==x){
        pHead=pHead->pNext;
        delete pCur;
        return;
    }
    else {
        while (pCur->pNext!=nullptr){
            if (pCur->pNext->data==x){
                Node* pTemp = pCur->pNext; //temp đang ở vị trí cần xóa
                pCur->pNext=pCur->pNext->pNext;
                delete pTemp;
                return;
            }
            pCur=pCur->pNext;
        }
    }
    display(pHead);
}

void removeAll_x(Node*&pHead, int x){
    cout << "Value of x that need to delete all: ";
    cin>>x;
    Node* pCur=pHead;
    while (pCur!=nullptr && pCur->pNext!=nullptr){
        if (pCur->pNext->data==x){
            //link sẽ giữ đầu dây của node sau x
            Node* pLink = pCur->pNext->pNext;
            delete pCur->pNext;
            //nối lại node trc x và sau x
            pCur->pNext=pLink;
        }
        else {pCur=pCur->pNext;}
    }

    //xóa x ở vị trí đầu (nếu có)
    if(pHead!=nullptr && pHead->data==x){
        //xóa link thay cho head, link giữ vị trí cho head nhảy
        Node* pLink=pHead;
        pHead=pHead->pNext;
        delete pLink;
    }display(pHead);
}

void insert_x_in_orderlist(Node* pHead, int x){
    Node* p=new Node;
    cin>>p->data;
    //xet Node dau tien
    if (pHead==nullptr || x<=pHead->data){
        p->pNext = pHead;
        pHead=p;
    }
    //xet cac Node sau 
    else {
        Node* pCur = pHead;
        while (pCur->pNext!=nullptr && pCur->pNext->data<x){
            pCur = pCur -> pNext;   
        } p->pNext=pCur->pNext;
        pCur->pNext=p;
    }display(pHead);
}

void merg_2_lists_in_order(Node* pHead){
    Node* pHead1=new Node;
    Node* pHead2=new Node;
    insert(pHead1);
    cout << endl;
    insert(pHead2);
    cout << endl;

    Node* pCur2= pHead2;
    while (pCur2->pNext!=nullptr){
        //xet Node dau tien
        if (pHead1==nullptr || pCur2->data<=pHead1->data){
            pCur2->pNext = pHead1;
            pHead1=pCur2;
        }
        //xet cac Node sau 
        else {
            Node* pCur1 = pHead1;
            while (pCur1->pNext!=nullptr && pCur1->pNext->data<pCur2->data){
                pCur1 = pCur1 -> pNext;   
            } pCur2->pNext=pCur1->pNext;
            pCur1->pNext=pCur2;
        }
        pCur2=pCur2->pNext;
    }
}

void split_a_list_into_2lists(Node* &pHead){
    Node* pOddHead=new Node;
    Node* pEvenHeda=new Node;
    
}

void insert2D(Node* &pHead){
    Node* pCur=nullptr;
    int t; 
    cout << "Insert data: ";
    cin>>t;

    while(t!=0){
        //tạo node đầu tiên cũng là pHead và pCur
        if (pHead==nullptr){
            pHead=new Node;
            pCur=pHead;
            pCur->pLast=nullptr;
        } // trường hợp node 1 có giá trị thì tạo node 2 và đưa Cur theo
        else {
            pCur->pNext = new Node;
            pCur->pNext->pLast=pCur; 
            pCur = pCur->pNext;
        }
        pCur->data = t;
        //đóng pNext ở node cuối
        pCur->pNext=nullptr;
        cout << "Insert data: ";
        cin>>t;
    }
}

void addXBeforeK_2D(Node*&pHead, int &x){
    Node*pCur = pHead; int k;
    cout << "Value of x that need to add: "; cin>>x;
    cout << "Value of k that need to add before: "; cin>>k;
    if (pHead->data==k){
        Node* pTemp=new Node;
        pTemp->data=x;
        pTemp->pNext=pHead;
        pHead->pLast=pTemp;
        pTemp->pLast=nullptr;
        pHead=pTemp;
    } else {
        while (pCur->pNext->data!=k){
            pCur=pCur->pNext;
        } if (pCur->pNext->data!=k) {
            cout << "List does not have " << k;
            return;
        } 
        Node*pTemp=new Node;
        pTemp->data=x;
        pTemp->pNext=pCur->pNext;
        pCur->pNext=pTemp;
        pTemp->pLast=pCur;
        pCur->pNext->pLast=pTemp;
    }
}

void DeathOfCircle(Node*&pHead){
    int k; cin >> k;
    int count=2;
    Node*pCur=pHead;
    while (pCur->pNext!=pCur){
        while (count<k){
            pCur=pCur->pNext;
            count++;
        } cout << pCur->pNext->data << " "; 
        Node*pLink=pCur->pNext;
        pCur->pNext=pCur->pNext->pNext;
        delete pLink;
        count=2;
        pCur=pCur->pNext;
    } cout<<pCur->data;
    delete pCur;
}

void main_menu(Node* pHead, int x, int value){
    int option, create=0;
    do{
        cout << "==============================" << endl;
        cout << "=  0. End task               =" << endl;
        cout << "=  1. Create a 1 side list   =" << endl;
        cout << "=  2. Create a 2 sides list  =" << endl;
        cout << "==============================" << endl;
        cout << "Your option: "; cin >> create;
        cout << endl;
        if (create==1){
            insert(pHead);
            display(pHead);
            cout << endl;
            do{
                cout << "==============================" << endl;
                cout << "=    0.End task              =" << endl;
                cout << "=    1.Add x in to begin     =" << endl;
                cout << "=    2.Add x before k        =" << endl;
                cout << "=    3.Add x after k         =" << endl;
                cout << "=    4.Remove single x       =" << endl;
                cout << "=    5.Remove family of x    =" << endl;
                cout << "=    6.Display List          =" << endl;
                cout << "==============================" << endl;
                cout << "Your Option: "; cin >> option;
                if (option==1){addBegin(pHead, value);}
                if (option==2){addXBeforeK(pHead, x);}
                if (option==3){addXAfterK(pHead, x);}
                if (option==4){remove_x(pHead, x);}
                if (option==5){removeAll_x(pHead, x);}
                if (option==6){display(pHead);}
            } while (option!=0);
        };
        if (create==2){
            insert2D(pHead);
            display(pHead);
            do{
                cout << "==============================" << endl;
                cout << "=    0.End task              =" << endl;
                cout << "=    1.Add x beore K         =" << endl;
                cout << "==============================" << endl;
                cout << "Your Option: "; cin >> option;
                if (option==1){addXBeforeK_2D(pHead, x);}
            } while (option!=0);
        } 
    } while (create!=0); 
    reduncy(pHead);
}

int main(){
    int value;
    int x;
    Node* pHead = nullptr;
    main_menu(pHead, x, value);
    return 0;
}