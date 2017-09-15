/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    int count = 0;
    ListNode *preh = new ListNode(-1);
    preh->next = head;
    ListNode *Count;
    Count = preh;
    while(Count = Count->next){
        count++;
    }
    ListNode *cur, *nex;
    ListNode *pre = preh;
    for(int j = 1; j <= count/k;j++){
        cur = pre->next;
        nex = cur->next;
        for (int i=0;i<k-1;i++){
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
    }
    return head;
    }
};
