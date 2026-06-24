// My brute force appraoch is to convert this into string and then addition adn then string to int convert and then reverrse so too much lengthy processs

// Optimal and stadnard solution approach 
// Time:O(max(M,N)) Space:O(max(M,N))


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum=sum+l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum=sum+l2->val;
                l2=l2->next;
            }
            sum=sum+carry;
            carry=sum/10;
            ListNode* node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
};