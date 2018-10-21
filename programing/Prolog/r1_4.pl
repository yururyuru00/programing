age(tom, 80).
age(bob, 58).
age(jim, 2).
age(pam, 76).
age(liz, 55).
age(pat, 27).

senior(X, Y) :- age(X, A), age(Y, B), A > B.
