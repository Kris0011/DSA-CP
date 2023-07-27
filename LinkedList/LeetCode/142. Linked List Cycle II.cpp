ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head ;
        ListNode* slow = head ;

        int flag = 0;

        while(fast!= nullptr && fast->next!= nullptr ){
            fast = fast->next->next ;
            slow = slow->next ;

            if( slow == fast ){
                flag =  1 ;
                break ;
            }
        }

        if(flag){
            slow = head ;
            // int pos = 0;
            while( slow != fast){
                slow = slow->next;
                fast = fast->next ;
            }
            return slow ;
        }
        else{
            return nullptr;
        }
    }