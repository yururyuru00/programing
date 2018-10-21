nth_element([L|_], 1, L).
nth_element([L|L1], N, X) :- N1 is N-1, nth_element(L1, N1, X).
