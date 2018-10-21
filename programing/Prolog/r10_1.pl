list_length2(L, N) :- list_len2(L, N, 0).

list_len2([], C, C).
list_len2([L1|L], N, C) :- C1 is C+1, list_len2(L, N, C1).
