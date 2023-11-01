bool hasCycle(ListNode *head) {
    ListNode * slow = head;
    ListNode * fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow)return true;
    }
    return false;
}
