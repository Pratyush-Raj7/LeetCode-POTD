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
    
    map<int, int> mp;
    
    void DFS(TreeNode* root, int currLevel) {
        
        if(!root)
            return;
        
        mp[currLevel] += root->val;
        
        DFS(root->left, currLevel+1);
        DFS(root->right, currLevel+1);
        
    }
    
    int maxLevelSum(TreeNode* root) {
        mp.clear();
        
        DFS(root, 1);
        
        int maxSum = INT_MIN;
        int result = 0;
        
        for(auto &it : mp) {
            
            int level = it.first;
            int sum   = it.second;
            
            if(sum > maxSum) {
                maxSum = sum;
                result = level;
            }
            
        }
        
        return result;
    }
};