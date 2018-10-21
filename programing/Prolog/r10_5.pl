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

dfs_bound(MaxDepth, Path) :- dfs2(MaxDepth, [], Path).

dfs2(C, [], Path) :- start(N), goal(M), howto(C, N, M, [N], Path).
howto(C, M, M, L, L) :- C >= 0.
howto(C, N, M, L, Path) :- node(N, N1), C1 is C-1, howto(C1, N1, M, [N1|L], Path).
