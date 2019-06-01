//Transforma una DV en una DF
#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    char name[20];
    printf(1,"Hola. Dame la direccion virtual:\n");
    gets(name,20);
    int a;
    for(a=1; a<20; a++){
        if ((name[a-1] == '\\') && (name[a] == 'n')){
            name[a-1] = ' ';
            name[a] = ' ';
            break;
            }
        }
    printf(1,"La direccion fisica es: %s\n", name);

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
