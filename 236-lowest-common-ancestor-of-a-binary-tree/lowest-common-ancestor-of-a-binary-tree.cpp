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
TreeNode* f(TreeNode*node,TreeNode* p, TreeNode* q)
{
    if(node==NULL) return NULL;
    if(node==p) return p;
    if(node==q) return q;
    TreeNode*left=f(node->left,p,q); 
    TreeNode*right=f(node->right,p,q);

 if(left==NULL)
    {
         return right;
    }
  else  if(right==NULL)
    {
        return left;
    }
    else return node;
   
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      return f(root,p,q);
       
    }
};