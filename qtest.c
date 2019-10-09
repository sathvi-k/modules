/* qtest.c --- test queue.c
 * 
 * 
 * Author: John B. Kariuki Jr. Hanna, Aya, Sathvika
 * Created: Tue Oct  8 20:40:28 2019 (-0400)
 * Version: 1.0
 * 
 * Description: Test queue.c
 * 
 */
#include <stdint.h>           
#include <stdbool.h>                          
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct car_t{
	int year;
	double price;
}car_t;

static car_t* make_car(int year,double price){
	
  car_t *c;
	
  if(!(c=(car_t*)malloc(sizeof(car_t)))){                                                                                
    printf("[Error: malloc failed allocating element]\n");                                                                 
    return NULL;  
  }                                                                                                                                     
  c->year=year;
	c->price=price;
  return c;                                                                                                      
}                    

int main(void){
	queue_t *qp;
	car_t *car;
	car_t *car1;

	qp=qopen();
	car=make_car(2000,200);
	car1=make_car(2019,1700);
	qput(qp,(void*)car1);
	qput(qp,(void*)car);
	//car_t *rcar=(car_t*)qget(qp);
	//car_t *rcar1=(car_t*)qget(qp);
	//car_t *rcar3=(car_t*)qget(qp);

	//printf("%d\n",rcar->year);
	//printf("%f\n",rcar1->price);
	
	//if(rcar3==NULL){
	//	printf("NULL\n");
	//	}
	
	qclose(qp);

	exit(EXIT_SUCCESS);
}
