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
    bool hasCycle(ListNode *head) {
        if(!head) return 0;
        auto slo = head, fast = head;

        while(fast->next && fast->next->next)
        {
            slo = slo->next;
            fast = fast->next->next;

            if(slo == fast) return 1;
        }
        return 0;
    }
};