#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "limits.h"
#include "Trie.h"
//#include "queue.h"
#include "main.h"
#include "linkedlist.h"

int m1 = 0, m2 = 0;
int main()
{
    int a, b, c, y, k, x, cost, total_cost = 0;
    //Queue Q1;
    list L1;
    init_list(&L1);
    // init_Queue(&Q1);
    char rest[255];
    char un[255];
    char p[255];
    char n[255];
    char address[255];
    char mobileno[10];
    Trie restaurant, FB;
    init(&FB);
    FILE *fp = fopen("FoodieBay.txt", "r");
    char word[255];
    while (fscanf(fp, "%s", word) != -1)
    {
        insert(&FB, word);
    }
    fclose(fp);

    // login-signup
    while (m1 >= 0)
    {
        // Trie restaurant;

        // init(&restaurant);
        // FILE *fp = fopen("restaurants.txt", "r");
        // char word[255];
        // while (fscanf(fp, "%s", word) != -1)
        // {
        //     insert(&restaurant, word);
        // }
        // fclose(fp);

        printf("Welcome to FoodieBay!\n");
        printf("1.Login\n2.Signup\n3.Exit");
        printf("\n");

        scanf("%d", &a);

        // FILE *fp;
        if (a == 1)
        {
            printf("Enter your username:\n");
            scanf("%s", un);
            printf("Enter your password:\n");
            scanf("%s", p);

            // fp = fopen("Login.txt", "a");
            //  fprintf(fp,"%s ",n);
            //  fprintf(fp,"%s\n",p);
            //  int len = sizeof(p) / sizeof(p[0]);
            //  if (len < 8)
            //      printf("Password must be at least 8 characters");
            //  else
            m2 = login(un, p);
            printf("%d", m2);
            if (m2 == 2)
                m1 = -1;
        }
        else if (a == 2)
        {
            fgetc(stdin);
            int i = 1;
            char word[255];
            printf("Enter your name:\n");
            // scanf("%s", n); fgets(n, 50, stdin);
            fgets(n, 50, stdin);
            printf("Enter your address:\n");
            // scanf("%s", address);
            fgets(address, 255, stdin);
            printf("Enter your mobile no:\n");
            scanf("%s", mobileno);

            while (i > 0)
            {
                i = 1;
                printf("Enter your username:\n");
                scanf("%s", un);

                fp = fopen("Login.txt", "r");
                while (fscanf(fp, "%s", word) != -1)
                {
                    if (!strcmp(un, word))
                    {
                        printf("This username already exists!\n");
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
                i = 1;
                int j = 0, cnt = 0;
                printf("Enter your password:\n");
                scanf("%s", p);
                while (p[j] != '\0')
                {
                    cnt++;
                    j++;
                }
                //  int len = sizeof(p) / sizeof(p[0]);
                // printf("%d",cnt);
                if (cnt < 8)
                {
                    printf("Password must be at least 8 characters:\n");
                    i = 2;
                }
                if (i != 2)
                    i = -1;
            }
            fclose(fp);
            signup(n, address, mobileno, un, p);
        }
        else if (a == 3)
            m1 = -1;
        else
            printf("Enter a valid number:\n");
    }

    // ordering food
    while (m2 >= 0)
    {
        if (m2 == 2)
        {
            printf("Order your food now\n");
            printf("1.Display menu\n2.Search for a specific dish\n3.Exit\n");
            scanf("%d", &b);
            if (b == 1)
            {
                int count = 0, c1;
                FILE *fp = fopen("FoodieBay.txt", "r");
                char word[255];
                while (fscanf(fp, "%s", word) != -1)
                {
                    printf("%d %s\n", count, word);
                    count++;
                }
                fclose(fp);
            }
            else if (b == 2)
            {
                int iloop = 1;
                while (iloop >= 1)
                {
                    printf("What would you like to order?\n");
                    char line[1000];
                    if (!fp)
                        return 0;

                    scanf("%s", line);

                    // while (fgets(line, sizeof(line), fp) != NULL)
                    // {
                    //     fputs(line, stdout);
                    // }
                    autocomplete(&FB, line);
                    printf("\n");
                    char p[1];
                    p[0] = line[0];
                    p[1] = line[1];
                    autocomplete(&FB, p);
                    printf("We have following items related to your search\n");
                    printf("What would you like to order?\n");
                    scanf("%s", line);
                    printf("Enter the quantity:\n");
                    scanf("%d", &k);
                    printf("Add %s to the cart?\n1.Yes\n2.No", line);
                    scanf("%d", &y);
                    if (y == 1)
                    {
                        // enQueue(&Q1,)
                        int count = 1, count1 = 0;
                        FILE *fp = fopen("FoodieBay.txt", "r");
                        while (fscanf(fp, "%s", word) != -1)
                        {
                            if (line == word)
                            {
                                break;
                            }
                            count++;
                        }
                        fclose(fp);
                        FILE *fptr = fopen("Prices.txt", "r");
                        while (fscanf(fptr, "%d", &cost) != -1)
                        {
                            if (count1 == count)
                            {
                                break;
                            }
                            count1++;
                        }
                        fclose(fptr);
                        k = 0;
                        insert_begin(&L1, line, cost, k);
                        total_cost = total_cost + cost;
                        // order[k].food=word;
                        // order[k].price=cost;

                        // cart *q;
                        // q=order;
                        // q->food=word;
                        // q->price=cost;
                        // C.food[k] = word;
                        // C.price[k] = cost;
                        printf("Do you want to order more?\n1.Yes\n2.No\n");
                        scanf("%d", &y);
                        if (y == 2)
                        {
                            printf("    Order details    \n");
                            //  printf("%s\n", line);
                            print_cart(L1);

                            printf("Do you want to confirm your order?\n1.Yes\n2.No\n");
                            scanf("%d", &y);
                            if (y == 1)
                            {
                                printf("Order placed!\nThanks for ordering!\n");
                                printf("Your order:\n");
                                print_cart(L1);

                                printf("Total:%d Rs\n", total_cost);
                                // FILE *fp = fopen("Signup.txt", "r");
                                // // printf("%s",un);
                                // while (fscanf(fp, "%s", word) != -1)
                                // {
                                //     if (un == word)
                                //     {
                                //         break;
                                //     }
                                // }
                                // fscanf(fp, "%s", word);
                                // fgets(word,sizeof(word),fp);
                                //  fscanf(fp, "%s", word);
                                // C.addr[0] = word;
                               // printf("Delivery address:%s\n", word);

                               // fclose(fp);
                                iloop = 0;
                                m2 = -1;
                            }
                            // if (y == 2)
                            // {
                            //     printf("Do you want to delete an item from the cart?\n");
                            //     scanf("%d", &y);
                            //     if(y==1){
                            //         scanf("%s",&word);
                            //         for(int i=0;i<k;i++){
                            //             if(C.food[k]==word){
                            //                 order[k].food='#';
                            //                 order[k].food==word
                            //             }
                            //         }

                            //     }
                        }
                    }
                }
            }
            else
            {
                m2 = -1;
            }
        }
    }
}
