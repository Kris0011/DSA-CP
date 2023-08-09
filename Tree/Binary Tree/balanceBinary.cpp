int height( TreeNode* root){
        if(root == nullptr) return 0;
        int left = height(root->left) ;
        int right = height(root->right) ;

        return max(left,right) + 1;
    }

    bool isBalanced(TreeNode* root) {

        if(root == nullptr)
            return true ;

        bool left = isBalanced(root->left) ;
        bool right = isBalanced(root->right) ;

        bool check = false; 

        int h = abs(height(root->left) - height(root->right)) ;

        if( h<=1){
            check = true ;
        }

        return left && right && check ;
    }