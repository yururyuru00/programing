goal([(2,2),(1,3),(2,3),(3,3),(3,2),(3,1),(2,1),(1,1),(1,2)]).

d((T1x, T1y), (T2x, T2y), D) :- D is abs(T1x-T2x) + abs(T1y-T2y).

tot_dist([], [], 0).
tot_dist([(S1x, S1y)|S1], [(S2x, S2y)|S2], D) :- tot_dist(S1, S2, D1), d((S1x, S1y), (S2x, S2y), D2), D is D1+D2.

node(Node, D) :- goal(G), tot_dist(Node, G, D).
