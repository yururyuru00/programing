male(tom).
male(bob).
male(jim).
female(liz).
female(ann).

gather_men(L) :- setof(X, male(X), L).
number_of_men(N) :- gather_men(L), counter(L, N).
counter([_|L1], N) :- counter(L1, N1), N is N1+1.
counter([], 0).
