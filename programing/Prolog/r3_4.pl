number_of_evens([], 0).
number_of_evens([X|X1], C) :- mod(X, 2) =:= 0, number_of_evens(X1, C1), C is C1 +1.
number_of_evens([X|X1], C) :- mod(X, 2) =:= 1, number_of_evens(X1, C).
