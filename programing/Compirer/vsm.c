#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "code.h"

#define MEM_MAXSIZE 512

/* 内部記憶 */
static int PC = 0;  /* プログラムカウンタ */
static int SP = -1;  /* スタックポインタ */
static int B[2] = {0, 0};  /* ベースレジスタ (0: global用, 1: local用) */
static int M[MEM_MAXSIZE];  /* メモリー/スタック */
static int max_SP = 0;  /* これまでにアクセスした最大 SP */


static void address_error(char *mem, int a);
static int MR (int a);
static void MW (int a, int d);
static int BR (int b);
static void BW (int b, int d);
static void display_config();
static int code_exec(code_t *c, int trace);
static int insn_exec(insn_t insn, int *finished);
static void argerr();
static void arg(int argc, char **argv, char *filename, int *trace);


static void address_error(char *mem, int a)
/* メモリーアクセスのアドレスのエラー */
{
  fprintf(stderr, "address error on %s (PC = %d, address = %d)\n", mem, PC, a);
  exit(EXIT_FAILURE);
}


static int MR (int a)
/* memory read */
{
  if (a<0 || MEM_MAXSIZE<=a) address_error("M", a);
  return M[a];
}


static void MW (int a, int d)
/* memory write */
{
  if (a<0 || MEM_MAXSIZE<=a) address_error("M", a);
  M[a] = d;
}


static int BR (int b)
/* base register read */
{
  if (b!=0 && b!=1) address_error("B", b);
  return B[b];
}


static void BW (int b, int d)
/* base register write */
{
  if (b!=0 && b!=1) address_error("B", b);
  B[b] = d;
}


static void display_config()
/* VSM の状態の表示 */
{
  int i;
  for (i=max_SP; 0<=i; i--) {
    int c;
    if (SP==i) {printf(" SP-> ");}
    else       {printf("      ");}
    c = MR(i);
    if (!isprint(c)) {c = '.';}
    printf("M[%3d] %4d %c", i, MR(i), c);
    if (B[0]==i) {printf(" <-B0");}
    if (B[1]==i) {printf(" <-B1");}
    printf("\n");
  }
}


static int insn_exec(insn_t insn, int *finished)
{
  opcode_t o = insn.opcode;
  int p1 = insn.operand[0];
  int p2 = insn.operand[1];
  int i;
  int rc = 0;
  switch(o) {
    case opcode_ISP: SP+=p1; break;
    case opcode_LA:  SP++; MW(SP, BR(p1)+p2); break;
    case opcode_LV:  SP++; MW(SP, MR(BR(p1)+p2)); break;
    case opcode_LC:  SP++; MW(SP, p1); break;
    case opcode_LI:  MW(SP, MR(MR(SP))); break;
    case opcode_DUP: SP++; MW(SP, MR(SP-1)); break;
    case opcode_SI:  MW(MR(SP-1), MR(SP)); SP-=2; break;
    case opcode_SV:  MW(BR(p1)+p2, MR(SP)); SP--; break;
    case opcode_SB:  BW(p1,MR(SP)); SP--; break;
    case opcode_B:   PC+=p1; break;
    case opcode_BZ:  if (MR(SP)==0) {PC+=p1;} SP--; break;
    case opcode_CALL:  MW(SP+2, BR(1)); MW(SP+3, PC); BW(1, SP+1); PC=p1;  break;
    case opcode_RET:  SP=BR(1); BW(1, MR(SP+1)); PC=MR(SP+2); break;

    case opcode_GETC: SP++; MW(SP, getc(stdin)); break;
    case opcode_GETI: SP++; scanf("%d", &i); MW(SP,i); break;
    case opcode_PUTC: printf("%c", MR(SP)); SP--; break;
    case opcode_PUTI: printf("%d", MR(SP)); SP--; break;

    case opcode_ADD: SP--; MW(SP, MR(SP)+MR(SP+1)); break;
    case opcode_SUB: SP--; MW(SP, MR(SP)-MR(SP+1)); break;
    case opcode_MUL: SP--; MW(SP, MR(SP)*MR(SP+1)); break;
    case opcode_DIV: SP--; MW(SP, MR(SP)/MR(SP+1)); break;
    case opcode_MOD: SP--; MW(SP, MR(SP)%MR(SP+1)); break;
    case opcode_INV: MW(SP, -MR(SP)); break;
    case opcode_EQ: SP--; MW(SP, (MR(SP)==MR(SP+1))); break;
    case opcode_NE: SP--; MW(SP, (MR(SP)!=MR(SP+1))); break;
    case opcode_GT: SP--; MW(SP, (MR(SP)>MR(SP+1))); break;
    case opcode_LT: SP--; MW(SP, (MR(SP)<MR(SP+1))); break;
    case opcode_GE: SP--; MW(SP, (MR(SP)>=MR(SP+1))); break;
    case opcode_LE: SP--; MW(SP, (MR(SP)<=MR(SP+1))); break;
    case opcode_EXIT: *finished=1; rc=M[SP]; SP--; break;
    default: 
      fprintf(stderr, "invalid insn '%s'\n", insn_mnemonic(o));
      exit(EXIT_FAILURE);
  }
  return rc;
}


static int code_exec(code_t *c, int trace) 
/* VSM の実行 */
{
  int finished;
  int rc = 0;

  for (finished=0; !finished;) {
    insn_t insn;
    if (PC<0 || c->size<=PC) {
      fprintf(stderr, "PC out of range (PC=%d)\n", PC);
      exit(EXIT_FAILURE);
    }
    insn = c->insn[PC];
    if (trace>=2) {
      display_config();
      printf("\n");
    }
    if (1<=trace) {
      printf("%d: %s %d %d\n", PC, 
        insn_mnemonic(insn.opcode), insn.operand[0], insn.operand[1]);
    }
    if (2<=trace) {
      char key = getchar();
      if (key=='q') {exit(0);}
    }
    PC++;
    rc = insn_exec(insn, &finished);
    if (SP>max_SP) max_SP = SP;
  }
  return rc;
}


static void argerr()
/* コマンドライン引数のエラー */
{
  fprintf(stderr, "sm [-t (1|2)] CODE.vsm\n");
  exit(0);
}


static void arg(int argc, char **argv, char *filename, int *trace)
/* コマンドライン引数の解析 */
{
  int i = 1;
  if (i>=argc) argerr();
  if (strcmp(argv[i],"-t")==0) {
    i++;
    *trace = atoi(argv[i]);
    if (*trace<1 || 2<*trace) argerr();
    i++;
  }
  if (i>=argc) argerr();
  strcpy(filename, argv[i]);
}


int main(int argc, char **argv) 
{
  int trace = 0;
  int rc;
  char code_file[FILENAME_MAX];
  code_t *c;

  arg(argc, argv, code_file, &trace);

  c = code_new();
  code_read(c, code_file);
  rc = code_exec(c, trace);
  code_delete(c);

  return rc;
}
