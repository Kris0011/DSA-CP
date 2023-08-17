 void getLeft( Node* root , vector<int> &v){
        if(( root == NULL) || (root->left == NULL && root->right == NULL)){
            return ; 
        }
        
        int x = root->data ; 
        v.push_back(x) ;
        if( root->left){
            getLeft(root->left , v) ;
        }
        
        else{
            getLeft( root->right  , v ) ;
        }
        
    }
    
    void getRight ( Node* root , vector<int> &v){
        if(( root == NULL) || (root->left == NULL && root->right == NULL)){
            return ; 
        }
          
        if( root->right){
            getRight(root->right , v) ;
        }
        else{
            getRight(root->left  , v) ;
        }
        v.push_back( root-> data) ;
    }
    
    
    void getBottom ( Node* root , vector<int> &v){
        if(root == NULL){
            return ;
        }
        
        if( root->left == NULL && root->right == NULL){
            v.push_back(root->data) ;
            return ; 
        }
        
        getBottom (root->left , v) ;
        getBottom (root->right , v) ;
        
    }


    vector <int> boundary(Node *root)
    {
        //Your code here
        
        if( root == NULL){
            return {}; 
        }
        
        vector<int> v ;
        v.push_back( root->data) ;
        
        getLeft(root->left  , v) ;
    
        getBottom ( root->left , v ) ;
        getBottom ( root->right , v ) ;
        
        getRight (root->right , v ) ;
        
    
        
        return v ;
        
    
        
    }