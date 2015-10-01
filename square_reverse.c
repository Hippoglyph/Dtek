#include <stdio.h>

void square(const double* x,double* y, int len){
	int i = 0;
	for(i;i<len;i++){
		*(y+len-1-i) = *(x+i)**(x+i);
	}
}


void test(){
	int len = 3;
	double in[] = {11.0, 20.0, 100.0};
	double out[3];
	square(in,out,3);
	printf("[");
	int i = 0;
	for(i;i<len;i++){
		printf("%f,", out[i]);
	}
	printf("]\n");
}

int main(int argc, char *argv[]){
  test();
}