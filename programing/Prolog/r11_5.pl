elim(sum(A, B), sum(X, Y)) :- elim(A, X), elim(B, Y).
elim(diff(A, B), sum(X, Y)) :- elim(A, X), elim(minus(B), Y).
elim(minus(minus(A)), X) :- elim(A, X).
elim(minus(A), minus(X)) :- elim(A, X).
elim(A, A).
