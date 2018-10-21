d((T1x, T1y), (T2x, T2y), D) :- D is abs(T1x-T2x) + abs(T1y-T2y).
tot_dist([], [], 0).
tot_dist([(S1x, S1y)|S1], [(S2x, S2y)|S2], D) :- tot_dist(S1, S2, D1), d((S1x, S1y), (S2x, S2y), D2), D is D1+D2.
node(Node, D) :- goal(G), tot_dist(Node, G, D).

swap(E, L1, [L1|L], [E|L]) :- d(E, L1, D), D=<1.
swap(E, T, [L|L1], [L|L2]) :- swap(E, T, L1, L2).

edge([L1|L], [T|L2]) :- swap(L1, T, L, L2).

start_a([(2,3),(1,3),(2,2),(3,3),(3,2),(3,1),(2,1),(1,1),(1,2)]).
start_c([(2,2),(1,3),(3,2),(2,3),(3,3),(3,1),(2,1),(1,1),(1,2)]).
start_d([(2,1),(1,2),(1,3),(3,3),(3,2),(3,1),(2,2),(1,1),(2,3)]).
goal([(2,2),(1,3),(2,3),(3,3),(3,2),(3,1),(2,1),(1,1),(1,2)]).

he_puzzle_2(Path) :- start_d(N), goal(M), climb(N, M, Path, [N]).
climb(M, M, FinalAns, FinalAns).
climb(N, M, FinalAns, Ans) :- setof(N1, edge(N, N1), ListAll), min(ListAll, Path), not(member(Path, Ans)), climb(Path, M, FinalAns, [Path|Ans]).

min([L1|L], FinalAns) :- node(L1, D), min(L, D, L1, FinalAns).
min([], D, Ans, Ans).
min([L1|L], D, Ans, FinalAns) :- node(L1, Dnew), Dnew < D, min(L, Dnew, L1, FinalAns).
min([L1|L], D, Ans, FinalAns) :- node(L1, Dnew), Dnew = D, min(L, Dnew, L1, FinalAns).
min([L1|L], D, Ans, FinalAns) :- min(L, D, Ans, FinalAns).
