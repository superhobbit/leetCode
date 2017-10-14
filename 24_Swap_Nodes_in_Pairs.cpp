Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Did by myself, running time is acceptable:
ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* pre = new ListNode(-1);
    pre->next = head;
    ListNode* cur = head;
    ListNode* nex = head->next;
    ListNode* result = head->next;
    while(nex){
        pre->next = nex;
        cur->next = nex->next;
        nex->next = cur;
        pre = cur;
        cur = cur->next;
        if (!cur) break;
        nex = cur->next;
    }
    return result;
}
