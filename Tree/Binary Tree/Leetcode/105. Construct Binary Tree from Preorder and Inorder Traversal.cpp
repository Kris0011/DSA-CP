
class Solution {
public:

    TreeNode* solve (vector<int> pre, vector<int> in , int& index , int start , int end , int n){


        if( (index>=n )|| (start>end) ){
            return nullptr ;
        }

        TreeNode* root = new TreeNode(pre[index]) ;
        index++;

        int pos = -1 ;

        for(int i=0;i< n ;i++){
            if(in[i] == root->val){
                pos = i ;
                break;
            } 
        }        

        root->left = solve(pre , in , index , start , pos-1 , n) ;
        root->right = solve(pre, in, index , pos+1 , end , n) ;

        return root ;

    }

    TreeNode* buildTree(vector<int> pre, vector<int> in) {
        int index = 0 ;
        int inSize = in.size() ;
        TreeNode* ans = solve(pre , in , index , 0 , inSize -1 , inSize ) ;
        return ans;

            
    }
};