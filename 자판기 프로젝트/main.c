#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

struct machine //����ü����
{
    char iceCream[10];
    int price;
    int stock;
};


void printMachine(struct machine menu[]);//���Ǳ� ��� �Լ� ����
int inputMoney(struct machine menu[],int sumMoney); //�ݾ� �Է� �Լ� ����
void theSelectMenu(struct machine menu[],int sumMoney); //�޴������Լ�����

int main()
{
    struct machine menu[SIZE]={{"������",700,5},{"������",1000,5},{"������",1500,5},{"������",2000,5}};
    int answer=0; //���� ��� �޴� ����
    int sumMoney=0; //���� �ݾ� �հ�
    int money=0; //�Ա� �ݾ�
    int selectMenu=0;


    printMachine( menu ); //���Ǳ� ��� �Լ�
    sumMoney=inputMoney(menu,sumMoney); //�ݾ� �Է� �Լ�
    theSelectMenu(menu,sumMoney);






    return 0;
}
void printMachine(struct machine menu[])
{
    printf("����������������������������������������������������������������������������\n");
    printf("��        *Premiun Ice Cream*         ��\n");
    printf("��                                    ��\n");
    printf("��  ����������������������   ����������������������         ��\n");
    printf("��  ��    ��   ��   ��    ��   ��         ��\n");
    printf("��  ��         ��   ��         ��         ��\n");
    printf("��  ��  ������ ��   ��  ������ ��         ��\n");
    printf("��  ��         ��   ��         ��         ��\n");
    printf("��  ��   %d�� ��   ��  %d�� ��         ��\n",menu[0].price,menu[1].price);
    printf("��  �� ���:%d����   �� ���:%d����         ��\n",menu[0].stock,menu[1].stock);
    printf("��  ����������������������   ����������������������         ��\n");
    printf("��       ��            ��             ��\n");
    printf("��                            ����������   ��\n");
    printf("��  ����������������������   ���������������������� ������������ ��\n");
    printf("��  ��    ��   ��   ��    ��   �� �������������� ��\n");
    printf("��  ��         ��   ��         �� �������������� ��\n");
    printf("��  ��  ������ ��   ��  ������ ��         ��\n");
    printf("��  ��         ��   ��         ��         ��\n");
    printf("��  ��  %d�� ��   ��  %d�� ��         ��\n",menu[2].price,menu[3].price);
    printf("��  �� ���:%d����   �� ���:%d����         ��\n",menu[2].stock,menu[3].stock);
    printf("��  ����������������������   ����������������������         ��\n");
    printf("��       ��            ��             ��\n");
    printf("��                                    ��\n");
    printf("��   ����������������������������������������������������������    ��\n");
    printf("��   ��                           ��    ��\n");
    printf("��   ��                           ��    ��\n");
    printf("��   ��            push           ��    ��\n");
    printf("��   ����������������������������������������������������������    ��\n");
    printf("����������������������������������������������������������������������������\n");


    return ;
}

int inputMoney(struct machine menu[],int sumMoney)
{

    int money=0;
    int answer=0;

    while(1)
    {
        printf("�ݾ��� �������ּ��� (�ݾ� ���� 10,50,100,500,1000,5000,10000,50000) :");
        scanf("%d",&money);

        if(money > 50000 || money <= 0)
        {
            printf("�ݾ��� �߸��Է��ϼ̽��ϴ�. �ٽ��Էº�Ź�帳�ϴ�.\n");
            continue;
        }
        else
        {
            sumMoney += money;
        }


        printf("��� �Ա��Ͻðڽ��ϱ�? (yes-1,no-0) :");
        scanf("%d",&answer);

        system("cls");
        printMachine( menu );
        printf("���Ա�: %d �� \n",sumMoney);


        if(answer==0)
        {
            break;

        }
        else
        {
            continue;
        }


    }


    return sumMoney;
}

void theSelectMenu(struct machine menu[],int sumMoney)
{
    int selectMenu=0;
    int answer=0;

    while(1)
    {
        printf("�޴��� �������ּ���(1��~4��) :");
        scanf("%d",&selectMenu);

        if(sumMoney<menu[selectMenu-1].price)
        {
            printf("�ܾ׺���.\n");

            printf("�߰��Ա��Ͻðڽ��ϱ�?(yes-1,no-0) :");
            scanf("%d",&answer);

            if(answer!=0)
            {
                system("cls");
                printMachine( menu );
                printf("���Ա�: %d �� \n",sumMoney);
                sumMoney=inputMoney(menu,sumMoney);
            }
        }else if(selectMenu > 4 || selectMenu < 1)
        {
            printf("�߸������ϼ̽��ϴ�.\n");
            continue;
        }
        else if(menu[selectMenu-1].stock == 0)
        {
            printf("������. �˼��մϴ�.\n");
            continue;
        }
        else
        {
            menu[selectMenu-1].stock-=1;
            sumMoney -= menu[selectMenu-1].price;

            printf("%d�� \'%s\'�޴� �����ϼ̽��ϴ�.\n",selectMenu,menu[selectMenu-1].iceCream);
            printf("�ݾ� %d��, �ܾ� %d���Դϴ�.\n",menu[selectMenu-1].price,sumMoney);

            Sleep(2000);

            system("cls");
            printMachine( menu );
            printf("���Ա�: %d �� \n",sumMoney);

        }

        printf("��� �����Ͻðڽ��ϱ�? (yes-1,no-0) :");
        scanf("%d",&answer);

        if(answer==0)
        {
            system("cls");
            printMachine( menu );
            printf("�ܵ� %d�� ��ȯ�ص帮�ڽ��ϴ�. �����մϴ�:) \n",sumMoney);
            Sleep(1000);
            break;
        }
        else continue;

        system("cls");
        printMachine( menu );
    }

    return;
}
