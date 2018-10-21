subst_atoc(f(X), f(Y)) :- subst_atoc(X, Y).
subst_atoc(X, Y) :- alphabet(X, Y).
alphabet(a, c).
alphabet(b, b).
