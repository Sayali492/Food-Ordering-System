typedef struct cart
{
    char food[255];
    int price[255];
    char *addr;
} cart;

int login(char name[], char password[]);
void signup(char name[], char address[], char mobileno[], char username[], char password[]);
