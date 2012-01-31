/****************************************************/
/*                                                  */
/* queue.c                                          */
/****************************************************/

#include "globals.h"
#include "list.h"
#include "queue.h"


status init_queue( queue *p_Q ){
  
  return init_list( p_Q ) ;

}

bool empty_queue( queue *p_Q ){

  return empty_list( *p_Q ) ;

}

// append the new item into the tail of the list
status push( queue *p_Q, generic_ptr data ){

  return append( p_Q, data ) ;

}

// pop item at the head of the list
// which is the first item 
status pop( queue *p_Q, generic_ptr *data ){
    return delete( p_Q, data ) ;

}



