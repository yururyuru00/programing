nth_element([], _, write('The length is less than N')).
nth_element([L|_], 1, L).
nth_element([_|L1], N, X) :- N1 is N-1, nth_element(L1, N1, X).
