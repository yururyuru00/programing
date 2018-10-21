/*
 * コンパイラの記号表
 *                                                      */

#ifndef __TAB_H_INCLUDED
#define __TAB_H_INCLUDED

#define itab_MAXSIZE 256
#define atab_MAXSIZE 256
#define itab_FAIL -1
#define atab_FAIL -1

typedef enum
{
  itab_role_UNDEF = '?',
  itab_role_VAR = 'V',
  itab_role_FUNC = 'F', 
} itab_role_t;


typedef enum
{
  itab_cls_UNDEF = '?',
  itab_cls_GLOBAL = 'G',
  itab_cls_LOCAL = 'L', 
  itab_cls_ARG = 'A', 
} itab_cls_t;


typedef enum
{
  itab_basetype_UNDEF = '?',
  itab_basetype_INT = 'I',
  itab_basetype_CHAR = 'C',
} itab_basetype_t;


/* ID表のエントリー */
typedef struct {
  char *id;
  itab_role_t  role;
  itab_cls_t  cls;
  itab_basetype_t  basetype;
  int  ptrlevel;
  int  argc;
  int  aref;
  int  address;
  int  size;
} itab_entry_t;

/* 配列表のエントリー */
typedef struct {
  int  max;
  int  elementsize;
} atab_entry_t;


/* 記号表 */
typedef struct {
  int id_maxlen;
  int itab_size;
  int itab_vsize;
  int atab_size;
  itab_entry_t itab[itab_MAXSIZE];
  atab_entry_t atab[atab_MAXSIZE];
} tab_t;


tab_t* tab_new(int id_maxlen);
void tab_delete(tab_t *t);

void tab_reset(tab_t *t);
int  tab_itab_new (tab_t *t, char *id);
int  tab_itab_find(tab_t *t, char *id);
int  tab_atab_append (tab_t *t, int max, int elementsize);
void tab_dump (tab_t *t);


#endif

