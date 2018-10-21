pow2(0, 1).
pow2(X, Y) :- X1 is X-1, pow(X1, Y1) + Y is 2*Y1.

pow(N, 0, 1).
pow(N, X, Y) :- X1 is X-1, pow(N, X1, Y1), Y is N*Y1.

rem3(0, 0).
rem3(1, 1).
rem3(2, 2).
rem3(X, Z) :- X1 is X-3, rem3(X1, Z).

rem(X, Y, Z) :- X1 is X-Y, X1 =< 0, Z is X.
rem(X, Y, Z) :- X1 is X-Y, rem(X1, Y, Z1), Z is Z1.
