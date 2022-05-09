#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "limits.h"

// typedef struct user_acc
// {
//     char name[255];
//     char password[255];
// } user_acc;

void login(char name[], char password[])
{
    FILE *fptr;
    char word[255];
    int wc = 0, i = 0, res;
    if (!fptr)
        return;
    // user_acc account;
    fptr = fopen("Login.txt", "r");
    while (fscanf(fptr, "%s", word) != -1)
    {
        if (!strcmp(name, word))
        {
            fscanf(fptr, "%s", word);
            // printf("%s", word);
            res = strcmp(word, password);
            if (res == 0)
                printf("You have logged in succesfully!");
            else
                printf("Incorrect username or password");
            return;
        }
    }
    printf("Incorrect username or password");

    fclose(fptr);
    return;
}

void signup(char name[], char address[], char mobileno[], char username[], char password[])
{
    char word[255];
    FILE *fp;
    fp = fopen("Login.txt", "a");
    
    fprintf(fp, "%s ", username);
    fprintf(fp, "%s\n", password);
    fclose(fp);
    fp = fopen("Signup.txt", "a");
    fprintf(fp, "%s ", name);
    fprintf(fp, "%s ", username);
    fprintf(fp, "%s ", address);
    fprintf(fp, "%s ", mobileno);
    fclose(fp);
    return;
}

int main()
{

    printf("Welcome to FoodieBay\n");
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
            fp=fopen("Login.txt","r");
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
        fclose(fp);
        signup(n, address, mobileno, un, p);

        return 0;
    }
}

// int main()
// {
//     char n[255];
//     char p[255];
//     scanf("%s", n);
//     scanf("%s", p);
//     FILE *fp;
//     fp = fopen("Login.txt", "a");
//     // fprintf(fp,"%s ",n);
//     // fprintf(fp,"%s\n",p);
//     int len = sizeof(p) / sizeof(p[0]);
//     if (len < 8)
//         printf("Password must be at least 8 characters");
//     else
//         login(n, p);
//     return 0;
// }