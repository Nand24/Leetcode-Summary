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
    vector<int> rightSideView(TreeNode* root) {
     vector<vector<int>> res;
         vector<int> ans;
         if(root==NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int size=q.size();
        for (int i = 0; i <size; i++)
        {
            TreeNode* nod=q.front();
            q.pop();
            if(nod->left!=NULL) q.push(nod->left);
            if(nod->right!=NULL) q.push(nod->right);
            level.push_back(nod->val);
        }
        res.push_back(level);
    }

    for(int i=0;i<res.size();i++)
    {
        int size=res[i].size();
               ans.push_back(res[i][size-1]);
    }
return ans;
    }
};