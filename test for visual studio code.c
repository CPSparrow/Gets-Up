//#include<stdio.h>
//#include <stdbool.h>
//#include<time.h>
//#include<windows.h>
//#include<conio.h>  //is for getch()

const char wep[10][5]= {
	"fits","gun","tank","knife","powder"
};

const char place[9][15]= {
	"empty","man 0's home","man 1's home",
	"market 1","market 2","street 1",
	"street 2","park 1","park 2", 
};

const char actions[][]={"fits","",""};

struct model {
	unsigned short has;
	unsigned short loca;
	unsigned short situ;
	bool aim;
} man[2];

unsigned short isAction[2][15];//deal with

void fight_new_new(bool ac){
    //print actions
    int count=0;
    int i;
    for(i=0;i<15;i++){
        if (isAction[ac][i]==1)
        {
            count++;
            printf("%d.%c",count,actions[i]);
        }
        
    }
    const unsigned short=getch();
    /*
    
    //interesting example

    //not this// printf("re = %d\n",re);

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
    */
    //process choice

}

int main(){

    return 0;
}