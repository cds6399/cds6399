
#include <stdio.h>

//수학관련 라이브러리 가져오기

#include <math.h>

?

void menu();

//일일 카페인 최대량 계산

float caf_per_day(float weight);

//일일 아메리카노 치사량 계산

float americano_lethal_dose(float weight);

//체질량지수 계산

float bmi(float weight, float height);

//비만도 결과 출력

void bmiresult(char* name, float weight, float height);

//물 치사량

float water_lethal_dose(float weight);

?

struct people{

    char name[20]; 

    float height;

    float weight;

};

?

//main 함수

int main(void) {

?

    //변수선언

   float height = 0;

    float weight = 0;

    int choice = 0;

    int num;

?

    printf("사람 수를 입력하세요.\n");

    scanf("%d",&num);

?

    struct people s[num];

?

    for(int i=0;i<num;i++){

        printf("%d번 사람 이름과 몸무게, 키를 입력하세요.",i+1);

        scanf("%s %f %f", s[i].name, &s[i].weight, &s[i].height);

    }

?

    /* 기존의 코드를 주석처리를 통해 무효화 시킴

   printf("당신의 건강 계산기\n");

?

    //신체 사항 입력

   printf("당신의 몸무게를 입력하세요");

    scanf("%f", &weight);

    printf("당신의 키를 입력하세요");

    scanf("%f", &height);

?

    */

    int i=0;

    //무한 루프

   while (1) {

        //메뉴판 호출

       menu();

        

?

        printf("%d번 사람이 알고자 하는 정보를 고르시오.(0입력시 종료)",i+1);

        scanf("%d", &choice);

?

        //무한 루프 반복문 탈출 조건

       if(choice==0)break;

?

        //choice 값에 따라 해당 케이스로 이동

       switch (choice) {

            

            case 1:

                printf("%s의 일일 카페인 최대치는 %.1f입니다.\n",s[i].name,caf_per_day(s[i].weight));

                break;

            case 2:

                printf("%s의 일일 아메리카노 치사량은 %.1f mL입니다.\n",s[i].name,americano_lethal_dose(s[i].weight));

                break;

            case 3:

                printf("%s의 체질량지수는 %.1f입니다\n",s[i].name,bmi(s[i].weight,s[i].height));

                break;

            case 4:

                bmiresult(s[i].name, s[i].weight, height);

                break;

            case 5:

                printf("%s이 하루에 %.1fL이상 마시면 물중독으로 사망할 위험이 큽니다.\n",s[i].name,water_lethal_dose(s[i].weight));

                break;

            case 6:

                printf("---다음 사람으로 넘어갑니다.---\n");

                i++;

                break;

        }

        

    }

    return 0;

}

?

void menu() {

    printf("\n");

    printf("1.일일 카페인 최대치\n");

    printf("2.일일 아메리카노 치사량\n");

    printf("3.체질량 지수\n");

    printf("4.bmi에 따른 당신의 등급\n");

    printf("5.일일 물 흡수 치사량 계산\n");

    printf("6.다음 사람으로 넘어가기\n");

}

?

//일일 카페인량

float caf_per_day(float weight) {

    int day_caf = 0;

?

    day_caf = weight * 2.5;

?

    return day_caf;

}

?

//일일 아메리카노 치사량

float americano_lethal_dose(float weight) {

    float lethal_dose = 0;

    lethal_dose = weight * 362;

    return lethal_dose;

}

?

//체지방지수

float bmi(float weight, float height) {

    float bmi_1 = 0;

    //bmi계산 : 몸무게/키^2

    //pow함수 - 제곱화

   bmi_1 = (weight / pow(height/100, 2));

    return bmi_1;

}

?

//bmi에 따른 등급

void bmiresult(char*name, float weight, float height){

    //bmi 함수 호출 및 변수에 그 값 저장

   float bmi_1 = bmi(weight, height);

    if(bmi_1>=35){

        printf("%s은 3단계 비만 입니다.\n",name);

    }

    else if(bmi_1>=30){

        printf("%s은 2단계 비만 입니다.\n",name);

    }

    else if(bmi_1>=25){

        printf("%s은 1단계 비만 입니다.\n",name);

    }

    else if(bmi_1>=23){

        printf("%s은 비만 전단계입니다.\n",name);

    }

    else if(bmi_1>=18.5){

        printf("%s은 정상입니다.\n",name);

    }

    else{

        printf("%s은 저체중입니다.\n",name);

    }

?

}

?

//물중독 사망률

float water_lethal_dose(float weight){

    float water_ld = 0.0;

?

    water_ld = weight*0.09;

?

    return water_ld;

}