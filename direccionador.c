//Transforma una DV en una DF
#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    char name[20];
    printf(1,"Hello. What's your name?\n");
    gets(name,20);
    int a;
    for(a=1; a<20; a++){
        if ((name[a-1] == '\\') && (name[a] == 'n')){
            name[a-1] = ' ';
            name[a] = ' ';
            break;
            }
        }
    printf(1,"Hi there, %s\n", name);
    printf(1,"%d\n", directioner());
    //printf(1,"%d\n", directioner());
    exit();
    }
