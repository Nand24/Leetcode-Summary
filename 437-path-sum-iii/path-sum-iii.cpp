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
long long dfs(TreeNode*node,long long target){
    if(node==NULL) return 0;
    long long match= (node->val==target) ? 1: 0;
    long long  left = dfs(node->left,target-node->val);
   
    long long right = dfs(node -> right, target - node -> val);

    return match + left + right;
}
 void preorder(TreeNode*node,long long target,long long &ans){
    if(node==NULL) return;
    
    preorder(node->left,target,ans);
    ans+=dfs(node,target);
    preorder(node->right,target,ans);

}
    int pathSum(TreeNode* root, int targetSum) {
     
     long long ans=0;

      preorder(root,targetSum,ans);
      return ans;

    }
};