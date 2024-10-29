sift([],[]).

sift([X|T],[X|Result]):- X > 6,	/* is X greater than 6 */

   sift(T,Result).              /* if so then go find the rest */

sift([ThrowAway|Tail],Result):- /* discard the head */

   sift(Tail,Result).           /* and look in the tail */