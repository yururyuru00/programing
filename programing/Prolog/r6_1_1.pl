isTm(X) :- alphabet(X).
isTm(f(X)) :- isTm(X).
alphabet(a).
alphabet(b).

my_copy_term(f(X), f(X)) :- my_copy_term(X, X).
my_copy_term(X, X) :- alphabet(X, X).
alphabet(a, a).
alphabet(b, b).
