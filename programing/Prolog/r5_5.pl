connect_lists([], 0, [], []).
connect_lists([Lf|L1], X, L2, [Lf|L]) :- connect_lists(L1, X, L2, L).
connect_lists([], X, L2, [X|L]) :- X >0, connect_lists([], 0, L2, L).
connect_lists([], 0, [Lf|L2], [Lf|L]) :- connect_lists([], 0, L2, L).

partition([], X, [], []).
partition([Li|Li1], X, [Li|L1], L2) :- Li >= X, partition(Li1, X, L1, L2).
partition([Li|Li1], X, L1, [Li|L2]) :- Li <  X, partition(Li1, X, L1, L2).

qsort([], []).
qsort([A], [A]).
qsort([L|L1], L2) :- partition(L1, L, B, S), qsort(S, S1), qsort(B, B1),
connect_lists(S1, L, B1, L2).
