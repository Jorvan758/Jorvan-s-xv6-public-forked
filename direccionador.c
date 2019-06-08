//Transforma una DV en una DF
#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    const int largo = 15;
    char name[largo]; //"0x + 8 caracteres en hexadecimal"
    name[largo-1] = 3;
    printf(1,"Hola. Dame la direccion virtual: ");
    gets(name,largo);
    //uint a;
    if ((name[largo-1] != 3) || (name[0] != '0') || (name[1] != 'x')){
        printf(1,"La direccion no es valida\n");
        exit();
        }
    /*else{
        int dir_temp = 0;
        for(a=2; a<12; a++){
            dir_temp *= 10;
            if (name[a] == '0'){
                dir_temp += 0;
                }
            else if (name[a] == '1'){
                dir_temp += 1;
                }
            else if (name[a] == '2'){
                dir_temp += 2;
                }
            else if (name[a] == '3'){
                dir_temp += 3;
                }
            else if (name[a] == '4'){
                dir_temp += 4;
                }
            else if (name[a] == '5'){
                dir_temp += 5;
                }
            else if (name[a] == '6'){
                dir_temp += 6;
                }
            else if (name[a] == '7'){
                dir_temp += 7;
                }
            else if (name[a] == '8'){
                dir_temp += 8;
                }
            else if (name[a] == '9'){
                dir_temp += 9;
                }
            else if (name[a] == 'a'){
                dir_temp += 10;
                }
            else if (name[a] == 'b'){
                dir_temp += 11;
                }
            else if (name[a] == 'c'){
                dir_temp += 12;
                }
            else if (name[a] == 'd'){
                dir_temp += 13;
                }
            else if (name[a] == 'e'){
                dir_temp += 14;
                }
            else if (name[a] == 'f'){
                dir_temp += 15;
                }
            else{
                printf(1,"La direccion no es valida\n");
                exit();
                }
            }
        printf(1,"La direccion numerica es: %d\n", dir_temp);
        }*/
    printf(1,"List%d\n", directioner(name));
    exit();
    }