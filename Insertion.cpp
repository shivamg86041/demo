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

Node* insertatHead(Node* head, int el){
    /*if(head == NULL){
        Node* temp = new Node(el);
        head = temp;
        head -> next = NULL;
        return head;
    }

    Node* temp = new Node(el);
    temp -> next = head;
    head = temp;
    return head;*/
    Node* temp = new Node(el, head);
    return temp;
}

Node* insertatTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }

    Node* temp2 = new Node(val, NULL);
    temp -> next = temp2;
    return head;
}

Node* insertatK(Node* head, int k, int el){
    if(k == 1){
        return new Node(el, head);
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            Node* newNode = new Node(el);
            prev -> next = newNode;
            newNode -> next = temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,5};
    Node* head = convert2LL(arr);
    // head = insertatTail(head, 89);
    // traverseLL(head);

    head = insertatK(head, 4, 56);
    traverseLL(head);
    return 0;
}