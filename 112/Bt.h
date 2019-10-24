#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
} TreeNode;
class Bt {
public:
	Bt(vector<string>& vec): root(NULL){
		root = Btinsert(1, vec);
	}
	TreeNode* getTree() {
		return root;
	}
	void printTree(TreeNode *p) {//lvr
		if (p) {
			printTree(p->left);
			cout << p->val << " ";
			printTree(p->right);
		}
		return;
	}
private:
	TreeNode* Btinsert(int idx, vector<string>& vec) {
		if (idx >= vec.size())
			return NULL;
		if (vec[idx].compare("-")==0)
			return NULL;
		TreeNode *newnode = new TreeNode(stoi(vec[idx]));
		newnode -> left = Btinsert(2*idx, vec);
		newnode -> right = Btinsert(2*idx+1, vec);
		return newnode;
	}
	TreeNode *root;
			
};
