even_list([], []).
even_list([X|X1], [Y|Y1]) :- mod(X, 2) =:= 0, Y is X, even_list(X1, Y1).
even_list([X|X1], Y) :- mod(X, 2) =:= 1, even_list(X1, Y).
