Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?


//we can also use a flag to extrack second while loop to the end (haveCircle == true, while...), but I don't think there would be any difference
ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) return NULL;
    ListNode* fast = head->next->next;
    ListNode* slow = head->next;
    while(fast && slow){
        if (fast == slow) {
            fast = head;
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;                    
            }
            return fast;
        }
        if (!fast->next) return NULL;
        fast = fast->next->next;
        slow = slow->next;
    }
    return NULL;
}
