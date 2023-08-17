class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    vector<int> topView(Node *root)
    {
        //Your code here
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
            
            if(mp.find(hd) == mp.end() ){
                mp[hd] = tempNode->data ;
            }
            
            
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