/*************clist*********
	>Creator:chenwengen
	>File name:clist.h
	>E-mail:xynhcwg@163.com
	>Author:Kyle Loudon
	>Date:2015/10/20,14:14
****************************/

#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

typedef struct ClistElmt_
{
	void *data;
	struct ClistElmt_ *next;
} ClistElmt;

typedef struct Clist_
{
	int size;
	void (*destroy)(void *data);
	ClistElmt *head;
} Clist;

void clist_init(Clist *clist,void (*destroy)(void *data));
void clist_des(Clist *clist);
int clist_ins_next(Clist *clist,ClistElmt *element,const void *data);
int clist_rem_next(Clist *clist,ClistElmt *element,void **data);

#define clist_size(clist) (clist->size)
#define clist_head(clist) (clist->head)
#define clistelmt_data(element) (element->data)
#define clistelmt_next(element) (element->next)

#endif
