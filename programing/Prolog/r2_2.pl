fact(0, 1).
fact(N, M) :- N1 is N-1, fact(N1, M1), M is M1 * N.
