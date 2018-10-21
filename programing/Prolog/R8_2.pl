:- dynamic above/2, below/2.

above(bicycle, pencil).
above(bird, sandglass).
above(camera, butterfly).
above(apple, fish).

a2b_na :- retract(above(bicycle, pencil)), assert(below(pencil, bicycle)).

a2b :- retract(above(X, Y)), assert(below(Y, X)).

above_to_below :- a2b, above_to_below.
above_to_below.
