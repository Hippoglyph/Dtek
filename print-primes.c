/*
 print-prime.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.

THIS CODE IS WRITTEN BY JONATHAN RINNARV VII
*/


#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

int currentColum = 0;

void print_numbers(int n){
	printf("%10d ", n);
	currentColum++;
	if(currentColum >= COLUMNS){
		printf("\n");
		currentColum = 0;	
	}
}


void print_primes(int n){
	int i = 2;
	for(i; i<=n;i++){
		if(is_prime(i))
			print_numbers(i);
	}
	printf("\n");
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]){
  if(argc == 2)
    print_primes(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}

int is_prime(int n){
  if(n <= 1)
	  return 0;
  if(n == 2)
	return 1;
  int loop = 2;
  while (n % loop != 0){
	  if(loop*loop > n)
		  return 1;
	  loop++;
  }
  return 0;
}

 
