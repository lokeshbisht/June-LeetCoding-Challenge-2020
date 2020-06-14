#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print2DUtil(TreeNode *root, int space) {
    if (root == NULL) {
        return;
    }
    
    space += 10;  
    
    print2DUtil(root->right, space);  

    cout<<endl;
    
    for (int i = 10; i < space; i++) {
        cout<<" ";
    }
    
    cout<<root->val<<"\n";  
 
    print2DUtil(root->left, space);  
}

//function that inverts the tree
TreeNode* invertTree(TreeNode* root) {
        
    if (!root) {
        return root;
    }
        
    TreeNode* temp = root->right;
        
    root->right = invertTree(root->left);
        
    root->left = invertTree(temp);
        
    return root;
}
    
int main() {
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(5);
    	
    cout<<"Original Tree: \n";
    print2DUtil(root, 0);
    cout<<endl;
    	
    invertTree(root);
    	
    cout<<"Inverted Tree: ";
    print2DUtil(root, 0);
}
