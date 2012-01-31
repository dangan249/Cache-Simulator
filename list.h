/******************************************************/
/*                                                    */
/* list.h                                             */
/*                                                    */
/******************************************************/

#ifndef _list

#define _list

#include "globals.h"
typedef struct node node, *list ;

struct node{
  generic_ptr datapointer ;
  list next ;
} ;

extern status init_list( list *p_L ) ;
extern bool empty_list( list L ) ;
extern status append( list *p_L, generic_ptr data ) ;
extern status insert( list *p_L, generic_ptr data ) ;
extern status delete( list *p_L, generic_ptr *p_data ) ;
extern status traverse( list L, status( *p_func_f ) () ) ;
extern status find_key( list L, generic_ptr key, int ( *p_cmp_f ) () , list *p_keynode ) ;
extern list list_iterator( list L, list lastreturn ) ;
extern status destroy( list *p_L, void (*p_func_f) () ) ;
extern bool is_equal( list L1, list L2, int (*p_cmp_func) () ) ;
extern bool set_equal( list L1, list L2, int (*p_cmp_func) () ) ;

#endif
