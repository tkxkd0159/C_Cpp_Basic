#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |->", p->data);
		}
	printf("\n");
}

void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}
													// In C, array parameters are treated as pointers
//int seq_search(int list[], int key, int arr_size)   // sizeof(arr)/sizeof(arr[0]) becomes sizeof(int *)/sizeof(int)
//{
//	int i;
//	for (i = 0; i < arr_size; i++)
//		if (list[i] == key) return i;
//	return -1;
//}

int main() {

	//int seq_res;
	//int new_list[10] = {5, 9, 10, 17, 21, 29, 33, 37, 38, 43};
	//int new_list_size = sizeof(new_list) / sizeof(new_list[0]);
	//seq_res = seq_search(new_list, 38, new_list_size);

	//printf("result = %d", seq_res);

	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("Add list\n");
	for (int i = 0; i < 10; i++) {
		
		dinsert(head, i);
		print_dlist(head);
	}

	printf("Delete list\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);

	return 0;
}