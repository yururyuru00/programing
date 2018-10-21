arith_prog([X, Y|Z]) :- Diff is Y-X, arith_prog([Y|Z], Diff).

arith_prog([_], Diff).
arith_prog([X, Y|Z], Diff) :- Diff =:= Y-X, arith_prog([Y|Z], Diff).
