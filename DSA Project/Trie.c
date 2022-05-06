#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "limits.h"

typedef struct node
{
    char ch;
    struct node *characters[26];
    int eow;

} node;

typedef node *Trie;

void init(Trie *t)
{
    *t = NULL;
    return;

    // int j;
    // (*t) = (node *)malloc(sizeof(node));
    // for (j = 0; j < 26; j++)
    // {
    //     (*t)->characters[j] = NULL;
    // }
    // (*t)->ch = 'R';
    // (*t)->eow = 0;
    // // (*t) = nn;
    // return;
}

void insert(Trie *t, char *word)
{
    int a = 2;
    // printf("%d", a);
    int j;
    node *p;

    // printf("%d", 2);
    if (*t == NULL)
    {
        p = (node *)malloc(sizeof(node));
        for (j = 0; j < 26; j++)
        {
            p->characters[j] = NULL;
        }
        p->ch = 'R';
        p->eow = 0;
        *t = p;
    }
    else
    {
        printf("ALL fine\n");
        p = *t;
    }
    // printf("%d", 2);
    // printf("%c", p->ch);
    // printf("%d", p->eow);
    // for (j = 0; j < 26; j++)
    // {
    //     printf("%d", p->characters[j]);
    // }

    int i = 0, index;
    // node *nn = (node *)malloc(sizeof(node));
    // for (j = 0; j < 26; j++)
    // {
    //     nn->characters[j] = NULL;
    // }
    // nn->ch = 'R';
    // nn->eow = 0;
    // p=nn;

    while (word[i] != '\0')
    {
        index = (int)word[i] - 97;
        // printf("%d", index);
        if (p->characters[index] == NULL)
        {
            p->characters[index] = (node *)malloc(sizeof(node));
            p = p->characters[index];
            p->ch = word[i];
            p->eow = 0;
            for (j = 0; j < 26; j++)
            {
                p->characters[j] = NULL;
            }
        }
        else
            p = p->characters[index];
        i++;
    }
    p->eow = 1;
    return;
}

//     p->ch = word[i];
//     p->eow = 0;
//     for (j = 0; j < 26; j++)
//     {
//         p->characters[j] = NULL;
//     }
//     if (word[i + 1] != '\0')
//     {

//         index = (int)word[i + 1] - 97;
//         p = p->characters[index];
//         // nn->characters[index] = (node *)malloc(sizeof(node));
//     }
//     else
//         p->eow = 1;
//     i++;
// }
// index = (int)word[0] - 97;
// (*t)->characters[index] = nn;
// return;

void print_trie(Trie *t)
{
    // Prints the nodes of the trie
    // if (!t)
    //     return;
    int index;
    node *temp = *t;
    if (*t == NULL)
        return;
    // printf("%s",temp);
    // temp = temp->characters[0];
    // printf("%s",temp);
    printf("%c -> ", temp->ch);
    //   printf("%d",index);
    for (int i = 0; i < 26; i++)
    {
        index = i;
        print_trie(&temp->characters[i]);
    }
    return;
}

int search(Trie *t, char *word)
{
    // node *p = *t;
    // node *q;
    // int index, i = 0;
    // if (*t == NULL)
    //     return INT_MIN;
    // checking if first character is present or not
    // index = (int)word[i] - 97;
    // if (p->characters[index] == NULL)
    //     return 0;
    // else
    // {
    //     p = p->characters[index];
    // }
    // i = 1;
    // index = (int)word[i] - 97;
    // while (word[i] != '\0')
    // {

    //     if (p->characters[index] == NULL)
    //         return 0;
    //     else
    //     {
    //         // p = &p->characters[index];
    //         index = (int)word[i + 1] - 97;
    //         q = p;
    //         p = p->characters[index];
    //         i++;
    //     }
    // }
    // if (p->eow == 1)
    //     return 1;
    // else
    //     return 0;

    // for (i = 0; word[i] != '\0'; i++)
    // {
    //     index = (int)word[i] - 97;
    //     if (p->characters[index] == NULL)
    //         return 0;
    //     else
    //     {
    //         q = p;
    //         index = (int)word[i + 1] - 97;
    //         p = p->characters[index];
    //     }
    // }
    // if (q->eow == 1)
    //     return 1;
    // else
    //     return 0;

    node *p;
    p = *t;
    int j;
    if (*t == NULL)
    {
        printf("Fail\n");

        return 0;
    }

    int i = 0, index;

    while (word[i] != '\0')
    {
        index = (int)word[i] - 97;
        // printf("%d", index);
        p = p->characters[index];

        if (p != NULL)
        {
            // p = p->characters[index];
            i++;
        }
        else
            return 0;
    }
    if (p->eow == 1)
        return 1;
    else
        return 0;
}

int main()
{
    Trie t1;
    int i = 0;
    // char ch;
    init(&t1);

    char *str;
    // scanf("%s", str);

    // insert(&t1, "apple");
    insert(&t1, "aaa");
    insert(&t1, "baa");
    insert(&t1, "caa");
    insert(&t1, "zaa");

    // printf("%c", t1->ch);
    // printf("%c", &t1->characters[0]->ch);
    print_trie(&t1);
    //   printf("%c",t1->characters[0]->ch);
    int s = search(&t1, "aaa");
    printf("search:%d", s);
    // int a = (int)ch;
    // printf("%d", a);
    return 0;
}