#if 0

/**
* ɾ�������е��ڸ���ֵ val �����нڵ㡣
* ����: 1->2->6->3->4->5->6, val = 6
* ���: 1->2->3->4->5
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* header = new ListNode(-1);//��һ���ٵ�����ͷ��ֹ�������۵����
        header->next = head;
        ListNode* cur = header;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            }
            else {
                cur = cur->next;
            }
        }
        return header->next;
    }
}
#endif

#if 0
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode nextTemp = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nextTemp;
        }
        return prev;
    }
}
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
    ListNode* reverse(ListNode* prev, ListNode* cur) {
        if (cur == NULL)return prev;
        ListNode* nexttemp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nexttemp;
        return reverse(prev, cur);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }
};


#endif