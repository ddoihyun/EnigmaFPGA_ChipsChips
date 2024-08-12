/* Yoon hongha / 22000484 / Electrical Engineering / Sophomore
Logic Design class01 */
#define Minterm     1
#define Dont_care   2
#define True        1
#define False       0
#define Null       '\0'
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
    char* encod;
    char* decod;
};

int n, num_of_total_min, num_of_minterm, num_of_dc, num_of_elements;
int prime_num=0;
int cover_num=0;
int changed;

int po_2(int x);            // 2^n에 해당하는 값을 정수형으로 반환
void show_interface();      // 변수 개수, minterm개수, don't care개수 에 대한 입출력함수
void input_data(struct data* minterm);                  // minterm 번호, don't care 번호 입력받는 함수
void str_reset(int size, char* space, char clear);      // string array에서 지정된 size까지의 공간을 원하는 값으로 초기화하는 함수
void incoding(int decimal, struct data* binary, int type);          // decimal로 표현된 minterm 값을 encoding 값으로 표현하는 함수
void combining(char* a, char* b,char* tmp);             //두 원소의 encoding 값을 비교하여 차이가 1개라면 합치고, 여러개가 다르다면 않는다면 null을 반환하는 함수
void data_move(int range, struct data* copy, struct data* orign);   // data structure를 이동시키며 기존 공간은 초기화하는 함수
void orgate(char* in_A, char* in_B, char* out);         // 두 minterm의 decoding 값을 합쳐주는 함수
void list_pi(struct data* input, struct data* output, struct data* prime,int visit);
//inout array 중에서 다른 원소와 합쳐지는 값은 합쳐진 값을 다음 list로, 그렇지 않은 값은 prime array로 보내는 함수
void find_epi(struct data* pi, struct data* cover);     // epi를 찾아내 epi와 관련된 값을 전부 제거하는 함수
void delete_col(struct data* pi);       // column dominating 관계를 찾아 불필요한 column을 제거하는 함수
void delete_row(struct data* pi);       // row dominating 관계를 찾아 불필요한 row를 제거하는 함수
void move_row(struct data* list, int index);            // row를 제거할 때 PI를 하나하나 옮기고 마지막 번호를 지워주는 함수
void convert(char* text);               // binary로 표현된 string을 X1X2... 의 값으로 변환해서 출력하는 함수
void convert2(char* text);
void setsetting(int NumberofM, int NumberofD);
void input_Binary(struct data* minterm, int mintermNum[]);


int map(int numberofminterms[]){
    num_of_elements=num_of_minterm+num_of_dc; //f=1 을 만들기 위해 필요한 전체 원소의 개수
    /*minterm이 2^n개일 때, List2의 element는 최대 n*2^(n-1)개 존재할 수 있다.*/
    struct data* minterm = (struct data*)malloc(num_of_elements*sizeof(struct data));     //minterm과 don't care의 집합
    struct data* prime = (struct data*)malloc(num_of_elements*sizeof(struct data));       //PI의 집합
    struct data* list_i = (struct data*)malloc((num_of_elements*n/2)*sizeof(struct data));
    struct data* list_o = (struct data*)malloc((num_of_elements*n/2)*sizeof(struct data));
    for(int index=0;index<num_of_elements;index++){     //minterm 공간 할당, prime array의 공간 할당 및 초기화
        minterm[index].encod=(char*)malloc((n+1)*sizeof(char));
        minterm[index].decod=(char*)malloc((num_of_total_min+1)*sizeof(char));
        prime[index].encod=(char*)malloc((n+1)*sizeof(char));
        prime[index].decod=(char*)malloc((num_of_total_min+1)*sizeof(char));
        str_reset(n+1,prime[index].encod,Null);
        str_reset(num_of_total_min+1,prime[index].decod,Null);
    }
    for(int index=0;index<num_of_elements*n/2;index++){     //list_i,o 의 공간 할당 및 초기화
        list_i[index].encod=(char*)malloc((n+1)*sizeof(char));
        list_i[index].decod=(char*)malloc((num_of_total_min+1)*sizeof(char));
        list_o[index].encod=(char*)malloc((n+1)*sizeof(char));
        list_o[index].decod=(char*)malloc((num_of_total_min+1)*sizeof(char));
        str_reset(n+1,list_i[index].encod,Null);
        str_reset(num_of_total_min+1,list_i[index].decod,Null);
        str_reset(n+1,list_o[index].encod,Null);
        str_reset(num_of_total_min+1,list_o[index].decod,Null);
    }
    
    input_Binary(minterm, numberofminterms);


    data_move(num_of_elements, list_i, minterm);    //list_pi 함수의 최초 input list를 minterm array로 설정
    int list_num=0;
    do{                                             //변하는 값이 없을 때 까지 list_pi를 찾는 과정을 반복
        changed=False;
        list_pi(list_i, list_o, prime, list_num);
        data_move(num_of_elements*n/2,list_i,list_o);
        list_num++;
    }while(changed);
    

    //PI 리스트에 대한 Debuging or Inspection을 위한 출력함수
    /*printf("\n");
    printf("------prime implement------\n");
    for(int index=0;index<prime_num;index++){
        printf("%s, ",prime[index].encod);
        printf("%s\n",prime[index].decod);
    }*/


    struct data* cover = (struct data*)malloc(prime_num*sizeof(struct data));   //최종 cover를 담을 pointer array. 최대 size는 prime_num
    for(int index=0;index<prime_num;index++){                                   //cover array 의 공간 할당 및 초기화
        cover[index].encod = (char*)malloc((n+1)*sizeof(char));
        str_reset(n+1,cover[index].encod,Null);
    }

    do{                         //변하는 값이 없을 때 까지 cover를 찾는 과정 반복
        changed=False;
        find_epi(prime, cover);
        delete_col(prime);
        delete_row(prime);
    }while(changed);


    //최종 출력
    printf("\nf = ");
    for(int index=0;index<cover_num;index++){
        if(index!=0)
            printf(" + ");
        convert2(cover[index].encod);
    }


    //공간 deallocation
    for(int index=0;index<num_of_elements*n/2;index++){
        free(list_i[index].encod);
        free(list_i[index].decod);
        free(list_o[index].encod);
        free(list_o[index].decod);
        if(index>=num_of_elements)  continue;
        free(minterm[index].encod);
        free(minterm[index].decod);
        free(prime[index].encod);
        free(prime[index].decod);
        if(index>=prime_num)    continue;
        free(cover[index].encod);
    }
    free(list_i);
    free(list_o);
    free(minterm);
    free(prime);
    free(cover);
    

    return 0;
}

void convert(char* text){
    for(int i=0;i<n;i++){
        if(text[i]=='0')            //string의 값이 '0'일 경우 Xi'
            printf("x%d'",i+1);
        else if(text[i]=='1')       //string의 값이 '1'일 경우 Xi
            printf("x%d",i+1);
    }
}

void convert2(char* text){
    for(int i=0;i<n;i++){
        switch(i) {
            case 0:
                if(text[i]=='0')            //string의 값이 '0'일 경우 Xi'
                    printf("!A");
                else if(text[i]=='1')       //string의 값이 '1'일 경우 Xi
                    printf("A");
                continue;
            case 1:
            if(text[i]=='0')            //string의 값이 '0'일 경우 Xi'
                printf("!B");
            else if(text[i]=='1')       //string의 값이 '1'일 경우 Xi
                printf("B");
                continue;
            case 2:
            if(text[i]=='0')            //string의 값이 '0'일 경우 Xi'
                printf("!C");
            else if(text[i]=='1')       //string의 값이 '1'일 경우 Xi
                printf("C");
                continue;
            case 3:
            if(text[i]=='0')            //string의 값이 '0'일 경우 Xi'
                printf("!D");
            else if(text[i]=='1')       //string의 값이 '1'일 경우 Xi   
                printf("D");
                continue;
            case 4:
            if(text[i]=='0')            //string의 값이 '0'일 경우 Xi'
                printf("!E");
            else if(text[i]=='1')       //string의 값이 '1'일 경우 Xi
                printf("E");
                continue;
            default :
                continue;
        }

    }
}

void delete_col(struct data* pi){
    for(int z=0;z<num_of_total_min;z++){
        int dominating[num_of_total_min];       //z번째 column을 기준으로 각 column의 dominating 관계를 기록하는 array
        for(int j=0;j<num_of_total_min;j++)
            dominating[j]=0;                    //domination 관계 : -1 = dominating하지 않음 / 0 = 자기 자신 / 1 = dominating

        for(int x=0;x<prime_num;x++){
            if(pi[x].decod[z]=='1'){            //z번째 column이 어떠한 PI를 포함할 때
                for(int k=0;k<num_of_total_min;k++){
                    if(k==z)    continue;       //dominating[z]는 0으로 내버려 두며

                    if ((pi[x].decod[k]=='1')&&(dominating[k]>-1))  //k번째 column이 dominating을 유지하며 같은 PI를 포함한다면, dominating 지속
                        dominating[k]=1;
                    else dominating[k]=-1;                          //k번째 column이 같은 PI를 포함하지 않는다면 dominating 관계 종료
                }
            }
        }

        for(int k=0;k<num_of_total_min;k++){
            if(dominating[k]==1){               //z번째 column을 dominate하는 어떠한 column에 대하여
                for(int i=0;i<prime_num;i++)
                    pi[i].decod[k]='0';         //해당 column(minterm 번호)을 제거
                changed=True;
            }
        }
    }
}

void delete_row(struct data* pi){
    for(int x=0;x<prime_num;x++){
        int dominating[prime_num];      //x번째 row를 기준으로 각 row의 dominating 관계를 기록하는 array
        for(int j=0;j<prime_num;j++)
            dominating[j]=0;            //domination 관계 : -1 = dominating하지 않음 / 0 = 자기 자신 / 1 = dominating

        for(int z=0;z<num_of_total_min;z++){
            if(pi[x].decod[z]=='1'){                //x번째 row가 어떠한 minterm을 포함할 때
                for(int k=0;k<prime_num;k++){
                    if(k==x)    continue;           //dominating[x]는 0으로 내버려 두며

                    if ((pi[k].decod[z]=='1')&&(dominating[k]>-1))  //k번째 row가 dominating을 유지하며 같은 minterm을 포함한다면, dominating 지속
                        dominating[k]=1;
                    else dominating[k]=-1;                          //k번째 row가 같은 minterm을 포함하지 않는다면 dominating 관계 종료
                }
            }
        }

        for(int k=0;k<prime_num;k++){
            if(dominating[k]==1){       //x번째 row가 어떠한 row에 의해 dominate 된다면
                move_row(pi,x--);     //x번째 row를 prime array에서 제거
                changed=True;
                break;
            }
        }
    }
}

void find_epi(struct data* pi, struct data* cover){
    int count,epi_num;
    for(int z=0;z<num_of_total_min;z++){
        count=0;

        for(int x=0;x<prime_num;x++){       //z번째 minterm을 포함하는 pi를 확인
            if(pi[x].decod[z]=='1'){
                epi_num=x;
                count++;
            }
        }

        if(count==1){                       //z번째 minterm을 포함하는 pi가 1개뿐일때
            strcpy(cover[cover_num++].encod, pi[epi_num].encod);

            for(int i=0;i<num_of_total_min;i++)     //epi에 해당하는 minterm 번호를 제거
                if(pi[epi_num].decod[i]=='1')
                    for(int j=0;j<prime_num;j++)
                        pi[j].decod[i]='0';

            move_row(pi,epi_num);                 //prime array에서 epi 자리를 제거
            changed=True;
        }
    }
}

void move_row(struct data* list, int index){
    while(index+1<prime_num){
        strcpy(list[index].encod, list[index+1].encod);
        strcpy(list[index].decod, list[index+1].decod);
        index++;
    }
    str_reset(n, list[index].encod, Null);
    str_reset(num_of_total_min, list[index].decod, Null);
    prime_num--;
}

void list_pi(struct data* input, struct data* output, struct data* prime, int visit){
    // Debuging or Inspection을 위한 출력함수
    /*printf("-----list%d-------\n",visit+1);
    for(int index=0;index<num_of_elements*n/2;index++){
        if(*input[index].encod == Null) break;
        printf("%s, ", input[index].encod);
        printf("%s\n", input[index].decod);
    }*/
    int x_out=0;
    static int repeat;
    repeat = (visit==0)? num_of_elements:repeat; //현재 반복 횟수는 이전 실행과정에서 output으로 넘겨진 원소의 개수, 처음일 경우 num_of_elements
    char combine[n+1];

    for(int i=0;i<repeat;i++){
        int not_combined=True;

        for(int j=0;j<repeat;j++){
            if(i==j)    continue;               //자기 자신과는 combine 하지 않음

            combining(input[i].encod, input[j].encod, combine);

            if(*combine){                       //combine에 값이 유효하다면
                not_combined=False;
                int dup=False;

                for(int k=0;k<x_out;k++)
                    if(strcmp(output[k].encod,combine)==0){    //현재 combine 한 값이 output list에 이미 있다면 중복되었다고 알림
                        dup=True;
                        break;
                    }

                if(dup) continue;                               //현재 combine 한 값이 중복되어있다면 output으로 보내는 작업을 생략함
                strcpy(output[x_out].encod,combine);
                orgate(input[i].decod, input[j].decod, output[x_out].decod);
                x_out++;
                changed=True;
            }
        }

        if(not_combined){                                       //합쳐지지 않는 원소는 pi array로 정리함
            strcpy(prime[prime_num].encod,input[i].encod);
            strcpy(prime[prime_num].decod,input[i].decod);
            prime_num++;
        }
    }
    repeat=x_out;       //다음 반복 횟수는 현재 실행과정에서 output으로 넘겨진 원소의 개수
}

void orgate(char* in_A, char* in_B, char* out){
    for(int i=0; i<num_of_total_min; i++){
        out[i] = (in_A[i]=='0')?   '0' :in_A[i];
        out[i] = (in_B[i]=='0')? out[i]:in_B[i];
    }
}

void combining(char* a, char* b,char* tmp){   //두 minterm을 비교하여 string 반환
    int twice=False;
    tmp[n]=Null;
    for(int i=0;i<n;i++){   //encoding 값의 각 자리에서
        if (a[i]==b[i])     //두 값이 같을 때는 그 값을 그대로 저장
            tmp[i]=a[i];
        else if(twice){     //값이 다른 자리가 2개 이상이면 null 반환   
            str_reset(n+1,tmp,Null);    
            break;
        }
        else {              //값이 다른 자리가 1개이면 그 값을 x로 저장
            tmp[i]='x';
            twice=True;
        }     
    }
}

void data_move(int range, struct data* copy, struct data* orign){
    for(int i=0;i<range;i++){
        strcpy(copy[i].encod, orign[i].encod);      //encoding 영역 copy & 초기화
        str_reset(n, orign[i].encod, Null);
        strcpy(copy[i].decod, orign[i].decod);      //decoding 영역 copy & 초기화
        str_reset(num_of_total_min, orign[i].decod, Null);
    }
}

int po_2(int x){
    int a=1;
    for(int i=0;i<x;i++)
        a=a*2;
    return a;
}

void str_reset(int size, char* space, char clear){
    int index;
    for(index=0;index<size-1;index++)
        space[index]=clear;
    space[index]=Null;
}

void incoding(int decimal, struct data* binary, int type){
    str_reset(num_of_total_min+1,binary->decod,'0');
    binary->decod[decimal] = (type==Minterm)? '1' : '2';
    for(int i=n-1;i>=0;i--){
        binary->encod[i] = (decimal%2==1)? '1' : '0';
        decimal=decimal/2;
    }
}

void input_data(struct data* minterm){
    int index;
    printf("Minterm list by number for f = 1 : ");
    for(index=0;index<num_of_minterm;index++){                  //num of minterms 의 수 만큼 입력을 받아 minterm array에 저장
        int min;
        scanf("%d",&min);
        incoding(min,&minterm[index],Minterm);
    }    

    if(num_of_dc>0)
        printf("Minterm list by number for don't care condition : ");
    for(index=num_of_minterm;index<num_of_elements;index++){    //num of dc 의 수 만큼 입력을 받아 minterm array에 저장
        int dc;
        scanf("%d",&dc);
        incoding(dc,&minterm[index],Dont_care);
    }

}

void input_Binary(struct data* minterm, int mintermNum[]){
    int index = 0;
    int i = 0;
    for(index=0;index<num_of_minterm;index++, i++){                  //num of minterms �� 수 만�� 입력을 받아 minterm array에 저장
        incoding(mintermNum[i],&minterm[index],Minterm);
    }
    int dc = 26;
    if(num_of_dc>0)
    for(index=num_of_minterm;index<num_of_elements;index++, dc++){    //num of dc �� 수 만�� 입력을 받아 minterm array에 저장
        incoding(dc,&minterm[index],Dont_care);
    }

}


void setsetting(int NumberofM, int NumberofD){
    n = 5;
    num_of_total_min=po_2(n);
    num_of_minterm = NumberofM;
    num_of_dc = NumberofD;
}


void show_interface(){
    while(1){    
        printf("Number of variable : ");
        scanf("%d",&n);
        if (0<n)                //avilable value condition
            break;
        printf("Entered value is invalid. Please check again.\n");
    }
    
    num_of_total_min=po_2(n);   //전체 minterm의 개수
    
    while(1){    
        printf("Number of minterms for f = 1 : ");
        scanf("%d",&num_of_minterm);
        if ((num_of_minterm <= num_of_total_min)&&(0<num_of_minterm))       //avilable value condition
            break;
        printf("Entered value is invalid. Please check again.\n");
    }
    
    while(1){    
        printf("Number of minterms for don't care condition : ");
        scanf("%d",&num_of_dc);
        if ((num_of_dc <= num_of_total_min-num_of_minterm)&&(0<=num_of_dc))  //avilable value condition
            break;
        printf("Entered value is invalid. Please check again.\n");
    }
}

    void setreset() {
        prime_num = 0;
        cover_num = 0;
        n, num_of_total_min, num_of_minterm, num_of_dc, num_of_elements = 0;
        changed = False;
    }