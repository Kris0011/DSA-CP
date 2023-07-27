    ListNode* solve( ListNode*  l1 , ListNode* l2){
        ListNode* curr1 = l1;
        ListNode* next1 = curr1->next  ;
        ListNode* curr2 = l2;
        ListNode* next2 = l2 ;
        if( next1 == nullptr){
            curr1->next = curr2 ; 
        }

        while( next2!=nullptr && next1!=nullptr ){
            
            if( curr1->val <= curr2->val && next1->val >= curr2->val){
                curr1->next = curr2 ;
                next2  = curr2->next ;
                curr2->next = next1 ;
                curr1 = curr2;
                curr2 = next2 ;
            }
            else{
                curr1 = next1 ;
                next1 = next1->next ; 
                
                if( next1 == nullptr){
                    curr1 ->next = curr2 ;
                }
            }
            
        }
        return l1 ;


    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == nullptr){
            return list2;
        }
        if( list2 == nullptr){
            return list1;
        }
            ListNode* curr1 = nullptr;
            ListNode* next1 = nullptr ;
            ListNode* curr2 = nullptr ;
            ListNode* next2 = nullptr ;

        if( list1->val <= list2->val){
            return solve(list1 , list2) ; 
        }
        else{
            return solve(list2 , list1) ; 
        }
        
    }