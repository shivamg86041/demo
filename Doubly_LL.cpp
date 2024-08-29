#include <iostream>
#include<vector>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;

    public:
    Node(int data,Node* prev, Node* next){
        this -> data = data;
        this->next = next;
        this -> prev = prev;
    }

    public:
    Node(int data){
        this -> data = data;
        next = nullptr;
        prev = nullptr;
    }
};

void traverseLL(Node *head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}

int main()
{
    vector<int> arr = {1,2,3,5};
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;
    for(int i = 1;i<arr.size();i++){
        Node* newNode = new Node(arr[i], prev, nullptr);
        prev-> next = newNode;
        prev = newNode; 
    }
    traverseLL(head);
    
    return 0;
}