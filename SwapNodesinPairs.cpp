/*
Problem: Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Solution: Straightforward swapping

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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode *current=head;
        ListNode *nextnode=current->next;
        head=nextnode;
        ListNode *prev=new ListNode(0);
        while(current!=NULL&&nextnode!=NULL){
            current->next=nextnode->next;
            nextnode->next=current;
            prev->next=nextnode;
            prev=current;
            current=current->next;
            if(current!=NULL)
                nextnode=current->next;
            else
                break;
            
        }
        return head;
    }
};