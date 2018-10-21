d((T1x, T1y), (T2x, T2y), D) :- D is abs(T1x-T2x) + abs(T1y-T2y).

swap(E, L1, [L1|L], [E|L]) :- d(E, L1, D), D=<1.
swap(E, T, [L|L1], [L|L2]) :- swap(E, T, L1, L2).

edge([L1|L], [T|L2]) :- swap(L1, T, L, L2).
