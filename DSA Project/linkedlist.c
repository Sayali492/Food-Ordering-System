#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
//#include "queue.h"
#include "main.h"
#include "linkedlist.h"

void init_list(list *L)
{
    *L = NULL;
    return;
}
void print_cart(list L)
{
    cart *p;
    p = L;
    if (L == NULL)
        printf("List is Empty");
    while (p != NULL)
    {
        printf("%s %d %d\n", p->food,p->quantity,p->price);
        p = p->next;
    }
}
void insert_begin(list *L, char *Food,int Price,int quant)
{ // here first I had done struct node *L,but it didnt give any op,coz I passed its value.Pass the arguments by reference and then u get the op.
    cart *nn;
    nn = (cart *)malloc(sizeof(cart));
    int i = 0;
    while (Food[i] != '\0')
    {
        nn->food[i] = Food[i];
        i++;
    }
    nn->price=Price;
   // nn->addr = address;
    nn->quantity = quant;
    nn->next = NULL;
    if (*L == NULL)
    {
        *L = nn;
        return;
    }

    else
    {

        nn->next = *L;
        *L = nn;
        return;
    }
}

void delete_item(list *L, char *d)
{
    struct cart *p, *q;
    int count;
    p = *L;
    q = NULL;
    if (p == NULL)
    {
        return;
    }
    // while (p != NULL)
    // {
    //         count++;
    //         p = p->next;
    // }
    // p = *L;
    // if (count == 1)
    // {
    if (p->next == NULL)
    {
        while (p && p->food != d)
        {
            q = p;
            p = p->next;
        }
        if (p != NULL)
        {
            *L = NULL;
            free(p);
        }
        else
        {
            return;
        }
    }
    else
    {

        if (p->food == d)
        {

            *L = p->next;
            free(p);

            return;
        }
        else
        {
            while (p && p->food != d)
            {
                q = p;
                p = p->next;
            }
            if (p != NULL)
            {
                q->next = p->next;
                free(p);
            }
            else
            {
                return;
            }
        }
    }
}

void destroy_List(list *L)
{

    cart *p = *L;
    cart *q;

    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }

    p = *L;
    p->next = NULL;
    *L = NULL;
}