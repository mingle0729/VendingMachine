#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

struct machine //구조체선언
{
    char iceCream[10];
    int price;
    int stock;
};


void printMachine(struct machine menu[]);//자판기 출력 함수 선언
int inputMoney(struct machine menu[],int sumMoney); //금액 입력 함수 선언
void theSelectMenu(struct machine menu[],int sumMoney); //메뉴선택함수선언

int main()
{
    struct machine menu[SIZE]={{"돼지바",700,5},{"빠삐코",1000,5},{"설레임",1500,5},{"월드콘",2000,5}};
    int answer=0; //진행 대답 받는 변수
    int sumMoney=0; //투입 금액 합계
    int money=0; //입금 금액
    int selectMenu=0;


    printMachine( menu ); //자판기 출력 함수
    sumMoney=inputMoney(menu,sumMoney); //금액 입력 함수
    theSelectMenu(menu,sumMoney);






    return 0;
}
void printMachine(struct machine menu[])
{
    printf("┌────────────────────────────────────┐\n");
    printf("│        *Premiun Ice Cream*         │\n");
    printf("│                                    │\n");
    printf("│  ┌─────────┐   ┌─────────┐         │\n");
    printf("│  │    ①   │   │    ②   │         │\n");
    printf("│  │         │   │         │         │\n");
    printf("│  │  돼지바 │   │  빠삐코 │         │\n");
    printf("│  │         │   │         │         │\n");
    printf("│  │   %d원 │   │  %d원 │         │\n",menu[0].price,menu[1].price);
    printf("│  │ 재고:%d개│   │ 재고:%d개│         │\n",menu[0].stock,menu[1].stock);
    printf("│  └─────────┘   └─────────┘         │\n");
    printf("│       ▣            ▣             │\n");
    printf("│                            ┌───┐   │\n");
    printf("│  ┌─────────┐   ┌─────────┐ └───┘Θ │\n");
    printf("│  │    ③   │   │    ④   │ ┌─────┐ │\n");
    printf("│  │         │   │         │ └─────┘ │\n");
    printf("│  │  설레임 │   │  월드콘 │         │\n");
    printf("│  │         │   │         │         │\n");
    printf("│  │  %d원 │   │  %d원 │         │\n",menu[2].price,menu[3].price);
    printf("│  │ 재고:%d개│   │ 재고:%d개│         │\n",menu[2].stock,menu[3].stock);
    printf("│  └─────────┘   └─────────┘         │\n");
    printf("│       ▣            ▣             │\n");
    printf("│                                    │\n");
    printf("│   ┌───────────────────────────┐    │\n");
    printf("│   │                           │    │\n");
    printf("│   │                           │    │\n");
    printf("│   │            push           │    │\n");
    printf("│   └───────────────────────────┘    │\n");
    printf("└────────────────────────────────────┘\n");


    return ;
}

int inputMoney(struct machine menu[],int sumMoney)
{

    int money=0;
    int answer=0;

    while(1)
    {
        printf("금액을 투입해주세요 (금액 단위 10,50,100,500,1000,5000,10000,50000) :");
        scanf("%d",&money);

        if(money > 50000 || money <= 0)
        {
            printf("금액을 잘못입력하셨습니다. 다시입력부탁드립니다.\n");
            continue;
        }
        else
        {
            sumMoney += money;
        }


        printf("계속 입금하시겠습니까? (yes-1,no-0) :");
        scanf("%d",&answer);

        system("cls");
        printMachine( menu );
        printf("투입금: %d 원 \n",sumMoney);


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
        printf("메뉴를 선택해주세요(1번~4번) :");
        scanf("%d",&selectMenu);

        if(sumMoney<menu[selectMenu-1].price)
        {
            printf("잔액부족.\n");

            printf("추가입금하시겠습니까?(yes-1,no-0) :");
            scanf("%d",&answer);

            if(answer!=0)
            {
                system("cls");
                printMachine( menu );
                printf("투입금: %d 원 \n",sumMoney);
                sumMoney=inputMoney(menu,sumMoney);
            }
        }else if(selectMenu > 4 || selectMenu < 1)
        {
            printf("잘못선택하셨습니다.\n");
            continue;
        }
        else if(menu[selectMenu-1].stock == 0)
        {
            printf("재고소진. 죄송합니다.\n");
            continue;
        }
        else
        {
            menu[selectMenu-1].stock-=1;
            sumMoney -= menu[selectMenu-1].price;

            printf("%d번 \'%s\'메뉴 선택하셨습니다.\n",selectMenu,menu[selectMenu-1].iceCream);
            printf("금액 %d원, 잔액 %d원입니다.\n",menu[selectMenu-1].price,sumMoney);

            Sleep(2000);

            system("cls");
            printMachine( menu );
            printf("투입금: %d 원 \n",sumMoney);

        }

        printf("계속 선택하시겠습니까? (yes-1,no-0) :");
        scanf("%d",&answer);

        if(answer==0)
        {
            system("cls");
            printMachine( menu );
            printf("잔돈 %d원 반환해드리겠습니다. 감사합니다:) \n",sumMoney);
            Sleep(1000);
            break;
        }
        else continue;

        system("cls");
        printMachine( menu );
    }

    return;
}
