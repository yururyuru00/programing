divide_by_three([], [], []).
divide_by_three([L|L1], [L|L2], L3) :-
mod(L, 3) =:= 0, divide_by_three(L1, L2, L3).
divide_by_three([L|L1], L2, [L|L3]) :-
mod(L, 3) =\= 0, divide_by_three(L1, L2, L3).
