//Transforma una DV en una DF
#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    const int largo = 11;
    char name[largo]; //"0x + 8 caracteres en hexadecimal"
    name[largo-1] = '\0';
    //uint kernbase = 4*1024*1024;
    printf(1,"Hola. Dame la direccion virtual: ");
    gets(name,largo);
    int a;
    for(a=1; a<largo; a++){
        if ((name[a-1] == '\\') && (name[a] == 'n')){
            name[a-1] = ' ';
            name[a] = ' ';
            break;
            }
        }
    if (name[largo-1] != '\0'){
        printf(1,"La direccion no es valida\n");
        }
    else{
        int dir_temp = 0;
        for(a=2; a<largo; a++){
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
            }
        printf(1,"La direccion fisica es: %d\n", dir_temp);
        }
    printf(1,"%d\n", directioner());

    /*char *virtual_addr = name;
    int physical_address;
    pde_t *pgdir,*pgtab,*pde;
    //must initialise pgdir
    pde = &pgdir[PDX(virtual_address)];
    if(*pde & PTE_P){
        pgtab = (pte_t*)V2P(PTE_ADDR(*pde));
        }
    else{
        cprintf("\n PTE Not Present! - Invalid Virtual address\n");
        return -1;
        }
    cprintf("\n ----------------- \n");
    cprintf(" Page Directory Entry (PDE): %d\n",*pde);
    cprintf(" PTE_P : %d\n",PTE_P);
    cprintf("\n ----------------- \n");
    //uva2ka
    pte_t *pte;
    pte = &pgtab[PTX(virtual_address)];
    physical_address=(char*)V2P(PTE_ADDR(*pte));

    cprintf(" --PHYSICAL ADDRESS-- %d\n",physical_address);*/

    //printf(1,"%d\n", directioner());   V2P()   pgtab = (pte_t*)P2V(PTE_ADDR(*pde));
    exit();
    }
