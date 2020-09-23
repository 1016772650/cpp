#include<iostream>
using namespace std;

// 2����ͷ˫��ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;
void ListInit(List* plist) {
	plist->_head = (ListNode*)malloc(sizeof(ListNode));
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}
void ListDestory(List* plist) {
	if (plist->_head->_next = plist->_head) {
		return;
	}
	else {
		ListNode* cur;
		cur = plist->_head->_next;
		while (cur != plist->_head) {
			ListNode* temp = cur->_next;
			free(cur);
			cur = temp;
		}
	}
	free(plist->_head);
	plist->_head = nullptr;
}
ListNode* CreateNode(LTDataType x) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->_next = nullptr;
	node->_prev = nullptr;
	return node;
}
void ListPushBack(List* plist, LTDataType x) {//β��
	ListNode* node = CreateNode(x);
	plist->_head->_prev->_next = node;
	node->_prev = plist->_head->_prev;
	plist->_head->_prev = node;
	node->_next = plist->_head;

}
void ListPopBack(List* plist) {//βɾ
	if (plist->_head->_next == plist->_head) {
		return;
	}
	else {
		ListNode* cur = plist->_head->_prev;//Ϊ8
		ListNode* temp = cur->_prev;
		temp->_next = plist->_head;
		plist->_head->_prev = temp;
		free(cur);
		cur = nullptr;//��һ��plist=198->��ȷ
	}
}
void ListPushFront(List* plist, LTDataType x) {//ͷ��
	ListNode* node = CreateNode(x);
	node->_next = plist->_head->_next;
	plist->_head->_next->_prev = node;
	node->_prev = plist->_head;
	plist->_head->_next = node;
}
void ListPopFront(List* plist) {//ͷɾ
	if (plist->_head->_next == plist->_head)
	{
		return;
	}
	else {
		ListNode* cur = plist->_head->_next;
		ListNode* temp = cur->_next;
		plist->_head->_next = temp;
		temp->_prev = plist->_head;
	}
}
ListNode* ListFind(List* plist, LTDataType x) {
	if (plist->_head->_next == plist->_head) {
		return nullptr;
	}
	else {
		ListNode* cur = plist->_head->_next;
		while (cur != plist->_head) {
			if (cur->_data == x) {
				return cur;
				break;
			}
			cur = cur->_next;
		}
	}
	return nullptr;
}
// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x) {
	ListNode* cur = CreateNode(x);
	cur->_prev = pos->_prev;
	pos->_prev->_next = cur;
	cur->_next = pos;
	pos->_prev = cur;
}
// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos) {//ɾ��
	if (pos->_next == pos)
	{
		return;
	}
	ListNode* cur = pos->_prev;
	pos->_next->_prev = cur;
	cur->_next = pos->_next;
	free(pos);

}
void ListRemove(List* plist, LTDataType x) {//ɾ��ֵΪx�Ľڵ�
	if (plist->_head->_next == plist->_head) { return; }
	else {
		ListNode* prev = plist->_head->_next;
		ListNode* cur = plist->_head->_next;
		//ͷ�ڵ����x�����
		while (cur != plist->_head)
		{
			if (cur->_data == x) {
				plist->_head->_next = cur->_next;
				cur->_next->_prev = plist->_head;
				cur = plist->_head->_next;
			}
			//����ͷ�ڵ����x�����
			else {
				for (;cur != plist->_head;cur = cur->_next)
				{
					if (cur->_data == x) {
						prev->_next = cur->_next;
						cur->_next->_prev = prev;
						cur = prev->_next;
					}
					prev = cur;
				}
			}
		}
	}
}
void ListPrint(List* plist) {//��ӡ
	if (plist->_head->_next == plist->_head) {
		//˵������Ϊ��
		printf("����Ϊ��, ��ӡʧ��!\n");
		return;
	}
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head) {
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
int main()
{
	List list;
	ListInit(&list);
	ListPushBack(&list, 1);
	ListPushBack(&list, 9);
	ListPushBack(&list, 8);
	ListPushBack(&list, 8);
	ListPrint(&list);//β��->1 9 8 8

	ListPopBack(&list);
	ListPrint(&list);//βɾ->1 9 8

	ListPushFront(&list, 2);
	ListPrint(&list);//ͷ��->2 1 9 8

	ListPopFront(&list);
	ListPrint(&list);//ͷɾ->1 9 8

	ListNode* cur = ListFind(&list, 9);
	ListInsert(cur, 7);//��cur��9��ǰ����7->1 7 9 8
	ListPrint(&list);

	ListNode* cur2 = ListFind(&list, 7);
	ListErase(cur2);
	ListPrint(&list);//ɾ���ڵ�Ϊ7�Ľڵ�->1 9 8

	ListRemove(&list, 9);
	ListPrint(&list);//ɾ����ֵΪ9�Ľڵ�->1 8
}
