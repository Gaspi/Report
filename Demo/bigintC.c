// ---------------------------------------------
//        C file generated from bigint.pvs
// ---------------------------------------------
//   Make sure to link GC.c and GMP in compilation:
//      gcc -O3 -o bigint bigint.c GC.c -lgmp
//      ./bigint
// ---------------------------------------------

#include<stdio.h>
#include<gmp.h>
#include "GC.h"
#include "bigint.h"

#define TRUE 1
#define FALSE 0

int main(void) {
  GC_start();
  printf("Executing bigint ...\n");
  // Insert code here
  int n = 100;
  mpz_t f;
  mpz_init(f);
  pvs_fibo_d715(f, n);
  printf("fibo(%i) = %s\n", n, mpz_get_str(NULL, 10, f) );
  mpz_clear(f);
  GC_quit();
  return 0;
}


void pvs_Fib0618(mpz_t result, int x) {
  mpz_set_si(result, (long) x);
}

void pvs_Fib0_d619(mpz_t result, int x) {
  mpz_set_si(result, (long) x);
}

void pvs_fiborec620(mpz_t result, mpz_t* A, int n) {
  if ((n == 0)) {
    mpz_set(result, A[1]);
    if( GC_count( A ) == 1 ) {
      int i722;
      for(i722 = 0; i722 < 2; i722++) {
        mpz_clear(A[i722]);
      }
    }
    GC_free(A);
  } else {
    mpz_t res623;
    mpz_init( res623 );
    mpz_set(res623, A[1]);
    mpz_t res625;
    mpz_init( res625 );
    mpz_add( res625 , A[0] , A[1] );
    mpz_t* aux626;
    if ( GC_count( A ) == 1 )
      aux626 = A;
    else {
      aux626 = GC_malloc(2, sizeof(mpz_t) );
      int i723;
      for(i723 = 0; i723 < 2; i723++) {
        mpz_init( aux626[i723] );
        mpz_set(aux626[i723], A[i723]);
      }
    }
    mpz_set(aux626[0], res623);
    mpz_set(aux626[1], res625);
    mpz_clear(res623);
    mpz_clear(res625);
    pvs_fiborec_d621( result , aux626 , (n - 1) );
  }
}

void pvs_fiborec_d621(mpz_t result, mpz_t* A, int n) {
  if ((n == 0)) {
    mpz_set(result, A[1]);
    if( GC_count( A ) == 1 ) {
      int i724;
      for(i724 = 0; i724 < 2; i724++) {
        mpz_clear(A[i724]);
      }
    }
    GC_free(A);
  } else {
    mpz_t res628;
    mpz_init( res628 );
    mpz_set(res628, A[1]);
    mpz_t res630;
    mpz_init( res630 );
    mpz_add( res630 , A[0] , A[1] );
    mpz_set(A[0], res628);
    mpz_set(A[1], res630);
    mpz_clear(res628);
    mpz_clear(res630);
    pvs_fiborec_d621( result , A , (n - 1) );
  }
}

mpz_t* pvs_succes692(mpz_t* A) {
  mpz_t res695;
  mpz_init( res695 );
  mpz_set(res695, A[1]);
  mpz_t res697;
  mpz_init( res697 );
  mpz_add( res697 , A[0] , A[1] );
  mpz_t* result;
  if ( GC_count( A ) == 1 )
    result = A;
  else {
    result = GC_malloc(2, sizeof(mpz_t) );
    int i725;
    for(i725 = 0; i725 < 2; i725++) {
      mpz_init( result[i725] );
      mpz_set(result[i725], A[i725]);
    }
  }
  mpz_set(result[0], res695);
  mpz_set(result[1], res697);
  mpz_clear(res695);
  mpz_clear(res697);
  return result;
}

mpz_t* pvs_succes_d693(mpz_t* A) {
  mpz_t res699;
  mpz_init( res699 );
  mpz_set(res699, A[1]);
  mpz_t res701;
  mpz_init( res701 );
  mpz_add( res701 , A[0] , A[1] );
  mpz_set(A[0], res699);
  mpz_set(A[1], res701);
  mpz_clear(res699);
  mpz_clear(res701);
  return A;
}

void pvs_fibo714(mpz_t result, int n) {
  mpz_t* aux717;
  aux717 = GC_malloc(2, sizeof(mpz_t) );
  int i716;
  for(i716 = 0; i716 < 2; i716++) {
    mpz_init( aux717[i716] );
    pvs_Fib0_d619( aux717[i716] , i716 );
  }
  pvs_fiborec_d621( result , aux717 , n );
}

void pvs_fibo_d715(mpz_t result, int n) {
  mpz_t* aux719;
  aux719 = GC_malloc(2, sizeof(mpz_t) );
  int i718;
  for(i718 = 0; i718 < 2; i718++) {
    mpz_init( aux719[i718] );
    pvs_Fib0_d619( aux719[i718] , i718 );
  }
  pvs_fiborec_d621( result , aux719 , n );
}
