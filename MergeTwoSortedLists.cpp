/*
Problem: Merge Two Sorted Lists 

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes
of the first two lists.

Solution: Basic Merging like in Merge Sort.

Time Complexity: O(m+n)

Space Complexity: O(m+n)

where m is the size of 1st list and n is the size of the 2nd list.
*/

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(5);
        ListNode *head=dummy;
        while(true){
            if(l1==NULL){
                head->next=l2;
                break;
            }
            else if(l2==NULL){
                head->next=l1;
                break;
            }
            else if(l1->val<l2->val){
                head->next=l1;
                head=head->next;
                l1=l1->next;
            }
            else{
                head->next=l2;
                head=head->next;
                l2=l2->next;
            }
        }
        return dummy->next;
    }
};
