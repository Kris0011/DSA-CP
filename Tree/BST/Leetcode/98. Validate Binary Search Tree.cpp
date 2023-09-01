class Solution {
public:

    bool isBST (TreeNode* root , long long max ,long long min){
        if(root == nullptr){
            return true;
        }

        if( root->val > min && root->val < max){
            return isBST(root->right , max , root->val ) && isBST(root->left , root->val , min) ;
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        cout << LLONG_MAX ;
        return isBST(root , LLONG_MAX , LLONG_MIN ) ;
    }
};