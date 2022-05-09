#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "limits.h"

int main()
{

    printf("Welcome to FoodieBay");
    printf("1.Login\n2.Signup\n");
    int a;
    char un[255];
    char p[255];
    char n[255];
    char address[255];
    char mobileno[10];
    scanf("%d", &a);
    FILE *fp;
    if (a == 1)
    {

        scanf("%s", un);
        scanf("%s", p);

        // fp = fopen("Login.txt", "a");
        //  fprintf(fp,"%s ",n);
        //  fprintf(fp,"%s\n",p);
        //  int len = sizeof(p) / sizeof(p[0]);
        //  if (len < 8)
        //      printf("Password must be at least 8 characters");
        //  else
        login(n, p);
    }
    else if (a == 2)
    {
        int i = 1;
        char word[255];
        printf("Enter your name:\n");
        scanf("%s", n);
        printf("Enter your address:\n");
        scanf("%s", address);
        printf("Enter your mobile no:\n");
        scanf("%s", mobileno);

        while (i > 0)
        {
            printf("Enter your username:\n");
            scanf("%s", un);
            while (fscanf(fp, "%s", word) != -1)
            {
                if (!strcmp(un, word))
                {
                    printf("This username already exists!");
                    i = 2;
                    break;
                }
            }
            if (i != 2)
                i = -1;
        }
        i = 1;

        while (i > 0)
        {
            printf("Enter your password:\n");
            scanf("%s", p);
            int len = sizeof(p) / sizeof(p[0]);
            if (len < 8)
            {
                printf("Password must be at least 8 characters");
                i = 2;
            }
            if (i != 2)
                i = -1;
        }

        signup(n, address, mobileno, un, p);

        return 0;
    }
}