#include<stdio.h>
#include <stdbool.h>
#include<time.h>
#include<windows.h>

bool isStart=0;

const char wep[10][10]= {
	"fits","gun","plane","tank","morto",
	"martoon","tomato","knife","iPad","egg"
};

const char place[9][15]= {
	"empty","man 0's home","man 1's home",
	"market 1","market 2","street 1",
	"street 2","park 1","park 2", 
};

struct model {
	unsigned short has;
	unsigned short loca;
	unsigned short situ;
	bool aim;
	bool isBe;
} man[2];


bool chos() {
	srand(0/*time(NULL)*/);
	return rand()%2;
}

void p(int n) {
	int m;
	for(m=0; m<n; m++) {
		printf(" ");
	}
}

void stay(){
	printf("--------------------------------\n");
	printf("we will stay for two seconds. . .\n");
	Sleep(2000); 
}

int setAc_new(bool ac) {
	////////////////////////////////////////
	unsigned int re=1;
	unsigned short ct=1;
	//system("cls");
	if(isStart==1){
		printf("\n\n\n");
	}else{
		isStart=1;
	}
	pInfo(ac);
	printf("now is man %d's turn\n",ac);
	printf("please choose your action\n\n");
	////////////////////////////////////////
	
	if(man[ac].situ==2 || man[ac].situ==4) {

		printf("1.wake");
		re=1;

	} else if(man[ac].situ==3) {

		printf("1. sleep    ");
		printf("2.jie");
		re=2;

	} else if(man[ac].situ==1) {

		printf("1. move   ");
		re*=10;
		//re=10

		printf("2. sleep  ");
		re+=1;
		re*=10;
		//re=110
		
		ct=3;

		if(man[ac].isBe==1) {
			printf("%d. hide   ",ct++);
			re+=1;
		}
		re*=10;

		if(man[ac].aim==1) {
		    printf("%d. fire   ",ct++);
			re+=1;
		}
		re*=10; 
		
		if(man[ac].loca==3||man[ac].loca==4){
			printf("%d. change ",ct++);
			re+=1;
		}
		re*=10;
		
		if(man[0].loca==man[1].loca){
			printf("%d. bang   ",ct++);
			re+=1;
		}
		re*=10;
		
		if(man[ac].aim==0){
			printf("%d. aim    ",ct++);
			re+=1;
		}
		
	} else {
		printf("wrong!!! -> 110\n");
		return -1;
	}
	
	printf("\n");
	
	return re;

}

void fight_new(){
	//////////////////////////////
	int ac=chos();
	unsigned int re=setAc_new(ac);
	unsigned short b;
	unsigned int a;
	fflush(stdin);
	scanf("%d",&a);
	fflush(stdin);
	//////////////////////////////
	
	////////////////////////////////
	printf("re = %d\n",re);
	if(a>=3){
		unsigned int x,y=re,z=10000;
		for(x=1;x<=4;x++){
			if(y/z%10==0&&a>=x+2){
				a+=1;
				//printf("a++\n");
				z/=10;
			}
		}
	}
	////////////////////////////////
	
	//////////////////////////////////////////////////////////////////
	switch(re){
			
		case 1:
			if(a==1){
				man[ac].situ-=1;
				printf("you are awake\n\n");
			}else{
				printf("wrong input!!\n\n");
			}
			break;
			
		case 2:
			if(a==1){
				man[ac].situ-=2;
				printf("escaped from ropes\n\n");
			}else if(a==2){
				man[ac].situ+=1;
				man[ac].loca=ac;
				man[ac].loca+=1;
				printf("back to bed\n\n");
			}else{
				printf("wrong input!!!\n\n");
			}
			break;
			
		default:
			
			switch(a){
				
				//move
				case 1:
					srand(time(NULL));
					b=rand()%7;
					b+=1;
					if(b==man[ac].loca){
						b*=b;
						b*=b;
						b%=7;
						b+=1;
					}
					man[ac].loca=b;
					man[0].isBe=man[1].isBe=0;
					man[0].aim=man[1].aim=0;
					printf("at %s now\n\n",place[b]);
					break;
					
				//sleep
				case 2:
					man[ac].situ+=1;
					man[ac].aim=0;
					printf("asleep\n\n");
					break;
				
				//hide	
				case 3:
					man[0].isBe=man[1].isBe=0;
					man[0].aim=man[1].aim=0;
					printf("out of aim\n\n");
					break;
				
				//fire	
				case 4:
					if(ac==0){
						man[1].situ=0;
						printf("man 1 died\n\n");
					}else{
						man[0].situ=0;
						printf("has man 0 killed\n\n");
					}
					break;
					
				//change	
				case 5:
					srand(time(NULL));
					b=rand()%10;
					if(b==man[ac].loca){
						b+=1;
						b%=10;
					}
					man[ac].has=b;
					printf("have %s\n\n",wep[b]);
					break;
				
				//bang	
				case 6:
					if(ac==0){
						man[1].situ+=2;
						man[0].isBe=0;
						man[1].aim=0;
						printf("man 1 is trapped\n\n");
					}else{
						man[0].situ+=2;
						man[1].isBe=0;
						man[0].aim=0;
						printf("man 1 is trapped\n\n");
					}
					break;
					
				case 7:
					if(ac==0){
						man[0].aim=1;
						man[1].isBe=1;
						printf("got a man 1\n\n");
					}else{
						man[1].aim=1;
						man[0].isBe=1;
						printf("got a man 0\n\n");
					}
					break;
					
				default :
					printf("tell the developer wrong in fight_new");
					printf(" -> first switch -> second switch\n\n");
					break;
			}
			break;
	}
	//////////////////////////////////////////////////////////////////
	
	//
	stay();
	//
}

int main() {
	
	man[0].has=man[1].has=0;
	man[0].aim=man[1].aim=0;
	man[0].isBe=man[1].isBe=0;
	man[0].situ=man[1].situ=2;
	man[0].loca=1;
	man[1].loca=2;
	//set for start
	
	while(man[0].situ!=0 && man[2].situ!=0) {
		fight_new();
	}
	return 0;
}
