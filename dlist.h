/*****************dlist***********
	>File_name:dlist.h
	>Creator:chenwengen
	>E-mail:xynhcwg@163.com
	>Time:2015/10/19,16:40
**********************************/
#ifndef DLIST_H
#define DLIST_H

#include <stdlib,h>

typedef struct DlistElmt_
{
	void *data;
	struct DlistElmt_ *prev;
	struct DlistElmt_ *next;
} DlistEmlt;

typedef struct Dlist_
{
	int size;
	void (*destroy)(void *data);
	DlistElmt *head;
	DlistElmt *tail;
} Dlist;

/********Public Interface********/
void dlist_init(Dlist *dlist,void (*destroy)(void *data));
void dlist_destroy(Dlist *dlist);
int dlist_ins_prev(Dlist *dlist,DlistElmt *element,const void *data);
int dlist_ins_next(Dlist *dlist,DlistElmt *element,const void *data);
int dlist_remove(Dlist *dlist,DlistElmt *element,void **data);

#define dlist_size(dlist) (dlist->size)
#define dlist_head(dlist) (dlist->head)
#define dlist_tail(dlist) (dlist->tail)
#define dlistelmt_data(element) (element->data)
#define dlistelmt_prev(element) (element->prev)
#define dlistelmt_next(element) (element->next)
#define dlistelmt_is_head(element) ((element)->prev==NULL ? 1:0)
#define dlistelmt_is_tail(element) ((element)->next==NULL ? 1:0)

#endif
