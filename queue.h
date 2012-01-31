/******************************************************/
/*                                                    */
/* queue.h                                            */
/*                                                    */
/******************************************************/

#ifndef _queue

#define _queue

#include "list.h"
#include "globals.h"

typedef list queue ;
extern status init_queue( queue *p_Q ) ;
extern bool empty_queue( queue *p_Q ) ;
extern status push( queue *p_Q, generic_ptr data ) ;
extern status pop( queue *p_Q, generic_ptr *data ) ;

#endif
