sum([], 0).
sum([L|L1], S) :- L=<10, sum(L1, S1), S is S1 + L.
sum([L|L1], S) :- L>=11, sum(L1, S1), S is S1.
