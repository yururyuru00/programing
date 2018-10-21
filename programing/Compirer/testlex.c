#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.h"

int main(int argc, char **argv)
{
  char filename[FILENAME_MAX];
  lex_t *x;

  if (argc<=1) {
    fprintf(stderr, "SYNTAX: %s filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  strcpy(filename,argv[1]);

  x = lex_new(filename);
  // lex_trace_set(x, lex_TRACE_BY_TOKEN);
  lex_get(x);
  while(x->type != token_EOF) {
    printf("type = %-10s", lex_typename(x->type));
    printf(" token = \"%s\"", x->token);
    if (x->type==token_INT || x->type==token_CHAR) {
      printf("  val = %d", x->val);
    }
    printf("\n");
    lex_get(x);
  }
  lex_delete(x);

  return 0;
}
