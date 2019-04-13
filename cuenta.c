// |J|
sudo apt-get install gcc-multilib
sudo apt-get install g++-multilib
#include <stdlib.h>
#include <stdio.h>
/*#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "syscall.c"*/

int main(void) {
    printf("La cantidad de procesos en ejecucion en la CPU es %i\n", getprocs());
    //exit();
    return 1;
    }