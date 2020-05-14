
#include <stdio.h>

//���а��� ���̺귯�� ��������

#include <math.h>

?

void menu();

//���� ī���� �ִ뷮 ���

float caf_per_day(float weight);

//���� �Ƹ޸�ī�� ġ�緮 ���

float americano_lethal_dose(float weight);

//ü�������� ���

float bmi(float weight, float height);

//�񸸵� ��� ���

void bmiresult(char* name, float weight, float height);

//�� ġ�緮

float water_lethal_dose(float weight);

?

struct people{

    char name[20]; 

    float height;

    float weight;

};

?

//main �Լ�

int main(void) {

?

    //��������

   float height = 0;

    float weight = 0;

    int choice = 0;

    int num;

?

    printf("��� ���� �Է��ϼ���.\n");

    scanf("%d",&num);

?

    struct people s[num];

?

    for(int i=0;i<num;i++){

        printf("%d�� ��� �̸��� ������, Ű�� �Է��ϼ���.",i+1);

        scanf("%s %f %f", s[i].name, &s[i].weight, &s[i].height);

    }

?

    /* ������ �ڵ带 �ּ�ó���� ���� ��ȿȭ ��Ŵ

   printf("����� �ǰ� ����\n");

?

    //��ü ���� �Է�

   printf("����� �����Ը� �Է��ϼ���");

    scanf("%f", &weight);

    printf("����� Ű�� �Է��ϼ���");

    scanf("%f", &height);

?

    */

    int i=0;

    //���� ����

   while (1) {

        //�޴��� ȣ��

       menu();

        

?

        printf("%d�� ����� �˰��� �ϴ� ������ ���ÿ�.(0�Է½� ����)",i+1);

        scanf("%d", &choice);

?

        //���� ���� �ݺ��� Ż�� ����

       if(choice==0)break;

?

        //choice ���� ���� �ش� ���̽��� �̵�

       switch (choice) {

            

            case 1:

                printf("%s�� ���� ī���� �ִ�ġ�� %.1f�Դϴ�.\n",s[i].name,caf_per_day(s[i].weight));

                break;

            case 2:

                printf("%s�� ���� �Ƹ޸�ī�� ġ�緮�� %.1f mL�Դϴ�.\n",s[i].name,americano_lethal_dose(s[i].weight));

                break;

            case 3:

                printf("%s�� ü���������� %.1f�Դϴ�\n",s[i].name,bmi(s[i].weight,s[i].height));

                break;

            case 4:

                bmiresult(s[i].name, s[i].weight, height);

                break;

            case 5:

                printf("%s�� �Ϸ翡 %.1fL�̻� ���ø� ���ߵ����� ����� ������ Ů�ϴ�.\n",s[i].name,water_lethal_dose(s[i].weight));

                break;

            case 6:

                printf("---���� ������� �Ѿ�ϴ�.---\n");

                i++;

                break;

        }

        

    }

    return 0;

}

?

void menu() {

    printf("\n");

    printf("1.���� ī���� �ִ�ġ\n");

    printf("2.���� �Ƹ޸�ī�� ġ�緮\n");

    printf("3.ü���� ����\n");

    printf("4.bmi�� ���� ����� ���\n");

    printf("5.���� �� ��� ġ�緮 ���\n");

    printf("6.���� ������� �Ѿ��\n");

}

?

//���� ī���η�

float caf_per_day(float weight) {

    int day_caf = 0;

?

    day_caf = weight * 2.5;

?

    return day_caf;

}

?

//���� �Ƹ޸�ī�� ġ�緮

float americano_lethal_dose(float weight) {

    float lethal_dose = 0;

    lethal_dose = weight * 362;

    return lethal_dose;

}

?

//ü��������

float bmi(float weight, float height) {

    float bmi_1 = 0;

    //bmi��� : ������/Ű^2

    //pow�Լ� - ����ȭ

   bmi_1 = (weight / pow(height/100, 2));

    return bmi_1;

}

?

//bmi�� ���� ���

void bmiresult(char*name, float weight, float height){

    //bmi �Լ� ȣ�� �� ������ �� �� ����

   float bmi_1 = bmi(weight, height);

    if(bmi_1>=35){

        printf("%s�� 3�ܰ� �� �Դϴ�.\n",name);

    }

    else if(bmi_1>=30){

        printf("%s�� 2�ܰ� �� �Դϴ�.\n",name);

    }

    else if(bmi_1>=25){

        printf("%s�� 1�ܰ� �� �Դϴ�.\n",name);

    }

    else if(bmi_1>=23){

        printf("%s�� �� ���ܰ��Դϴ�.\n",name);

    }

    else if(bmi_1>=18.5){

        printf("%s�� �����Դϴ�.\n",name);

    }

    else{

        printf("%s�� ��ü���Դϴ�.\n",name);

    }

?

}

?

//���ߵ� �����

float water_lethal_dose(float weight){

    float water_ld = 0.0;

?

    water_ld = weight*0.09;

?

    return water_ld;

}