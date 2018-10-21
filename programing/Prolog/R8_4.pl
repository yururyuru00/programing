fruit(banana).
fruit(apple).
veg(carrot).
veg(spinach).
can(spam).

contained2([L|L1]) :- L, contained2(L1).
contained2([]).

s1 :- contained2([fruit(apple), can(spam)]).
s2 :- contained2([fruit(banana), veg(cababage)]).
s3 :- contained2([f(banana)]).
