:- dynamic parent/2, male/1, female/1.

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

del_all :- retract(parent(pam, Y)), del_all.
del_all :- retract(parent(X, pam)), del_all.
del_all :- retract(male(pam)), del_all.
del_all :- retract(female(pam)), del_all.
del_all.
