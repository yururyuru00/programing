:- dynamic cond/2.

find_atom(A, X, [A|Xs], [B|Xs]) :- cond(A, B).
find_atom(A, B, [X|Xs], [X|Ys]) :- find_atom(A, B, Xs, Ys).

cond(a, zzz).

do(B, L2) :- find_atom(a, B, [a, b, c, d], L2).
do1(B, L2) :- find_atom(d, B, [a, b, c, a], L2).

d((T1x, T1y), (T2x, T2y), D) :- D is abs(T1x-T2x) + abs(T1y-T2y).

#swap(E, T, L1, L2) :- swap(E, T, L1, L1, L2).
swap((Ex, Ey), T, [(Lx, Ly)|L], L2) :- d((Ex, Ey), (Lx, Ly), D), D<=1, assert(cond(E, L1)), find_atom(E, X, buffo, Y).
swap(E, T, [L1|L], L2) :- swap(E, T, L, L2).
#swap(E, T, [L1|L], buffo, L2) :- d(E, L1, D), D<=1, assert(cond(E, L1)), find_atom(E, X, buffo, Y).
#swap(E, T, [L1|L], buffo, L2) :- swap(E, T, L, buffo, L2).
