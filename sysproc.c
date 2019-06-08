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
  cprintf("%d\n", V2P(proceso->pgdir));

  int a;
  int dir_temp = 0;
  for(a=2; a<10; a++){
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
      cprintf("La direccion no es valida\n");
      return 0;
      }
    }
  dir_temp = dir_temp*-1;
  cprintf("n");
  cprintf("La direccion fisica verdadera es: %d\n", dir_temp);
  cprintf("La direccion fisica verdadera es: %d\n", V2P(dir_temp));
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
