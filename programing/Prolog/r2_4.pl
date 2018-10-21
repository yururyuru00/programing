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

father(X, Y) :- parent(X, Y), male(X).

grandfather(X, Y) :- parent(Z, Y), parent(X, Z), male(X).

ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).

niece(X, Y) :- parent(Z, Y), parent(Z, Y1), parent(Y1, X), female(X).
