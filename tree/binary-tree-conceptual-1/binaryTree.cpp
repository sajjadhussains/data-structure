#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};
void print(Node* root)
{
    if(root == NULL) return;
    print(root->left);
    cout<<root->data<<endl;
    print(root->right);
}
int main()
{
    Node *root = new Node(1);
    Node *a = new Node(2);
    Node *b = new Node(3);
    Node *c = new Node(4);
    Node *d = new Node(5);
    Node *e = new Node(6);
    Node *f = new Node(7);
    Node *g = new Node(8);
    root->left = a;
    root->right = b;

    a->left = c;
    c->right = g;

    b->left = d;
    b->right = e;
    e->right = f;
    print(root);
    return 0;
}
