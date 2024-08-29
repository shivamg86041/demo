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

Node* removesHead(Node *head){
    if(head == NULL) return NULL;

    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

Node* removesTail(Node *head){
    if(head == NULL || head -> next == NULL) return NULL;

    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }

    free(temp -> next);
    temp -> next = NULL;
    return head;
}

Node* deleteK(Node* head, int k){
    if(head == NULL) return NULL;
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev -> next = prev -> next -> next;
            free(temp);
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
    // head = removesHead(head);
    // traverseLL(head);
    // head = removesTail(head);
    // traverseLL(head);

    head = deleteK(head, 2);
    traverseLL(head);

    return 0;
}