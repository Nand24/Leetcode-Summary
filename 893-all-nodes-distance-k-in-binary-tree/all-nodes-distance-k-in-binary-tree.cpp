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
void mp(TreeNode*node,unordered_map<TreeNode*,TreeNode*>& mpp)
{
    if(node==NULL) return;
    if(node->left)
    {
        mpp[node->left]=node;
        mp(node->left,mpp);
    }
     if(node->right)
    {
        mpp[node->right]=node;
        mp(node->right,mpp);
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
   unordered_map<TreeNode*,TreeNode*> mpp;
   unordered_map<TreeNode*,int> vis;
   mp(root,mpp);
    queue<TreeNode*> q;
    q.push(target);
    vis[target]=1;
    int dist=0;
    while(!q.empty()&& dist!=k)
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode* node=q.front();
            q.pop();
            if(mpp.count(node) && vis[mpp[node]]!=1)
            {
                q.push(mpp[node]);
                vis[mpp[node]]=1;
            }
            if(node->left!=NULL && vis[node->left]!=1)
            {
                q.push(node->left);
                vis[node->left]=1;
            }
            if(node->right!=NULL && vis[node->right]!=1)
            {
                q.push(node->right);
                vis[node->right]=1;
            }
        }
        dist+=1;
    }
    vector<int> res;
    while(!q.empty())
    {
          res.push_back(q.front()->val);
          q.pop();
    }
    return res;
    }
};