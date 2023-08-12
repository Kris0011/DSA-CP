 vector<vector<int>> levelOrder(TreeNode* root) {

        if( root == nullptr)
            return {} ;   
        queue<TreeNode*> q ;
        q.push(root) ;
        q.push(nullptr) ;
        vector<vector<int>> v ;
        vector<int> t ;
        while( !q.empty()){
            TreeNode* temp = q.front() ;
            q.pop() ;
            if( temp ){
                t.push_back(temp->val);
            }
            if( temp == nullptr){
               
                v.push_back(t) ;
                t.clear() ;
                if( !q.empty()){
                    q.push(nullptr) ;
                }
            }
            else{
                if( temp->left){
                    q.push(temp->left) ;
                }
                if( temp->right){
                    q.push(temp->right) ;
                }   
            }
        }
        return v ;
    }