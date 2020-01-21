//  getChoice.c
//  copyright @ Handsome Coder Studio, 2020

//  remain question :
//  not solve a input like 1234abcd succcessfully

//  (probably input)
//  1,2,3...
//  a,b,c... (10 times)
//  1234abcd
//  123 dsuhfiu2b389fn sdn dkfn s
//  jq ef93bb js a
#include<stdio.h>

#define QUIT -1

#define GAME 1

#define INTRODUCE 2

#define CHANGECOLOR 3
#define TOOMUCH "too much wrong input"

#define TYPEAINT "please type a proper int like 1 or 2"

/*/////////////////////////////////////////////////
///////these above are which is OK now.////////////
/////////////////////////////////////////////////*/

void clean(void){
	while(getchar()!='\n'){
        continue;
	}
}

int getChoice(void){
    unsigned short times;
    unsigned int choice,ch;
    times=choice=ch=0;
    while(1){
        if(times==10){
            printf("%s\n",TOOMUCH);
            return QUIT;
        }else{
            times++;
            if((ch=scanf("%d",&choice))!=1){
                char hide;
                hide=getchar();
                if('C'==hide){
                	clean();
                    return CHANGECOLOR;
                }else if('q'==hide||'Q'==hide){
                	clean();
                    return QUIT;
                }else{
                	clean();
                    printf("%s\n",TYPEAINT);
                    continue;
                }
            }else{
            	//later here should be more
                if(GAME!=choice&&INTRODUCE!=choice){
                    printf("%s\n",TYPEAINT);
                }else{
                	clean();
                    return choice;
                }
            }
        }
    }
}

int main(void){
	while(1){
		printf("get a return = %d\n",getChoice());
	}
	return 0;
}


/*
  note:
  do not make a stupid mistake like this:
  
  char ch=getchar();
  while(ch!='\n'){
      ch=getchar();
  }
  
  remember this:
  
  while(getchar()!='\n){
      cotinue;
  }
*/
