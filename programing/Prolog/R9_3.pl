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

exist_path() :- start(N), goal(M), edges(N, M).
edges(N, M) :- edge(N, M).
edges(N, M) :- edge(N, N1), edges(N1, M).
