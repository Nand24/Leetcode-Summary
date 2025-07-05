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
            
            temp+=to_string(node->val);
            vec.push_back(temp);
            return;
    }
    temp+=to_string(node->val);
    temp+="->";
    f(node->left,vec,temp);
    f(node->right,vec,temp);
    
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        string temp="";
        f(root,vec,temp);
        return vec;
    }
};