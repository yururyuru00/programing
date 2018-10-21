isFormula(neg(Atm)) :- isFormula(Atm).
isFormula(and(Atm1, Atm2)) :- isFormula(Atm1), isFormula(Atm2).
isFormula(or(Atm1, Atm2)) :- isFormula(Atm1), isFormula(Atm2).
isFormula(imp(Atm1, Atm2)) :- isFormula(Atm1), isFormula(Atm2).
isFormula(p).
isFormula(q).
isFormula(r).
