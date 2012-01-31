/**************************************/
/* Check_Direct.c                     */        
/**************************************/


#include "check_direct.h"

status check_direct(int test[], char* hit_miss[] , int s ,int l, int test_num ){
  int i, j ;
  int numlines ;
  unsigned int new_tag, index ;
  queue Q ;

  numlines= s / l ;
  line cache[MAXLINES] ;
  // initialize the cache and the queue
  // the queue will store the index of the cache line
  // which has its valid field changed from 0 to 1
  init_cache ( cache, numlines ) ;
  init_queue ( &Q ) ;

  for ( i = 0 ; i < test_num; i++ ){
    if( cache_full( cache, numlines ) == TRUE )
      evict_cache( cache , &Q ) ;
    get_tag_index ( &new_tag, &index, test[i], l, numlines ) ;

    if( cache[index].valid == 1 &&  cache[index].tag == new_tag )
      hit_miss[i] = "HIT" ;
    else{
      hit_miss[i] = "MISS" ;
      cache[index].tag = new_tag ;
      if ( cache[index].valid == 0 ){
        push_int( &Q, index ) ;
      }
      cache[index].valid = 1 ;
    }
  }
  return OK ;
}
