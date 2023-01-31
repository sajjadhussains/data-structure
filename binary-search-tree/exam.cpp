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
treeNode* insertionBST(treeNode* root,int value)
{
    //root empty
    treeNode *newNode = new treeNode(value);
    if(root == NULL)
    {
        root = newNode;
    }
    //value<root->data
    else if(value<root->data)
    {
        root->leftChild = insertionBST(root->leftChild,value);
    }
    //value>root->data
    else if(value > root->data)
    {
        root->rightChild = insertionBST(root->rightChild,value);
    }
    return root;
}
void inOrder(treeNode* root,string &chk)
{
    if(root==NULL) return;
    inOrder(root->leftChild,chk);
    chk+=(to_string(root->data)+" ");
    inOrder(root->rightChild,chk);
}

treeNode* inordersucc(treeNode* root){
    treeNode *cur = root;
    while(cur->leftChild != NULL){
        cur = cur->leftChild;
    }
    return cur;
}
treeNode* deletionBST(treeNode* root,int value)
{
    if(value<root->data){
        root->leftChild = deletionBST(root->leftChild,value);
    }
    else if(value>root->data){
        root->rightChild = deletionBST(root->rightChild,value);
    }
    else{
        if(root->leftChild == NULL){
            treeNode *tmp = root->rightChild;
            free(root);
            return tmp;
        }
        else if(root->rightChild == NULL){
            treeNode *tmp = root->leftChild;
            free(root);
            return tmp;
        }
        else{
            treeNode *temp = inordersucc(root->rightChild);
            root->data = temp->data;
            root->rightChild = deletionBST(root->rightChild,temp->data);
        }
    }

    return root;
}

int main()
{
    int n;
    cin>>n;
    treeNode *root = NULL;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        root = insertionBST(root,value);
    }
    deletionBST(root,12);
    root = insertionBST(root,11);
    deletionBST(root,6);
    string traversal = "";
    inOrder(root,traversal);
    cout<<traversal<<endl;

    return 0;
}
/*
13
7 5 12 3 6 9 15 1 4 8 10 13 17

*/


