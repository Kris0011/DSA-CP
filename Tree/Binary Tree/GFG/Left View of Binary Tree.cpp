void lView( Node* root , vector<int> &ans , int level ){
 
    if(root == NULL) { return;}
    
   if( level == ans.size()) {
       ans.push_back(root->data) ;
   }
    
   if(root->left){
        lView( root->left , ans , level+1 ) ;
   }
   
   if( root->right){
       lView(root->right , ans , level+1 ) ;
   }
}

vector<int> leftView(Node *root)
{
   // Your code here
   if( root == NULL){ return {} ;}
   
   
   vector<int> ans ;
   
   lView(root , ans , 0) ;
   return ans;
   
   
}
