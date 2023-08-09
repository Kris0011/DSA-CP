    int height(TreeNode* root){
        if(root == nullptr) 
            return 0;
    
        int left = height(root->left);
        int right = height(root->right);

        return max(left,right)+ 1 ;

    }

    int diameterOfBinaryTree(TreeNode* root) {

        if(root == nullptr)
            return 0;

        int d1 = diameterOfBinaryTree(root->left) ;
        int d2 = diameterOfBinaryTree(root->right) ;
        int d3 = height(root->left) + height(root->right)  ;


        return max(d3, max(d1,d2))  ;
    }