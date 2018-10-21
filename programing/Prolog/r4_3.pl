insert_end([], A, [A]).
insert_end([L|L1], A, [L|L2]) :- insert_end(L1, A, L2).
