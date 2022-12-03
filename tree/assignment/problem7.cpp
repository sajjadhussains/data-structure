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
        data = value;
        left = NULL;
        right = NULL;
    }
};

int helper(Node *root, int *tiltsum)
{
        if(root==NULL)
        {
            return 0;
        }
        if(root->left==NULL and root->right==NULL)
        {
            return root->data;
        }
        int left=helper(root->left,tiltsum);
        int right=helper(root->right,tiltsum);
        *tiltsum+=abs(left-right);
        return left+right+root->data;

}





int findTilt(Node *root)
    {
        int tiltsum=0;
        helper(root,&tiltsum);
        return tiltsum;
    }
int main()
{
    Node* root = new Node(4);
    Node* a = new Node(2);
    Node* b = new Node(3);
    Node* c = new Node(5);
    Node* d = new Node(9);
    Node* e = new Node(7);
    root->left = a;
    root->right = d;
    a->left = b;
    a->right = c;
    d->right = e;
    int result = findTilt(root);
    cout<<"Output: " <<result<<endl;
    return 0;
}
