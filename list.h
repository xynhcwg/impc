/***********************list*************
	>File_name:list.h
	>Creator:chenwengen
	>E-mail:xynhcwg@163.com
	>Source:Master Alogritbms with C
	>Time:2015/10/19,16:30
*****************************************/
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct listElmt_
{
	void *data;
	struct listElmt_ *nest;
} ListEmlt;

typedef struct List_
{
	int size;
	void (*destroy)(void *data);
	ListElmt *head;
	ListElmt *tail;
} List;

/******Interface*******/
void list_init(List *list,void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list,ListElmt *element,const void *data);
int list_rem_next(List *list,ListElmt *element,void **data);

#define list_size(list) ((list)->size);
#define list_head(list) ((list)->head);
#define list_tail(list) ((list)->tail);
#define list_data(element) ((element)->data);
#define list_next(element) ((element)->next);
#define list_is_head(list,element) (element == ((list)->head)?1:0);
#define list_is_tail(element) ((element)->next == NULL?1:0);

#endif
