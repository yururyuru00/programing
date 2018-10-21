del_duplication([L|L1], L2) :- member(L, L1), del_duplication(L1, L2).
del_duplication([L|L1], [L|L2]) :- del_duplication(L1, L2).
del_duplication([A], [A]).
