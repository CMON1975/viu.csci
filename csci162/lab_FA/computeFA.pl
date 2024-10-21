computation(P, [], P).

computation(P, [H|T], Q):-
    transition(P,H,X),
    computation(X,T,Q).

accept(String):- computation(s, String, F), final(F).
