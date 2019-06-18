#ifndef BST
#define BST
#include <vector>
#include <iostream>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
} TreeNode;
class Bst {
public:
	Bst(vector<int>& vec): tree(NULL) {
		for (int i = 0; i < vec.size(); i++) 
			tree = InsertNode(tree, vec[i]);
	}
	TreeNode* InsertNode(TreeNode *root, int val) {
		if (root == NULL) {
			TreeNode *newNode = new TreeNode(val);
			return newNode;
		}
		else if (val <= root->val)
			root->left = InsertNode(root->left, val);
		else
			root->right = InsertNode(root->right, val);
		return root;	
	}
	TreeNode* searchNode(TreeNode* root, int tar) {
		if (root == NULL)
			return NULL;
		if (tar == root->val)
			return root;
		else if (tar < root->val)
			return searchNode(root->left, tar);
		else
			return searchNode(root->right, tar);

	}
	TreeNode* searchNode(int tar) {
		return searchNode(tree, tar);
	}
	void printTree(TreeNode *root) {
		if (root == NULL)
			return;
		printTree(root->left);
		cout << root->val << " ";
		printTree(root->right);
		return;
	}
	void printTree() {
		printTree(tree);
		cout << endl;
	}
	TreeNode* getTree() {return tree;}

private:
	TreeNode* tree;

};

#endif
