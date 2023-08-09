int height(struct Node* node){
        // code here 
        
        if( node == NULL){
            return 0 ;
        }
        
        int left = height(node->left) ;
        int right = height(node->right) ;
        
        return max(left,right)+1;

    }

