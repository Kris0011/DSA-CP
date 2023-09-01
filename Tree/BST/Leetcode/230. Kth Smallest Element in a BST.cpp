class Solution {
public:
    int trav(TreeNode* root, int& i , int k ){

        if(root == nullptr){
            return -1 ;
        }

        int left  = trav(root->left , i , k)  ;
        if( left != -1 ){
            return left ;
        }
        i++ ;
        if(i == k){
            return root->val ;
        }
        return  trav(root->right , i, k ) ;  

    }

    int kthSmallest(TreeNode* root, int k) {
        int i = 0 ;
        return trav(root , i , k ) ;
    }
};