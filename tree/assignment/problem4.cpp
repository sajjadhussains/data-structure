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
bool isMirror(Node* root1,Node* root2)
{
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 != NULL && root2 != NULL)
    {
        if( root1->data == root2->data
            && isMirror(root1->leftChild,root2->rightChild)
            && isMirror(root1->rightChild,root2->leftChild)){
        return true;
    }
    }
    return false;
}
bool isSymmetric(Node* root)
{
    if(isMirror(root,root)){
      return true;
    }
    else{
        return false;
    }
}
int main()
{
     Node* root = new Node(1);
     Node* a = new Node(2);
     Node* b = new Node(3);
     Node* c = new Node(4);
     Node* d = new Node(2);
     Node* e = new Node(4);
     Node* f = new Node(3);
    root->leftChild = a;
    root->rightChild = d;
    a->leftChild = b;
    a->rightChild = c;
    d->leftChild =e;
    d->rightChild = f;
    if(isSymmetric(root)){
        cout<<"Symetric"<<endl;
    }
    else{
        cout<<"Not Symetric"<<endl;
    }
}
