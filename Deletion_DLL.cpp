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

Node* removesHead(Node* head){
    if(head == NULL || head -> next == NULL) return NULL;

    Node* temp = head;
    head = head -> next;
    head -> prev = NULL;
    temp -> next = NULL;
    free(temp);
    return head;
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

Node* removesTail(Node* head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }

    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* back = temp -> prev;
    back -> next = NULL;
    temp -> prev = NULL;
    delete(temp);
    return head;
}

Node* deleteKnode(Node* head, int k){
    if(head == NULL) return NULL;

    if(k == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        head -> prev = NULL;
        delete(temp);
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp -> next;
    }

    if(temp -> next == NULL){
        Node* back = temp -> prev;
        back -> next = NULL;
        temp -> prev = NULL;
        temp -> next = NULL;
        delete(temp);
        return head;
    }

    Node* back = temp -> prev;
    back -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    temp -> next = NULL;
    temp -> prev = NULL;
    delete(temp);
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,5};
    Node* head = convert2DLL(arr);
    // traverseLL(head);
    // head = removesHead(head);
    // traverseLL(head);
    
    // head = removesTail(head);
    // traverseLL(head);

    head = deleteKnode(head, 4);
    traverseLL(head);
    return 0;
}