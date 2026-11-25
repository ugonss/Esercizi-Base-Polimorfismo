#include <iostream>

class Veicolo{
public:
    virtual void muovi () const = 0;
    virtual void descrizione () const = 0;

    virtual ~Veicolo() = default;
};

class Auto: public Veicolo{
public:
    void muovi() const override {
        std::cout << "L'auto accelera sull'asfalto" << std::endl;
    }

    void descrizione() const override {
        std::cout << "L'auto ha 4 ruote" <<std::endl;
    }
};

class Bicicletta: public Veicolo{
public:
    void muovi() const override {
        std::cout << "La bicicletta impenna" << std::endl;
    }

    void descrizione() const override {
        std::cout << "La bicicletta ha 2 ruote" <<std::endl;
    }
};

class Treno: public Veicolo{
public:
    void muovi() const override {
        std::cout << "Il treno parte dal binario" << std::endl;
    }

    void descrizione() const override {
        std::cout << "Il treno ha molte ruote" <<std::endl;
    }
};

int main(void){
    Veicolo* v = new Auto();
    v->muovi();
    v->descrizione();

    delete v;

    Veicolo* v1 = new Bicicletta();
    v1->muovi();
    v1->descrizione();

    delete v1;

    Veicolo* v2 = new Treno();
    v2->muovi();
    v2->descrizione();

    delete v2;

    return 0;
}




