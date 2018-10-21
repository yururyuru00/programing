node(s, a).
node(s, b).
node(a, c).
node(a, e).
node(b, d).
node(c, d).
node(c, e).
node(d, f).
node(e, g).
node(f, c).
node(f, h).
node(f, g).
node(h, g).


start(s).
goal(g).

dfs_loop(Path) :- dfs_loop(Path, []).
dfs_loop(Path, []) :- start(N), goal(M), howto(N, M, Path, [N]).

howto(M, M, Ans, Ans).
howto(N, M, Path, Ans) :- node(N, N1), not(member(N1, Ans)), howto(N1, M, Path, [N1|Ans]).
