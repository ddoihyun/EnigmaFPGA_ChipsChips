#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "KarnaughMap.h"

struct Anigma
{
    int first;
    int second;
    int binaryFirst[5];
    int binarySecond[5];
};

void readfile(FILE *fs, struct Anigma anigma[], char *name);
void changeBinary(struct Anigma anigma[]);
void printAnigma(struct Anigma anigma[]);
void makereverse(struct Anigma anigma[], struct Anigma reverse[]);
void printBoth(struct Anigma anigma[], struct Anigma reverse[]);
void makekar(struct Anigma anigma[]);

int main() {
    FILE *fs;
    struct Anigma anigma[3][26];
    struct Anigma reverse[3][26];

    readfile(fs, anigma[0], "reflextable.txt");

    int c = 0;
    makereverse(anigma[c], reverse[c]);
    changeBinary(anigma[c]);
    changeBinary(reverse[c]);
    printBoth(anigma[c], reverse[c]);

    printf("turntable%d:", c+1);
    makekar(anigma[c]);
    printf("\nreverse%d:", c+1);
    makekar(reverse[c]);

    return 0;
}

void readfile(FILE *fs, struct Anigma anigma[], char *name) {
    fs = fopen(name, "r");
    if (fs == NULL) {
        printf("File not found");
        exit(1);
    }
    int i = 0;
    while(!feof(fs)){
        fscanf(fs, "%d", &anigma[i].first);
        fscanf(fs, "%d", &anigma[i].second);
        i++;
    }
}
void changeBinary(struct Anigma anigma[]) {
    for(int i = 0; i < 26; i++) {
        int number = anigma[i].first;
        for (int j = 0; j < 5; j++) {
            anigma[i].binaryFirst[j] = number % 2;
            number /= 2;
        }
    }
    for(int i = 0; i < 26; i++) {
        int number = anigma[i].second;
        for (int j = 0; j < 5; j++) {
            anigma[i].binarySecond[j] = number % 2;
            number /= 2;
        }
    }
}
void printAnigma(struct Anigma anigma[]) {
    for(int i = 0; i < 26; i++) {
        printf("%d\t%d\t", anigma[i].first, anigma[i].second);
        for (int j = 4; j >= 0; j--) {
            printf("%d", anigma[i].binaryFirst[j]);
        }
        printf("\t");
        for (int j = 4; j >= 0; j--) {
            printf("%d", anigma[i].binarySecond[j]);
        }
        printf("\n");
    }
}

void makereverse(struct Anigma anigma[], struct Anigma reverse[]) {
    for(int i = 0; i < 26; i++) {
        reverse[anigma[i].second].first = anigma[i].second;
        reverse[anigma[i].second].second = anigma[i].first;
    }
}

void printBoth(struct Anigma anigma[], struct Anigma reverse[]) {
    for(int i = 0; i < 26; i++) {
        printf("%d\t%d\t", anigma[i].first, anigma[i].second);
        for (int j = 4; j >= 0; j--) {
            printf("%d", anigma[i].binaryFirst[j]);
        }
        printf("\t");
        for (int j = 4; j >= 0; j--) {
            printf("%d", anigma[i].binarySecond[j]);
        }
        printf("\t");
        printf("%d\t%d\t", reverse[i].first, reverse[i].second);
        for (int j = 4; j >= 0; j--) {
            printf("%d", reverse[i].binaryFirst[j]);
        }
        printf("\t");
        for (int j = 4; j >= 0; j--) {
            printf("%d", reverse[i].binarySecond[j]);
        }
        printf("\n");
    }
}

void makekar(struct Anigma anigma[]) {
    for(int indexj = 4; indexj >= 0; indexj--) {
        int sizeofmin = 0;
        for(int i = 0; i < 26; i++) {
            if(anigma[i].binarySecond[indexj] == 1) {
                sizeofmin++;
            }
        }
        int minterms[sizeofmin];
        for(int i = 0, index = 0; i < 26; i++) {
            if(anigma[i].binarySecond[indexj] == 1) {
                minterms[index] = anigma[i].first;
                index++;
            }
        }

        setsetting(sizeofmin, 6);
        map(minterms);
        setreset();
    }
}