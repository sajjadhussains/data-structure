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
vector<int> arr;

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
                arr.push_back(chkNode->data);
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
}
int second_minimum(Node* root)
{
    levelOrderTraversal(root);
    sort(arr.begin(),arr.end());

    for (int i = 0; i < arr.size() - 1; i++)
        if (arr[i] != arr[i + 1]){
            return arr[i + 1];
        }
    return -1;
}
int main()
{
    Node* root = new Node(2);
    Node* a = new Node(2);
    Node* b = new Node(5);
    Node* c = new Node(5);
    Node* d = new Node(7);
    root->leftChild = a;
    root->rightChild = b;
    b->leftChild = c;
    b->rightChild = d;
    int result = second_minimum(root);
    cout<<"Output: "<<result<<endl;

    return 0;
}

