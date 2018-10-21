#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "code.h"


#define code_INSN_MNEMONIC_MAXLEN 7 /* 命令の名前の最大長 */
static char insn_mnemonic_[opcode_MAX_][code_INSN_MNEMONIC_MAXLEN+1]; /* 命令名 */
static int insn_n_operands_[opcode_MAX_]; /* オペランド数 */


static void set_insn_info(opcode_t op, char *mnemonic, int n_operands)
{
  assert(opcode_BEGIN_<=op && op<opcode_END_);
  strcpy(insn_mnemonic_[op], mnemonic);
  insn_n_operands_[op] = n_operands;
}


static void define_insn_info()
{
  set_insn_info(opcode_NOP, "NOP", 0);
  set_insn_info(opcode_ISP, "ISP", 1);
  set_insn_info(opcode_LA, "LA", 2);
  set_insn_info(opcode_LV, "LV", 2);
  set_insn_info(opcode_LC, "LC", 1);
  set_insn_info(opcode_LI, "LI", 0);
  set_insn_info(opcode_DUP, "DUP", 0);
  set_insn_info(opcode_SI, "SI", 0);
  set_insn_info(opcode_SV, "SV", 2);
  set_insn_info(opcode_SB, "SB", 1);
  set_insn_info(opcode_B, "B", 1);
  set_insn_info(opcode_BZ, "BZ", 1);
  set_insn_info(opcode_CALL, "CALL", 1);
  set_insn_info(opcode_RET, "RET", 0);
  set_insn_info(opcode_GETC, "GETC", 0);
  set_insn_info(opcode_GETI, "GETI", 0);
  set_insn_info(opcode_PUTC, "PUTC", 0);
  set_insn_info(opcode_PUTI, "PUTI", 0);
  set_insn_info(opcode_ADD, "ADD", 0);
  set_insn_info(opcode_SUB, "SUB", 0);
  set_insn_info(opcode_MUL, "MUL", 0);
  set_insn_info(opcode_DIV, "DIV", 0);
  set_insn_info(opcode_MOD, "MOD", 0);
  set_insn_info(opcode_INV, "INV", 0);
  set_insn_info(opcode_EQ, "EQ", 0);
  set_insn_info(opcode_NE, "NE", 0);
  set_insn_info(opcode_GT, "GT", 0);
  set_insn_info(opcode_LT, "LT", 0);
  set_insn_info(opcode_GE, "GE", 0);
  set_insn_info(opcode_LE, "LE", 0);
  set_insn_info(opcode_EXIT, "EXIT", 0);
}


char* insn_mnemonic(opcode_t op)
{
  return insn_mnemonic_[op];
}


int insn_n_operands(opcode_t op)
{
  return insn_n_operands_[op];
}


code_t* code_new()
{
  code_t* c;
  int i;
  define_insn_info();
  c = (code_t*) malloc(sizeof(code_t));
  assert(c!=NULL);
  c->size = 0;
  return c;
}


void code_delete(code_t *c)
{
  assert(c!=NULL);
  free(c);
  c = NULL;
}


void code_read(code_t *c, char filename[])
{
  FILE *fp;
  char tmp[256];

  assert(c!=NULL);
  assert(filename!=NULL);
  if ((fp=fopen(filename,"r")) == NULL) {
    fprintf(stderr, "cannot open file '%s'\n", filename);
    exit(EXIT_FAILURE);
  }
  while (fscanf(fp, "%s", tmp) != EOF) {
    if (c->size >= code_MAXSIZE) {
      fprintf(stderr, "code too large\n");
      exit(EXIT_FAILURE);
    }
    if (tmp[strlen(tmp)-1] == ':' || strcmp(tmp,"0")==0 || atoi(tmp)>0) {
      ;
    }
    else {
      int found = 0;
      opcode_t oc;
      for (oc=opcode_BEGIN_; oc<opcode_END_; oc++) {
	if (strcmp(tmp, insn_mnemonic(oc))==0) {
          c->insn[c->size].opcode = oc;
	  found = 1;
          break;
	}
      }
      if (!found) {
        fprintf(stderr, "code: invalid op (%d) '%s'\n", c->size, tmp);
        exit(EXIT_FAILURE);
      }
      c->insn[c->size].operand[0] = 0;
      c->insn[c->size].operand[1] = 0;
      if (1<=insn_n_operands(oc)) {
        fscanf(fp, "%d", &c->insn[c->size].operand[0]);
      }
      if (2<=insn_n_operands(oc)) {
        fscanf(fp, "%d", &c->insn[c->size].operand[1]);
      }
      c->size++;
    }
  }
}


void code_write(code_t *c, char filename[])
{
  int j;
  FILE *fp;

  assert(c!=NULL);
  assert(filename!=NULL);
  if (strcmp(filename,"")==0) {fp = stdout;}
  else if ((fp=fopen(filename,"w")) == NULL) {
    fprintf(stderr, "cannot open file '%s'\n", filename);
    exit(EXIT_FAILURE);
  }
  for (j=0; j<c->size; j++) {
    insn_t i = c->insn[j];
    fprintf(fp, "%3d", j);
    fprintf(fp, " %s", insn_mnemonic(i.opcode));
    if (1<=insn_n_operands(i.opcode)) {
      fprintf(fp, " %d", i.operand[0]);
    }
    if (2<=insn_n_operands(i.opcode)) {
      fprintf(fp, " %d", i.operand[1]);
    }
    fprintf(fp, "\n");
  }
}


int code_append(code_t *c, opcode_t oc, int p0, int p1)
{
  int addr = c->size;
  assert(c!=NULL);
  assert(addr < code_MAXSIZE);
  c->insn[c->size].opcode = oc;
  c->insn[c->size].operand[0] = p0;
  c->insn[c->size].operand[1] = p1;
  c->size++;
  return addr;
}


void code_set(code_t *c, int addr, opcode_t oc, int p0, int p1)
{
  assert(c!=NULL);
  assert(0<=addr && addr < c->size);
  c->insn[addr].opcode = oc;
  c->insn[addr].operand[0] = p0;
  c->insn[addr].operand[1] = p1;
}


#undef __IN_CODE_C
