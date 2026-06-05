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
    int count = 0;
    void dfs(TreeNode* root, int currMax){
        if(!root) return;
        if(root->val > currMax) currMax = root->val;
        if(currMax==root->val) count++;
        dfs(root->left, currMax);
        dfs(root->right, currMax);
    }
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return count;
    }
};
