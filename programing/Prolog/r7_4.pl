senior([(A1, N1)|L1], [A1|L2]) :- N1 >=60, senior(L1, L2).
senior([(A1, N1)|L1], L2) :- senior(L1, L2).
senior([], []).
