#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"

struct {
  struct spinlock lock;
  struct proc proc[NPROC];
} ptable;

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_getprocs(void)
{
  struct proc *p;
  int contador = 0;
  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++)
    {
      if ((p->state == EMBRYO) || (p->state == SLEEPING) || (p->state == RUNNING) || (p->state == RUNNABLE)) contador++;
    }
    
  return contador;
}

int
sys_showprocs(void)
{
  static char *states[] = {
  [UNUSED]    " unused ",
  [EMBRYO]    " embryo ",
  [SLEEPING]  "sleeping",
  [RUNNABLE]  "runnable",
  [RUNNING]   "running ",
  [ZOMBIE]    " zombie "
  };
  struct proc *p;
  for(p = ptable.proc; p < &ptable.proc[NPROC]; p++)
    {
      if (p->state != UNUSED) cprintf("%d %s %d %s %d\n", p->pid, states[p->state], p->tickets, p->name, p->pgdir); //kstack
    }
  exit();
  return 0;
}

int
sys_directioner(char* name)
{
  argstr(0, &name);
  cprintf("Me has dado: %s\n", name);
  struct proc *proceso = myproc();
  cprintf("%d\n", proceso->pgdir);

  pte_t *pte;
  /*pde_t *pgdir,*pgtab,*pde;
  pte = &pgtab[PTX(virtual_address)];
  pgtab = (pte_t*)V2P(PTE_ADDR(*pde));*/
  *int physical_address=(char*)P2V(PTE_ADDR(*pte));
  /*uint a = PGROUNDDOWN(rcr2()); // round down faulty VA to page start
  char *mem;
  mem = kalloc();
  memset(mem, 0, PGSIZE);
  //mappages(proc->pgdir, (char*)a, PGSIZE, v2p(mem), PTE_W|PTE_U);
  pde_t *pgdir = proceso->pgdir;
  void *va = (char*)a; 
  uint size = PGSIZE;
  uint pa = v2p(mem);
  int perm = PTE_W|PTE_U;

  char *a, *last;
  pte_t *pte;
  a = (char*)PGROUNDDOWN((uint)va);
  last = (char*)PGROUNDDOWN(((uint)va) + size - 1);
  for(;;){
    if(*pte & PTE_P)
      panic("remap");
    *pte = pa | perm | PTE_P;
    if(a == last)
      break;
    a += PGSIZE;
    pa += PGSIZE;
    }*/
  cprintf("%p\n", (void*)physical_address);
  /*char name[20];
  //gets(name,20);
  int a;
  for(a=1; a<20; a++){
    if ((name[a-1] == '\\') && (name[a] == 'n')){
      name[a-1] = ' ';
      name[a] = ' ';
      break;
      }
    }*/
  //printf(1,"La direccion fisica es: %s\n", name);



  //int retorno = 7;
  
  /*int physical_address;
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
  physical_address=(char*)P2V(PTE_ADDR(*pte));

  cprintf(" --PHYSICAL ADDRESS-- %d\n",physical_address);*/

  return 0;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
