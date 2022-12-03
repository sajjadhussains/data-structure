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

void average_level(Node* root)
{
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    float sum = 0;
    stack<float> s;
    s.push(root->data);
    cout<<"Output: " ;
    while(!q.empty()){
        Node* chkNode = q.front();
        q.pop();
        if(chkNode != NULL)
        {
                //cout<<chkNode->data<<" ";
                if(chkNode->leftChild != NULL)
                    {
                        q.push(chkNode->leftChild);
                        sum += chkNode->leftChild->data;
                    }
                if(chkNode->rightChild != NULL)
                    {
                        q.push(chkNode->rightChild);
                        sum += chkNode->rightChild->data;
                    }
        }
        else{
            if(!q.empty()){
                q.push(NULL);
                float result = sum/2;
                s.push(result);
                sum = 0;
            }
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
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
    Node*  e = new Node(5);
    Node* f = new Node(6);
    root->leftChild = a;
    a->leftChild = e;
    a->rightChild = f;
    root->rightChild = b;
    b->leftChild = c;
    b->rightChild = d;
    average_level(root);

    return 0;
}
