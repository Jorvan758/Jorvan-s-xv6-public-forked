//Transforma una DV en una DF
#include "types.h"
#include "stat.h"
#include "user.h"
//#include "stdio.h"

int main(void) {
    char name[20];
    printf(1,"Hello. What's your name?\n");
    gets(name,20);
    //fgets(name,20,stdin);
    printf(1,"Hi there, %s\n", name);
    printf(1,"%d\n", directioner());
    exit();
    }
