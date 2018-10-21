same_elements([_]).
same_elements([X, X|Z]) :- same_elements([X|Z]).
