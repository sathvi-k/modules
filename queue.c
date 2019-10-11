/* queue.c --- Create a queue 
 * 
 * 
 * Author: John B. Kariuki Jr., Hanna , Aya , and Sathvika
 * Created: Mon Oct  7 21:39:00 2019 (-0400)
 * Version: 1.0
 * 
 * Description: Creates a queue module that implements the queue.h interface
 * 
 */

#include <stdint.h>
#include <stdbool.h>
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct element_t{
	struct element_t *next;
	void *data;
}element_t;

typedef struct iqueue_t{
	element_t *front;
	element_t *back;
}iqueue_t;

static element_t* create_element(void *elementp){              
 	element_t *et;
  if(!(et=(element_t*)malloc(sizeof(element_t)))){
    printf("[Error: malloc failed allocating element]\n");
    return NULL;
  }
  et->next=NULL;
	et->data=elementp;
  return et;
}

queue_t* qopen(void){               
	iqueue_t *qp;
  if(!(qp=(iqueue_t*)malloc(sizeof(iqueue_t)))){
    printf("[Error: malloc failed allocating queue]\n");
    return NULL; 
  }
  qp->front=NULL;
	qp->back=NULL;
  return qp;
}

void qclose(queue_t *qp){
	iqueue_t *iqp=(iqueue_t*)qp;
	element_t *i=iqp->front;
	element_t *save=NULL;
	
	while(i!=NULL){
		free(i->data);
		save=i->next;
		free(i);
		i=save;
	}
	free(iqp);
}

int32_t qput(queue_t *qp,void *elementp){
	element_t *element=create_element(elementp);
	iqueue_t *iqp=(iqueue_t*)qp;
	
	if(iqp->front==NULL && iqp->back==NULL){
		iqp->front=element;
		iqp->back=element;
		return 0;
	}
	else{
		iqp->back->next=element;
		iqp->back=element;
		return 0;
	}
	return 1;
}

void* qget(queue_t *qp){
	element_t *save=NULL;
	iqueue_t *iqp=(iqueue_t*)qp;
	
	if(iqp->front!=NULL && iqp->back!=NULL){
		save=iqp->front;
		iqp->front=iqp->front->next;
		if(iqp->front==NULL){
			iqp->back=NULL;
		}
	}
	if(save==NULL){
		return NULL;
	}
	return save->data;
}

void qapply(queue_t *qp, void (*fn)(void* elementp)){
	iqueue_t *iqp=(iqueue_t*)qp;
	if (iqp->front!=NULL){
		element_t *ep;
		for(ep=iqp->front;ep!=NULL;ep=ep->next){
			fn(ep->data);
		}
	}
	else{
		printf("The list is empty, can't apply the function\n");
	}
}

void* qsearch(queue_t *qp,
              bool (*searchfn)(void* elementp,const void* keyp),
              const void* skeyp){
	iqueue_t *iqp=(iqueue_t*)qp;
	element_t *ep;
	for(ep=iqp->front;ep!=NULL;ep=ep->next){
		if(searchfn(ep->data,skeyp)==true){
			return ep->data;
		}
	}
	return NULL;
}

void* qremove(queue_t *qp,
              bool (*searchfn)(void* elementp,const void* keyp),
              const void* skeyp){
	iqueue_t *iqp=(iqueue_t*)qp;
	element_t *ep;
	element_t *prev;
	
	for(ep=iqp->front;ep!=NULL;ep=ep->next){
		if(searchfn(ep->data,skeyp)==true){
			if(ep==iqp->front){
				iqp->front=iqp->front->next;
				ep->next=NULL;
				return ep->data;
			}
			else if(ep==iqp->back){
				iqp->back=prev;
				prev->next=NULL;
				ep->next=NULL;
				return ep->data;
			}
			else{
				prev->next=ep->next;
				ep->next=NULL;
				return ep->data;
			}
		}
		prev=ep;
	}
	return NULL;
} 


/* concatenatenates elements of q2 into q1
 * q2 is dealocated, closed, and unusable upon completion
 */ 
void qconcat(queue_t *q1p, queue_t *q2p) {
	iqueue_t *iq1p=(iqueue_t*)q1p;
	iqueue_t *iq2p=(iqueue_t*)q2p;
	element_t *front_2=iq2p->front;
	iq1p->back->next=front_2;
	iq1p->back=iq2p->back;
	qclose(iq2p);
}
