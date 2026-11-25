#include <iostream>
#include <vector>

class Personaggio{
public:
    virtual void attacca() const = 0;
    virtual void presentati() const = 0;

    virtual ~Personaggio() = default;
};

class Guerriero: public Personaggio{
    public:
    void attacca() const override{
        std::cout << "Uso la spada"<< std::endl;
    }
    void presentati() const override{
        std::cout << "Il mio nome è Matteo ma tutti mi conoscono come belisario_mat: ";
    }
};

class Mago: public Personaggio{
    public:
    void attacca() const override{
        std::cout << "Uso la magia nera"<< std::endl;
    }
    void presentati() const override{
        std::cout << "Il mio nome è Samuel ma tutti mi conoscono come cody: " ;
    }
};

class Arciere: public Personaggio{
public:
    void attacca() const override{
        std::cout << "Uso l'arco incantato"<< std::endl;
    }
    void presentati() const override{
        std::cout << "Il mio nome è Mattia ma tutti mi conoscono come ppaschee: " ;
    }
};

void turno(Personaggio* p){
    p->presentati();
    p->attacca();
};

int main(void){
    std::vector<Personaggio*> personaggi;
    personaggi.push_back(new Guerriero());
    personaggi.push_back(new Mago());
    personaggi.push_back(new Arciere());

    for(Personaggio* v : personaggi) {
        turno(v);
    }

    for (Personaggio* p : personaggi) {
        delete p;
    }

        return 0;
}