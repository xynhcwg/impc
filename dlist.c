/*************************************************************************
	> File Name: dlist.c
	> Creator:chenwengen
	> Mail: xynhcwg@163.com 
	> Source:Master Algoritbms with C
	> Created Time: 2015年10月19日 星期一 17时39分33秒
 ************************************************************************/

#include <stdlib.h>
#include <string.h>

#include "dlist.h"

void dlist_init(Dlist *dlist,void (*destroy)(void *data))
{
	dlist->size=0;
	dlist->destroy=destroy;
	dlist->head=NULL;
	dlist->tail=NULL;
	return ;
}
void dlist_destroy(Dlist *dlist)
{
	void *data;
	while(dlist_size(dlist)>0)
	{
		if(dlist_remove(dlist,dlist_head(dlist),(void **)&data)==0 && dlist->destroy != NULL)
			dlist->destroy(data);
	}
	memset(dlist,0,sizeof(Dlist));
	return ;
}
int dlist_ins_prev(Dlist *dlist,DlistElmt *element,const void *data)
{
	DlistElmt *new_element;
	if(element==NULL && dlist_size(dlist) !=0)
		return -1;
	if((new_element=(DlistElmt *)malloc(sizeof(DlistElmt))) == NULL)
		return -1;
	new_element->data=data;
	if(dlist_size(dlist)=0)
	{
		dlist->head=new_element;
		dlist->head->prev=NULL;
		dlist->head->next=NULL;
		dlist->tail=new_element;
	}
	else
	{
		new_element->next=element;
		new_element->prev=element->prev;
		if(element->prev==NULL)
			dlist->head=new_element;
		else
			element->prev->next=new_element;
		element->prev=new_element;
	}
	dlist->size++;
	return 0;
}
int dlist_ins_next(Dlist *dlist,DlistElmt *element,void *data)
{
	DlistElmt *new_element;
	if(element == NULL && dlist_size(dlist) != 0)
		return -1;
	if((new_element=(DlistElmt *)malloc(sizeof(DlistElemt)))==NULL)
		return -1;
	if(dlist_size(dlist)=0)
	{
		dlist->head=new_element;
		dlist->head->prev=NULL;
		dlist->head->next=NULL;
		dlist->tail=new_element;
	}
	else
	{
		new_element->next=element->next;
		new_element->prev=element;
		if(element->next==NULL)
			dlist->tail=new_element;
		else
			element->next->prev=new_element;
		element->next=new_element;
	}
	dlist->size++;
	return 0;
}
int dlist_remove(Dlist *dlist,DlistElmt *element,void **data)
{
	if(element == NULL || dlist_size(dlist)=0)
		return -1;
	*data=element->data;
	if(element==dlist->head)
	{
		dlist->head=element->next;
		if(dlist->head == NULL)
			dlist->tail=NULL;
		else
			element->next->prev=NULL;
	}
	else
	{
		element->prev->next=element->next;
		if(element->next == NULL)
			dlist->tail=element->prev;
		else
			element->next->prev=element->prev;
	}
	free(element);
	dlist->size--;
	return 0;
}
