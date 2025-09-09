
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

int sum(Node* head){
    cout<<"Sum of Linked List : ";
    int ans = 0;
    while(head){
        ans += head->val;
        head = head->next;
    }
    return ans;
}

int main(){
    Node* head = new Node(410);
    Node* curr = head;

    for(int i=2; i<=7; i++){
        int val = 400 + (i * 10);
        Node* temp = new Node(val);
        curr->next = temp;
        curr = curr->next;
    }

    print(head);
    cout<<sum(head)<<endl;
    return 0;
}


