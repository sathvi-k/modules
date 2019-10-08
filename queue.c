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

typedef void queue_t;
typedef struct queue_t;

typedef struct queue_t{
	void *front;
	void *back;
	void *next;
}queue_t;

queue_t* qopen(void){
	                            
 	queue_t *qp;
                                                                                
  if(!(qp=(queue_t*)malloc(sizeof(queue_t)))){                                       
    printf("[Error: malloc failed allocating queue]\n");                          
    return NULL;                                                                
  }                                                                             
                                                                                
  qp->front=NULL;
	qp->back=NULL;
	qp->next=NULL;
  return qp;                                                                     
}

void qclose(queue_t *qp){
	if(qp->front != NULL && qp->back !=NULL){
		void *i
			for(i=qp->front;i!=NULL;i=i->next){
				free(i);
			}
	}
	
}
 

	
