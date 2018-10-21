node(s, 10).
node(a, 2).
node(b, 3).
node(c, 5).
node(d, 4).
node(e, 2).
node(g, 0).

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

hc([N|Path]) :- start(N), goal(M), lowway(N, M, Path).

lowway(M, M, []).
lowway(N, M, [Path|L]) :- setof(N1, edge(N, N1), Lall), min(Lall, Path), lowway(Path, M, L).

min([L1|L], Path) :-  node(L1, N1), min(L, L1, N1, Path).
min([], Ln, Nn, Ln).
min([L1|L], Ln, Nn, Path) :- node(L1, N1), N1<Nn, min(L, L1, N1, Path).
min([L1|L], Ln, Nn, Path) :- min(L, Ln, Nn, Path).
