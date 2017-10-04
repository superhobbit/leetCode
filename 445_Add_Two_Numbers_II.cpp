You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7


A very dump solution:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l1T = traverse(l1);
    ListNode* l2T = traverse(l2);
    ListNode* result = new ListNode(0);
    ListNode* preR = result;
    while (l1T != NULL && l2T != NULL){

        result->val += l1T->val+l2T->val;
        result->next = new ListNode(0);
        if (result->val >= 10) {

            result->next->val += (result->val)/10;
            result->val = result->val - 10;
        }
        result = result->next;
        l1T = l1T->next;
        l2T = l2T->next;
    }
    if (l2T == NULL){
        while (l1T != NULL){

            result->val += l1T->val;
            l1T = l1T->next;
            result->next = new ListNode(NULL);
            if (result->val >= 10) {

                result->next->val += (result->val)/10;
                result->val = result->val - 10;
            }
            result = result->next;

        }
    }else if (l1T == NULL){
        while (l2T != NULL){
            result->val += l2T->val;
            l2T = l2T->next;
            result->next = new ListNode(NULL);
            if (result->val >= 10) {

                result->next->val += (result->val)/10;
                result->val = result->val - 10;
            }
            result = result->next;
        }
    }
    ListNode* tmp = traverse(preR);
    if (tmp->val == 0) return tmp->next;
    else return tmp;

}
ListNode* traverse(ListNode* root){
    ListNode* pre = new ListNode(-1);
    pre->next = root;
    ListNode* cur = root;
    ListNode* nex = root->next;
    while(nex != NULL){

        cur->next = nex->next;
        nex->next = pre->next;
        pre->next = nex;

        nex = cur->next;
    }
    return pre->next;
}
