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
    long SUM = 0; // sum of tree
    long maxP = 0;
    int totalSum(TreeNode* root){
        if(root == NULL) return 0;

        int leftSubtreeSum = totalSum(root->left);
        int rightSubtreeSum = totalSum(root->right);
        int sum = root->val + leftSubtreeSum + rightSubtreeSum;

        return sum;

    }

    int find(TreeNode* root){
        if(root == NULL) return 0;
         
         int leftSum = find(root->left);
         int rightSum = find(root->right);
         long s1 = root->val + leftSum + rightSum;
         long s2 = SUM - s1;
         maxP = max(maxP,(s1*s2));

         return s1;


    }
    int maxProduct(TreeNode* root) {
        if(root == NULL) return 0;
        maxP = 0;
        SUM = totalSum(root);
        find(root);

        return maxP%(1000000000+7);

    }
};