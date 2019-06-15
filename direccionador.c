//Transforma una DV en una DF
#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    const int largo = 15;
    char name[largo]; //"0x + 10 caracteres en hexadecimal"
    name[largo-1] = 3;
    printf(1,"Hola. Dame la direccion virtual (ejemplo: 0x123456789a): ");
    gets(name,largo);
    if ((name[largo-1] != 3) || (name[0] != '0') || (name[1] != 'x')){
        printf(1,"La direccion no es valida (recuerda iniciar con 0x y despues usar 10 digitos)\n");
        exit();
        }
    int dir_fis = directioner(name);
    printf(1,"%d\n", dir_fis);
    exit();
    }