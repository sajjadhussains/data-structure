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

treeNode* searchBST(treeNode* root,int value)
{
    if(root == NULL) return NULL;
    if(root->data == value){
            cout<<root->data;
            return root;
    }
    else if(value>root->data) {
        cout<<root->data<<"->";
        searchBST(root->rightChild,value);
    }
    else {
        cout<<root->data<<"->";
        searchBST(root->leftChild,value);
    }
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
//    string traversal = "";
//    inOrder(root,traversal);
//    cout<<traversal<<endl;
    int key;
    cin>>key;
//    if(searchBST(root,key))     cout<<endl<<"value exists in the BST"<<endl;
//    else cout<<"value doesn't exist in the BST"<<endl;
    root = deletionBST(root,key);
    string after = "";
    inOrder(root,after);
    cout<<after<<endl;
    return 0;
}
/*
9
11 5 9 43 34 1 2 7 21

*/

