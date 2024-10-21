    house_elf(dobby).
    witch(hermione).
    witch('McGonagall').
    witch(rita_skeeter).
    wizard(nobody).
    magic(X):- house_elf(X).
    magic(Y):- wizard(Y).
    magic(Z):- witch(Z).
