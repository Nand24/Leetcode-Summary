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
int count(TreeNode*node)
{
    if(node==NULL) return 0;
    if(lh(node)==rh(node)) return pow(2,lh(node)) -1;
    
    return 1+count(node->left)+count(node->right);

}
int lh(TreeNode*node)
{
    if(node==NULL)
    {
       return 0;
    }
    return lh(node->left)+1;
}
int rh(TreeNode*node)
{
    if(node==NULL)
    {
       return 0;
    }
    return rh(node->right)+1;
}
    int countNodes(TreeNode* root) {
    return count(root);
    }
};