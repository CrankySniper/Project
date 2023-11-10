#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

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
struct items
{
    char item[20];
    float price;
    int qty;
};

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

struct orders
{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};

struct premium
{
    char name[50];
    char id[50];
    char paswrd[50];
    char address[500];
    char phn[11];
};

struct Employee
{
    char name[50];
    char id[50];
    char paswrd[50];
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
// functions to generate biils
void generateBillHeader(char name[50], char date[30])
{
    printf("\n\n");
    printf("\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\n\n\t\t\t============ADV. RESTAURANT============");
    printf("\n\t   -----------------");
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

void generatePremBillHeader(char name[50], char date[30])
{
    printf("\n\n");
    printf("\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
    printf("\n\n\t\t\t============ADV. RESTAURANT============");
    printf("\n\t   -----------------");
    printf("\nDate:%s", date);
    printf("\nInvoice To: %s", name);
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    // printf("Discount\t\t");
    printf("Total\t\t");
    printf("\n----------------------------------------------");
    printf("\n\n");
}

// void generatePremBillHeader(char name[50], char date[30])
// {
//     printf("\n\n");
//     printf("\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
//     printf("\t\t\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
//     printf("\n\n\t\t\t============ADV. RESTAURANT============");
//     printf("\n\t   -----------------");
//     printf("\nDate:%s", date);
//     printf("\nInvoice To: %s", name);
//     printf("\n");
//     printf("---------------------------------------\n");
//     printf("Items\t\t");
//     printf("Qty\t\t");
//     printf("Dis\t\t");
//     printf("Total\t\t");
//     printf("\n---------------------------------------");
//     printf("\n\n");
// }

void generatePremiumBody()
{
    printf("%-8s%-16s%-16s%-16s\n", "SL No.", "Name", "ID", "Password");
}

// void generatePremiumContent(char name[50],char id[50],char pas[50]){

// printf("%d \t\t",i++);
//   printf("\t\t%s \t\t",name);
////     printf("%s \t\t",id);
//     printf("%s \t\t",pas);
//     printf("\n");

// }

void generatePremiumContent(int i, char name[50], char id[50], char pas[50])
{
    printf("%-8d", i);
    printf("%-16s", name);
    printf("%-16s", id);

    // Ensure that the password string is null-terminated
    pas[49] = '\0'; // Assuming the maximum length of the password is 50 characters

    printf("%s", pas);
    printf("\n");
}

void generateBillBody(char item[30], int qty, float price)
{
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    printf("%.2f\t\t", qty * price);
    printf("\n\n");
}

// void generatePremBillBody(char item[30], int qty, int dis,float price)
// {
//     printf("%s\t\t", item);
//     printf("%d\t\t", qty);
//     printf("%.2f\t\t", qty * price);
//     printf("\n\n");
// }

void generatePremBillBody(char item[30], int qty, float price)
{
    printf("%s\t\t", item);
    printf("%d\t\t", qty);
    //  printf("%d\t\t",discount);ss
    printf("%.2f\t\t", qty * price);
    printf("\n\n");
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

void generatePremMenu()
{

    printf("\t\t Welcome to Swaad Restaurant\n");
    printf("-----------\n");
    printf("Appetizers:\n");
    printf("-----------\n\n");
    printf("1. Vegetable Samosa - Rs 5.99 (10%% off)\n");
    printf("2. Paneer Tikka - Rs 7.99 (15%% off)\n");
    printf("3. Chicken Tikka - Rs 8.99 (10%% off)\n");
    printf("4. Tandoori Shrimp - Rs 10.99 (5%% off)\n");
    printf("5. Aloo Chaat - Rs 6.99 (20%% off)\n\n");
    printf("--------------------------\n");
    printf("Main Courses - Vegetarian:\n");
    printf("--------------------------\n\n");
    printf("6. Vegetable Biryani - Rs 12.99 (10%% off)\n");
    printf("7. Paneer Butter Masala - Rs 14.99 (15%% off)\n");
    printf("8. Chana Masala - Rs 11.99 (20%% off)\n");
    printf("9. Baingan Bharta - Rs 12.99 (10%% off)\n");
    printf("10. Malai Kofta - Rs 13.99 (15%% off)\n\n");
    printf("------------------------------\n");
    printf("Main Courses - Non-Vegetarian:\n");
    printf("------------------------------\n\n");
    printf("11. Chicken Curry - Rs 14.99 (10%% off)\n");
    printf("12. Lamb Rogan Josh - Rs 16.99 (15%% off)\n");
    printf("13. Butter Chicken - Rs 15.99 (10%% off)\n");
    printf("14. Goan Fish Curry - Rs 17.99 (5%% off)\n");
    printf("15. Tandoori Mixed Grill - Rs 19.99 (10%% off)\n");
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

void displayPremiumMenuAndDiscounts(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }
    printf("Exclusive Menu Options and Special Discounts for Premium Members:\n");
    char line[100]; // Assuming each line in the file is at most 100 characters
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }
    int choice;
    double totalBill = 0;
    while (1)
    {
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            totalBill += 12.99 * 0.8; // 20% off
            break;
        case 2:
            totalBill += 11.99 * 0.85; // 15% off
            break;
        case 3:
            totalBill += 14.99 * 0.9; // 10% off
            break;
        case 4:
            // Complimentary, no cost
            break;
        case 5:
            totalBill += 19.99 * 0.75; // 25% off
            break;
        case 6:
            totalBill += 7.99 * 0.5; // 50% off during Happy Hour
            break;
        case 7:
            printf("You've chosen: 30%% off on your birthday\n");
            break;
        case 8:
            totalBill += 4.99 * 0.5; // 50% off
            break;
        case 9:
            // Complimentary, no cost
            break;
        case 10:
            // Loyalty bonus, no cost
            break;
        default:
            printf("Invalid choice. Please enter a number from 1 to 10 or 0 to finish your order.\n");
            continue;
        }

        printf("Your current total bill is: $%.2lf\n", totalBill);
        printf("Enter your next choice (1-10) or 0 to finish your order: ");
    }

    printf("Your final bill is: $%.2lf\n", totalBill);

    fclose(file);
}
int main()
{
    int opt, n, n1, price;
    struct orders ord;
    struct orders order;
    struct Employee employee;

    char saveBill = 'y', contFlag = 'y';
    char name[50];
    FILE *fp;
    FILE *premFile;

    FILE *employeeFile;
    int countPrem = 0;
    int countemployee = 0;
    struct premium premStuc;

    int ix = 0;

    int discount;
    int sn = 1;

    char c;
    tlog();
    pass();
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
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    [4] Enter new Employee        \xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    [5] Diplay All Employee       \xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    [6] Show Log     \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    [7] Become Premium Customer     \xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    [8] Search Premium Customers     \xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    [9] Display Premium Customers       \xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    [10] Display Premium Features      \xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 [11] Exit             \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
        printf("\t\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n");
        printf("\n \t\t Today is: ");
        tm();
        printf("\n\t\t Please Enter Your Choice: ");
        scanf("%d", &opt);
        fgetc(stdin);

        char premName[50];
        char paswPrem[50];
        int i = 0;
        char premCh;
        const char *filename;

        switch (opt)
        {
        case 1:
            system("cls");
            printf("\nPlease enter the name of the customer:\t");
            fgets(ord.customer, 50, stdin);
            ord.customer[strlen(ord.customer) - 1] = 0;
            strcpy(ord.date, __DATE__);

            // printf("\nPlease enter the number of items:\t");
            // scanf("%d", &n);
            // ord.numOfItems = n;
            // for (int i = 0; i < n; i++)
            // {
            //     fgetc(stdin);
            //     printf("\n\n");
            //     printf("Please enter the item %d:\t", i + 1);
            //     fgets(ord.itm[i].item, 20, stdin);
            //     ord.itm[i].item[strlen(ord.itm[i].item) - 1] = 0;
            //     printf("Please enter the quantity:\t");
            //     scanf("%d", &ord.itm[i].qty);
            //     printf("Please enter the unit price:\t");
            //     scanf("%f", &ord.itm[i].price);
            //     total += ord.itm[i].qty * ord.itm[i].price;
            // }

            generateMenu();
            int i = 0;
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
                    price = 5.99;
                    break;
                case 2:
                    strcpy(item, "Paneer Tikka");
                    price = 7.99;
                    break;
                case 3:
                    strcpy(item, "Chicken Tikka");
                    price = 8.99;
                    break;
                case 4:
                    strcpy(item, "Tandoori Shrimp");
                    price = 10.99;
                    break;
                case 5:
                    strcpy(item, "Aloo Chaat");
                    price = 6.99;
                    break;
                case 6:
                    strcpy(item, "Vegetable Biryani");
                    price = 12.99;
                    break;
                case 7:
                    strcpy(item, "Paneer Butter Masala");
                    price = 14.99;
                    break;
                case 8:
                    strcpy(item, "Chana Masala");
                    price = 14.99;
                    break;
                case 9:
                    strcpy(item, "Baingan Bharta");
                    price = 11.99;
                    break;
                case 10:
                    strcpy(item, "Malai Kofta");
                    price = 12.99;
                    break;
                case 11:
                    strcpy(item, "Chicken Curry");
                    price = 13.99;
                    break;
                case 12:
                    strcpy(item, "Lamb Rogan Josh");
                    price = 14.99;
                    break;
                case 13:
                    strcpy(item, "Butter Chicken");
                    price = 15.99;
                    break;
                case 14:
                    strcpy(item, "Goan Fish Curry");
                    price = 17.99;
                    break;
                case 15:
                    strcpy(item, "Tandoori Mixed Grill");
                    price = 19.99;
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
            printf("\n  Your Previous Invoices\n");
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
            printf("\t*Invoice of %s*", name);
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
            system("cls");
            system("color 8e");

            printf("Enter your Name :");
            gets(employee.name);

            printf("Enter your preffered User id :");
            gets(employee.id);

            printf("Enter the password :");
            gets(employee.paswrd);

            employeeFile = fopen("Employee.dat", "a+");

            fwrite(&employee, sizeof(struct Employee), 1, employeeFile);

            if (fwrite != 0)
            {
                printf("\nSuccessfully saved");
                countemployee++;
            }

            else
                printf("\nError saving");

            fflush(employeeFile);
            fclose(employeeFile);
            break;

        case 5:
            system("cls");
            system("color 9d");
            int px = 0;
            employeeFile = fopen("Employee.dat", "r");
            generatePremiumBody();

            while (fread(&employee, sizeof(struct Employee), 1, employeeFile))
            {
                int sl = 1;

                for (int x5 = 0; x5 < countemployee; x5++)
                {
                    generatePremiumContent(++px, employee.name, employee.id, employee.paswrd);
                }
            }
            // system("cls");

            fclose(employeeFile);
            break;

        case 6:
            // system("cls");
            //          system("color 5b");

            //         fp = fopen("RestaurantBill.dat","r");
            //         float tot = 0;

            //          while (fread(&order, sizeof(struct orders), 1, fp))
            //          {

            //                 for (int i = 0; i < order.numOfItems; i++)
            //                 {
            //                     tot += order.itm[i].qty * order.itm[i].price;
            //                 }

            //               //  printf("Itv ran");
            //          }

            //          printf("SALES SUMMARY :-------");
            //          printf("\n\n\n\t\t\t\t-----------------------------------");
            //          printf("\n\n\n\t\t\t\tTotal Sales : %f \n",tot);
            //          printf("\n\n\n\t\t\t\tTotal Profits : %f (Assuming a 15 %% margin) \n",tot/6.66);

            //          fclose(fp);
            //          break;

            system("cls");

            fp = fopen("log.txt", "a+");
            c = fgetc(fp);
            while (c != EOF)
            {
                printf("%c", c);
                c = fgetc(fp);
            }

            fclose(fp);
            break;

        case 7:
            system("cls");
            system("color 8e");

            printf("Enter your Name :");
            gets(premStuc.name);

            printf("\nEnter your preffered User id :");
            gets(premStuc.id);

            printf("\nEnter the password :");
            while (1)
            {
                premCh = getch();
                if (premCh == 13)
                    break;
                premStuc.paswrd[ix] = premCh;
                printf("*");
                ix++;
            }

            paswPrem[ix] = '\0';
            ix = 0;

            printf("\n\nEnter your address : ");
            gets(premStuc.address);

            printf("\nEnter your Phone Number : ");
            gets(premStuc.phn);

            premFile = fopen("PremCustomers.dat", "a");

            fwrite(&premStuc, sizeof(struct premium), 1, premFile);

            if (fwrite != 0)
            {
                printf("\nSuccessfully saved");
                countPrem++;
            }

            else
                printf("\nError saving");

            // fflush(premFile);
            fclose(premFile);
            break;

        case 8:
            system("cls");
            system("color 5e");
            printf(" \n                      ENTER USERNAME:-");
            scanf("%s", &premName);
            printf(" \n                      ENTER PASSWORD:-");

            while (1)
            {
                premCh = getch();
                if (premCh == 13)
                    break;
                paswPrem[ix] = premCh;
                printf("*");
                ix++;
            }

            paswPrem[ix] = '\0';
            ix = 0;

            premFile = fopen("PremCustomers.dat", "r");
            // generatePremiumBody();

            while (fread(&premStuc, sizeof(struct premium), 1, premFile))
            {
                if (!(strcmp(premStuc.id, premName) && strcmp(premStuc.paswrd, paswPrem)))
                {
                    printf("\n\nName : %s \n\n", premStuc.name);
                    printf("USer ID : %s \n\n", premStuc.id);
                    printf("Password : %s \n\n", premStuc.paswrd);

                    printf("Address : %s  \n\n", premStuc.address);
                    printf("Phone Number : %s  \n\n", premStuc.phn);

                    break;
                }
            }

            break;

        case 9:
            system("cls");
            system("color 9d");
            int p = 0;
            premFile = fopen("PremCustomers.dat", "r");
            generatePremiumBody();

            while (fread(&premStuc, sizeof(struct premium), 1, premFile))
            {
                int sl = 1;

                for (int x2 = 0; x2 < countPrem; x2++)
                {
                    generatePremiumContent(++p, premStuc.name, premStuc.id, premStuc.paswrd);
                }
            }
            // system("cls");

            fclose(premFile);
            break;

        case 10:
            system("cls");
            system("color 5e");
            printf(" \n                      ENTER USERNAME:-");
            scanf("%s", &premName);
            printf(" \n                      ENTER PASSWORD:-");

            while (1)
            {
                premCh = getch();
                if (premCh == 13)
                    break;
                paswPrem[ix] = premCh;
                printf("*");
                ix++;
            }

            paswPrem[ix] = '\0';
            ix = 0;

            premFile = fopen("PremCustomers.dat", "r");
            // generatePremiumBody();

            while (fread(&premStuc, sizeof(struct premium), 1, premFile))
            {
                if (!(strcmp(premStuc.id, premName) && strcmp(premStuc.paswrd, paswPrem)))
                {

                    system("cls");
                    //  printf("\nPlease enter the name of the customer:\t");
                    fgets(ord.customer, 50, stdin);
                    ord.customer[strlen(ord.customer) - 1] = 0;
                    strcpy(ord.date, __DATE__);

                    // printf("\nPlease enter the number of items:\t");
                    // scanf("%d", &n);
                    // ord.numOfItems = n;
                    // for (int i = 0; i < n; i++)
                    // {
                    //     fgetc(stdin);
                    //     printf("\n\n");
                    //     printf("Please enter the item %d:\t", i + 1);
                    //     fgets(ord.itm[i].item, 20, stdin);
                    //     ord.itm[i].item[strlen(ord.itm[i].item) - 1] = 0;
                    //     printf("Please enter the quantity:\t");
                    //     scanf("%d", &ord.itm[i].qty);
                    //     printf("Please enter the unit price:\t");
                    //     scanf("%f", &ord.itm[i].price);
                    //     total += ord.itm[i].qty * ord.itm[i].price;
                    // }

                    generatePremMenu();
                    int i = 0;
                    int choice;
                    while (1)
                    {
                        // int choice;
                        // fgetc(stdin);
                        printf("\n\n");
                    label2:
                        printf("Please enter the item no. and quantity :");
                        scanf("%d %d", &choice, &n1);
                        char item[50];
                        switch (choice)
                        {
                        case 1:
                            strcpy(item, "Vegetable Samosa");
                            price = 5.99 * n1;
                            discount = price * 0.1;
                            price = price - discount;
                            break;
                        case 2:
                            strcpy(item, "Paneer Tikka");
                            price = 7.99 * n1;
                            discount = price * 0.15;
                            price = price - discount;
                            break;
                        case 3:
                            strcpy(item, "Chicken Tikka");
                            price = 8.99 * n1;
                            discount = price * 0.1;
                            price = price - discount;
                            break;
                        case 4:
                            strcpy(item, "Tandoori Shrimp");
                            price = 10.99 * n1;
                            discount = price * 0.05;
                            price = price - discount;
                            break;
                        case 5:
                            strcpy(item, "Aloo Chaat");
                            price = 6.99 * n1;
                            discount = price * 0.2;
                            price = price - discount;
                            break;
                        case 6:
                            strcpy(item, "Vegetable Biryani");
                            price = 12.99 * n1;
                            discount = price * 0.1;
                            price = price - discount;
                            break;
                        case 7:
                            strcpy(item, "Paneer Butter Masala");
                            price = 14.99 * n1;
                            discount = price * 0.15;
                            price = price - discount;
                            break;
                        case 8:
                            strcpy(item, "Chana Masala");
                            price = 14.99 * n1;
                            discount = price * 0.1;
                            price = price - discount;
                            break;
                        case 9:
                            strcpy(item, "Baingan Bharta");
                            price = 11.99 * n1;
                            discount = price * 0.1;
                            price = price - discount;
                            break;
                        case 10:
                            strcpy(item, "Malai Kofta");
                            price = 12.99 * n1;
                            discount = price * 0.15;
                            price = price - discount;
                            break;
                        case 11:
                            strcpy(item, "Chicken Curry");
                            price = 13.99 * n1;
                            discount = price * 0.1;
                            price = price - discount;
                            break;
                        case 12:
                            strcpy(item, "Lamb Rogan Josh");
                            price = 14.99 * n1;
                            discount = price * 0.15;
                            price = price - discount;
                            break;
                        case 13:
                            strcpy(item, "Butter Chicken");
                            price = 15.99 * n1;
                            discount = price * 0.1;
                            price = price - discount;
                            break;
                        case 14:
                            strcpy(item, "Goan Fish Curry");
                            price = 17.99 * n1;
                            discount = price * 0.1;
                            price = price - discount;
                            break;
                        case 15:
                            strcpy(item, "Tandoori Mixed Grill");
                            price = 19.99 * n1;
                            discount = price * 0.1;
                            price = price - discount;
                            break;

                        default:
                            goto label2;
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
                    int prinDis;

                    // if(choice==1 || choice==3|| choice==9||choice==11|| choice==13||choice==6)
                    //     prinDis= 10;

                    // else if(choice==2 ||choice == 10 || choice==12||choice ==7)
                    //  prinDis = 15;

                    //  else if(choice == 4)
                    //      prinDis = 5;
                    //  else if(choice == 5)
                    //     prinDis=20;

                    generatePremBillHeader(ord.customer, ord.date);
                    for (int i = 0; i < ord.numOfItems; i++)
                    {
                        generatePremBillBody(ord.itm[i].item, ord.itm[i].qty, ord.itm[i].price);
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
                }
            }
            break;

        case 11:
            //  printf("\n\t\t Code ends\n\n");
            endingscreen();
            exit(0);
            break;

        default:
            printf("Sorry invalid option");
            break;
        }
        printf("\n<Enter any key to continue>");
        getch();

        printf("\nDo you want to perform another operation? [y/n]");
        scanf("%s", &contFlag);
    }
    // printf("\n\t\t Code ends\n\n");
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
    printf(" \n\t * ID:  - Anand Roy\n\n");
    printf(" \t * ID:  - Aum Vyas\n\n");
    printf(" \t * ID:  - Aditya Raj\n\n");
    printf(" \t * ID:  - Naman Agarwal\n\n");
    printf("\n");
    system("pause");
    system("CLS");
    system("color 5e");
    printf("\n\n\n\n\n\n");
    printf("\t\t\tOur project on:\n\n");
    printf("\n");
    char nam[] = "\n\n\t\t\t Invoice Management System Project \n\n";
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
        printf("\n  *  LOGIN FORM  *  ");
        printf(" \n                       ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n                       ENTER PASSWORD:-");
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
            printf("                     __ ______ ___ _______ ______\n");
            printf("                    /                             \\          \n");
            printf("                   |     Loading.............      |           \n");
            printf("\t\t   |\t");
            for (j = 0; j < 24; j++)
            {
                printf("%c", 219);
                delay(50);
            }
            printf("   |\n                   \\_______ _______ _____ ___ _____/           \n");
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
    }

    while (a <= 2);

    if (a > 2)
    {
        printf("\nSorry you have entered the wrong user name and password for four times!!!");
        getch();
    }
    system("cls");
}
