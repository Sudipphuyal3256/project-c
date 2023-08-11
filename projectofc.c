#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


FILE *fp;
// Defining Structure
typedef struct mynode {
    char name[20];
    char gen[6];
    int age;
    struct mynode* link;
} Node;

Node* start = NULL;

void details(int);
int seat(int);
int cal(int, int, int);
void bill(int, int);

// Global variables
// "Depar" = place of departure and "des" = place of destination
char Depar[20], des[20], train[40];
char station[40], cla[40];
int time1, time2, a[55];

// Function prototypes
void add_node(char[], char[], int);

// Driver Code
int main()
{
    fp=fopen("records.txt","a+");
    if(fp==NULL)
    {
        printf("ERRORS");
    }
    int i, j, a1, a2, d, x = 0;
    printf("Enter Number Of Passengers: ");
    scanf(" %d", &j);
    fprintf(fp,"%d ",j);



    // Calling details() function with
    // argument number of passenger
    details(j);
    printf("Enter The Departure Place: ");
    scanf(" %[^\n]", Depar);
    fprintf(fp,"%s ",Depar);
    printf("Enter The Destination Place: ");
    scanf(" %[^\n]", des);
    fprintf(fp,"%s ",des);
    printf("\t\tThe Following Trains from %s to %s""\tare available.....\n",Depar,des);
    printf("\t\t1. Rajdhani Express..""....10:00 ""a.m.....Sealdah Station\n");
    printf("\t\t2. Satabdi Express...""....05:00 ""p.m.....Howrah Station\n");
    printf("\t\t3. Humsafar Express...""...11:00 ""p.m.....Kolkata Chitpur"" Station\n");
    printf("\t\t4. Garib-Rath Express""....05:00 ""p.m.....Sealdah Station\n");
    printf("\t\t5. Duronto Express...""....07:00 ""a.m.....Santraganchi Station\n");
    printf(" Please enter the train number you want to travel: ");
    scanf("%d", &i);
    fprintf(fp,"%d ",i);

    do {
        switch (i) {
        case 1:
            strcpy(train,
                   "Rajdhani Express");
            strcpy(station,
                   "Sealdah Station");
            time1 = 10;
            time2 = 0;
            a1 = 1200;
            a2 = 600;

            // Calling cal() function
            // with the three argument
            // and return value
            d = cal(a1, a2, j);
            //printf("Total Bill Amount:"" %d\n",d);
         break;
        case 2:
            strcpy(train,
                   "Satabdi Express");
            strcpy(station,
                   "Howrah Station");
            time1 = 17;
            time2 = 0;
            a1 = 1100;
            a2 = 550;

            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            //printf("Total Bill Amount:"
//"%d\n",d);

            break;
        case 3:
            strcpy(train,
                   "Humsafar Express");
            strcpy(station,
                   "Kolkata Chitpur");
            time1 = 23;
            time2 = 0;
            a1 = 1300;
            a2 = 650;

            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            //printf("Total Bill Amount: %d\n", d);
         break;
        case 4:
            strcpy(train, "Garib-Rath Express");
            strcpy(station, "Sealdah Station");
            time1 = 17;
            time2 = 0;
            a1 = 1800;
            a2 = 1200;

            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            //printf("Total Bill Amount: %d\n", d);
         break;
        case 5:
            strcpy(train, "Duronto Express");
            strcpy(station, "Santraganchi Station");
            time1 = 7;
            time2 = 0;
            a1 = 2000;
            a2 = 900;

            // Calling cal() function with
            // three argument & return value
            d = cal(a1, a2, j);
            //printf("Total Bill Amount: %d\n", d);
         break;
        default:
            printf("Enter Correct choice.....\n");
            x = 1;
            break;
        }
    } while (x);
    fprintf(fp,"%s ",train,station);
    printf("Now Book Your Seats......\n");

    // Calling seat() function with number
    // of passenger
    seat(j);

    // Calling bill() function with
    // the number of passenger
    // and amount as argument
    bill(d, j);

    return 0;
    fclose(fp);
}

// Function for calculation of amount
int cal(int y1, int y2, int h)
{
    fp = fopen("records.txt","a+");
    int b, c, i, m;
    printf("\t\tEnter Your Choice......\n");
    printf("\t\t1. Sleeper Class....\n");
    printf("\t\t2. A.C Class.......\n");
    scanf("%d", &i);
    if(i==1)
    {
         fprintf(fp,"Sleeper Class ");
    }
    else if(i==2)
    {
          fprintf(fp,"A.C Class ");
    }
    switch (i) {
    case 1: {
        strcpy(cla, "Sleeper Class");
        b = y2 * h;
        c = b ;
    } break;
    case 2: {
        printf("\t\tEnter Your Choice....\n");
        printf("\t\t1. 3A Class....\n");
        printf("\t\t2. 2A Class....\n");
        printf("\t\t3. 1st Class A.C.....\n");
        scanf("%d", &m);
        if(m==1)
        {
            fprintf(fp,"3A Class ");
        }
        else if(m==2)
        {
            fprintf(fp,"2A Class ");
        }
        else if(m==3)
        {
            fprintf(fp,"1st Class ");
        }
        switch (m) {
        case 1: {
            strcpy(cla, "3A Class");
            b = y1 * h;
            c = b ;
        } break;
        case 2: {
            strcpy(cla, "2A Class");
            b = (y1 + 1000) * h;
            c = b ;
        } break;
        case 3: {
            strcpy(cla, "1st Class A.C.");
            b = (y1 + 1500) * h;
            c = b ;
        } break;
        default: {
            printf("\t\tEnter Right Choice......\n");
            c = 0; // Set the amount to 0 if choice is invalid
        }
        }
    } break;
    default: {
        printf("\t\tEnter Right Choice......\n");
        c = 0; // Set the amount to 0 if choice is invalid
    }
    }
    return c;
}


void details(int k)
{
    fp=fopen("records.txt","a");
    int i, a;
    char val[20], gen[6];
    for (i = 1; i <= k; i++) {
        printf("Enter The Passenger %d Name: ", i);
        scanf(" %[^\n]", val);
        fprintf(fp,"%s ", val);
        printf("Enter The Passenger %d Gender: ", i);
        scanf("%s", gen);
        fprintf(fp,"%s ", gen);
        char ag[3];
        printf("Enter The Passenger %d Age: ", i);
        scanf(" %s",ag);
        int flag = 1 ;
        do{
        for(int i = 0; i<strlen(ag); i++)
        {
            if(isdigit(ag[i]))
            {
                flag=0;
            }
            else
            {
                flag = 1;
                printf("Please Re-Enter valid Age:");
                scanf("%s",ag);
            }
        }
        }while(flag==1);

        int a = atoi(ag);

        fprintf(fp,"%d ", a);

        add_node(val, gen, a);
    }
    fclose(fp);
}

//Add Details Of Each Passenger
void add_node(char lol[20], char der[6], int b)
{
    Node* newptr = NULL;
    newptr = (Node*)malloc(sizeof(Node));
    strcpy(newptr->name, lol);
    strcpy(newptr->gen, der);
    newptr->age = b;
    newptr->link = NULL;
    if (start == NULL)
        start = newptr;
    else {
        Node* ptr = start;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = newptr;
    }
}

// Function for choosing seats
int seat(int p)
{
    fp = fopen("records.txt","a+");
    int i;
    printf("\t           -:SEATS:-        \n");
    printf("\t(U)    (M)        (L)    (L)    "
           "    (U)\n\n");
    printf("\t01    02        03\t04        "
           "05\n\n");
    printf("\t06    07        08\t09        "
           "10\n");
    printf("\t11    12        13\t14        "
           "15\n\n");
    printf("\t16    17        18\t19        "
           "20\n");
    printf("\t21    22        23\t24        "
           "25\n\n");
    printf("\t26    27        28\t29        "
           "30\n");
    printf("\t31    32        33\t34        "
           "35\n\n");
    printf("\t36    37        38\t39        "
           "40\n");
    printf("\t41    42        43\t44        "
           "45\n\n");
    printf("\t46    47        48\t49        "
           "50\n");
    printf("\t51    52        53\t54        "
           "55\n\n");
    printf("\t56    57        58\t59        "
           "60\n");
    printf("\tEnter Seat Numbers: \n");
    for (i = 0; i < p; i++)
    {

        scanf("%d", &a[i]);
        fprintf(fp,"%d", a[i]);
    }
    return 0;

}

// Function for printing receipt
void bill(int y, int j)
{
    fp = fopen("records.txt","a+");

    int i;

    Node* ptr = start;
    for (i = 1; i <= j; i++) {
        printf("\t\tPassenger %d Name: ", i);
        puts(ptr->name);

        printf("\t\tPassenger %d Gender: ", i);
        puts(ptr->gen);

        printf("\t\t Passenger %d Age: %d\n\n", i, ptr->age);

        ptr = ptr->link;
    }
      //
    printf("\t\tDeparture Place: ");
    puts(Depar);

    printf("\t\tDestination Place: ");
    puts(des);

    printf("\t\tThe Boarding Station: ");
    puts(station);

    printf("\t\tTrain Is: ");
    puts(train);

    printf("\t\tAllocated Class: %s\n",cla);

    printf("\t\tBoarding Time: %d:%02d\n", time1, time2);
    printf("\t\tTotal Bill Amount: %d\n", y);
    printf("\t\tAllocated Seats Are: \n");
    for (i = 0; i < j; i++) {
        printf("\t\t%d ", a[i]);
    }
    printf("\n");
    printf("\t\t\t\tThank You......\n");
    fprintf(fp,"\n\n");


}


