/*
 prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
 
 Assignment code written by Fredrik Hyyrynen
*/


#include <stdio.h>

int is_prime(int n){
  if(n <= 1)
	  return 0;
  int loop = 2;
  do{
	  if(loop*loop > n)
		  return 1;
	  loop++;
  }while (n % loop != 0);
  return 0;
}

int main(void){
  printf("%d\n", is_prime(11));  // 11 is a prime.      Should print 1.
  printf("%d\n", is_prime(383)); // 383 is a prime.     Should print 1.
  printf("%d\n", is_prime(987)); // 987 is not a prime. Should print 0.
}
