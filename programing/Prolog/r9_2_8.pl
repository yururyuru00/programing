picnic1(Day) :- holiday(Day), sunny(Day).
picnic2(Day) :- holiday(Day), !, sunny(Day).
holiday(saturday).
holiday(sunday).
sunny(sunday).

[trace]  ?- picnic1(Xday).
   Call: (8) picnic1(_1946) ? creep
   Call: (9) holiday(_1946) ? creep
   Exit: (9) holiday(saturday) ? creep
   Call: (9) sunny(saturday) ? creep
   Fail: (9) sunny(saturday) ? creep
   Redo: (9) holiday(_1946) ? creep
   Exit: (9) holiday(sunday) ? creep
   Call: (9) sunny(sunday) ? creep
   Exit: (9) sunny(sunday) ? creep
   Exit: (8) picnic1(sunday) ? creep
Xday = sunday.

[trace]  ?- picnic2(Xday).
   Call: (8) picnic2(_1946) ? creep
   Call: (9) holiday(_1946) ? creep
   Exit: (9) holiday(saturday) ? creep
   Call: (9) sunny(saturday) ? creep
   Fail: (9) sunny(saturday) ? creep
   Fail: (8) picnic2(_1946) ? creep
false.

以上のようにカットオペレーターは別解を求めるような場合に
効果を発揮することが分かった。
上のように解が複数ある場合→holiday(saturday), holiday
(sunday)に関しては、もし次の述語sunny()で単一化が失敗し
バックトラック(別解探し)をする場合でもカットオペレーター
がある場合には今まで通り別解を探しに行き、ある場合には
別解を探しに行かずそのままfalseを出力してしまった。
ここから分かるようにカットオペレーターを用いて効率化する
ときはDBの様子を見ながら、条件の厳しい述語(別解がない)述語
をカットオペレーターの前に置き、カットオペレーターのあとに
条件の浅い述語(別解が多い)を置くほうが正しい解を期待できる
と思った。
