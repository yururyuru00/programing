parent(pam, bob).
parent(tom, bob).
parent(bob, pat).
parent(pat, jim).
parent(tom, liz).

male(tom).
male(bob).
male(jim).

female(pam).
female(liz).
female(pat).

father(X, Y) :- parent(X, Y), male(X).

ok :- father(tom, bob).

grandfather(X, Y) :- parent(Z, Y), parent(X, Z), male(X).

ancestor(X, Y) :- parent(X, Y).
ancestor(X, Y) :- parent(X, Z), ancestor(Z, Y).

right_of(bird, bicycle).
right_of(camera, bird).
right_of(apple, camera).
right_of(sandglass, pencil).
right_of(butterfly, sandglass).
right_of(fish, butterfly).

above(bicycle, pencil).
above(bird, sandglass).
above(camera, butterfly).
above(apple, fish).

left_of(Obj1, Obj2) :- right_of(Obj2, Obj1).
below(Obj1, Obj2) :- above(Obj2, Obj1).
upper_right(Obj1, Obj2) :-  above(Obj3, Obj2), right(Obj1, Obj3).
right(Obj1, Obj2) :- right_of(Obj1, Obj2).
right(Obj1, Obj2) :- right_of(Obj1, Obj3), right(Obj3, Obj2).

age(tom, 80).
age(bob, 58).
age(jim, 2).
age(pam, 76).
age(liz, 55).
age(pat, 27).

senior(X, Y) :- age(X, A), age(Y, B), A > B.

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


edge(a, b).
edge(b, c).
edge(b, d).
edge(c, e).
edge(d, e).
edge(f, g).

connected(N, M) :- edge(N, M).
connected(N, M) :- edge(N, Z), connected(Z, M).
