class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void RView( Node* root , vector<int> &ans , int level ){
 
        if(root == NULL) { return;}
    
        
        if( ans.size() == level){
           ans.push_back(root->data);  
       }
      
       
       if( root->right){
           RView(root->right , ans , level+1 ) ;
       }
    
       if(root->left){
            RView( root->left , ans , level+1 ) ;
       }
    }

    vector<int> rightView(Node *root)
    {
       // Your Code here
       if( root == NULL){ return {} ;}
   
   
       vector<int> ans ;
       
       RView(root , ans , 0) ;
       return ans;
    }
};
