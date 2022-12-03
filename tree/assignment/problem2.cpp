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
                if(chkNode->leftChild != NULL)
                    {
                        q.push(chkNode->leftChild);
                    }
                if(chkNode->rightChild != NULL)
                    {
                        q.push(chkNode->rightChild);
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
    Node* root = new Node(3);
    Node* a = new Node(9);
    Node* b = new Node(20);
    Node* c = new Node(15);
    Node* d = new Node(7);
    root->leftChild = a;
    root->rightChild = b;
    b->leftChild = c;
    b->rightChild = d;
    levelOrderTraversal(root);

    return 0;
}
