/*
Problem: Remove Nth Node From End of List

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

Solution: Linked List traversal

Time Complexity: O(n)
where n is the number of nodes in the linked list.

Space Complexity: O(1)
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *end=head;
        int temp=n;
        while(temp--){
            end=end->next;
        }
        ListNode *start=head;
        if(end==NULL)return head->next;
        while(end->next!=NULL){
            end=end->next;
            start=start->next;
        }
        ListNode *t=start->next;
        start->next=start->next->next;
        delete(t);
        return head;
    }
};