#include"GU_heads.h"

int main(){
    unsigned short result;
    putMenu();
    while (QUIT!=(result=getChoice()))
    {
        switch (result){
        case GAME:
        	//printf("this is game\n");
            gameBody();
            break;
        
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
        	accident(DATA_CHANGED);
            break;
        }
        putMenu();
    }
    ending();
	//printf("game ended properly\n");
    return 0;
}

