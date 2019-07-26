#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include <stdbool.h>

#define places (8)

int part=0;

//which wepon
const char wep[10][10]= {
	"fits","gun","plane","tank","morto",
	"martoon","tomato","knife","iPad","egg"
};

struct model {
	unsigned short has;
	unsigned short loca;
	unsigned short situ;
	bool aim;
	bool isBe;
} man[2];

bool chos() {
	srand(time(NULL));
	if(rand()%2) {
		return 0;
	} else {
		return 1;
	}
}

void p(int n) {
	int m;
	for(m=0; m<n; m++) {
		printf(" ");
	}
}

int setAc(bool ac) {
	unsigned short  re;
	if(man[ac].situ==2 || man[ac].situ==4) {
		printf("1.wake");
		re=0;
		return re;
	} else if(man[ac].situ==3) {
		printf("1.slee");
		p(14);
		printf("2.jie");
		re=1;
		return re;
	} else if(man[ac].situ==1) {
		printf("1.move");
		p(14);
		if(man[ac].isBe==1) {
			if(man[ac].aim==1) {
				if(man[ac].loca==5) {
					printf("2.hide");
					p(12);
					printf("3.fire");
					p(14);
					printf("4.change");
					re=2;
					return re;
				} else {
					printf("2.hide");
					p(14);
					printf("3.fire");
					re=3;
					return re;
				}
			} else {
				if(man[ac].loca==5) {
					printf("2.hide");
					p(12);
					printf("3.aim");
					p(14);
					printf("4.change");
					re=4;
					return re;
				} else {
					printf("2.hide");
					p(14);
					printf("3.aim");
					re=5;
					return re;
				}
			}
		} else {//wei bei m
			if(man[ac].aim==1) {
				if(man[ac].loca==5) {
					printf("2.fire");
					p(14);
					printf("3.change");
					re=6;
					return re;
				} else {
					printf("2.fire");
					re=7;
					return re;
				}
			} else {
				if(man[ac].loca==5){
					printf("2.aim");
					p(15);
					printf("3.change");
					re=8;
					return re;
				}else{
					printf("2.aim");
					re=9;
					return re;
				}
			}
		}
	}
}

void fight() {
	
	int ac=chos();
	int i = setAc(ac);
	
	char a;
	scanf("%c",&a);
	fflush(stdin);
	
	switch(i){
		case 0:
			if(a==1){
				man[ac].situ-=1;
				printf("you are awake now\n");
			}else{
				printf("a wrong input!!!\n");
			}
			break;
		case 1:
			if(a==1){
				man[ac].situ-=2;
				printf("you are free now\n");
			}else{
				printf("a wrong input!!!\n");
			}
			break;
		case 2:
			switch(a){
				case 1:
					srand(time(NULL));
					int b;
					b=rand()%places;
					b+=1;
					for(;;){
						if(b==man[ac].loca){
							b*=b;
							b%=places;
							b+=1;
						}else{
							break;
						}
					}
					man[ac].loca=b;
					printf("place No. %d\n",b);
					break;
				case 2:
					if(ac==0){
						man[1].aim=0;
					}else{
						man[0].aim=0;
					}
					printf("safe\n");
					break;
				case 3:
					
					if(ac==0){
						man[1].situ=0;
						printf("man 1 died\n");
					}else{
						man[0].aim=0;
						printf("man 2 died\n");
					}
					break;
				case 4:
					int b;
					srand(time(NULL));
					b=rand()%10;
					b+=1;
					for(;;){
						if(b==man[ac].has){
							b*=b;
							b%=10;
							b+=1;
						}else{
							break;
						}
					}
					printf("wepon No.%d\n",b);
					break;
				default:
					printf("a wrong input!!!\n");
					break;
			}
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		default:
			printf("something wrong in fight() > first switch\n");
			break;
	}
	
}

int main() {
	
	man[0].has=man[1].has=0;
	man[0].aim=man[1].aim=0;
	man[0].isBe=man[1].isBe=0;
	man[0].situ=man[1].situ=1;
	man[0].loca=1;
	man[1].loca=2;
	//set for start
	
	while(man[0].situ!=0 && man[2].situ!=0) {
		fight();
	}
	
	return 0;
}
