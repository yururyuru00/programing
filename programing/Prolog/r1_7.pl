lecture(mediasyakairon, mon, 1).
lecture(tishikijyouhousyori_1, mon, 2).
lecture(keisanron, mon, 3).
lecture(suurikeikakuhou, mon, 4).
lecture(jyouhousyorigijyutu, tues, 1).
lecture(hugouriron, tues, 2).
lecture(tishikijyouhousyori, tues, 3).
lecture(saitekikariron, tues, 4).
lecture(suurironnrigaku, wed, 1).
lecture(ryouiki, wed, 2).
lecture(operatingSystem, wed, 4).
lecture(suushikisyori, fri, 1).
lecture(compiler, fri, 2).
lecture(modeling, fri, 3).

tuesday(X) :- lecture(X, tues, A).
correct(0) :- lecture(tishikijyouhousyori, tues, 3),
lecture(tishikijyouhousyori_1, mon, 2).
