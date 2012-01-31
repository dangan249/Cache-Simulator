/******************************************************/
/*                                                    */
/* queue_interface.h                                  */
/*                                                    */
/******************************************************/

#ifndef _queue_interface

#define _queue_interface
#include "globals.h"
#include "queue.h"

extern status push_int( queue *p_Q, int i ) ;
extern status pop_int( queue *p_Q, int *p_I ) ;

#endif
