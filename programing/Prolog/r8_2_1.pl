:-dynamic right/2, left/2.

right(apple, orange).
right(lemon, apple).


update_db :- retract(right(X, Y)), assert(left(Y, X)), update_db.
update_db.
