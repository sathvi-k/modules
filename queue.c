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

typedef struct intqueue_t{
	void *front;
	void *back;
}intqueue_t;

typedef struct element_t{
	struct element_t *next;
	void *data;
}element_t;


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
	                            
 	queue_t *qp;
                                                                                
  if(!(qp=(queue_t*)malloc(sizeof(queue_t)))){                                       
    printf("[Error: malloc failed allocating queue]\n");                          
    return NULL;                                                                
  }                                                                             
                                                                                
  qp->front=NULL;
	qp->back=NULL;
  return qp;
}

void qclose(queue_t *qp){
	if(qp->front != NULL && qp->back !=NULL){
		void *i;
			for(i=qp->front;i!=NULL;i=i->next){
				free(i->data);
				free(i);
			}
	}
	free(qp);
}

int32_t qput(queue_t *qp,void *elementp){
	if(qp->front==NULL && qp->back=NULL){
		qp->front=elementp;
		qp->back=elementp;
	}
	else{
		back->next=elementp;
		
	}
}

	
