// Optimal solution 
// Time:O(N) Space:O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        int length = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            length++;
            temp = temp->next;
        }

        k = k % length;

        if (k == 0)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;

        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }

        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* newHead = slow->next;

        slow->next = NULL;
        fast->next = head;
        return newHead;
    }
};