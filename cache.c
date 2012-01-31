/******************************************/
/* Cache.c                                */
/******************************************/

#include "cache.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int find_expt( int num ) ;
// evict_cache will pop the first item
// which is the earliest cache'line got written 
// it will reset the line's valid bit to 0
status evict_cache( line cache[], queue *p_Q ){
  int index ;
  pop_int( p_Q , &index ) ;
  cache[index].valid = 0 ;
  cache[index].tag = -1 ;
  return OK ;
}

// cache is full if all line 's valid fields are 1
bool cache_full ( line cache[], int numlines ) {
  int i ;
  int flag ;
  for ( i = 0 ; i < numlines ; i++ )
    if ( cache[i].valid == 0 )
      return FALSE ;

  return TRUE ;
}
//init_cache will place 0s in all cache'lines' fields
void init_cache( line cache[], int numlines ){
  int i ;
    
  for( i = 0; i < numlines; i++ ){
    cache[i].valid = 0 ;
    cache[i].tag = -1 ;
  }
 
  return ; 
}  
// get_tag_index will break down the given address to its tag and index(block) fields
status get_tag_index(unsigned int *p_tag, unsigned int *p_index , int a, int l, int numlines ){

  int offset_size ,index_size ,tag_size ;
  unsigned int temp1 ;
  
  offset_size = find_expt( l ) ;
  index_size = find_expt( numlines ) ;
  tag_size = 8 - offset_size - index_size ;
  
  temp1 = a << (32 - 8 + tag_size) ;
  *p_index = temp1 >> ( 32 - index_size ) ;
  *p_tag = a >> ( index_size + offset_size ) ;
  return OK ;

}

// find_expt will find a in function : 2^a = number
int find_expt( int num ){
  
  int i ;
  for ( i = 0 ; i < MAXLINES; i++ ){
    if( num == pow ( 2, (double) i ) )
      break ;
  }
  return i ; 
}



