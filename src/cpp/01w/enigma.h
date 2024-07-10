#ifndef ENIGMA_H
#define ENIGMA_H

typedef struct roter {
    int status;
    int type;
} Roter;

class Enigma {
    private:
        Roter rL, rC, rR;
        int reflector;
    
    public:
        Enigma(Roter, Roter, Roter, int);
        Enigma();

        void showRoters();

        char generator(char);
        int keyConverter(Roter*);

        void roterChecker();
};

#endif