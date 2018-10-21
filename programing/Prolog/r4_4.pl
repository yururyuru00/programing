mid([], Min, Max, []).
mid([L|L1], Min, Max, [L|L2]) :- L>=Min, L=<Max, mid(L1, Min, Max, L2).
mid([L|L1], Min, Max, L2) :- mid(L1, Min, Max, L2).
