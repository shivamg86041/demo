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

Node* convert2DLL(vector<int>& arr){
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;
    for(int i = 1;i<arr.size();i++){
        Node* newNode = new Node(arr[i], prev, nullptr);
        prev-> next = newNode;
        prev = newNode; 
    }
    return head;
}

Node* insertatHead(Node* head, int val){
    if(head == NULL){
        Node* temp = new Node(val, NULL, NULL);
        return temp;
    }
    Node* temp = new Node(val, NULL, head);
    head -> prev = temp;
    return temp;
}

Node* insertbeforetail(Node* head, int val){
    if(head -> next == NULL){
        return new Node(val, NULL, head);
    }

    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* prev = temp -> prev;
    Node* newNode = new Node(val, prev, temp);
    prev -> next = newNode;
    temp -> prev = newNode;
    return head;
}

Node* insertbeforeKth(Node* head, int k, int val){
    if(k == 1){
        return insertatHead(head, val);
    }

    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp -> next;
    }
    Node* prev = temp -> prev;
    Node* newNode = new Node(val, prev, temp);
    prev -> next = newNode;
    temp -> prev = newNode;
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,5};
    Node* head = convert2DLL(arr);

    // head = insertatHead(head, 10);
    // traverseLL(head);

    // head = insertbeforetail(head, 10);
    // traverseLL(head);

    head = insertbeforeKth(head, 3, 10);
    traverseLL(head);
    return 0;
}