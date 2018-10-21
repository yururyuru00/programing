find_atom(A, X, [A|Xs], [B|Xs]) :- cond(A, B).
find_atom(A, B, [X|Xs], [X|Ys]) :- find_atom(A, B, Xs, Ys).

cond(a, zzz).

do(B, L2) :- find_atom(a, B, [a, b, c, d], L2).
do1(B, L2) :- find_atom(d, B, [a, b, c, a], L2).  
