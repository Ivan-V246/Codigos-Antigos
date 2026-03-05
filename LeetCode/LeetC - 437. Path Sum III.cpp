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
    map <long long, long long> freq;

    long long ans = 0;
    long long pathSum(TreeNode* root, long long targetSum) {
        freq[0]++;
        recurso(root, targetSum, 0);
        return ans;
    }

    void recurso(TreeNode* atual, long long x, long long soma) {
        if(atual == nullptr) return;

        soma += (atual->val);
        ans += freq[soma-x];

        freq[soma]++;

        recurso(atual->left, x, soma);
        recurso(atual->right, x, soma);
        
        freq[soma]--;
    }
};