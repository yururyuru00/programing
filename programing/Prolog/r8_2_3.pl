goods(riceball,new).
goods(lunchbox,new).
goods(sandwitch,new).
goods(milk,new).
goods(yogult,old).
goods(tea,old).

check([L|L1]) :- goods(L, new), check(L1).
check([]). 
