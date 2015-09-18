/*
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

void print_sieves(int n){
	int start = 2;
	int *marked = malloc((n-start)*sizeof(int));
	int j = 0;
	for(j;j<(n-start);j++){
		marked[j] = 0;
	}
	int i = start;
	for(i;i <= n;i++ ){
		if(marked[i-start] == 1)
			continue;
		else
			print_numbers(i);
		int j = 1;
		while(i*j <= n){
			marked[i*j-start] = 1;
			j++;
		}
	}
	free(marked);
	printf("\n");
}

int main(int argc, char *argv[]){
  if(argc == 2)
    print_sieves(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}