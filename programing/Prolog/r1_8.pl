edge(a, b).
edge(b, c).
edge(b, d).
edge(c, e).
edge(d, e).
edge(f, g).

connected(N, M) :- edge(N, M).
connected(N, M) :- edge(N, Z), connected(Z, M).
