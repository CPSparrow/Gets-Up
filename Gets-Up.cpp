#include<stdio.h>

int part=0;

//which wepon
const char wep[10][5]= {
	"f","g","p","t","j","m","to","ma","k","i"
};

struct model {
	unsigned short has;
	unsigned short loca;
	unsigned short situ;
	bool aim;
	bool isBe;
} man[2];

bool chos() {
	if(1/*something*/) {
		return 0;
	} else {
		return 1;
	}
}

void p(int n) {
	for(int m=0; m<n; m++) {
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
		printf("2.change");
		p(12);
		if(man[ac].isBe==1) {
			if(man[ac].aim==1) {
				printf("3.hide");
				p(14);
				printf("4.fire");
				re=2;
				return re;
			} else {
				printf("3.hide");
				p(14);
				re=3;
				return re;
			}
		} else {
			if(man[ac].aim==1) {
				printf("3.fire");
				re=4;
				return re;
			} else {
				re=5;
				return re;
			}
		}
	}
}

void fight() {
	int i = setAc(chos());
}

int main() {
	man[0].has=man[1].has=0;
	man[0].aim=man[1].aim=0;
	man[0].isBe=man[1].isBe=0;
	man[0].situ=man[1].situ=1;
	man[0].loca=1;
	man[1].loca=2;
	while(man[0].situ!=0 && man[2].situ!=0) {
		fight();
	}
	return 0;
}
