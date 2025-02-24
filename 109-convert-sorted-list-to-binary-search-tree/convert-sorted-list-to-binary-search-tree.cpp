/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* middleNode(ListNode* head) {
         ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev != nullptr) {
            prev->next = nullptr;
        }

        return slow;
    }
TreeNode* buildTree(ListNode*head)
{
    if(head==NULL) return NULL ;
    ListNode* mid=middleNode(head);
    ListNode*lefthead=head;
    ListNode*righthead=mid->next;
    TreeNode*root =new TreeNode(mid->val);
    if(mid==head) return root;
    root->left=buildTree(lefthead);
    root->right=buildTree(righthead);
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
      return   buildTree(head);
    }
};