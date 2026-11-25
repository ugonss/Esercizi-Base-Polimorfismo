#include <iostream>
#include <vector>
#include <string>

class Notifica {
    public:
    virtual void invia(std::string messaggio) const = 0;
    virtual ~Notifica() = default;
};

class NotificaEmail: public Notifica {
    public:
    void invia(std::string messaggio) const override {
        std::cout <<"Email: " << messaggio << std::endl;
    }
};

class NotificaSMS: public Notifica {
public:
    void invia(std::string messaggio) const override {
        std::cout <<"NotificaSMS: "<< messaggio << std::endl;
    }
};

class NotificaPush: public Notifica {
public:
    void invia(std::string messaggio) const override {
        std::cout <<"NotificaPush: "<< messaggio << std::endl;
    }
};

class GestoreNotifiche {
    private:
    std::vector<Notifica*> notifiche;
    public:
    void aggiungi(Notifica* n) {
        notifiche.push_back(n);
    }
    void inviaATutti(std::string messaggio) const {
        for (Notifica* n : notifiche) {
            n->invia(messaggio);
        }
    }

};

int main(void) {
    NotificaEmail email;
    NotificaSMS sms;
    NotificaPush push;

    GestoreNotifiche gestore;
    gestore.aggiungi(&email);
    gestore.aggiungi(&sms);
    gestore.aggiungi(&push);

    gestore.inviaATutti("Bella a tutti argazzi");

    return 0;
}