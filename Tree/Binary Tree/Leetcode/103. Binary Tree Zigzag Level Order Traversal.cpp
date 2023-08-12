vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if( root == nullptr)
            return {} ;


        int count = 0 ;   
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
                cout << count << " " ;
                if( count % 2 != 0){
                    reverse(t.begin() , t.end()) ;
                }
                v.push_back(t) ;
                count ++ ;
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