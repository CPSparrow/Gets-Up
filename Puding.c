#include<stdio.h>
#include <stdbool.h>
#include<time.h>
#include<windows.h>

bool isStart=0;

//which wepon
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

void stay(){
	printf("\n\n");
	printf("--------------------------------\n");
	printf("请按任意键继续. . .");
}

void pInfo(){
	printf("man 0 has a %s",wep[man[0].has]);
	p(19);
	printf("man 1 has a %s\n",wep[man[1].has]);
	
	printf("man 0 is now at %s",place[man[0].loca]);
	p(7);
	printf("man 1 is now at %s\n",place[man[1].loca]);
	
	switch(man[0].situ){
		case 1:
			printf("man 0 is normol");
			break;
		case 2:
	 		printf("man 0 is asleep");
			break;
		case 3:
			printf("man 0 is trapped");
			break;
		case 4:
			printf("man 0 is asleep and trapped");
			break;
		default:
			printf("something wrong in pInfo() -> 0");
			printf("please tell the developer");
			break;
	}
	
	p(20);
	
	switch(man[1].situ){
		case 1:
			printf("man 1 is normol\n");
			break;
		case 2:
	 		printf("man 1 is asleep\n");
			break;
		case 3:
			printf("man 1 is trapped\n");
			break;
		case 4:
			printf("man 1 is asleep and trapped\n");
			break;
		default:
			printf("something wrong in pInfo()");
			printf("please tell the developer\n\n");
			break;
	}
	
	if(man[0].aim==0){
		printf("man 0 has not got an aim");
	}else{
		printf("man 0 has got an aim");
	}
	
	p(11);
	
	if(man[1].aim==0){
		printf("man 1 has not got an aim\n");
	}else{
		printf("man 1 has got an aim\n");
	}
	
	if(man[0].isBe==0){
		printf("man 0 is not an aim now");
	}else{
		printf("man 0 is an aim now");
	}
	
	p(12);
	
	if(man[1].isBe==0){
		printf("man 1 is not an aim now\n");
	}else{
		printf("man 1 is an aim now\n");
	}
	
	printf("\n");
}

int setAc_new(bool ac) {

	unsigned int re=1;
	
	//count
	unsigned short ct=1;
	
	system("cls");

	pInfo(ac);
	
	printf("now is man %d's turn\n",ac);
	
	printf("please choose your action\n\n");

	if(man[ac].situ==2 || man[ac].situ==4) {

		printf("1.wake");
		re=0;

	} else if(man[ac].situ==3) {

		printf("1. sleep    ");
		printf("2.jie");
		re=1;

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
		
		if(man[0].loca==man[ac].loca){
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
	//////////////////////////////
	
	/////////////////
	unsigned short b;
	/////////////////
	
	///////////////
	unsigned int a;
	fflush(stdin);
	scanf("%d",&a);
	fflush(stdin);
	///////////////
	
	//////////////////////
	if(a>=3){
		int i=re;
		int x;
		for(x=1;x<=5;x++){
			if(i%10!=1){
				a+=1;
				i/=10;
			}
		}
	}
	//////////////////////
	
	//////////////////////////////////////////////////////////////////
	switch(re){
		case -1:
			printf("there is some thing wrong in setAc()\n\n");
			printf("please stop to tell the developer immediately\n");
			break;
			
		case 0:
			if(a==1){
				man[ac].situ-=1;
				printf("you are awake\n\n");
			}else{
				printf("wrong input!!\n\n");
			}
			break;
			
		case 1:
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
					
				case 2:
					man[ac].situ+=1;
					man[ac].aim=0;
					printf("asleep\n\n");
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
	
	while(man[0].situ!=0 || man[2].situ!=0) {
		fight_new();
	}
	
	return 0;
}

 	/*man[0].has=0;//short
	man[0].aim=0;//bool
	man[0].isBe=0;//bool
	man[0].situ=1;//short
	man[0].loca=1;//short*/

