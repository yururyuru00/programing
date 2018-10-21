:- dynamic cond_list/1, del_list/1, add_list/1.

cond_list([CL|CL1]) :- CL, cond_list(CL1).
cond_list([]).
del_list([DL|DL1]) :- retract(DL), del_list(DL1).
del_list([]).
add_list([AL|AL1]) :- assert(AL), add_list(AL1)
add_list([]).

apply_operation(CL, DL, AL) :- cond_list(CL), del_list(DL), add_list(AL).
