has_duplication([L|L1]) :- member(L, L1).
has_duplication([_|L1]) :- has_duplication(L1).
