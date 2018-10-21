node(s, 10).
node(a, 2).
node(b, 3).
node(c, 5).
node(d, 4).
node(e, 2).
node(g, 0).

node_list(L) :- setof(N/M, node(N, M), L).

a_value(Ave) :- node_list(L), add_list(L, Sum, C), Ave is Sum/C.
add_list([N/M|L1], Sum, C) :- add_list(L1, Sum1, C1), Sum is Sum1+M, C is C1+1.
add_list([], 0, 0).
