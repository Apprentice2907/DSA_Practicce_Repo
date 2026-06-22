// My solution and optimal 
// Time:O(N) Space:O(1)



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        int pos = len - n + 1;

        // deleting head
        if (pos == 1) {
            return head->next;
        }

        temp = head;

        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};





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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=new ListNode(0,head);
        ListNode* slow=temp;
        ListNode* fast=temp;
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        while(fast!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return temp->next;
    }
};