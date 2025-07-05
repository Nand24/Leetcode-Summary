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
void f(TreeNode*node,vector<string>&vec,string temp)
{
    if(node==NULL) return;
    if(node->left==NULL && node->right==NULL)
    {
        temp+=node->val+'a';
        string x=temp; 
        reverse(x.begin(),x.end());
        vec.push_back(x);
        temp.pop_back();
        return;
    }
    temp+=node->val+'a';
    f(node->left,vec,temp);
    f(node->right,vec,temp);
    temp.pop_back();
}
    string smallestFromLeaf(TreeNode* root) {
        vector<string> vec;
        string temp="";
         f(root,vec,temp);
         sort(vec.begin(),vec.end());
         return vec[0];
    }
};