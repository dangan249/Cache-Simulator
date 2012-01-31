/***************************************************/
/* Programmer: An Dang			           */
/*                                                 */
/* Program : list.c                                */
/***************************************************/

#include "globals.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

status allocate_node( list *p_L, generic_ptr data ) ;
void free_node( list *p_L ) ;

// allocating the space for a node
status allocate_node( list *p_L, generic_ptr data ){

  list L = (list) malloc( sizeof( node ) ) ;
  if ( L == NULL ) return ERROR ;
  
  DATA(L) = data ;
  NEXT(L) = NULL ;
  
  *p_L = L ;

  return OK ;
}

// free the allocated space
void free_node( list *p_L ){
  free( *p_L );
  *p_L = NULL ;
}

//initializw the poiter to NULL
status init_list( list *p_L ){
  *p_L = NULL ;
  return OK ;
}

//check whether is empty or not
bool empty_list( list L ){
  return ( L == NULL ) ? TRUE : FALSE ;
}

//insert : add item to the head of the list
status insert( list *p_L, generic_ptr data ){
  list L ;
  if ( allocate_node( &L, data ) == ERROR )
    return ERROR ;
  NEXT(L) = *p_L ;
  return OK ;
}

//append: add item to the tail of the list
status append( list *p_List, generic_ptr data ){
  
  list L, tmplist ;
  if ( allocate_node( &L, data ) == ERROR )
    return ERROR ;
  
  if( empty_list( *p_List ) == TRUE )
    *p_List = L ;
  else {
    for ( tmplist = *p_List; NEXT(tmplist) != NULL; tmplist = NEXT(tmplist) );
    NEXT(tmplist) = L ;
  }
  return OK ;
}

//delete the list's node, and free the space
status delete_node( list *p_L, list node ){
  if( empty_list( *p_L ) == TRUE )
    return ERROR ;
  if( *p_L == node )
    *p_L = NEXT(*p_L) ;
  else{
    list L ;
    for( L = *p_L; L != NULL && NEXT(L) != node; L = NEXT(L) ) ;
    
    if( L == NULL )
      return ERROR ;
    else 
      NEXT( L ) = NEXT( node ) ;
  }
  free_node( &node ) ;
  return OK ;
}

//delete the first item of the list, 
//give back the pointer to the deleted data 
status delete( list *p_L, generic_ptr *p_data ){
   if( empty_list( *p_L ) )
     return ERROR ;
   *p_data = DATA( *p_L ) ;
   return delete_node( p_L, *p_L ) ;
 }

status traverse( list L, status (*p_func_f) () ){
  if( empty_list( L ) )
    return OK ;
  if( (*p_func_f) ( DATA(L) ) == ERROR )
    return ERROR ;
  else
    return traverse( NEXT(L), p_func_f ) ;
}

status find_key( list L, generic_ptr key, int( *p_cmp_f ) (), list *p_keynode ){
  list curr = NULL ;
  
  while( ( curr = list_iterator( L, curr ) ) != NULL ){
    if( (*p_cmp_f)( key, DATA(curr) ) == 0 ){
      *p_keynode = curr ;
      return OK;
    }
  }
  return ERROR ;
}

list list_iterator( list L, list lastreturn ){
  return ( lastreturn == NULL ) ? L : NEXT(lastreturn) ;
}

status destroy( list *p_L, void (*p_func_f) () ){
  if( empty_list( *p_L ) == FALSE ){
    destroy( &NEXT(*p_L), p_func_f ) ;
    if( p_func_f != NULL )
      ( *p_func_f ) ( DATA(*p_L) ) ;
    free_node( p_L ) ;
  }
  return OK ;
}

bool is_equal( list L1, list L2, int (*p_cmp_func) () ){

  if( L1 == NULL && L2 == NULL ) return TRUE ;
  if( L1 == NULL && L2 != NULL ) return FALSE ;
  if( L1 != NULL && L2 == NULL ) return FALSE ;

  return (!(*p_cmp_func)( DATA(L1), DATA(L2) ) ) &&
    is_equal( NEXT(L1), NEXT(L2), p_cmp_func ) ;
}

bool set_equal( list L1, list L2, int (*p_cmp_func) () ){
  
  list match ;
  list lastreturn ;
  
  is_equal( L1, L2, p_cmp_func ) ;
  lastreturn = NULL ;
  while( ( lastreturn = list_iterator( L1, lastreturn ) ) != NULL ){
    if( find_key( L2, DATA(lastreturn), p_cmp_func, &match ) == ERROR )
      return FALSE ;
  }
  while( ( lastreturn = list_iterator( L1, lastreturn ) ) != NULL ){
     if( find_key( L2, DATA(lastreturn), p_cmp_func, &match ) == ERROR )
       return FALSE ;
  }
  return TRUE ;
}
