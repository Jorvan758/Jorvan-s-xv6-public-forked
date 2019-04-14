
//#include <stdlib.h>
#include "types.h"
#include "stat.h"
#include "user.h"
#include "sysproc.c"

int main(void) {
    printf(1,"La cantidad de procesos en ejecucion en la CPU es %i\n", getprocs());
    exit();
    }
