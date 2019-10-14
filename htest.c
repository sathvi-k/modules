/* htest.c --- test the hash.c module
 * 
 * 
 * Author: John B. Kariuki Jr. Hanna , Aya , Sathvika
 * Created: Sat Oct 12 16:33:53 2019 (-0400)
 * Version: 1.0
 * 
 * Description: test if the hash.c module thoroughly 
 * 
 */

#include <stdint.h>
#include <stdbool.h>                                                                                                                   
#include <stdlib.h>
#include <stdio.h>                                                                                                                     
#include "hash.h"                                                                                                                      
#include "queue.h"
#include <string.h>

typedef struct car_t{                                                           
  int year;                                                                     
  double price;

	char* plate;
	
}car_t;                                                                         
                                                                                
static car_t* make_car(int year,double price, char* plate){                                                                                                                  
  car_t *c;                                                                                                                                                     
  if(!(c=(car_t*)malloc(sizeof(car_t)))){                                                                                                                   
    printf("[Error: malloc failed allocating element]\n");                                                                                                   
    return NULL;                                                                
  }                                                                                                                                                        
  c->year=year;                                                                 
  c->price=price;
	c->plate= plate;
  return c;                                                                                                                                              
}

void print_anything(void *elementp){                                            
  car_t *cp1=(car_t*)elementp;                                                  
  printf("this is the cars year %d\n", cp1->year);                            
}                                                                               
int main(void){

	car_t *car;                                                                   
  car_t *car1;                                                                  
  car_t *car2;                                                                  
  car_t *car3;                                                                  
  car_t *car4;                                                                 

	car=make_car(2000,200, "FIRST");                                                       
  car1=make_car(2019,1700, "SECOND");                                                     
  car2=make_car(2000,200, "THIRD");
	car3=make_car(2003,500, "FOUR" );                                                      
  car4=make_car(2009,100, "FIVE");                                                     
	/*	int a = 11;
	int b = 11;
	int c = 7;
	int d = 1;
	int e = 10;*/

	const char ca = (const char) (car->year);
	const char cb = (const char) (car1->year);
	const char cc = (const char) (car2->year);
	const char cd = (const char) (car3->year);
	const char ce = (const char) (car4->year); 

	hashtable_t *ht = hopen(6);
	int32_t resa = hput(ht,(void*)&car,&ca,sizeof(car));
	int32_t resb = hput(ht,(void*)&car1,&cb,sizeof(car1));
	int32_t resc = hput(ht,(void*)&car2,&cc,sizeof(car2));
	int32_t resd = hput(ht,(void*)&car3,&cd,sizeof(car3));
	int32_t rese = hput(ht,(void*)&car4,&ce,sizeof(car4));
	happly(ht,print_anything);
	hclose(ht);
	
	if (resa==0 && resb==0 && resc==0 && resd==0 && rese==0) {
		printf("SUCCESS!!!!!!!\n");
		exit(EXIT_SUCCESS);
	}
	
	else if(resa!=0){
		printf("problem is with a");
	}

	else if(resb!=0){
		printf("problem is with b");
	}

	else if(resc!=0){
		printf("problem is with c");
	}

	else if(resd!=0){
		printf("problem is with d");
	}

	else if(rese!=0){
		printf("problem is with e");
		}



	
}
