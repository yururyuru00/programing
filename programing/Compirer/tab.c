/*
 * tab                        by Nagisa Neco Ishiura    *
 *                                                     */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tab.h"


tab_t* tab_new(int id_maxlen)
{
  tab_t *t;
  int j;
  t = (tab_t*) malloc(sizeof(tab_t));
  assert(t!=NULL);

  t->id_maxlen = id_maxlen;
  t->itab_size = 0;
  t->itab_vsize = 0;
  for (j=0; j<itab_MAXSIZE; j++) {
    t->itab[j].id = (char*) malloc(sizeof(char) * t->id_maxlen);
    assert(t->itab[j].id!=NULL);
    t->itab[j].id[0] = '\0';
    t->itab[j].role = itab_role_UNDEF;
    t->itab[j].cls = itab_cls_UNDEF;
    t->itab[j].basetype = '?';
    t->itab[j].ptrlevel = 0;
    t->itab[j].argc = 0;
    t->itab[j].aref = -1;
    t->itab[j].address = -1;
    t->itab[j].size = 0;
  }
  t->atab_size = 0;
  for (j=0; j<atab_MAXSIZE; j++) {
    t->atab[j].max = 0;
    t->atab[j].elementsize = 0;
  }
  return t;
}


void tab_delete(tab_t *t)
{
  int j;
  assert(t!=NULL);
  for (j=0; j<itab_MAXSIZE; j++) {
    assert(t->itab[j].id);
    free(t->itab[j].id);
    t->itab[j].id = NULL;
  }
  free(t);
  t = NULL;
}


void tab_reset(tab_t *t)
{
  int j;
  assert(t!=NULL);
  t->itab_size = 0;
  t->itab_vsize = 0;
  t->atab_size = 0;
  for (j=0; j<itab_MAXSIZE; j++) {
    t->itab[j].id[0] = '\0';
    t->itab[j].role = itab_role_UNDEF;
    t->itab[j].cls = itab_cls_UNDEF;
    t->itab[j].basetype = itab_basetype_UNDEF;
    t->itab[j].ptrlevel = 0;
    t->itab[j].argc = 0;
    t->itab[j].aref = -1;
    t->itab[j].address = -1;
    t->itab[j].size = 0;
  }
  for (j=0; j<atab_MAXSIZE; j++) {
    t->atab[j].max = 0;
    t->atab[j].elementsize = 0;
  }
}


int tab_itab_find(tab_t *t, char *id)
/* itab 中に id を探し，見つかればそのインデックスを返す．
   見つからなければ itab_FAIL を返す */
{
  int j;
  int index = itab_FAIL;
  assert(t!=NULL);
  for (j=0; j<t->itab_size; j++) {
    if (strcmp(t->itab[j].id,id)==0) {
      index = j;
      break;
    }
  }
  return index;
}


int tab_itab_new(tab_t *t, char *id)
/* itab 中に id を登録し, そのインデックスを返す.
   もし既に id が登録されていれば itab_FAIL を返す */
{
  int i;
  int new_i;
  assert(t!=NULL);
  i = tab_itab_find(t, id);
  if (i==itab_FAIL) {
    assert(t->itab_size < itab_MAXSIZE);
    new_i = t->itab_size;
    //printf("aaa%s\n", id);
    strcpy(t->itab[new_i].id,id);
    t->itab_size++;
  }
  else { new_i = itab_FAIL; }
  return new_i;
}


int tab_atab_append(tab_t *t, int max, int elementsize)
{
  int a;
  assert(t!=NULL);
  a = t->atab_size;
  assert(a < atab_MAXSIZE);
  t->atab[a].max = max;
  t->atab[a].elementsize = elementsize;
  t->atab_size++;
  return a;
}


void tab_dump(tab_t *t)
{
  int j;
  if (t==NULL) {
    fprintf(stderr,"* tab not allocated yet\n");
  }
  else {
    fprintf(stderr, "[itab]         r c b pl ac ar  ad  sz\n");
    for (j=0; j<t->itab_size; j++) {
      fprintf(stderr,"%3d", j);
      fprintf(stderr," %-10s", t->itab[j].id);
      fprintf(stderr," %c", t->itab[j].role);
      fprintf(stderr," %c", t->itab[j].cls);
      fprintf(stderr," %c", t->itab[j].basetype);
      fprintf(stderr," %2d", t->itab[j].ptrlevel);
      fprintf(stderr," %2d", t->itab[j].argc);
      fprintf(stderr," %2d", t->itab[j].aref);
      fprintf(stderr," %3d", t->itab[j].address);
      fprintf(stderr," %3d", t->itab[j].size);
      fprintf(stderr,"\n");
    }
    fprintf(stderr, "[atab] mx elsz\n");
    for (j=0; j<t->atab_size; j++) {
      fprintf(stderr,"%3d  ", j);
      fprintf(stderr," %3d", t->atab[j].max);
      fprintf(stderr," %4d", t->atab[j].elementsize);
      fprintf(stderr,"\n");
    }
  }
}
