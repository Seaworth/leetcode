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
    ListNode* insertionSortList(ListNode* head) {
        //思路：将元素从原链表中取出来，然后插入新的链表中
        //time: O(N*N) space: O(1)
        ListNode* dummy=new ListNode(-1), *cur=dummy;
        while(head){
            ListNode* tmp=head->next;
            cur=dummy;//每次从头开始遍历
            while(cur->next && cur->next->val<=head->val){
                cur=cur->next;
            }
            head->next=cur->next;
            cur->next=head;
            head=tmp;
        }
        return dummy->next;
    }
};