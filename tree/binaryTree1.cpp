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

void printLeaves(treeNode* root)
{
    if(root == NULL) return;
    if(root->leftChild == NULL  &&  root->rightChild == NULL){
        cout<<root->data<<" ";
        return;
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}
void printLeftNonLeaves(treeNode* root)
{
    if(root == NULL) return;
    if(root->leftChild != NULL){
        cout<<root->data<<" ";
        printLeftNonLeaves(root->leftChild);
    }
    else if(root->rightChild != NULL){
        cout<<root->data<<" ";
        printLeftNonLeaves(root->rightChild);
    }
}
void printRightNonLeaves(treeNode* root)
{
    if(root == NULL) return;
    if(root->leftChild != NULL){
        cout<<root->data<<" ";
        printLeftNonLeaves(root->rightChild);
    }
    else if(root->rightChild != NULL){
        cout<<root->data<<" ";
        printLeftNonLeaves(root->leftChild);
    }
}
void boundaryTraversal(treeNode* root)
{
    if(root == NULL) return;
    cout<<root->data<<" ";
    //LB non leaves
    printLeftNonLeaves(root->leftChild);
    //LB leaves
    printLeaves(root->leftChild);
    //RB leaves
    printLeaves(root->rightChild);
    //RB non leaves
    printRightNonLeaves(root->rightChild);
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
//    string inOrderString="";
//    string preOrderString="";
//    string postOrderString = "";
//string levelorderTraversal = "";
//    inOrder(allNodes[0],inOrderString);
//    preOrder(allNodes[0],preOrderString);
//    postOrder(allNodes[0],postOrderString);
    //    int maxValueAtk=levelOrderTraversal(allNodes[0],levelorderTraversal,2);
//    cout<<"In order traversal: "<<inOrderString<<endl;
//    cout<<"Pre order traversal: "<<preOrderString<<endl;
//    cout<<"Post order traversal: "<<postOrderString<<endl;
//cout<<endl<<"Max value at level 2: "<<maxValueAtk<<endl;
boundaryTraversal(allNodes[0]);
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
