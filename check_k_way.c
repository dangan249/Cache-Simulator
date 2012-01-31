/***************************************************/
/* check_k_way.c                                   */
/***************************************************/

#include "check_k_way.h"
#include <stdio.h>
status check_k_way( int test[], char* hit_miss[], int k, int s , int l, int test_num ){

  int i, j, a ,numlines ;
  unsigned int new_tag, block ;
  int flag ;
  line cache [MAXLINES] ;
  queue Q1 ;
  queue block_array[MAXLINES] ;
  int evict_index ;
  //initialize all of the pointers in block_array to NULL
  // the index of block_array correspond the block number
  for( i = 0 ; i < MAXLINES; i++ )
    init_queue ( &(block_array[i]) ) ;
  
  numlines= s / l ;
  //initialize the cache
  init_cache( cache, numlines ) ;
  init_queue( &Q1 ) ;
  
  for ( i = 0 ; i < test_num; i++ ){
    if( cache_full( cache, numlines ) == TRUE )
      evict_cache( cache, &Q1 ) ;
    
    //get the block number
    if ( k == numlines )
      get_tag_index ( &new_tag, &block, test[i], l, numlines ) ; // fully associative case  
    else
      get_tag_index ( &new_tag, &block, test[i], l, numlines/k ) ;  //k-way case
    
    // go through the chosen block and compare the new_tag
    // with the k tags in each block      
    flag = 0 ;
    
    // block * k will give the correct starting index     
    // the loop will iterate k times
    for ( a = 0 ; a < k ; a++ ){
      j = block * k + a ;
      if ( cache[j].valid == 1 && cache[j].tag == new_tag ){
        flag = 1 ;
        break ;
      }
    }
    
    if ( flag == 1 )
      hit_miss[i] = "HIT" ;
    else{
      hit_miss[i] = "MISS" ;
      
      // save the new_tag in the first found cache in that block
      // that has valid = 0      
      flag = 0 ;
      // if flag never get changed to 1 
      // we are in the case that all lines in the block have valid bits = 1
      // but the current tags are not = new_tag
      for ( a = 0 ; a  <  k ; a++ ){

        j = block * k + a ;
	if ( cache[ j ].valid == 0 ){
	  flag = 1 ; 
	  cache[j].tag = new_tag ;
          cache[j].valid = 1 ;
          // push the index of the cache's line to the queue
          push_int( &Q1 , j ) ;
	  push_int( &(block_array[block]), j ) ; 
	  break ;
        }
      }

      // overide a line in the block with first in first out strategy
      if (flag == 0 ){
	pop_int( &(block_array[block]), &evict_index ) ;
	cache[evict_index].tag = new_tag ;
	cache[evict_index].valid = 1 ;
      }
      
    }
  }
  return OK ;
}
