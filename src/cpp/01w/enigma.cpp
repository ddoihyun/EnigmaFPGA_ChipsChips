#include <iostream>
#include "enigma.h"
using namespace std;

char roterKeys[][27] = { // 0~8 회전자 종류
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ", // 0 : 테스트용
    "EKMFLGDQVZNTOWYHXUSPAIBRCJ", // 1 : 회전자 I
    "AJDKSIRUXBLHWTMCQGZNPYFVOE", // 2 : 회전자 II
    "BDFHJLCPRTXVZNYEIWGAKMUSQO", // 3 : 회전자 III
    "ESOVPZJAYQUIRHXLNFTGKDCMWB", // 4 : 회전자 IV
    "VZBRGITYUPSDNHLXAWMJQOFECK", // 5 : 회전자 V
    "JPGVOUMFYQBENHZRDKASXLICTW", // 6 : 회전자 VI
    "NZJHGRCXMYSWBOUFAIVLPEKQDT", // 7 : 회전자 VII
    "FKQHTLXOCBJSPDZRAMEWNIUYGV"  // 8 : 회전자 VIII
};

char reflectorKeys[][27] = { // 0~5 반사판 종류
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ", // 0 : 테스트용
    "EJMZALYXVBWFCRQUONTSPIKHGD", // 1 : Reflector A
    "YRUHQSLDPXNGOKMIEBFZCWVJAT", // 2 : Reflector B
    "FVPJIAOYEDRZXWGCTKUQSBNMHL", // 3 : Reflector C
    "ENKQAUYWJICOPBLMDXZVFTHRGS", // 4 : Reflector B Dünn
    "RDOBJNTKVEHMLFCWZAXGYIPSUQ"  // 5 : Reflector C Dünn
};

    
Enigma::Enigma(Roter rL, Roter rC, Roter rR, int reflector) {
    this->rL.status = rL.status;
    this->rL.type = rL.type;

    this->rC.status = rC.status;
    this->rC.type = rC.type;

    this->rR.status = rR.status;
    this->rR.type = rR.type;

    this->reflector = reflector;
}

Enigma::Enigma() {
    rL.status = 0, rL.type = 0;
    rC.status = 0, rC.type = 0;
    rR.status = 0, rR.type = 0;
    reflector = 0;
}

void Enigma::showRoters() {
    cout << "Left   : " << rL.type << ' ' << rL.status << endl;
    cout << "Middle : " << rC.type << ' ' << rC.status << endl;
    cout << "Right  : " << rR.type << ' ' << rR.status << endl;
}


char Enigma::generator(char raw) {
    int key = keyConverter(&rL) + keyConverter(&rC) + keyConverter(&rR);
    int result = raw - 'A';

    result = (result + key) % 26;
    result = reflectorKeys[reflector][result];
    result = (result - key + 26) % 26;

    result += 'A'; 
    ++rR.status;
    roterChecker();

    return ( (char)result );
}

int Enigma::keyConverter(Roter *roter) {
    char key = roterKeys[roter->type][roter->status];
    int result = key - 'A';
    return result;
}

void Enigma::roterChecker() {
        if (rR.status > 25)
            rR.status = 0, ++rC.status;
        if (rC.status > 25)
            rC.status = 0, ++rL.status;
        if (rL.status >= 25)
            rL.status = 0;
}