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

int levelOrderTraversal(treeNode* root,string &chk,int k){
    if(root == NULL){
        return -1;
    }
    int level = 0;
    queue<treeNode*>q;
    q.push(root);
    q.push(NULL);
    int max = -9999;
    while(!q.empty()){
        treeNode* chkNode = q.front();
        q.pop();
        if(chkNode!=NULL){
                if(level == k){
                    if(max<chkNode->data){
                        max = chkNode->data;
                    }
                }
            cout<<chkNode->data<<" ";
            chk+=to_string(chkNode->data);
            if(chkNode->leftChild != NULL){
                q.push(chkNode->leftChild);
            }
            if(chkNode->rightChild != NULL){
                q.push(chkNode->rightChild);
            }
        }
        else{
            if(!q.empty()){
                q.push(NULL);
                level++;
            }
        }
    }
    return max;
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

int searchInorder(int inorderArray[],int current,int start,int end){
    for(int i=start;i<=end;i++){
        if(inorderArray[i]==current){
            return i;
        }
    }
    return -1;
}
treeNode* buildTreePreIn(int preorderArray[],int inorderArray[],int start,int end){
    static int id = 0;
    int current = preorderArray[id];
    id++;
    treeNode* newNode = new treeNode(current);
    if(start == end){
        return newNode;
    }
    int pos = searchInorder(inorderArray,current,start,end);
    newNode->leftChild = buildTreePreIn(preorderArray,inorderArray,start,pos-1);
    newNode->rightChild = buildTreePreIn(preorderArray,inorderArray,pos+1,end);
    return newNode;
}

int main()
{
    int n;
    cin>>n;
    int preOrderArray[n],inOrderArray[n];
    for(int i=0;i<n;i++){
        cin>>preOrderArray[i];
    }
    for(int i=0;i<n;i++){
        cin>>inOrderArray[i];
    }
    treeNode* root = buildTreePreIn(preOrderArray,inOrderArray,0,n-1);
    string chk = "";
    inOrder(root,chk);
    cout<<"InOrder: "<<chk<<endl;
    return 0;
}
/*
9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6

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

