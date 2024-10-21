domains
    list = integer*.
    Max = integer.
predicates
    maximum_no(list,integer).
clauses
    maximum_no([],Max):-
    write("Maximum No in List is:: ",Max),nl.
    maximum_no([H|T],Max):-
    H>Max,
    N = H,
    maximum_no(T,N).
    maximum_no(L,Max):-
    maximum_no(L,Max).
