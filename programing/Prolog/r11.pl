increase([]).
increase([_]).
increase([X, Y|Z]) :- X =< Y, increase([Y|Z]).
