isTm(X) :- alphabet(X).
isTm(f(X)) :- isTm(X).
alphabet(a).
alphabet(b).
