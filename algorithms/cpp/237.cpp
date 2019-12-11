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
    void deleteNode(ListNode* node) {
        //思路：由于函数没有传入head，pre->cur->nex->next，不能通过pre直接指向nex从而删除cur
        //只有通过将nex的值复制到cur，将cur直接指向next，从而删除指定node节点
        //time: O(1) space: O(1)
        auto *nex=node->next;//保存下一个节点
        *node=*nex;//将当前节点复制为下一个节点
        delete nex;//删除下一个节点，防止内存泄漏
    }
};