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


int main(void){

	int a = 11;
	int b = 11;
	int c = 7;
	int d = 1;
	int e = 10;

	const char ca = (const char)a;
	const char cb = (const char)b;
	const char cc = (const char)c;
	const char cd = (const char)d;
	const char ce = (const char)e;

	hashtable_t *ht = hopen(20);
	int32_t resa = hput(ht,(void*)&a,&ca,sizeof(ca));
	int32_t resb = hput(ht,(void*)&b,&cb,sizeof(cb));
	int32_t resc = hput(ht,(void*)&c,&cc,sizeof(cc));
	int32_t resd = hput(ht,(void*)&d,&cd,sizeof(cd));
	int32_t rese = hput(ht,(void*)&e,&ce,sizeof(ce));
	
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
