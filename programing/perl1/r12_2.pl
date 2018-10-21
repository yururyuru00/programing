d((T1x, T1y), (T2x, T2y), D) :- D is abs(T1x-T2x) + abs(T1y-T2y).

tot_dist([], [], 0).
tot_dist([(S1x, S1y)|S1], [(S2x, S2y)|S2], D) :- tot_dist(S1, S2, D1), d((S1x, S1y), (S2x, S2y), D2), D is D1+D2.
