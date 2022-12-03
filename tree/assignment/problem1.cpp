#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};
bool isSame(Node* root1, Node* root2)
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
	Node* root1 = new Node(1);
	Node* root2 = new Node(1);
	Node* a = new Node(2);
	Node* b = new Node(3);
	Node* c = new Node(2);
	Node* d = new Node(3);
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

