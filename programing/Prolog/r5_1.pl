are_edges(a, [b, c]).
are_edges(b, [a, c, d]).
are_edges(c, [d]).
are_edges(d, []).

n_of_edges(N, K) :- are_edges(N, L), are_edges_count(L, K).
are_edges_count([], 0).
are_edges_count([L|L1], K) :- are_edges_count(L1, K1), K is K1 +1.
