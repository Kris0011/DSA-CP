  int tour(petrolPump p[],int n)
    {
       //Your code here
       int front = 0 ;
       int balance = 0; 
       int temp = 0 ;
       
       for( int i=0; i<n ; i++){
            balance += p[i].petrol - p[i].distance;
            if( balance < 0 ){
                temp += balance ;
                front = i+1 ;
                balance = 0;
            }
        
       }
       
       if( balance + temp >=0) {
            return front ;
       }
       else{
        return -1;
       }
        