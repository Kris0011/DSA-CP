int height( TreeNode* root){
        if(root == nullptr) return 0;
        int left = height(root->left) ;
        int right = height(root->right) ;

        return max(left,right) + 1;
    }

    bool isBalanced(TreeNode* root) {

        if(root == nullptr)
            return true ;

        bool left = isBalanced(root->left) ;
        bool right = isBalanced(root->right) ;

        bool check = false; 

        int h = abs(height(root->left) - height(root->right)) ;

        if( h<=1){
            check = true ;
        }

        return left && right && check ;
    }



    pair<bool,int> fastBalanced( TreeNode* root){
        if(root == nullptr){
            pair<bool,int> p = make_pair(true,0) ;
            return p ;
        }

        pair<bool,int> left = fastBalanced(root->left);
        pair<bool,int> right = fastBalanced(root->right);       


        bool leftA = left.first ;
        bool rightA = right.first ;


        bool check = abs(left.second -  right.second) <= 1 ;

        int h = max( left.second , right.second ) + 1 ;
        pair<bool,int> ans ;

        if( leftA && rightA && check){
            return make_pair(true , h) ;
        }
        return  make_pair(false , h) ;

    }

    bool isBalanced(TreeNode* root) {
        return fastBalanced(root).first ;
    }