 pair<int,int> diameter( TreeNode* root){
        if(root == nullptr){
            pair<int,int> p = make_pair(0,0) ;
            return p;
        }

        pair<int, int> left = diameter(root->left) ;
        pair<int, int> right = diameter(root->right) ;

        int d1 = left.second ;
        int d2 = right.second ; 
        int d3 = left.first + right.first ;

        int d = max(d3, max(d1,d2)) ;
        int h = max(left.first,right.first)+ 1 ;

        return make_pair(h,d) ;

    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        return diameter(root).second ;
    }