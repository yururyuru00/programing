count_ocr(A, g(X, Y), C) :- count_ocr(A, X, C1), count_ocr(A, Y, C2), C is C1 + C2.
count_ocr(A, f(X), C) :- count_ocr(A, X, C1), C is C1.
count_ocr(A, A, 1).
count_ocr(A, X, 0).
