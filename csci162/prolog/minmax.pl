/* take a list of non-negative integers as first arg,
   then return max integer as last arg, via accumulator. */

accMax([H|T],A,Max) :- /* test if head of list is larger than largest val found so far */
   H > A,              /* if so, set accumulator to new value then recurse */
   accMax(T,H,Max).

accMax([H|T],A,Max) :- /* if head less than or equal to accumulator, recurse with acc val */
   H =< A,
   accMax(T,A,Max).

accMax([],A,A).        /* unify 2nd and 3rd args, returning highest val found */

max(List,Max) :-       /* initializes accumulator to head of list to allow for negative integers */
   List = [H|_],
   accMax(List,H,Max).

max([],-9999999).      /* sets max val for empty list */

/* same thing reversed for minimum values */

accMin([H|T],A,Min) :-
   H < A,
   accMin(T,H,Min).

accMin([H|T],A,Min) :-
   H >= A,
   accMin(T,A,Min).

accMin([],A,A).

min(List,Min) :-
   List = [H|_],
   accMin(List,H,Min).

min([],-9999999).
