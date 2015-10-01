#include <stdio.h>

void switchSomeBits(){
	int x = 0x011110;
	//00000001000100010001000
	int y = 0x0F;
	int z = 0xFFFFFFFF;
	printf("x=0x%x y=0x%x z=0x%x ",x,y,z);
	printf("\n");
	/*
	x = x >> 13;	//Remove least 13 bits
	x = x & 0x1f;	//Take the least 5 bits
	printf("x=0x%x\n", x);	
	printf("z=0x%x\n", z);
	z = z & ~(0x1f);	//Clears the least 5 bits
	printf("z=0x%x\n", z);
	z = z | x;		//Merges x and z
	printf("z=0x%x\n", z);
	y = y & 0x7;	//Takes the least 3 bits
	printf("y=0x%x\n", y);
	z = z & ~(0xe0);	//Clears bit indx 7,6 and 5
	printf("z=0x%x\n", z);
	y = y << 5;		//Addes 5 zeros to y
	printf("y=0x%x\n", y);
	z = z | y;		//Merges z and y
	printf("z=0x%x\n", z);
	*/
	printf("x=0x%08x\n", (x>>13)&(0x1f) );
	printf("y=0x%08x\n", (y&(0x07))<< 5 );
	z = (((z&~(0x1f))|(((x>>13)&0x1f)))&~(0xe0))|((y&0x7)<<5);
	printf("z=0x%x\n", z);
}

int main(int argc, char *argv[]){
	switchSomeBits();
}