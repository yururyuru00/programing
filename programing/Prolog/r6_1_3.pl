subst_atob(g(X, Y), g(A, B)) :- subst_atob(X, A), subst_atob(Y, B).
subst_atob(f(X), f(Y)) :- subst_atob(X, Y).
subst_atob(X, Y) :- alphabet(X, Y).
subst_atob(X, Y) :- digit(X, Y).
alphabet(a, b).
alphabet(b, b).
digit(0, 0).
digit(1, 1).
