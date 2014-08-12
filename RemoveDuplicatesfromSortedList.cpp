/*
Problem: Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

Solution: Iterate over each element in the linkedlist to check if the current->next->val==current->val.
If yes,delete that node.

Time Complexity: O(n)

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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *current=head;
        while(current!=NULL&&current->next!=NULL){
            if(current->next->val==current->val){
                ListNode *temp=current->next;
                current->next=temp->next;
                delete(temp);
            }
            else{
                current=current->next;
            }
        }
        return head;
    }
};
