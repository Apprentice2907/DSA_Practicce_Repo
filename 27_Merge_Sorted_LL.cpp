// My solution and optimal also
// time:O(M+N) space:O(1)

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        ListNode* i=list1;
        ListNode* j=list2;
        while(i!=nullptr && j!=nullptr){
            if(i->val <=j->val){
                tail->next=i;
                i=i->next;
            }
            else{
                tail->next=j;
                j=j->next;
            }
            tail=tail->next;
        }
        if(i!=nullptr) tail->next=i;
        if(j!=nullptr) tail->next=j;
        return dummy->next;
    }
};