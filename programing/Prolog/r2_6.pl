convert(0, 0).
convert(N, s(M1)) :- N1 is N - 1, convert(N1, M1).
