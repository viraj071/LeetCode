/*
Problem: Add Two Numbers

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Solution: Basic addition arithmetic using an auxillary carry variable.

Time Complexity: O(n)

Space Complexity: O(1)
where n is the number of nodes in the longer list.

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
    ListNode *add(ListNode *l1,ListNode *l2,int carry){
        if(l1==NULL&&l2==NULL&&carry==0)return NULL;
        int value=carry;
        if(l1!=NULL){
            value+=l1->val;
        }
        if(l2!=NULL){
            value+=l2->val;
        }
        ListNode *result=new ListNode(value%10);
        if(l1!=NULL||l2!=NULL){
            ListNode *more=add(l1==NULL?NULL:l1->next,l2==NULL?NULL:l2->next,value>=10?1:0);
            result->next=more;
        }
        return result;
    }
    
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return add(l1,l2,0);
    }
};