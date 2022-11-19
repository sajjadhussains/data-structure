#include<bits/stdc++.h>

using namespace std;

class treeNode{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;
    treeNode(int val)
    {
        data = val;
        leftChild =NULL;
        rightChild = NULL;
    }
};
void printTree(treeNode* root,int level);
void spacePrint(int level);

void inOrder(treeNode* root,string &chk)
{
    if(root==NULL) return;
    inOrder(root->leftChild,chk);
    chk+=to_string(root->data);
    inOrder(root->rightChild,chk);
}
void preOrder(treeNode* root,string &chk)
{
    if(root==NULL) return;
    chk+=to_string(root->data);
    preOrder(root->leftChild,chk);
    preOrder(root->rightChild,chk);
}
void postOrder(treeNode* root,string &chk)
{
    if(root==NULL) return;
    postOrder(root->leftChild,chk);
    postOrder(root->rightChild,chk);
    chk+=to_string(root->data);
}
void printTree(treeNode* root,int level){
    if(root == NULL)
    {
        return;
    }
    if(root->leftChild == NULL && root->rightChild == NULL){
        cout<<root->data<<endl;
    }
    else{
        cout<<endl;
        spacePrint(level);
        cout<<"Root: "<<root->data<<endl;
    }
    if(root->leftChild != NULL)
    {
        spacePrint(level);
        cout<<"Left:";
        printTree(root->leftChild,level+1);
    }
    if(root->rightChild != NULL)
    {
        spacePrint(level);
        cout<<"Right:";
        printTree(root->rightChild,level+1);
    }

}
void spacePrint(int level)
{
    for(int i=0;i<level;i++)
    {
        cout<<"   ";
    }
}

int main()
{
    int n;
    cin>>n;
    treeNode* allNodes[n];

    for(int i=0;i<n;i++)
    {
        allNodes[i] = new treeNode(-1);
    }
    for(int i=0;i<n;i++)
    {
        int value,left,right;
        cin>>value>>left>>right;
        allNodes[i]->data = value;
        if(left>n-1 || right>n-1){
            cout<<"Invalid Index";
            break;
        }
        if(left != -1){
            allNodes[i]->leftChild=allNodes[left];
        }
        if(right != -1){
            allNodes[i]->rightChild = allNodes[right];
        }
    }
    printTree(allNodes[0],0);
    string inOrderString="";
    string preOrderString="";
    string postOrderString = "";
    inOrder(allNodes[0],inOrderString);
    preOrder(allNodes[0],preOrderString);
    postOrder(allNodes[0],postOrderString);
    cout<<"In order traversal: "<<inOrderString<<endl;
    cout<<"Pre order traversal: "<<preOrderString<<endl;
    cout<<"Post order traversal: "<<postOrderString<<endl;
    return 0;
}
/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

Root 0:
left:
    Root:1
    left:3
    right:4
right:
    Root:2
    left:
        Root:5
        left:7
        right:8
    right:6



*/
