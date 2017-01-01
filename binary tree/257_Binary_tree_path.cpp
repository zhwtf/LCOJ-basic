
void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
    if(!root->left && !root->right) {
        result.push_back(t);
        return;
    }

    if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
    if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if(!root) return result;

    binaryTreePaths(result, root, to_string(root->val));
    return result;
}





// wrong solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<string> help(TreeNode* root, vector<string>& result){
        if (root == NULL) return result;
        if (root->left == NULL && root->right == NULL){
            result.push_back(to_string(root->val));
            return result;
        }
        help(root->left, result);
        help(root->right, result);
        for (int i = 0; i < result.size(); i++){
            result[i].insert(0, (to_string(root->val) + "->"));
        }
        return result;

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        help(root, result);
        return result;

    }
};
