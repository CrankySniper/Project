#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void tlog()
{
    FILE *log;
    log = fopen("log.txt", "a+");

    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    fprintf(log, "%s", asctime(timeinfo));
    fclose(log);
}

void delayy(int milliseconds)
{
    Sleep(milliseconds);
}

void clearScreen()
{
    system("cls");
}

void setConsoleColor(int text, int background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (background << 4));
}

void scrollText(const char *text, int speed)
{
    int textLength = strlen(text);
    int screenWidth = 150;
    int padding = 0;

    while (padding < screenWidth + textLength)
    {
        clearScreen();
        setConsoleColor(14, 0);
        printf("\n\n");

        for (int j = 0; j < screenWidth; j++)
        {
            if (j + padding < textLength)
            {
                printf("%c", text[j + padding]);
            }
            else
            {
                printf(" ");
            }
        }

        setConsoleColor(15, 7);

        delayy(speed);
        padding++;
        padding = (padding == (screenWidth + textLength - 1)) ? 0 : padding;
    }
}

void endingscreen()
{
    clearScreen();
    scrollText("                                                                                                            PDS Project - Thank You!", 50);
    getch();
    clearScreen();
    setConsoleColor(15, 0);
}

void generateMenu()
{
    printf("\t\t Welcome to Swaad Restaurant\n");
    printf("-----------\n");
    printf("Appetizers:\n");
    printf("-----------\n\n");
    printf("1. Vegetable Samosa - Rs 5.99\n");
    printf("2. Paneer Tikka - Rs 7.99\n");
    printf("3. Chicken Tikka - Rs 8.99\n");
    printf("4. Tandoori Shrimp - Rs 10.99\n");
    printf("5. Aloo Chaat - Rs 6.99\n\n");
    printf("--------------------------\n");
    printf("Main Courses - Vegetarian:\n");
    printf("--------------------------\n\n");
    printf("6. Vegetable Biryani - Rs 12.99\n");
    printf("7. Paneer Butter Masala - Rs 14.99\n");
    printf("8. Chana Masala - Rs 11.99\n");
    printf("9. Baingan Bharta - Rs 12.99\n");
    printf("10. Malai Kofta - Rs 13.99\n\n");
    printf("------------------------------\n");
    printf("Main Courses - Non-Vegetarian:\n");
    printf("------------------------------\n\n");
    printf("11. Chicken Curry - Rs 14.99\n");
    printf("12. Lamb Rogan Josh - Rs 16.99\n");
    printf("13. Butter Chicken - Rs 15.99\n");
    printf("14. Goan Fish Curry - Rs 17.99\n");
    printf("15. Tandoori Mixed Grill - Rs 19.99\n");
}

struct items
{
    char item[20];
    float price;
    int qty;
};

struct orders
{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

int pass(void);

int tm()
{
    time_t mytime;
    mytime = time(NULL);
    printf(ctime(&mytime));
    return 0;
}

int delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void generateBillHeader(char name[50], char date[30])
{
    printf("\n\n");
    printf("\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t\t\t\t\t============ADV. RESTAURANT============");
    printf("\n\t\t\t\t\t   -----------------");
    printf("\nDate:%s", date);
    printf("\nInvoice To: %s", name);
    printf("\n");
    printf("---------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n---------------------------------------");
    printf("\n\n");
}

void generateBillBody(char item[30], int qty, float price)
{
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", qty * price);
    printf("\n");
}

void generateBillFooter(float total)
{
    printf("\n");
    float dis = 0.1 * total;
    float netTotal = total - dis;
    float cgst = 0.09 * netTotal, grandTotal = netTotal + 2 * cgst; // netTotal + cgst + sgst
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f", total);
    printf("\nDiscount @10%s\t\t\t%.2f", "%", dis);
    printf("\n\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
    printf("\nCGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\nSGST @9%s\t\t\t%.2f", "%", cgst);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n---------------------------------------\n");
}

int main()
{
    int opt, n;
    struct orders ord;
    struct orders order;
    char saveBill = 'y', contFlag = 'y';
    char name[50];
    FILE *fp;
    pass();
    tlog();
    while (contFlag == 'y')
    {
        system("cls");
        float total = 0;
        int invoiceFound = 0;
        system("CLS");
        system("color 07");
        printf("\n\n\t\t\t============ADV. RESTAURANT============");
        printf("\n\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf("\n\n");
        printf("\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [1] Generate Invoice  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [2] Show all Invoices \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [3] Search Invoice    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [4] Exit              \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
        printf("\n \t\t Today is: ");
        tm();
    label1:
        printf("\n\t\t Please Enter Your Choice: ");
        scanf("%d", &opt);
        fgetc(stdin);
        switch (opt)
        {
        case 1:
            system("cls");
            printf("\nPlease enter the name of the customer:\t");
            fgets(ord.customer, 50, stdin);
            ord.customer[strlen(ord.customer) - 1] = 0;
            strcpy(ord.date, __DATE__);

            generateMenu();
            int i = 0, price, n1;
            while (1)
            {
                int choice;
                // fgetc(stdin);
                printf("\n\n");
            label:
                printf("Please enter the item no. and quantity :");
                scanf("%d %d", &choice, &n1);
                char item[50];
                switch (choice)
                {
                case 1:
                    strcpy(item, "Vegetable Samosa");
                    price = 5.99 * n1;
                    break;
                case 2:
                    strcpy(item, "Paneer Tikka");
                    price = 7.99 * n1;
                    break;
                case 3:
                    strcpy(item, "Chicken Tikka");
                    price = 8.99 * n1;
                    break;
                case 4:
                    strcpy(item, "Tandoori Shrimp");
                    price = 10.99 * n1;
                    break;
                case 5:
                    strcpy(item, "Aloo Chaat");
                    price = 6.99 * n1;
                    break;
                case 6:
                    strcpy(item, "Vegetable Biryani");
                    price = 12.99 * n1;
                    break;
                case 7:
                    strcpy(item, "Paneer Butter Masala");
                    price = 14.99 * n1;
                    break;
                case 8:
                    strcpy(item, "Chana Masala");
                    price = 14.99 * n1;
                    break;
                case 9:
                    strcpy(item, "Baingan Bharta");
                    price = 11.99 * n1;
                    break;
                case 10:
                    strcpy(item, "Malai Kofta");
                    price = 12.99 * n1;
                    break;
                case 11:
                    strcpy(item, "Chicken Curry");
                    price = 13.99 * n1;
                    break;
                case 12:
                    strcpy(item, "Lamb Rogan Josh");
                    price = 14.99 * n1;
                    break;
                case 13:
                    strcpy(item, "Butter Chicken");
                    price = 15.99 * n1;
                    break;
                case 14:
                    strcpy(item, "Goan Fish Curry");
                    price = 17.99 * n1;
                    break;
                case 15:
                    strcpy(item, "Tandoori Mixed Grill");
                    price = 19.99 * n1;
                    break;

                default:
                    goto label;
                    break;
                }

                fgetc(stdin);
                strcpy(ord.itm[i].item, item);
                ord.itm[i].qty = n1;
                ord.itm[i].price = price;
                total += price * n1;
                char ch;
                printf("Add more (y/n): ");
                scanf(" %c", &ch);
                if (ch == 'n')
                {
                    ord.numOfItems = i + 1;
                    break;
                }
                i++;
            }
            system("cls");
            generateBillHeader(ord.customer, ord.date);
            for (int i = 0; i < ord.numOfItems; i++)
            {
                generateBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
            }
            generateBillFooter(total);

            printf("\nDo you want to save the invoice [y/n]:\t");
            scanf("%s", &saveBill);

            if (saveBill == 'y')
            {
                fp = fopen("RestaurantBill.dat", "a+");
                fwrite(&ord, sizeof(struct orders), 1, fp);
                if (fwrite != 0)
                    printf("\nSuccessfully saved");
                else
                    printf("\nError saving");
                fclose(fp);
            }
            break;

        case 2:
            system("cls");
            fp = fopen("RestaurantBill.dat", "r");
            printf("\n  **Your Previous Invoices**\n");
            while (fread(&order, sizeof(struct orders), 1, fp))
            {
                float tot = 0;
                generateBillHeader(order.customer, order.date);
                for (int i = 0; i < order.numOfItems; i++)
                {
                    generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                    tot += order.itm[i].qty * order.itm[i].price;
                }
                generateBillFooter(tot);
            }
            fclose(fp);
            break;

        case 3:
            printf("Enter the name of the customer:\t");
            fgets(name, 50, stdin);
            name[strlen(name) - 1] = 0;
            system("cls");
            fp = fopen("RestaurantBill.dat", "r");
            printf("\t**Invoice of %s**", name);
            while (fread(&order, sizeof(struct orders), 1, fp))
            {
                float tot = 0;
                if (!strcmp(order.customer, name))
                {
                    generateBillHeader(order.customer, order.date);
                    for (int i = 0; i < order.numOfItems; i++)
                    {
                        generateBillBody(order.itm[i].item, order.itm[i].qty, order.itm[i].price);
                        tot += order.itm[i].qty * order.itm[i].price;
                    }
                    generateBillFooter(tot);
                    invoiceFound = 1;
                }
            }
            if (!invoiceFound)
            {
                printf("Sorry the invoice for %s doesnot exists", name);
            }
            fclose(fp);
            break;

        case 4:
            endingscreen();
            exit;
            break;

        default:
            printf("Sorry invalid option");
            goto label1;
        }
        printf("\n<Enter any key to continue>");
        getch();

        printf("\nDo you want to perform another operation? [y/n]");
        scanf("%s", &contFlag);
    }
    endingscreen();
    printf("\n\n");
}

int pass(void)
{
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    system("cls");
    system("color e0");
    int i1, j, l, l1;
    char name[50] = "\n\n\n\n\t\t\t  WELCOME TO OUR PROJECT\n\n";
    printf("\t\n");
    for (i1 = 0; i1 < 50; i1++)
    {
        printf("%c", name[i1]);
        delay(20);
    }
    printf("\n\t   ");
    for (j = 0; j < 59; j++)
    {
        printf("%c", 2);
        delay(30);
    }
    printf("\n\n\n\n");
    system("cls");
    system("color 0f");

    printf("\n\n");
    system("CLS");
    system("color 1f");
    printf("\n\n\n");
    char ame[25] = "\tGROUP MEMBERS\n\n";
    printf("\t\n");
    for (l1 = 0; l1 < 25; l1++)
    {
        printf("%c", ame[l1]);
        delay(150);
    }
    printf(" \n\t 23EE01004:  - Anand Roy\n\n");
    printf(" \t 23EC01005:  - Aum Vyas\n\n");
    printf(" \t 23ME01003:  - Aditya\n\n");
    printf(" \t 23ME01044:  - Naman\n\n");
    printf("\n");
    system("pause");
    system("CLS");
    system("color 5e");
    printf("\n\n\n\n\n\n");
    printf("\t\t\tOur project on:\n\n");
    printf("\n");
    char nam[] = "\n\n\t\t\tInvoice Management System Project \n\n";
    printf("\t\n");
    for (l = 0; l < 40; l++)
    {
        printf("%c", nam[l]);
        delay(40);
    }
    printf("\n\n\n");
    delay(600);
    do
    {
        system("cls");
        printf("\n\n\n \t \t \t   ***  LOGIN FORM  ***  ");
        printf("\n\n\n  \t           ENTER USERNAME:-");
        scanf("%s", &uname);
        printf("\n  \t          ENTER PASSWORD:-");
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';
        i = 0;
        if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0)
        {
            printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
            system("cls");
            system("color 1a");
            printf("\n\n\n\n\n\n");
            printf("                                                           \n");
            printf("                                                           \n");
            printf("                      \t  Please Wait...\n\n\n\n\n");
            printf("                     ______________ _____________               \n");
            printf("                    /                             \\          \n");
            printf("                   |     Loading.............      |           \n");
            printf("\t\t   |\t");
            for (j = 0; j < 24; j++)
            {
                printf("%c", 219);
                delay(50);
            }
            printf("   |\n                    \\______________ ______________/           \n");
            printf("                                                           \n");
            printf("\n\n\n");
            delay(1000);
            break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
            system("PAUSE");
            a++;
            getch();
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("\nSorry you have entered the wrong user name and password for four times!!!");
        getch();
    }
    system("cls");
}
