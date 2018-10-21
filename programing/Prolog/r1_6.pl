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
