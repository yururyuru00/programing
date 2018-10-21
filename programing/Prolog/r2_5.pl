edge(a, b).
edge(b, c).
edge(b, d).
edge(c, e).
edge(d, e).
edge(f, g).

dist(N, N, 0).
dist(N, M, L) :- edge(M1, M), dist(N, M1, L1), L is L1 + 1.
