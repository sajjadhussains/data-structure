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
//the asking function from the question
Node* invert_tree(Node* root)
{
    if(root==NULL){
        return root;
    }
    if(root->left!= NULL && root->right != NULL)
    {
        Node* chkNode = root->left;
        root->left = root->right;
        root->right = chkNode;
        invert_tree(root->left);
        invert_tree(root->right);
    }
    return root;
}
//for checking inverted tree function is working or not,level order traversal is used
void levelOrderTraversal(Node* root)
{
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    cout<<"Output: " ;
    while(!q.empty()){
        Node* chkNode = q.front();
        q.pop();
        if(chkNode != NULL)
        {
                cout<<chkNode->data<<" ";
                if(chkNode->left != NULL)
                    {
                        q.push(chkNode->left);
                    }
                if(chkNode->right != NULL)
                    {
                        q.push(chkNode->right);
                    }
        }
        else{
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
    cout<<endl;
}

int main()
{
    Node* root = new Node(4);
    Node* a = new Node(2);
    Node* b = new Node(1);
    Node* c = new Node(3);
    Node* d = new Node(7);
    Node* e = new Node(6);
    Node* f = new Node(9);
    root->left = a;
    root->right = d;
    a->left = b;
    a->right = c;
    d->left = e;
    d->right = f;
    //before inverting the tree level order traversal
    levelOrderTraversal(root);
    Node* newRoot = invert_tree(root);
    //after inverting the tree,level order traversal
    levelOrderTraversal(newRoot);

}
