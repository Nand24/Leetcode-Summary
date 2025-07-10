/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void inorder(TreeNode*node,vector<int>&in)
{
    if(node==NULL) return;
    inorder(node->left,in);
    in.push_back(node->val);
    inorder(node->right,in);

}
    int countNodes(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        return in.size();
    }
};