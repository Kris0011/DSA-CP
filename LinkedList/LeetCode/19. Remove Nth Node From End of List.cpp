ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head ;
        ListNode* slow = head ;

      
       
        for( int i= 0 ;i< n;i++){
            fast = fast->next ;
        }
        
        if(fast == nullptr){
            head = head->next;
            return head ;
        }
    

        while(fast->next != nullptr && fast!= nullptr){
            slow = slow->next ;
            fast = fast->next ;
        }


       slow->next = slow->next->next ;
        
        return head ;
    }