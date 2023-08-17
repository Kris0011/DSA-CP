class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        if( root == NULL) { return {} ; }
        
        map<int , int > mp ;
        vector<int> v ;
        queue< pair< int , Node* > > q ;
        q.push(make_pair(0 , root)) ;
        
        while(!q.empty()){
            pair< int , Node*> temp = q.front() ;
            q.pop() ;
            
            int hd = temp.first ;
            Node* tempNode = temp.second ;
    
                mp[hd] = tempNode->data ;
            
            
            if(tempNode->left){
                q.push(make_pair(hd-1, tempNode->left)) ;
            }
            
            if( tempNode->right){
                q.push(make_pair(hd+1,tempNode->right)) ;
            }
            
        }
        
        
        for( auto it : mp){
            v.push_back(it.second) ;
        }
        
        
        return v ;
    }
};