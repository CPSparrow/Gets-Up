//  mainBody.c
//  copyright @ Handsome Coder Studio, 2020

void beingingSet(){}

int isAlive(){}

int choose(){}

void putOptions(){}

int getOptions(who){}

void act(option,who){}

int main(void){
    bool who;
    unsigned int option;
    beginingSet();
    while (isAlive()){
        who=choose();
        //who = 0 or 1
        //while who = 1
        //so player = 1
        if(who){
            putOptions();
        }
        option=getOptions(who);
        act(option,who);
    }
}
