/***********************************************************/
/* Programmer: An Dang					   */
/*                                                         */		
/* Program : Cache Simulator                               */
/*                                                         */
/***********************************************************/

#include "globals.h"
#include "cache.h"
#include "check_direct.h"
#include "check_k_way.h"
#include <stdio.h>

int get_index(int address) ;  

int main( int argc, char *argv[] ){
  
  int numlines, k,s,l,i ;
  int choice ;
  // the number of the test addresses
  const int test_num = 39 ; 
  
  
    int test[] = { 0, 4, 8, 12, 16, 20, 24, 28, 32, 
    36, 40, 44, 48, 52, 56, 60, 64, 68, 72,
    76, 80, 0, 4, 8, 12, 16, 71, 3, 41, 
    81, 39, 38, 71, 15, 39, 11, 51, 57, 41 } ;
  
  //hit_miss is a record if each address, when it is checked in cache 
  char* hit_miss[test_num] ;

  printf( "Enter the size of cache (in byte): " ) ;
  scanf("%d", &s ) ;
  printf( "Enter the size of a cache's line (in byte): " ) ;
  scanf("%d", &l ) ;
  
    
  printf( "Choose one of these options: \n" ) ;
  printf(" 1: Direct Map Cache\n 2: Fully Associative Cache\n 3: K-way Associative Cache\n " ) ;
  scanf( " %d" ,&choice ) ;
  
  switch( choice ){
 /*
   a  direct-mapped cache corresponds to
   a 1-way set associative cache (n=1), and a fully associative corresponds
   to a n-way set associative cache with n=s/l, the number of rows (lines) in
   the cache.
 */
        
  case 1:
    check_direct(test, hit_miss, s, l, test_num ) ;
    break ;

  case 2:
    //fully associative has the number of k-way = s / l
    check_k_way(test, hit_miss, (s/l) ,s, l, test_num) ;
    break ;
  case 3:
    printf(" Enter how many k-way this cache has: " ) ;
    scanf( "%d", &k ) ;
    check_k_way(test, hit_miss, k, s, l, test_num ) ;
    break ;

  default:
    printf( "Bye \n " ) ;
    break ;
  }

  for( i = 0 ; i < test_num; i++ ){ 
    printf( "Address: %d \t %s\n", test[i], hit_miss[i]);
  }
  printf("\n\n") ;
  return 0 ;
}
