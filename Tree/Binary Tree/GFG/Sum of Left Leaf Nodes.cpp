    void rSum( Node* root , int & sum , int check) {
        
        if( root == NULL){
            return ;
        }
        
        if( root->left == NULL && root->right == NULL && check){
            sum+=root->data;
            return ;
        }
        
        
        rSum( root->left , sum , 1 ) ; 
        rSum( root->right , sum , 0 ) ;
        
        
    }
    int leftLeavesSum(Node *root)
    {
        // Code here
        int sum = 0 ;
        rSum(root , sum , 0 ) ;
        return sum ;
    }