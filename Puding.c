#include<stdio.h>
#include <stdbool.h>
#include<windows.h>

//which wepon
const char wep[10][10]= {
	"fits","gun","plane","tank","morto",
	"martoon","tomato","knife","iPad","egg"
};

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

struct model {
	unsigned short has;
	unsigned short loca;
	unsigned short situ;
	bool aim;
	bool isBe;
} man[2];

void setAc_new(bool ac) {
	
	unsigned short re=1;
	unsigned short count=1;
	
	printf("now is man %d's turn\n",ac+1);
	printf("please choose your action\n");
	printf("1.move   ");
	printf("2.sleep  ");
	
	if(man[ac].situ==2 || man[ac].situ==4) {
		
		printf("1.wake");
		re=0;
		
	} else if(man[ac].situ==3) {
		
		printf("1.sleep  	");
		//p(14);
		printf("2.jie	");
		re=1;
		
	}else if(){
		
	}
	
	return re;
	
}

int main() {
	
	
	man[0].has=0;//short
	man[0].aim=0;//bool
	man[0].isBe=0;//bool
	man[0].situ=1;//short
	man[0].loca=1;//short
	
	setAc_new(0);
	
	
	return 0;
}
