rem(X, Y, Z) :- X1 is X-Y, X1 =< 0, Z is X.
rem(X, Y, Z) :- X1 is X-Y, rem(X1, Y, Z1), Z is Z1.
