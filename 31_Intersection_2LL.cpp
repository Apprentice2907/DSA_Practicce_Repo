// i also think the brute force approach first and didnt get the optimal solution
// i am fascinated by the better solution using address and comparing then 

// Optimal solution (Out of the world)
// Time: O(2 × max(M,N)) Space:O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;

        while (p1 != p2) {
            if (p1 == nullptr)
                p1 = headB;
            else
                p1 = p1->next;

            if (p2 == nullptr)
                p2 = headA;
            else
                p2 = p2->next;
        }
        return p1;
    }
};






// Brute force approach 
// Time:O(M*N) Space:O(1)



node* intersectionPresent(node* head1, node* head2) {
    while (head2 != NULL) {
        node* temp = head1;
        while (temp != NULL) {
            // If both nodes are the same (intersection point)
            if (temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    // Intersection is not present between the lists, return NULL
    return NULL;
}



// Better Solution
// Time:O(M+N) space:O(1)



node* intersectionPresent(node* head1, node* head2) {
    unordered_set<node*> st;  // Set to store visited nodes from the first list
    while (head1 != NULL) {
        st.insert(head1);  // Insert nodes of the first list into the set
        head1 = head1->next;
    }
    while (head2 != NULL) {
        if (st.find(head2) != st.end()) return head2;  // If node is found in set, it's the intersection point
        head2 = head2->next;
    }
    return NULL;  // Return NULL if no intersection is found
}



// Optimal solution
// Time:O(2*(M,N)) Space:O(1)

int a=0;
int b=0;
while(head1!=NULL) a++;
while(head2!=NULL) b++;
int diff=a-b;
 