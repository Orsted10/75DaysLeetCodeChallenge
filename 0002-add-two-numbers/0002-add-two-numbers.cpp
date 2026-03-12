class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* fakeHead = new ListNode();  // The poor dummy who takes the first hit 😅
        ListNode* tail = fakeHead;
        int leftover = 0;  // That annoying carry from last party
        
        ListNode* a = l1;
        ListNode* b = l2;
        
        while (a || b || leftover) {
            int sum = leftover;
            if (a) {
                sum += a->val;
                a = a->next;
            }
            if (b) {
                sum += b->val;
                b = b->next;
            }
            tail->next = new ListNode(sum % 10);  // The new digit joins the chain
            tail = tail->next;
            leftover = sum / 10;  // Whatever's left for next round
        }
        
        ListNode* answer = fakeHead->next;
        delete fakeHead;  // Clean up the dummy, he's done his job
        return answer;
    }
};