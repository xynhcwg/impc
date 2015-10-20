/*************************************************************************
	> File Name: clist.c
	> Author: chenwengen
	> Mail: xynhcwg@163.com 
	> Created Time: 2015年10月20日 星期二 14时32分35秒
 ************************************************************************/

#include <stdlib.h>
#include <string.h>

#include "clist.h"
void clist_init(Clist *clist,void (*destroy)(void *data))
{
	clist->size=0;
	clist->destroy=destroy;
	clist->head=NULL;
	return ;
}
void clist_des(Clist *clist)
{
	void *data;
	while(clist_size(clist)>0)
	{
		if(clist_rem_next(clist,clist->head,(void **)&data) == 0 && destroy != NULL)
			clist->destroy(data);
	}
	memset(clist,0,sizeof(Clist));
	return ;
}
int clist_ins_next(Clist *clist,ClistElmt *element,void *data)
{
	ClistElmt *new_element;
	if((new_element=(ClistElmt *)malloc(sizeof(ClistElmt)))==NULL)
		return -1;
	new_element->data=data;
	if(clist_size(clist)==0)
	{
		new_element->next=new_element;
		clist->head=new_element;
	}
	else
	{
		new_element->next=element->next;
		element->next=new_element;
	}
	clist->size++;
	return 0;
}
int clist_rem_next(Clist *clist,ClistElmt *element,void **data)
{
	ClistElmt *old_element;
	if(clist_size(clist)==0)
		return -1;
	*data=element->next->data;
	if(element->next==element)
	{
		old_element=element->next;
		clist->head=NULL;
	}
	else
	{
		old_element=element->next;
		element->=element->next->next;
		if(old_element == clist_head(clist))
			clist->head=old_element->next;
	}
	free(old_element);
	list->size--;
	return 0;
