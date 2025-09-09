
#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        next = NULL;
    }
};

void print(Node* head){
    cout<<"Linked List : ";
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void rearrange(Node* head){
    if(!head || !head->next) return;
    Node* p = head;
    Node* q = head->next;

    while(q){
        swap(p->val, q->val);

        p = q->next;
        q = (p) ? p->next : NULL;
    }
}

int main(){
    Node* head = new Node(22);
    Node* curr = head;

    for(int i=3; i<=8; i++){
        int val = i * 11;
        Node* temp = new Node(val);
        curr->next = temp;
        curr = curr->next;
    }

    print(head);
    rearrange(head);
    print(head);
    return 0;
}


