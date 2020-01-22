//this is to test putMenu()
#include<stdio.h>
#include<windows.h>

#define STARS "**************"

void putMenu(void){
	printf("\n%s%s%s%s\n",STARS,STARS,STARS,STARS);
	printf("\nwhat do you want to do?\n");
	printf("1) play the game		2) get some introduction\n");
	printf("q) just quit  \n");
	printf("\n%s%s%s%s\n",STARS,STARS,STARS,STARS);
}

void accident(void){
	printf("something dangerours happened just now\n");
	printf("and we are sorry to tell you this game have to stop in 3 seconds\n");
	Sleep(3000);
	long long int stop[100000000];
}
/*/////////////////////////////////////////////////
///////these above are which is OK now.////////////
/////////////////////////////////////////////////*/

#define QUIT 4

#define GAME 1

#define INTRODUCE 2

#define CHANGECOLOR 3

#define TOOMUCH "too much wrong input"

#define TYPEAINT "please type a proper int like 1 or 2"

int getChoice(char* toomuch,char* typeaint,int game,int introduce,int changeColor,int quit);

int main(){
    unsigned short result;
    putMenu();
    //quit when 'q' or 'Q'
    while (QUIT!=(result=getChoice(TOOMUCH,TYPEAINT,GAME,INTRODUCE,CHANGECOLOR,QUIT)))
    {
        switch (result){
        //while type 1
        case GAME:
        	printf("this is game\n");
            //gameBody();
            break;
        
        //2
        case INTRODUCE:
            printf("this is info\n");
            //putInfo();
            break;
		
		//THESE should all be put off
		//'C' only,not 'c'
		case CHANGECOLOR:
			printf("changed the color\n");
			//changeColor();
			break;
		
		//and this is about to be out of my ability
        default:
        	accident();
            break;
        }
        putMenu();
    }
    //ending();
	printf("game ended properly\n");
    return 0;
}

int getChoice(char* toomuch,char* typeaint,int game,int introduce,int changeColor,int quit){
    unsigned short times;
    unsigned int choice,ch;
    times=choice=ch=0;
    while(1){
        if(times==10){
            printf("%s\n",toomuch);
            return quit;
        }else{
            times++;
            if((ch=scanf("%d",&choice))!=1){
                char hide;
                hide=getchar();
                if('C'==hide){
                    return changeColor;
                }else if('q'==hide||'Q'==hide){
                    return quit;
                }else{
                    printf("%s\n",typeaint);
                    continue;
                }
            }else{
            	//later here should be more
                if(game!=choice&&introduce!=choice){
                    printf("%s\n",typeaint);
                }else{
                    return choice;
                }
            }
        }
    }
}

