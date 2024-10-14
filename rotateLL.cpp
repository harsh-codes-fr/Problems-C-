// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int a) {
            num = a;
            next = NULL;
    }
};

// brute-force
// node* rotateLL(node* head,int k){
//     if(head->next==NULL || head == NULL){
//         return head;
//     }
    
//     int cnt = 0;
//     node*temp = head;
//     while(temp!=NULL){
//         cnt++;
//         temp = temp->next;
//     }
    
//     if(k==cnt){
//         return head;
//     }
    
//     while(k%cnt){
//         temp = head;
//         while(temp->next->next!=NULL){
//             temp = temp->next;
//         }
        
//         node*nextnode = temp->next;
//         temp->next = NULL;
//         nextnode->next = head;
        
//         head = nextnode;
//         k--;
//     }
    
//     return head;
// }

//optimize
node* rotateLL(node* head,int k){
    if(head->next==NULL || head == NULL || k==0){
        return head;
    }
    
    int cnt = 0;
    node*temp = head;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }

    k = k % cnt;
    
    if(k==0){
        return head;
    }

    temp = head;

    for(int i=1;i<cnt-k;i++){
      temp = temp->next;
    }
    
        node*newhead = temp->next;
        temp->next = NULL;
        temp = newhead;

        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = head;
        
    return newhead;
}



void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    } 
    cout<<head->num<<endl;
    return;
}

int main() {
    // Write C++ code here
      node* head = NULL;
    //inserting Node
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    
    cout<<"Original list: ";
    printList(head);
    cout << "Try programiz.pro"<<endl;
    node*newhead = rotateLL(head,7);
    printList(newhead);
    return 0;
}