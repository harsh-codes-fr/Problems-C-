// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* next;
        node* child;  

        node() : data(0), next(nullptr), child(nullptr) {};
        node(int x) : data(x), next(nullptr), child(nullptr) {}
        node(int x, node *nextNode, node *childNode) :
                    data(x), next(nextNode), child(childNode) {}
};


void printList(node* head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->child;
    } 
    cout<<endl;
}

node* convertarrtolinkedlist(vector<int>&arr){
    node* dummy = new node(-1);
    node* temp = dummy;

    for(int i = 0;i<arr.size();i++){
       temp->child = new node(arr[i]);
       temp = temp->child;
    }

    return dummy->child;
}

node* flattenlinkedlist(node*head){

    vector<int> arr;

    while(head!=NULL){
        node*t2 = head;
        while(t2!=nullptr){
            arr.push_back(t2->data);
            t2 = t2->child;
        }

        head = head -> next;
    }

    sort(arr.begin(),arr.end());

    return convertarrtolinkedlist(arr);
}

void printoriginalLinkedlist(node*head,int depth){
    while(head!=NULL){
        cout<<head->data;

        if(head->child){
            cout<<"->";
            printoriginalLinkedlist(head->child,depth+1);
        }
         
        if(head->next){
            cout<<endl;
            for(int i=0;i<depth;++i){
                cout<<"|";
            }
        }

        head = head->next;
    }
}

int main() {
    node*head = new node(5);
    head->child =  new node(3);

    head->next = new node(12);
    head->next->child = new node(7);

    head->next->next = new node(14);
    head->next->next->child = new node(10);

    head->next->next->next = new node(20);
    head->next->next->next->child = new node(15);
    head->next->next->next->child->child = new node(16);

    cout<<"original linked list with child";
    printoriginalLinkedlist(head,0);
    cout<<endl;
    
    node*flatten = flattenlinkedlist(head);
    printList(flatten);
    
    return 0;
}