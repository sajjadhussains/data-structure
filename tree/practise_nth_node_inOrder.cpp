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
        leftChild = NULL;
        rightChild = NULL;
    }
};

void inOrder(treeNode* root,string &chk){
    if(root==NULL) return;
    inOrder(root->leftChild,chk);
    chk+=to_string(root->data);
    inOrder(root->rightChild,chk);
}

int main()
{
    int n,k;
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
        if(left!=-1){
            allNodes[i]->leftChild = allNodes[left];
        }
        if(right!=-1){
            allNodes[i]->rightChild = allNodes[right];
        }
    }

    string inOrderString = "";
    inOrder(allNodes[0],inOrderString);
    cout<<"In Order traversal: "<<inOrderString<<endl;


   return 0;
}
/*
5
1 2 3
2 4 5
3 -1 -1
4 -1 -1
5 -1 -1

*/
