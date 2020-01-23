#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void accident(void){
	printf("something dangerours happened just now\n");
	printf("and we are sorry to tell you that "
	"this game have to be stopped in 3 seconds\n");
	
	Sleep(3000);
	exit(0);
	printf("accident\n");
}

int main(void){
	printf("before accident\1\n\n");
	accident();
	printf("after\n");
	return 0;
}
