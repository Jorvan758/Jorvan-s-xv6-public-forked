//Cuenta los procesos "activos"
#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    //fork();
    printf(1,"La cantidad de procesos en ejecucion en la CPU es %d\n", getprocs());
    exit();
    }
