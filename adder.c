#include <stdio.h>

void adder(const int *x, const int *y, int *z){
	*z = *x + *y;
}

void foo(int a){
	const int k = 10;
	int z = 0;
	adder(&a,&k,&z);
	printf("%d\n", z);
}

int main(int argc, char *argv[]){
  if(argc == 2)
    foo(atoi(argv[1]));
  else
    printf("Please state an interger number.\n");
  return 0;
}