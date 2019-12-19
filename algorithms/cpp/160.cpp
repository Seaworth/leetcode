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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //方法1：先获得两个链表的长度，然后求得长度差，将长的链表向后移动差值，然后一一比较。
        //time: O(N) space: O(1)
        int lenA=getLen(headA), lenB=getLen(headB);
        if(lenA>lenB){
            for(int i=0;i<lenA-lenB;++i) headA=headA->next;
        }else{
            for(int i=0;i<lenB-lenA;++i) headB=headB->next;
        }
        while(headA!=NULL && headB!=NULL && headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA==headB?headA:NULL;
    }
    int getLen(ListNode* root){
        int cnt=0;
        while(root!=NULL){
            root=root->next;
            ++cnt;
        }
        return cnt;
    }
};