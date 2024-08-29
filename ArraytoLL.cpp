#include <iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data, Node* next){
        this -> data = data;
        this->next = next;
    }

    public:
    Node(int data){
        this -> data = data;
        next = nullptr;
    }
};

Node* convert2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

void traverseLL(Node *head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}

int lengthLL(Node *head){
    int size = 0;
    Node* temp = head;
    while(temp != nullptr){
        size++;
        temp = temp -> next;
    }
    return size;
}

bool search(Node* head, int key){
    Node* temp = head;
    while(temp != nullptr){
        if(temp -> data == key){
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

int main()
{
    vector<int> arr = {1,2,3,5};
    Node* head = convert2LL(arr);
    traverseLL(head);
    cout<<endl<<endl;
    cout<<"Size of Linked list is "<<lengthLL(head);
    cout<<endl<<endl;
    cout<<search(head, 45);
    return 0;
}