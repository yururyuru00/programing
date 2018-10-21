node(s, a).
node(s, b).
node(a, c).
node(a, d).
node(b, e).
node(b, g).
node(c, g).
node(d, g).
node(e, g).

start(s).
goal(g).

dfs2(Path) :- dfs2([], Path).

dfs2([], Path) :- start(N), goal(M), howto(N, M, [N], Path).
howto(M, M, L, L).
howto(N, M, L, Path) :- node(N, N1), howto(N1, M, [N1|L], Path).
