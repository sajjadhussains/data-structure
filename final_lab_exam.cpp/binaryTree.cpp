#include<bits/stdc++.h>

using namespace std;

class treeNode{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;
    treeNode(int val)
    {
        this->data = val;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};
void printTree(treeNode* root)
{
    if(root==NULL) return;
    printTree(root->leftChild);
    cout<<root->data<<endl;
    printTree(root->rightChild);
}
int main()
{
    int a;
    cin>>a;
    treeNode* root=new treeNode(a);
    queue<treeNode *>Q;
    Q.push(root);
    while(!Q.empty()){
        treeNode* presentNode = Q.front();
        Q.pop();
        int x,y;
        cin>>x>>y;
        treeNode* n1=NULL;
        treeNode* n2 = NULL;
        if(x!=-1) n1= new treeNode(x);
        if(y!=-1) n2 = new treeNode(y);
        presentNode->leftChild = n1;
        presentNode->rightChild = n2;
        if(n1!=NULL) Q.push(n1);
        if(n2!=NULL) Q.push(n2);
    }
    printTree(root);
    return 0;
}
