// Optimal solution and my approach but didnt know how to write the code so little bit confuse there
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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL || k == 1)
            return head;

        ListNode* current = head;
        ListNode* previousGroupTail = NULL;
        ListNode* newHead = NULL;

        while (current != NULL) {

            // Check if there are at least k nodes
            ListNode* temp = current;
            int count = 0;

            while (temp != NULL && count < k) {
                temp = temp->next;
                count++;
            }

            if (count < k) {
                // Remaining nodes stay as they are
                if (previousGroupTail != NULL)
                    previousGroupTail->next = current;
                break;
            }

            // Reverse k nodes
            ListNode* groupHead = current;
            ListNode* prev = NULL;
            ListNode* next = NULL;

            count = 0;

            while (count < k) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }

            // First group
            if (newHead == NULL)
                newHead = prev;

            // Connect previous group
            if (previousGroupTail != NULL)
                previousGroupTail->next = prev;

            // Connect current group's tail to next group
            groupHead->next = current;

            // Update previousGroupTail
            previousGroupTail = groupHead;
        }

        return newHead;
    }
};