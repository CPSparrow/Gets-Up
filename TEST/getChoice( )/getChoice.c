//  getChoice.c
//  copyright @ Handsome Coder Studio, 2020

//  remain question :
//  not solve a input like 1234abcd succcessfully

#include<stdio.h>

#define QUIT -1

#define GAME 1

#define INTRODUCE 2

#define CHANGE_COLOR 3

#define TOO_MUCH "too much wrong input"

#define TYPE_A_INT "please type a proper int like 1 or 2"

/*/////////////////////////////////////////////////
///////these above are which is OK now.////////////
/////////////////////////////////////////////////*/

void clean(void){
	while(getchar()!='\n'){
        continue;
	}
}

int new_getchoice(void){
	unsigned short times=0;
	while(1){
		if(10==times){
			printf("quit successfully\n");
			return QUIT;
		}else if(0<=times&&10>times){
			times++;
			const char first = getchar();
			if('\n'==first){
				times--;
				continue;
			}
			const char second = getchar();
			if('\n'==second){
				switch(first){
					case '0'+GAME:
						return GAME;
						//break;
					case '0'+INTRODUCE:
						return INTRODUCE;
					case 'C':
						return CHANGE_COLOR;
					case 'q':
					case 'Q':
						return QUIT;
					default:
						//clean();
						printf("%s\n",TYPE_A_INT);
						break;
				}
			}else{
				clean();
				printf("%s\n",TYPE_A_INT);
			}
		}else{
			printf("DATA_CHANGED(times)\n");
		}
	}
}

int main(void){
	while(1){
		printf("get a return = %d\n",new_getchoice());
	}
	return 0;
}

