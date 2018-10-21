edge(a, b).
edge(b, c).
edge(b, d).
edge(c, e).
edge(d, e).
edge(f, g).

dist(N, N, 0).
dist(N, M, L) :- edge(M1, M), dist(N, M1, L1), L is L1 + 1.

(i) 論理的意味
ノードN,M間の辺数Lは終着点Mの一個手前までの辺数L1 + より一歩多い

(ii) [trace]  ?- dist(a, e, D).
   Call: (8) dist(a, e, _1950) ? creep
      dist(N, M, L)と単一化
   Call: (9) edge(_2164, e) ? creep
      条件文一個目、edge(M1, M)の単一化
   Exit: (9) edge(c, e) ? creep
      call(9)に対してDBから探し見つかった二つのDBから一つ目のedge(c, e)と単一化して
      出力
   Call: (9) dist(a, c, _2168) ? creep
      二つ目の条件式を単一化。自分の関数を新たに呼び出しているため、再帰処理になる
   Call: (10) edge(_2164, c) ? creep
      条件文一つ目edge(M1, M)と単一化
   Exit: (10) edge(b, c) ? creep
      DBから探し、見つかったedge(b, c)と単一化する
   Call: (10) dist(a, b, _2168) ? creep
      二つ目の条件式を単一化。自分の関数を新たに呼び出しているため二回目の再帰処理
   Call: (11) edge(_2164, b) ? creep
      一つ目の条件式を単一化する。
   Exit: (11) edge(a, b) ? creep
      DBから探し見つかったedge(a, b)と単一化し出力
   Call: (11) dist(a, a, _2168) ? creep
      二つ目の条件式を単一化するがdist(a, a)は今までと異なり、単一化する形は
      dist(N, M, L)ではなく、dist(N, N, 0)のためそちらに単一化
      ついにdist()の三つ目の引数が実数として求まったためここから巻き戻る形
   Exit: (11) dist(a, a, 0) ? creep
      call(11)より単一化したものを出力
   Call: (11) _2170 is 0+1 ? creep
      二回目の再帰処理の二つ目の条件文のdist(N, M1, L1)のL1の値が分かったため、
      三つ目の条件文のL is L1 + 1の部分が実行できる
   Exit: (11) 1 is 0+1 ? creep
      call(11)のLの部分を出力する
   Exit: (10) dist(a, b, 1) ? creep
   Call: (10) _2176 is 1+1 ? creep
   Exit: (10) 2 is 1+1 ? creep
      以下、同様L1が分かればL1に+1して出力する操作を繰り返す
   Exit: (9) dist(a, c, 2) ? creep
   Call: (9) _1950 is 2+1 ? creep
   Exit: (9) 3 is 2+1 ? creep
   Exit: (8) dist(a, e, 3) ? creep
D = 3 ;
   Redo: (11) dist(a, a, _2168) ? creep
   Call: (12) edge(_2164, a) ? creep
   Fail: (12) edge(_2164, a) ? creep
   Fail: (11) dist(a, a, _2168) ? creep
   Fail: (10) dist(a, b, _2168) ? creep
   Fail: (9) dist(a, c, _2168) ? creep
   Redo: (9) edge(_2164, e) ? creep
   Exit: (9) edge(d, e) ? creep
   Call: (9) dist(a, d, _2168) ? creep
   Call: (10) edge(_2164, d) ? creep
   Exit: (10) edge(b, d) ? creep
   Call: (10) dist(a, b, _2168) ? creep
   Call: (11) edge(_2164, b) ? creep
   Exit: (11) edge(a, b) ? creep
   Call: (11) dist(a, a, _2168) ? creep
   Exit: (11) dist(a, a, 0) ? creep
   Call: (11) _2170 is 0+1 ? creep
   Exit: (11) 1 is 0+1 ? creep
   Exit: (10) dist(a, b, 1) ? creep
   Call: (10) _2176 is 1+1 ? creep
   Exit: (10) 2 is 1+1 ? creep
   Exit: (9) dist(a, d, 2) ? creep
   Call: (9) _1950 is 2+1 ? creep
   Exit: (9) 3 is 2+1 ? creep
   Exit: (8) dist(a, e, 3) ? creep
D = 3 .

(iii)　正しくできた
