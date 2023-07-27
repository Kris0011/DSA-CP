ListNode* deleteMiddle(ListNode* head) {

        if( head == nullptr || head->next == nullptr)
            return nullptr ;

        ListNode* fast = head ;
        ListNode* slow = head ;
        while( fast!= nullptr && fast->next!= nullptr ){
            slow = slow->next ;
            fast = fast->next->next;
        }

        if(slow->next != nullptr){

        slow->val = slow->next->val ;
        slow->next = slow->next->next ;

        }
        else{
            head->next = nullptr ;
        }

        return head;

        
    }