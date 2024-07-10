#include <stdio.h>
#include <iostream>
#include "enigma.h"
using namespace std;

int main() {
    Roter left, middle, right;
    int reflector;

    printf("장착할 로터를 입력해주세요 (1-8범위, L->C->R순) : ");
    scanf("%d %d %d", &left.type, &middle.type, &right.type);

    printf("다이얼의 넘버를 입력해주세요 (0-25[A-Z]범위, L->C->R순) : ");
    scanf(" %d %d %d", &left.status, &middle.status, &right.status);
    getchar();

    printf("반사판의 종류를 입력해주세요\n");
    printf("1) Reflector A\n");
    printf("2) Reflector B\n");
    printf("3) Reflector C\n");
    printf("4) Reflector B Dünn\n");
    printf("5) Reflector C Dünn\n");
    printf(" : ");
    scanf(" %d", &reflector);


    Enigma *chips = new Enigma(left, middle, right, reflector);
    chips->showRoters();

    char typo = 0;
    printf("input : ");
    scanf(" %c", &typo);

    while (typo != '!') {
        if (!isalpha(typo)) {
            cout << "영문자(A-Z) 범위만 입력 가능합니다!" << endl;
            printf("input : ");
            scanf(" %c", &typo);
            continue;    
        }

        cout << "변환 결과는 ";
        typo = toupper(typo);
        cout << chips->generator(typo) << "입니다.\n" << endl;
        chips->showRoters();

        cout << "input : ";
        while(getchar() != '\n');
        scanf(" %c", &typo);
        cout << endl;
    }

    return 0;
}