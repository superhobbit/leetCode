A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Duplicated copy every node in a single list, copy random, then extract.

RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) return head;
    RandomListNode* tmp = head;
    RandomListNode* newHead = new RandomListNode(head->label);
    while(tmp != NULL){
        //cout << "first" << endl;
        newHead->next = tmp->next;
        tmp->next = newHead;
        if (newHead->next != NULL) {
            tmp = newHead->next;
            newHead = new RandomListNode(tmp->label);
        }else{
            tmp = newHead->next;
        }
    }
    RandomListNode* handleRandom = head;
    RandomListNode* handleNew = head->next;
    while(handleNew != NULL){
        //cout << "second" << endl;
        RandomListNode* random1 = handleRandom->random;
        if (random1 != NULL){
            handleNew->random = random1->next;

        }
            handleRandom = handleNew->next;
            if (handleRandom != NULL) handleNew = handleRandom->next;
            else handleNew = NULL;              
    }
    RandomListNode* result = head->next;
    RandomListNode* depart = result;
    RandomListNode* nex = result->next;
    if (nex == NULL) head->next = NULL;
    while(nex != NULL){
        //cout << "third" << endl;
        head->next = nex;
        depart->next = nex->next;
        head = head->next;
        depart = depart->next;
        nex = depart->next;
    }
    head->next = NULL;
    return result;
}
