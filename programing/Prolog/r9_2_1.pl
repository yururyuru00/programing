male(tom).
male(bob).
male(jim).
female(liz).
female(ann).

all_members(L) :- setof(X, male(X), A), setof(Y, female(Y), B), append(A, B, L).
