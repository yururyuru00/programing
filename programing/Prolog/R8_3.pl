fruit(banana).
fruit(apple).
fruit(grape).

contained([L|L1]) :- fruit(L), contained(L1).
contained([]).

t1 :- contained([apple, banana]).
t2:- contained([orange]).
