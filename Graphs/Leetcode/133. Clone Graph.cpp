class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == NULL) return NULL ;
         
        vector<int> visited (101 , 0) ;
        vector<Node*> adress ( 101 ) ;
        
        for(int i=0 ; i<= 100 ; i++){
            Node* temp = new Node(i) ;
            adress[i] = temp ;
        }
        
        Node* newStart = adress[node->val] ;
        queue<Node*> q ;
        q.push(node) ;
        
        
        while(!q.empty()){
            
            Node* temp = q.front() ;
            Node* newNode = adress[temp->val] ;
            // cout << temp->val << ": " << newNode << endl;
            visited[temp->val] = 1 ;
            
            q.pop() ;
        
            for(auto it : temp->neighbors){
                // cout << it->val << " " ;
                Node* tempNode = adress[it->val] ;
                // cout << tempNode << endl;
                newNode->neighbors.push_back(tempNode) ;
                if(!visited[it->val]){
                    q.push(it) ;
                    visited[it->val] = 1 ;
                    // cout << tempNode->val << ": " << tempNode << endl;
                    // newNode->neighbors.push_back(tempNode) ;
                }
            }
            // cout << endl;
            
        }
        
        
        
        
        return newStart;
    }
};