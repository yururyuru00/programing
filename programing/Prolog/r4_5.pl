prefix([], L2).
prefix([L|L1], [L|L2]) :- prefix(L1, L2).
