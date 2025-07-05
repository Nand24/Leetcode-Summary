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
void f(TreeNode*node,int target,vector<int>&temp,vector<vector<int>>&ans)
{
    if(node==NULL) return;
   if(node->left==NULL && node->right==NULL && target==node->val)
   {
    temp.push_back(node->val);
    ans.push_back(temp);
    temp.pop_back();
    return;
   }
   temp.push_back(node->val);
   f(node->left,target-node->val,temp,ans);
   f(node->right,target-node->val,temp,ans);
   temp.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;

        f(root,targetSum,temp,ans); 
        return ans;
    }
};