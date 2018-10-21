edge(s,a).
edge(s,b).
edge(a,c).
edge(a,d).
edge(b,e).
edge(b,g).
edge(c,g).
edge(d,g).
edge(e,g).

start(s).
goal(g).

dfs(Path) :- start(N), goal(M), howto(N, M, Path).
howto(N, N, [M]) :- goal(M).
howto(N, M, [N|L]) :- edge(N, N1), howto(N1, M, L).


search_all(L) :- setof(Path, dfs(Path), L).
