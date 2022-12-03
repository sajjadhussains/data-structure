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
void level_order_reverse(Node* root)
{
    if(root == NULL) return;
    stack<Node*> s;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* chkData = q.front();
        q.pop();
        if(chkData!=NULL){
        s.push(chkData);
        if(chkData->rightChild != NULL)
        {
            q.push(chkData->rightChild);
        }
        if(chkData->leftChild != NULL)
        {
            q.push(chkData->leftChild);
        }
        }
        else{
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
    }
  while(!s.empty())
   {
       Node* data = s.top();
        cout<<data->data<<" ";
        s.pop();
    }
}
int main()
{
    Node* root = new Node(3);
    Node* a = new Node(9);
    Node* b = new Node(20);
    Node* c = new Node(15);
    Node* d = new Node(7);
    root->leftChild = a;
    root->rightChild = b;
    b->leftChild = c;
    b->rightChild = d;
    level_order_reverse(root);
}
