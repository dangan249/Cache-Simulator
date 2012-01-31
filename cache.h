/****************************************/
/* cache.h                              */
/****************************************/

#ifndef _cache
#define _cache
#include "globals.h"
#include "queue.h"
typedef struct line line ;
struct line{
  int valid ;
  int tag ;
} ;


extern void init_cache(line cache[], int numlines) ;
extern bool cache_full ( line cache[], int numlines ) ;
extern status get_tag_index ( unsigned int *p_tag, unsigned int *p_index , int address, int l, int numlines) ;
extern int find_expt( int num ) ;
extern status evict_cache( line cache[], queue *p_Q ) ;
extern bool cache_full ( line cache[], int numlines ) ;

#endif 
