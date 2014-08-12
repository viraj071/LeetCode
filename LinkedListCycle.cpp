/*
Problem: Linked List Cycle 

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Solution: Slow/Fast pointer method.

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
    bool hasCycle(ListNode *head) {
        ListNode *slowptr=head;
        ListNode *fastptr=head;
        if(head==NULL)return false;
        while(slowptr!=NULL&&fastptr!=NULL&&fastptr->next!=NULL){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
            if(slowptr==fastptr)return true;
        }
        return false;
    }
};