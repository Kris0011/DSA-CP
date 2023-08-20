class Solution {
public:

    vector< vector<int> > ans;
    void Sum(TreeNode* root , int sum , int& targetSum  , vector<int> v){
        if(root== NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL ){
            if(sum + root->val == targetSum){  
                v.push_back(root->val);
                ans.push_back(v) ;
            }
            return;
        }

        sum = sum + root->val; 
        // if(sum > targetSum){
        //     return ;
        // }

        v.push_back(root->val) ;
        Sum(root->left , sum , targetSum , v) ;
        Sum(root->right , sum , targetSum , v) ;



    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        if(root== NULL){
            return {} ;
        }

        vector<int> v ;

        Sum(root , 0 , targetSum , v);

        for(auto i : ans){
            for(auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }

        return ans ;
        
    }
};