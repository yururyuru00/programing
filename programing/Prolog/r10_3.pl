mid2(L1, Min, Max, L2) :- midmake2(L1, [], Min, Max, L2).

midmake2([], L, Min, Max, L).
midmake2([L|L1], L3, Min, Max, L2) :- L >= Min, L =< Max, midmake2(L1, [L|L3], Min, Max, L2).
midmake2([L|L1], L3, Min, Max, L2) :- midmake2(L1, L3, Min, Max, L2).
