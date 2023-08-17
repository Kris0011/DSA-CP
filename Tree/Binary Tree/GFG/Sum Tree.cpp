class Solution
{
    public:
    pair<bool, int> sumFast(Node* root){
        
        if( root == NULL){
            return make_pair(true, 0 ) ;
        }
        
        
        if( root->left == NULL && root->right == NULL)
            return make_pair(true , root->data) ;
        
        pair<bool , int> left = sumFast(root->left) ;
        pair<bool , int> right = sumFast(root->right) ;
        
        int sum = left.second + right.second + root->data ;
        
        if( left.first  && right.first && (left.second + right.second == root->data) ){
            return make_pair(true , sum) ;
        }
        
        
        return make_pair(false, 0 ) ;

    }
    
    
    bool isSumTree(Node* root)
    {
        return sumFast(root).first ;
    }
};