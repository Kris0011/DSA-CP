// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    
    stack<int> st ;
    int n = q.size() ;
    
    for( int i=0;i<k;i++){
        st.push(q.front()) ;
        q.pop() ;
    }
    
    while( !st.empty()){
        q.push(st.top()) ;
        st.pop() ;
    }
    
    for( int i=0;i< n-k ;i++){
        q.push(q.front()) ;
        q.pop() ;
    }
    
    return q;
}