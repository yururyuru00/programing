connect_lists([], [], [], []).
connect_lists([], X, L2, L3) :- append(X, L2, L3), connect_lists([], [], [], []).
connect_lists(L1, X, L2, L) :- append(L1, [X], L3), connect_lists([], L3, L2, L).
