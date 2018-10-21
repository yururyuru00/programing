classify([(A1, N1)|L1], [(A1, N1)|L2], L3, L4) :- N1 >=60, classify(L1, L2, L3, L4).
classify([(A1, N1)|L1], L2, [(A1, N1)|L3], L4) :- N1 >= 20, N1 <60, classify(L1, L2, L3, L4).
classify([(A1, N1)|L1], L2, L3, [(A1, N1)|L4]) :- N1 < 20, classify(L1, L2, L3, L4).

classify([], [], [], []).
