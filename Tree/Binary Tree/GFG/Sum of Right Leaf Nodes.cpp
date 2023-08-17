class Solution{
    public:
    
    void rSum( Node* root , int & sum , int check) {
        
        if( root == NULL){
            return ;
        }
        
        if( root->left == NULL && root->right == NULL && check){
            sum+=root->data;
            return ;
        }
        
        
        rSum( root->left , sum , 0 ) ; 
        rSum( root->right , sum , 1 ) ;
        
        
    }
    
    int rightLeafSum(Node* root)
    {
         //Code here
         int sum = 0 ;
         rSum(root , sum , 1 ) ;
         return sum ;
            
    }
};
