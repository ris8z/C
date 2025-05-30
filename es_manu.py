
class Docente():
    def __init__(self, name, surname, age, typeDoc="Ordinario"):
        self.name = name
        self.surname = surname 
        self.age = age
        self.typeDoc = typeDoc

    def __str__(self):
        return f"Docente:{self.name}, {self.surname}, {self.age}, {self.typeDoc}"

    def __repr__(self):
        return self.__str__() + "\n"


class Uni():
    def __init__(self, name, city, tot_corsi, lst_docenti = None):
        self.name = name
        self.city = city
        self.tot_corsi = tot_corsi

        if lst_docenti is None:
            self.lst_docenti = []
        else:
            self.lst_docenti = lst_docenti

    def __str__(self):
        return f"{self.name}, {self.city}, {self.tot_corsi}, {self.lst_docenti}"

    def __repr__(self):
        return self.__str__()

    def youngestdoc(self):
        guess = None

        for doc in self.lst_docenti:
            if (guess is None) or (guess.age > doc.age):
                guess = doc

        return guess

    def __eq__(self, other):
        if type(self) != type(other):
            return False
        return self.tot_corsi > other.tot_corsi





def main():
    doc1 = Docente("Paolo", "baudo", 34)

    doc2 = Docente("zioPeppe", "baudo", 34, "matematica")

    doc3 = Docente("Waleed", "baudo", 23, "matematica")

    u1 = Uni("FedII", "Napoli", 47, [doc1, doc2, doc3])
    
    u2 = Uni("FedII", "Napoli", 20, [doc1, doc2, doc3])

    print(u1 == u2)
    print(u1.__eq__(u2))

    print(u2.__eq__(u1))
    print(u2 == u1)

    u1.lst_docenti.append(Docente('nuovodoc', 'wasd', 18, "arte"))
    print(u1)


main()





trick per gli oggetti mutabili nel costruttore (__init__)
forte su i dunder method (__str__, __repr__, __init__, __add__, __eq__, __gt)
runna il tuo codice hai tempo tanto, ne vale la pena
Linear serach, trova numero piu grande e piu 
