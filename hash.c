/* 
 * hash.c -- implements a generic hash table as an indexed set of queues.
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
#include "queue.h"

/* 
 * SuperFastHash() -- produces a number between 0 and the tablesize-1.
 * 
 * The following (rather complicated) code, has been taken from Paul
 * Hsieh's website under the terms of the BSD license. It's a hash
 * function used all over the place nowadays, including Google Sparse
 * Hash.
 */
#define get16bits(d) (*((const uint16_t *) (d)))

static uint32_t SuperFastHash (const char *data,int len,uint32_t tablesize) {
  uint32_t hash = len, tmp;
  int rem;
  
  if (len <= 0 || data == NULL)
		return 0;
  rem = len & 3;
  len >>= 2;
  /* Main loop */
  for (;len > 0; len--) {
    hash  += get16bits (data);
    tmp    = (get16bits (data+2) << 11) ^ hash;
    hash   = (hash << 16) ^ tmp;
    data  += 2*sizeof (uint16_t);
    hash  += hash >> 11;
  }
  /* Handle end cases */
  switch (rem) {
  case 3: hash += get16bits (data);
    hash ^= hash << 16;
    hash ^= data[sizeof (uint16_t)] << 18;
    hash += hash >> 11;
    break;
  case 2: hash += get16bits (data);
    hash ^= hash << 11;
    hash += hash >> 17;
    break;
  case 1: hash += *data;
    hash ^= hash << 10;
    hash += hash >> 1;
  }
  /* Force "avalanching" of final 127 bits */
  hash ^= hash << 3;
  hash += hash >> 5;
  hash ^= hash << 4;
  hash += hash >> 17;
  hash ^= hash << 25;
  hash += hash >> 6;
  return hash % tablesize;
}

typedef struct ihashtable_t{
  int size;
	queue_t **qtable;
}ihashtable_t;

/* hopen -- opens a hash table with initial size hsize */
hashtable_t *hopen(uint32_t hsize){
	ihashtable_t *hp;
	queue_t **qpp;
	
  if(!(hp=(ihashtable_t *)malloc(sizeof(ihashtable_t)))){                               
    printf("[Error: malloc failed allocating hashtable]\n");                        
    return NULL;                                                                
  }
	
	if(!(qpp=(queue_t**)calloc(hsize,sizeof(queue_t*)))){
    printf("[Error: malloc failed allocating memory]\n");    
    return NULL;
	}
  
	for(int i=0;i<hsize;i++){
		queue_t *qp=qopen();
		//hp->qtable[i]=(*qpp);
		qpp[i]=qp;
	}
	
	hp->qtable=qpp;
	hp->size=hsize;

	hashtable_t* ht=(hashtable_t*)hp;
  return ht;       
}

/* hclose -- closes a hash table */ 
void hclose(hashtable_t *htp){
	ihashtable_t *ihtp=(ihashtable_t*)htp;
	int s=ihtp->size;
	for(int i=0; i<s;i++){
		if((ihtp->qtable[i])!=NULL){
			printf("pointers of hashtable are NOT null");
		}
		//printf("freed:%p\n",ihtp->qtable[i]->);
		queue_t **queue=ihtp->qtable[i];
		//printf("hello");
		queue_t *qp=(*queue);
		if(qp==NULL){
			printf("qp is NULL");
		}
		qclose(qp);
	}
	free(ihtp->qtable);
	free(ihtp);
}

/* hput -- puts an entry into a hash table under designated key
 * returns 0 for success; non-zero otherwise
 */
int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen){
	
	ihashtable_t *ihtp=(ihashtable_t *)htp;
	uint32_t loc=SuperFastHash(key,keylen,(ihtp->size));

	//printf("loc:%u",loc);
	queue_t **qp1=ihtp->qtable[loc];
	//	printf("3location:%p\n",ihtp->qtable[1]);
	qput(qp1,ep);
	return 0;
	
}
                                                                                                                                
/* happly -- applies a function to every entry in hash table*/
void happly(hashtable_t *htp, void (*fn)(void* ep)){
	ihashtable_t *ihtp=(ihashtable_t *)htp;
	for(int i=0; i<(ihtp->size);i++){                                       
    qapply(ihtp->qtable[i],fn);
  }  
}                                                                                     
                                                                                                                                         
/* hsearch -- searchs for an entry under a designated key using a                                                                        
 * designated search fn -- returns a pointer to the entry or NULL if                                                                     
 * not found                                                                                                                             
 */                                                                                                                                      
//void *hsearch(hashtable_t *htp,                                                                                                          
//      bool (*searchfn)(void* elementp, const void* searchkeyp),                                                                        
//      const char *key,                                                                                                                 
//       int32_t keylen);                                                                                                                 
                                                                                                                                         
/* hremove -- removes and returns an entry under a designated key                                                                        
 * using a designated search fn -- returns a pointer to the entry or                                                                     
 * NULL if not found                                                                                                                     
 */                                                                                                                                      
//void *hremove(hashtable_t *htp,                                                                     
//      bool (*searchfn)(void* elementp, const void* searchkeyp),
//const char *key,
				//      int32_t keylen); 
