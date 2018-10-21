failures([(A1, A2)|L1], N) :- A1<60, failures(L1, N1), N is N1+1.
failures([(A1, A2)|L1], N) :- A2<60, failures(L1, N1), N is N1+1.
failures([(A1, A2)|L1], N) :- failures(L1, N).
failures([], 0).
