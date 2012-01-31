/********************************************/
/* Programmer: An Dang			    */
/*                                          */
/* Program : queue_interface.c              */  
/********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "queue_interface.h"


status push_int( queue *p_Q, int i ){
  
  int *p_I = (int *) malloc( sizeof( int ) ) ;  
  if ( p_I == NULL )
    return ERROR ;
  
  *p_I = i ;
  
  if ( push( p_Q, (generic_ptr) p_I ) == ERROR){
    free ( p_I ) ;
    return ERROR ;
  }
  
  return OK ;
}

status pop_int( queue *p_Q, int *p_I ){
 
  int *p_data ;
  if ( pop ( p_Q, ( generic_ptr * ) &p_data ) == ERROR ) return ERROR ;
  
  *p_I = *p_data ;
  free ( p_data ) ;
  return OK ;
}





