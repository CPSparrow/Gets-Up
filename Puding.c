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

void pInfo(bool ac){
	printf("man %d has a %s\n",ac,wep[man[ac].has]);
	printf("man %d is now at %s\n",ac,place[man[ac].loca]);
	switch(man[ac].situ){
		case 1:
			printf("man %d is normol\n",ac);
			break;
		case 2:
	 		printf("man %d is asleep\n",ac);
			break;
		case 3:
			printf("man %d is trapped\n",ac);
			break;
		case 4:
			printf("man %d is asleep and trapped\n",ac);
			break;
		default:
			printf("something wrong in pInfo()\n");
			printf("please tell the developer");
			printf("immediately as for the case of");
			printf("emergency\n\n");
			break;
	}
	if(man[ac].aim==0){
		printf("man %d has not got an aim\n",ac);
	}else{
		printf("man %d has got an aim\n",ac);
	}
	
	if(man[ac].isBe==0){
		printf("man %d is not an aim now\n",ac);
	}else{
		printf("man %d is an aim now\n",ac);
	}
	printf("\n");
}

int setAc_new(bool ac) {

	unsigned int re=1;
	
	//count
	unsigned short ct=1;
	
	if(isStart==1){
		printf("\n\n\n\n\n");
	}else{
		isStart=1;
	}

	printf("now is man %d's turn\n\n",ac);
	
	pInfo(ac);
	
	printf("please choose your action\n\n");

	if(man[ac].situ==2 || man[ac].situ==4) {

		printf("1.wake");
		re=0;

	} else if(man[ac].situ==3) {

		printf("1. sleep   ");
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
	//
	int ac=chos();
	unsigned int re=setAc_new(ac);
	//
	
	//
	unsigned int a;
	fflush(stdin);
	scanf("%d",&a);
	fflush(stdin);
	//
	
	//
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
	//
	
	//
	switch(re){
		case -1:
			printf("please stop to tell the developer immediately\n");
			printf("there is some thing wrong in setAc()\n\n");
			break;
			
		case 0:
			if(a==1){
				man[ac].situ-=1;
			}else{
				printf("a wrong input!!\n\n");
			}
			break;
			
		case 1:
			if(a==1){
				man[ac].situ-=2;
			}
			break;
			
		default:
			break;
	}
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

