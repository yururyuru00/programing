partition([], X, [], []).
partition([Li|Li1], X, [Li|L1], L2) :- Li >= X, partition(Li1, X, L1, L2).
partition([Li|Li1], X, L1, [Li|L2]) :- Li <  X, partition(Li1, X, L1, L2).
 
