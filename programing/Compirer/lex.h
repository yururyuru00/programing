#ifndef __LEX_H_INCLUDED
#define __LEX_H_INCLUDED

/*
 * コンパイラの字句解析ルーチンのヘッダ
 */


/* トークンの最大文字数 */
#define lex_TOKEN_MAXLEN 127

/* トークンのタイプ */
#define token_BEGIN_ 0
typedef enum {
  token_UNDEF = token_BEGIN_, /* 未定義 */
  token_EOF, /* end of file */
  token_ID, /* 識別子 (変数名や関数名) */
  token_INT, /* 整数リテラル */
  token_CHAR, /* 文字リテラル */
  token_KW_CHAR, /* キーワード char */
  token_KW_ELSE, /* キーワード else */
  token_KW_IF, /* キーワード if */
  token_KW_INT, /* キーワード int */
  token_KW_RETURN, /* キーワード return */
  token_KW_WHILE, /* キーワード while */
  token_PLUS, /* 演算子 + */
  token_MINUS, /* 演算子 - */
  token_STAR, /* 演算子 * */
  token_SLASH, /* 演算子 / */
  token_PERC, /* 演算子 % */
  token_AMP, /* 演算子 & */
  token_ASSIGN, /* 演算子 = */
  token_EQ, /* 演算子 == */
  token_NE, /* 演算子 != */
  token_GT, /* 演算子 > */
  token_GE, /* 演算子 >= */
  token_LT, /* 演算子 < */
  token_LE, /* 演算子 <= */
  token_COMMA, /* 記号 , */
  token_SEMICOLON, /* 記号 ; */
  token_LPAREN, /* 記号 ( */
  token_RPAREN, /* 記号 ) */
  token_LBRACE, /* 記号 { */
  token_RBRACE, /* 記号 } */
  token_LBRACK, /* 記号 [ */
  token_RBRACK, /* 記号 ] */
  token_END_, /* terminator */
} lex_type_t;
#define token_MAX_ token_END_


/* lex のデバッグ用のトレース出力のモード */
typedef enum {
  lex_TRACE_NO, /* 何もしない */
  lex_TRACE_BY_CHAR, /* 文字単位で出力 */
  lex_TRACE_BY_TOKEN, /* トークン単位で出力 */
} lex_trace_t;


/* 字句解析のデータを保持する構造体 */
typedef struct {
  char  *filename; /* 処理中のファイル名 */
  FILE  *fp; /* ファイルにアクセスするためのポインタ */
  char  c; /* 現在読んでいる 1 文字 */
  int  linenum; /* 現在読んでいる行の番号 */
  lex_type_t  type;  /* 直近に切り出したトークンのタイプ */
  char  token[lex_TOKEN_MAXLEN+1]; /* トークンそのもの */
  int  token_len; /* トークン長 */
  int  val; /* 整数リテラルや文字リテラルの値 */
  lex_trace_t  trace; /* デバッグ用のトレース情報出力のモード */
} lex_t;


lex_t* lex_new(char* filename);
void lex_get (lex_t *x);
void lex_trace_set(lex_t *x, lex_trace_t trace);
char* lex_typename(lex_type_t type);
void lex_err(lex_t *x, char *msg);
void lex_delete(lex_t *x);

#endif
