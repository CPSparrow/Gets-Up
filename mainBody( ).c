//  mainBody.c
//  copyright @ Handsome Coder Studio, 2020

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<time.h>

void accident(const char* kind) {
	puts(kind);
	printf("请按任意键以退出\n");
	getchar();
	exit(EXIT_FAILURE);
}

void clean(void) {
	while(getchar()!='\n') {
		continue;
	}
}
//which is done

#define COMPUTER 0

#define PLAYER 1

#define TYPE_A_INT "请输入如1，2的整数"
struct model {
	unsigned short has;
	unsigned short loca;
	unsigned short situ;
	bool aim;
	bool warm;
} man[2];

const char *action[16]= {
	"拳套","小刀","射击","火箭筒","碾压","开炮","躲开","移动","换武器","离开坦克","到ta后面","睡眠","打晕","绑起来","苏醒","解开"
	//0       1       2       3      4     5       6     7        8        9          10       11     12     13       14     15
};



bool isAction[2][16];

void beginningSet(void);

int maxOptions(const bool who);

void putOptions(void);

int getOption(const bool person);

void act(const int option,const bool person);

int main(void) {
	beginningSet();
	puts("欢迎来到 gets-up ,如果您想要退出，请输入q\n"); 
	do {
		bool who;
		unsigned int option;
		srand(time(NULL));
		who=rand()%2;
		who=1;
		if(who) {
			putOptions();
		}
		//puts("this is getOptions");
		//getchar();
		option=getOption(who);
		printf("option = %d\n",option);
		act(option,who);
	} while(0!=man[0].situ&&0!=man[1].situ);
}

void beginningSet(void) {
	man[COMPUTER].aim=man[PLAYER].aim = man[0].has=man[PLAYER].has = man[0].warm=man[PLAYER].warm=0;
	man[COMPUTER].loca=0;
	man[PLAYER].loca=1;
	man[COMPUTER].situ=man[PLAYER].situ=1;

	int a,b;
	for(a=0; a<2; a++) {
		for(b=0; b<16; b++) {
			isAction[a][b]=0;
		}
	}
	isAction[PLAYER][14]=isAction[COMPUTER][14]=1;
}

void putOptions(void) {
	int j,k;
	puts("现在是你的回合了，请在输入选择之后回车\n");
	puts("这是你可选的操作:\n");
	for(j=0,k=0; j<16; j++) {
		if(isAction[PLAYER][j]) {
			k++;
			printf("%d.%-15s",k,action[j]);
			if(k%3==0) {
				putchar('\n');
			}
		}
		if(k%3!=0) {
			putchar('\n');
		}
	}
}

int maxOptions(const bool who) {
	int index,count;
	for(index=0,count=0; index<16; index++) {
		if(isAction[who][index]) {
			count++;
		}
	}
	return count;
}

int getOption(const bool person) {
	//PLAYER
	if(person) {
		unsigned short times=0;
		while(1) {
			if(10==times) {
				accident("WRONG_INPUT\n");
			} else if(0<=times&&10>times) {
				times++;
				const char first = getchar();

				if('\n' == first) {
					times--;
					continue;
				} else {
					unsigned short option;
					int max = maxOptions(person);

					if(first>='1'&&first<='9') {
						const char second = getchar();
						if(second>='1'&&second<='9') {
							const char third = getchar();
							if(third=='\n') {
								option=10*(first-'0')+second-'0';
								if(option>=10&&option<=max) {
									return option;
								} else {
									puts("请输入一个在选择范围内的整数"); 
									continue;
								}
							} else {
								puts(TYPE_A_INT);
								clean();
								continue;
							}
						} else if(second=='\n') {
							option=first-'0';
							if(option<=max) {
								return option;
							} else {
								puts("请输入一个在范围内的整数\n");
								continue;
							}
						} else {
							puts(TYPE_A_INT);
							clean();
							continue;
						}
					} else {
						puts(TYPE_A_INT);
						clean();
						continue;
					}
				}
			}else{
				accident("DATA_CHANGED\n");
			}
		}
	}else{
		//random algorithm
		int max = maxOptions(person);
		srand(time(NULL));
		int options = rand()%max+1;
		return options;
	}
}

void act(const int option,const bool who){
	printf("this is who\n\n");
}
