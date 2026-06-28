// Optimal and easy solution
// Time:O(N) space:O(1)


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
    ListNode *detectfirst(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL || fast!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return slow->val;
        }
        return NULL;
    }
};









// LL cycle-2 leetcode 

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
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        if (fast == NULL || fast->next == NULL)
            return NULL;

        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
