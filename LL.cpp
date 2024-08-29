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

int main()
{
    vector<int> arr = {1,2,3,5};
    Node* x = new Node(arr[0]);
    cout<<x->data;
    return 0;
}