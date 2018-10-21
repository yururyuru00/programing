parent(pam, bob).
parent(tom, bob).
parent(bob, pat).
parent(pat, jim).
parent(tom, liz).

male(tom).
male(bob).
male(jim).

female(pam).
female(liz).
female(pat).

siblings(X, Y) :- parent(Xp, X), parent(Xp, Y).
n_of_siblings(X, N) :- setof(A, siblings(X, A), L), counter(L, N).
counter([], -1).
counter([L|L1], N) :- counter(L1, N1), N is N1+1.
