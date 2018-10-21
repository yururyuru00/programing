count_ocr(A, g(X, Y), C) :- count_ocr(A, X, C1), count_ocr(A, Y, C2), C is C1 + C2.
count_ocr(A, f(X), C) :- count_ocr(A, X, C1), C is C1.
count_ocr(A, A, 1).
count_ocr(A, X, 0).

ocr_check(A, g(X, Y)) :- ocr_check(A, X).
ocr_check(A, g(X, Y)) :- ocr_check(A, Y).
ocr_check(A, f(X)) :- ocr_check(A, X).
ocr_check(A, A).
