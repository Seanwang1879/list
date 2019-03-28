#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

void list_creat(NODE *head, int nums)
{
	int i;
	NODE *node;

	head->next = NULL;

	for(i=0; i<nums; i++){
		node = (NODE *)malloc(sizeof(NODE));
		node->next = NULL;
		node->data = 0;

		head->next = node;
		head = head->next;
	}
	return ;
}

int list_insert(NODE *head, int data, int location)    //min of location is 0
{
	if(!head || location < 0){
		return -1;
	}
	int i;
	NODE * list;
	NODE *node;

	list = head;
	node = (NODE*)malloc(sizeof(NODE));
	node->data = data;
	node->next = NULL;
	
	for(i=0; i<location; i++){
		list = list->next;
	}
	node->next = list->next->next;
	list->next = node;

	return 0;
}



int list_delete(NODE *head, int location)    //min of location is 1
{
	if(!head || location < 1){
		return -1;
	}
	int i;
	NODE *list;
	
	list = head;
	
	for(i=0; i<locaiton-1; i++){
		list = list->next;
	}
	free(list->next);
	list->next = list->next->next;
	
	return 0;
}

NODE* list_addr(NODE *head, int nums)    //0 is list of head.
{
	int i;
	NODE *list;

	list = head;
	for(i=0; i<nums; i++){
		list = list->next;
	}
	
	return list;
}

NODE* list_exchange(NODE *head, int nums)
{
	int i;
	NODE *list;
	NODE *node00, *node01;

	list = head;
	for(i=0; i<nums-1; i++){
		list = list->next;
	}
	
	node00 = list->next;
	node01 = list->next->next;
	
	node00->next = node00->next->next;
	node01->next = node00;
	list-next = node01;
	
	return head;
}

int list_sort(NODE *head, int nums)    //pop   链表不适合排序
{
	int i,j;
	NODE *node;

	for(i=0; i<nums; i++){
		for(j=0; j<nums-(i+1); j++){
			if(list_addr(head, j) < list_addr(head, j+1)){
				list_exchange(head, j);
			}
		}
	}
	return 0;
}

int list_reversal(NODE *head, int nums)
{
	if(!head){
		return -1;
	}

	int i;
	NODE *list_node;
	NODE *list;
	NODE *node;
	
	list = head;
	list_node = head;
	
	for(i=0; i<nums-1; i++){
		while(list_node->next){
			list_node = list_node->next;
		}
		list_node->next = list->next;
		list->next = list_node;
		
		list = list_node;
	}
	list->next->next = NULL;
	return 0;
}


















