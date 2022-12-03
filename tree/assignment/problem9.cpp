#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node* leftChild;
    Node* rightChild;
    Node(int value)
    {
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};
bool is_unival(Node* root)
{
    if(root == NULL){
        return true;
    }
    if (root->leftChild != NULL && root->data != root->leftChild->data){
        return false;
        }
    if (root->rightChild != NULL && root->data != root->rightChild->data){
        return false;
    }
    return is_unival(root->leftChild) && is_unival(root->rightChild);
}
int main()
{
    Node* root = new Node(1);
    Node* a = new Node(1);
    Node* b = new Node(1);
    Node* c = new Node(1);
    Node* d = new Node(1);
    Node* e = new Node(1);
    root->leftChild = a;
    root->rightChild = b;
    a->leftChild = c;
    a->rightChild = d;
    b->rightChild = e;
    if(is_unival(root)==true){
        cout<<"unival"<<endl;
    }
    else{
        cout<<"not unival"<<endl;
    }
    return 0;
}

