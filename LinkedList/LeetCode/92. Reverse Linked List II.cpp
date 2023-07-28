ListNode* reverseList( ListNode* first  , ListNode* last ){

        if( (first!= nullptr && first->next == nullptr) || first == nullptr){
            return first ;
        }
        ListNode* prev = last ;
        ListNode* curr = first ;
        ListNode* next = nullptr ;

        while( curr != last ){
            next = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = next ;
        }

        return prev ;


    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1 ;
        ListNode* ptr  = head ;
        ListNode* first = ptr ;
        ListNode* first1 = ptr ;

        ListNode* last = nullptr ;

        if( first ==  nullptr){
            return first ;
        }

        while( count <= right){
            if(count  + 1 == left){
                first = ptr ;
                first1 = ptr->next;
            }

            if( count == right){
                last = ptr->next ;
            }
            count ++ ;
            ptr = ptr->next ;
        }

        if( first1 == first){
            return reverseList( first1 , last) ;
        }

        ListNode* temp = reverseList(first1  , last ); 

        first->next = temp ;

        return head ;



        
    }