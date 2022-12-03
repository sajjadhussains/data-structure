#include <bits/stdc++.h>
using namespace std;

class treeNode{
    public:
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};
bool isSame(treeNode* root1, treeNode* root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
		if(root1 != NULL &&  root2!= NULL)
        {
            if(root1->data == root2->data && isSame(root1->left,root2->left) && isSame(root1->right,root2->right)){
                return true;
            }
        }
        return false;
}
int main()
{
	treeNode* root1 = new treeNode(1);
	treeNode* root2 = new treeNode(1);
	treeNode* a = new treeNode(2);
	treeNode* b = new treeNode(3);
	treeNode* c = new treeNode(2);
	treeNode* d = new treeNode(3);
    root1->left = a;
    root1->right = b;
    root2->left = c;
    root2->right = d;

	if (isSame(root1, root2) == true){
        cout << " trees are considered the same ";
	}
	else{
		cout << " trees are not considered the same ";
	}
	return 0;
}

