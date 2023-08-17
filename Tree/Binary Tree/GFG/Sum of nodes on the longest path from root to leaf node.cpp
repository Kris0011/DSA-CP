class Solution
{
public:
    vector<pair<int,int>>  v ;
    void sumTree(Node* root , int height , int sum ){
        if(root == NULL){
            v.push_back(make_pair(height , sum));
            return ;
        }
       
        
        sum += root->data ;
        sumTree(root->left , height+1 , sum) ;
        sumTree(root->right  , height+1 , sum) ;
        
        
    
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        if(root ==  NULL){
            return 0 ;
        }
        
        
        sumTree( root , 1 , 0 ) ;
      
        
        const auto p = *max_element(v.begin(), v.end() );
        
        return p.second ;
        
    }
};