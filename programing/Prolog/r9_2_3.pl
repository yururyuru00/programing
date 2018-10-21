node(s, 10).
node(a, 2).
node(b, 3).
node(c, 5).
node(d, 4).
node(e, 2).
node(g, 0).

node_list(L) :- setof(N/M, node(N, M), L).
