reverse2(L1, L2) :- rever2(L1, [], L2).

rever2([], L, L).
rever2([L1|L], L3, L2) :- rever2(L, [L1|L3], L2).
