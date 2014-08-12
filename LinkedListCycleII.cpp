/*
Problem: Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?

Solution: 
1. Use a fast and slow pointer to detect a cycle.
2. Count the number of nodes in the cycle. 
3. Use 2 pointers start,slowptr. 
4. Start both from the head. Move start the number of nodes in the cycle times ahead of slowptr.
Then move both of them together until the start->next=slowptr.
5. slowptr is the answer.

Time Complexity: O(n)
n is the number of nodes in the linked list.

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slowptr=head;
        ListNode *fastptr=head;
        bool isloop=false;
        while(slowptr&&fastptr&&fastptr->next){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
            if(slowptr==fastptr){
                isloop=true;
                break;
            }
        }
        if(isloop==false)return NULL;
        ListNode *start=slowptr;
        int count=0;
        while(start->next!=slowptr){
            count++;
            start=start->next;
        }
        start=head;
        slowptr=head;
        while(count--){
            start=start->next;
        }
        while(start->next!=slowptr){
            start=start->next;
            slowptr=slowptr->next;
        }
        return slowptr;
    }
};
