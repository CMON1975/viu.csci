transition(s,a,s).
transition(s,c,s).
transition(s,b,s).
transition(s,a,p).
transition(p,a,q).
transition(q,b,r).

final(r).
computation(P,[],P).
computation(P, [H|T], Q):-
  transition(P,H,X),
  computation(X,T,Q).

accept(String):- computation(s, String, F), final(F).