edge(a, b, 8).
edge(b, c, 10).
edge(b, d, 5).
edge(c, e, 7).
edge(d, e, 2).
edge(f, g, 16).

dist2(N, N, 0).
dist2(N, M, D) :- edge(M1, M, D2), dist2(N, M1, D1), D is D1+D2.
