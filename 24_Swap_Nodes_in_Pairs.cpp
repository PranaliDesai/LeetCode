class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* ans ;
        ans = head->next;
        head->next = swapPairs(head->next->next);
        ans->next = head;
        return ans;
    }
};
