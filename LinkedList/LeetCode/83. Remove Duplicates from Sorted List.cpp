ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        if(head == nullptr || head->next == nullptr)
            return head ;

        while(ptr->next != nullptr){
            if(ptr->next->val == ptr->val){
                ptr->next = ptr->next->next ;
            }else{
                ptr = ptr->next ;
            }
            
        }
        return head ;

    }