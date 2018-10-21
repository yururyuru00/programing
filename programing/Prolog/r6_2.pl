isTerm(g(X, Y)) :- isTerm(X), isTerm(Y).
isTerm(f(X)) :- isTerm(X).
isTerm(X) :- alphabet(X).
isTerm(X) :- digit(X).
alphabet(a).
alphabet(b).
digit(0).
digit(1).
