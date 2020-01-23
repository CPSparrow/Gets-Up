#include"GU_heads.h"

//this part is to show how the main() works

int main(){
    unsigned short result;
    putMenu();
    //quit when 'q' or 'Q'
    while (QUIT!=(result=getChoice()))
    {
        switch (result){
        //while type 1
        case GAME:
        	//printf("this is game\n");
            gameBody();
            break;
        
        //2
        case INTRODUCE:
            //printf("this is info\n");
            putInfo();
            break;
		
		//THESE should all be put off
		//'C' only,not 'c'
		case CHANGECOLOR:
			//printf("changed the color\n");
			changeColor();
			break;
		
		//and this is about to be out of my ability
        default:
        	accident();
            break;
        }
        putMenu();
    }
    ending();
	//printf("game ended properly\n");
    return 0;
}

