parent(adam,quinn).
parent(adam,alice).
parent(suzie,quinn).
parent(suzie,alice).
parent(lester,ted).
parent(ada,ted).
parent(frank,mona).
parent(ada,mona).
parent(frank,liz).
parent(frank,pete).
parent(gigi,pete).
parent(ada,liz).
parent(tobias,chester).
parent(tobias,lulu).
parent(finn,chester).
parent(finn,lulu).
parent(quinn,jade).
parent(quinn,spot).
parent(alice,niko).
parent(alice,desiree).
parent(ted,desiree).
parent(mona,spot).
parent(mona,ned).
parent(chester,ned).
parent(liz, fluffy).
parent(pete,opta).
parent(pete, karen).
parent(chester,fluffy).
parent(chester,poopsie).
parent(lulu,karen).
parent(desiree,opta).
parent(ned,niko).
parent(ned,steve).
parent(karen,nick).
parent(karen,poopsie).
parent(niko,stumpy).
parent(spot, stumpy).
parent(spot,wendy).
parent(opta,nick).
parent(fluffy,steve).
parent(stumpy,jade).
parent(steve,lola).
parent(poopsie,lola).
parent(nick,wendy).

female(suzie).
female(ada).
female(gigi).
female(finn).
female(lulu).
female(liz).
female(alice).
female(mona).
female(karen).
female(desiree).
female(niko).
female(poopsie).
female(stumpy).
female(fluffy).

coparents(P1, P2, Child):- parent(P1,Child), parent(P2,Child), P1\==P2.

sibling(X,Y):- parent(Z,X), parent(Z,Y).

sister(X,Y):- sibling(X,Y), female(X).

grandparent(X,Y):- parent(X,Z), parent(Z,Y).

mother(X,Y):- parent(X,Y), female(X).

male(X):- \+(female(X)).
