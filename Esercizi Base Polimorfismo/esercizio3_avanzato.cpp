#include <iostream>
#include <vector>

class MetodoPagamento {
    public:
        virtual void paga(double importo) const = 0;
        virtual ~MetodoPagamento() = default;
        void pagaConCommisone(double importo, double perCommisione) const {
        double commissione = (importo * perCommisione) /100.0;
        double totale = importo + commissione;
        paga(totale);

        }
};

class CartaCredito : public MetodoPagamento {
    public:
    void paga(double importo) const override {
        std::cout << "Pagato: "<< importo <<"€ con carta di credito" << std::endl;
    }
};
class PayPal : public MetodoPagamento {
public:
    void paga(double importo) const override {
        std::cout << "Pagato: "<< importo <<"€ con PayPal" << std::endl;
    }
};

class Contanti : public MetodoPagamento {
public:
    void paga(double importo) const override {
        std::cout << "Pagato: "<< importo <<"€ con i cash" << std::endl;
    }
};

int main(void) {
    std::vector<MetodoPagamento*> pagamenti;
    pagamenti.push_back(new CartaCredito());
    pagamenti.push_back(new PayPal());
    pagamenti.push_back(new Contanti());

    pagamenti[0]->pagaConCommisone(67.0, 1);
    pagamenti[1]->pagaConCommisone(67.0, 0.67);
    pagamenti[2]->pagaConCommisone(67.0, 0.0);

    for (MetodoPagamento* pag : pagamenti) {
        delete pag;
    }
    return 0;
}





