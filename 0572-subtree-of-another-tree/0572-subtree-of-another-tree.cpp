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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       //Base Case
       if(p == NULL || q == NULL){
        return p == q;
       } 
       bool leftIdentical = isSameTree(p -> left, q -> left);
       bool rightIdentical = isSameTree(p -> right, q -> right);

       return leftIdentical && rightIdentical && p -> val == q -> val;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //Base Case
        if(root == NULL || subRoot == NULL){
            return root == subRoot;
        }
        if(root -> val == subRoot -> val && isSameTree(root, subRoot)){
            return true;
        }
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right ,subRoot);
    }
};