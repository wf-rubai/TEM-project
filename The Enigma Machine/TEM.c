/*****************************************************************************************

Group no. 2....
THE ENIGMA MACHINE

Washio Ferdous.............2231107642
Mumtahina..................2231749642
Nazifa Anjum...............2233406642

When you login for the first time you have to use the id and the password below...
ID: 2231107
PASS: potato

The goal was rebuild the actual ENIGMA machine that used in world war II. The
functionality is the same as the real machine but in software form. If you want to
know more about ENIGMA I will suggest to run the code and read the ABOUT ENIGMA
section which contains a summary on THE ENIGMA.........

******************************************************************************************/
#include <stdio.h>               ///   ----------------------------------------------------
#include <stdlib.h>              ///   |        Contributions of the group members        |
#include <string.h>              ///   ----------------------------------------------------
#include <termios.h>             ///   
void management();               ///...done by Washio Ferdous && designed by Washio Ferdous
int  login(int n);               ///...done by Washio Ferdous
int  in_app_login(int n);        ///...done by Washio Ferdous
int  add_id(int n);              ///...done by Nazifa Anjum   && designed by Washio Ferdous
void user_data(int n);           ///...done by Mumtahina      && designed by Washio Ferdous
int  remove_id(int a);           ///...done by Washio Ferdous && designed by Washio Ferdous
void encrypt(int f);             ///...done by Washio Ferdous && designed by Washio Ferdous
void decrypt();                  ///...done by Washio Ferdous && designed by Washio Ferdous
void history();                  ///...done by Washio Ferdous && designed by Washio Ferdous
void settings();                 ///...done by Washio Ferdous && designed by Washio Ferdous
char switch_box1(char a, int n); ///...done by Nazifa Anjum   && assisted by Washio Ferdous
char switch_box2(char a);        ///...done by Mumtahina
void pause();                    ///...done by Washio Ferdous
void TEM();                      ///...done by Washio Ferdous && designed by Washio Ferdous
void abt_enigma();               ///...done by Mumtahina      && designed by Washio Ferdous
void abt_dev();                  ///...done by Nazifa Anjum   && designed by Washio Ferdous

FILE *user_information, *store_room;
int save_loger = 0;
int lock = 1;

struct TEM_user
{
    int user_no;
    char name[100];
    int id;
    char pass[50];
    int gen;
} userLog[100];

struct store
{
    int num;
    char user_name;
    char string_to_decrypt;
    int key_to_unlock;
} str[100];

int main()
{
    userLog[1].user_no = 2;
    int n = 10, x, c, e, i, j;
    char b[100], d[100];

    user_information = fopen("user_information.txt", "r");
    if (user_information == NULL)
    {
        userLog[0].user_no = 0;
        strcpy(userLog[0].name, "General_Rubai");
        userLog[0].id = 2231107;
        strcpy(userLog[0].pass, "potato");
        userLog[0].gen = 1;

        user_information = fopen("user_information.txt", "w");
        fprintf(user_information, "%d", userLog[0].user_no);
        fprintf(user_information, "\t%s", userLog[0].name);
        fprintf(user_information, "\t\t%d", userLog[0].id);
        fprintf(user_information, "\t\t%s", userLog[0].pass);
        fprintf(user_information, "\t\t%d\n", userLog[0].gen);
        fclose(user_information);
    }
    fclose(user_information);

    store_room = fopen("store_room.txt", "r");
    if (store_room == NULL)
    {
        store_room = fopen("store_room.txt", "w");
        fprintf(store_room, "%d", 0);
        fprintf(store_room, "\t%s", "no_user");
        fprintf(store_room, "\t\t\t%s", "this_line_is_blank");
        fprintf(store_room, "\t\t\t\t%d\n", 666666);
        fclose(store_room);
    }
    fclose(store_room);
    fclose(user_information);

    while (n > 0)
    {
        system("clear");
        TEM();

        user_information = fopen("user_information.txt", "r");
        fscanf(user_information, " %d %s %d %s %d", &x, b, &c, d, &e);
        while (1)
        {
            fscanf(user_information, " %d %s %d %s %d", &x, b, &c, d, &e);
            if (feof(user_information))
                break;
        }
        x++;
        lock = 1;

        user_information = fopen("user_information.txt", "r");
        for (i = 0; i < x; i++)
        {
            fscanf(user_information, "%d %s %d %s %d", &userLog[i].user_no, userLog[i].name, &userLog[i].id, userLog[i].pass, &userLog[i].gen);
        }
        fclose(user_information);

        printf("\n\n  1. Log in to enigma");
        printf("\n  2. About enigma");
        printf("\n  3. About the developers");
        printf("\n  0. Exit\n\n  \U000025BA  ");
        scanf("%d", &n);

        if (n == 1)
        {
            if (login(x) == 1)
                management();
            else
            {
                printf("\a");
                printf("\033[1;31m");
                printf("\n\n\t\t");
                char s[3][27] = {"1-------------------------2",
                                 "|Wrong user ID or password|",
                                 "3-------------------------4"};
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 27; j++)
                    {
                        if (s[i][j] == '-')
                            printf("\U00002550");
                        else if (s[i][j] == '1')
                            printf("\U00002554");
                        else if (s[i][j] == '2')
                            printf("\U00002557");
                        else if (s[i][j] == '3')
                            printf("\U0000255A");
                        else if (s[i][j] == '4')
                            printf("\U0000255D");
                        else if (s[i][j] == '|')
                            printf("\U00002551");
                        else
                            printf("%c", s[i][j]);
                    }
                    printf("\n\t\t");
                }
                printf("\033[0m");
                printf("  \n\n  Enter any key to go back...");
                pause();
            }
        }
        else if (n == 2)
        {
            abt_enigma();
        }
        else if (n == 3)
        {
            abt_dev();
        }
    }
    return 0;
}

void management()
{
    int n = 9, x, c, e, i, j;
    char b[100], d[100], nam[100];

    while (n > 0)
    {
        system("clear");
        TEM();

        user_information = fopen("user_information.txt", "r");
        fscanf(user_information, " %d %s %d %s %d", &x, b, &c, d, &e);
        while (1)
        {
            fscanf(user_information, " %d %s %d %s %d", &x, b, &c, d, &e);
            if (feof(user_information))
                break;
        }
        x++;
        fclose(user_information);

        user_information = fopen("user_information.txt", "r");
        for (i = 0; i < x; i++)
        {
            fscanf(user_information, "%d %s %d %s %d", &userLog[i].user_no, userLog[i].name, &userLog[i].id, userLog[i].pass, &userLog[i].gen);
        }
        fclose(user_information);

        printf("\033[1;32m");
        strcpy(nam, userLog[save_loger].name);
        for (j = 0; nam[j] != 0; j++)
        {
            if (nam[j] == '_')
                nam[j] = ' ';
        }
        printf("  %s", nam);
        printf("\033[0m");
        if (userLog[save_loger].gen == 2)
            printf(" madam,");
        else
            printf(" sir,");
        printf(" you are in enigma.....\n\n");

        if (n == 1)
        {
            printf("\033[1;33m");
            printf("  1. Encrypt with enigma");
            printf("\033[0m");
            printf("\n  2. Decrypt with enigma");
            printf("\n  3. See the history of uses");
            printf("\n  4. Add new user to enigma");
            printf("\n  5. See user info of enigma");
            printf("\n  6. Remove user from enigma");
            printf("\n  7. Settings");
            printf("\n  0. Back to login page\n\n  \U000025BA  ");
        }
        else if (n == 2)
        {
            printf("  1. Encrypt with enigma");
            printf("\033[1;33m");
            printf("\n  2. Decrypt with enigma");
            printf("\033[0m");
            printf("\n  3. See the history of uses");
            printf("\n  4. Add new user to enigma");
            printf("\n  5. See user info of enigma");
            printf("\n  6. Remove user from enigma");
            printf("\n  7. Settings");
            printf("\n  0. Back to login page\n\n  \U000025BA  ");
        }
        else if (n == 3)
        {
            printf("  1. Encrypt with enigma");
            printf("\n  2. Decrypt with enigma");
            printf("\033[1;33m");
            printf("\n  3. See the history of uses");
            printf("\033[0m");
            printf("\n  4. Add new user to enigma");
            printf("\n  5. See user info of enigma");
            printf("\n  6. Remove user from enigma");
            printf("\n  7. Settings");
            printf("\n  0. Back to login page\n\n  \U000025BA  ");
        }
        else if (n == 4)
        {
            printf("  1. Encrypt with enigma");
            printf("\n  2. Decrypt with enigma");
            printf("\n  3. See the history of uses");
            printf("\033[1;33m");
            printf("\n  4. Add new user to enigma");
            printf("\033[0m");
            printf("\n  5. See user info of enigma");
            printf("\n  6. Remove user from enigma");
            printf("\n  7. Settings");
            printf("\n  0. Back to login page\n\n  \U000025BA  ");
        }
        else if (n == 5)
        {
            printf("  1. Encrypt with enigma");
            printf("\n  2. Decrypt with enigma");
            printf("\n  3. See the history of uses");
            printf("\n  4. Add new user to enigma");
            printf("\033[1;33m");
            printf("\n  5. See user info of enigma");
            printf("\033[0m");
            printf("\n  6. Remove user from enigma");
            printf("\n  7. Settings");
            printf("\n  0. Back to login page\n\n  \U000025BA  ");
        }
        else if (n == 6)
        {
            printf("  1. Encrypt with enigma");
            printf("\n  2. Decrypt with enigma");
            printf("\n  3. See the history of uses");
            printf("\n  4. Add new user to enigma");
            printf("\n  5. See user info of enigma");
            printf("\033[1;33m");
            printf("\n  6. Remove user from enigma");
            printf("\033[0m");
            printf("\n  7. Settings");
            printf("\n  0. Back to login page\n\n  \U000025BA  ");
        }
        else if (n == 7)
        {
            printf("  1. Encrypt with enigma");
            printf("\n  2. Decrypt with enigma");
            printf("\n  3. See the history of uses");
            printf("\n  4. Add new user to enigma");
            printf("\n  5. See user info of enigma");
            printf("\n  6. Remove user from enigma");
            printf("\033[1;33m");
            printf("\n  7. Settings");
            printf("\033[0m");
            printf("\n  0. Back to login page\n\n  \U000025BA  ");
        }
        else
        {
            printf("  1. Encrypt with enigma");
            printf("\n  2. Decrypt with enigma");
            printf("\n  3. See the history of uses");
            printf("\n  4. Add new user to enigma");
            printf("\n  5. See user info of enigma");
            printf("\n  6. Remove user from enigma");
            printf("\n  7. Settings");
            printf("\n  0. Back to login page\n\n  \U000025BA  ");
        }

        scanf("%d", &n);

        if (n == 1)
        {
            if (in_app_login(x) == 1)
            {
                encrypt(x);
            }
            else
            {
                printf("\a");
                printf("\033[1;31m");
                printf("\n\n\t\t");
                char s[3][27] = {"1-------------------------2",
                                 "|Wrong user ID or password|",
                                 "3-------------------------4"};
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 27; j++)
                    {
                        if (s[i][j] == '-')
                            printf("\U00002550");
                        else if (s[i][j] == '1')
                            printf("\U00002554");
                        else if (s[i][j] == '2')
                            printf("\U00002557");
                        else if (s[i][j] == '3')
                            printf("\U0000255A");
                        else if (s[i][j] == '4')
                            printf("\U0000255D");
                        else if (s[i][j] == '|')
                            printf("\U00002551");
                        else
                            printf("%c", s[i][j]);
                    }
                    printf("\n\t\t");
                }
                printf("\033[0m");
                printf("  \n\n  Enter any key to go back...");
                pause();
            }
        }
        else if (n == 2)
        {
            if (in_app_login(x) == 1)
            {
                decrypt();
            }
            else
            {
                printf("\a");
                printf("\033[1;31m");
                printf("\n\n\t\t");
                char s[3][27] = {"1-------------------------2",
                                 "|Wrong user ID or password|",
                                 "3-------------------------4"};
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 27; j++)
                    {
                        if (s[i][j] == '-')
                            printf("\U00002550");
                        else if (s[i][j] == '1')
                            printf("\U00002554");
                        else if (s[i][j] == '2')
                            printf("\U00002557");
                        else if (s[i][j] == '3')
                            printf("\U0000255A");
                        else if (s[i][j] == '4')
                            printf("\U0000255D");
                        else if (s[i][j] == '|')
                            printf("\U00002551");
                        else
                            printf("%c", s[i][j]);
                    }
                    printf("\n\t\t");
                }
                printf("\033[0m");
                printf("  \n\n  Enter any key to go back...");
                pause();
            }
        }
        else if (n == 3)
        {
            if (in_app_login(x) == 1)
            {
                history();
            }
            else
            {
                printf("\a");
                printf("\033[1;31m");
                printf("\n\n\t\t");
                char s[3][27] = {"1-------------------------2",
                                 "|Wrong user ID or password|",
                                 "3-------------------------4"};
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 27; j++)
                    {
                        if (s[i][j] == '-')
                            printf("\U00002550");
                        else if (s[i][j] == '1')
                            printf("\U00002554");
                        else if (s[i][j] == '2')
                            printf("\U00002557");
                        else if (s[i][j] == '3')
                            printf("\U0000255A");
                        else if (s[i][j] == '4')
                            printf("\U0000255D");
                        else if (s[i][j] == '|')
                            printf("\U00002551");
                        else
                            printf("%c", s[i][j]);
                    }
                    printf("\n\t\t");
                }
                printf("\033[0m");
                printf("  \n\n  Enter any key to go back...");
                pause();
            }
        }
        else if (n == 4)
        {
            if (in_app_login(x) == 1)
            {
                if (add_id(x++) == 1)
                    x--;
                userLog[x].user_no = x + 2;
            }
            else
            {
                printf("\a");
                printf("\033[1;31m");
                printf("\n\n\t\t");
                char s[3][27] = {"1-------------------------2",
                                 "|Wrong user ID or password|",
                                 "3-------------------------4"};
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 27; j++)
                    {
                        if (s[i][j] == '-')
                            printf("\U00002550");
                        else if (s[i][j] == '1')
                            printf("\U00002554");
                        else if (s[i][j] == '2')
                            printf("\U00002557");
                        else if (s[i][j] == '3')
                            printf("\U0000255A");
                        else if (s[i][j] == '4')
                            printf("\U0000255D");
                        else if (s[i][j] == '|')
                            printf("\U00002551");
                        else
                            printf("%c", s[i][j]);
                    }
                    printf("\n\t\t");
                }
                printf("\033[0m");
                
                printf("  \n\n  Enter any key to go back...");
                pause();
            }
        }
        else if (n == 5)
        {
            user_data(x);
        }
        else if (n == 6)
        {
            if (in_app_login(x) == 1)
            {
                if (remove_id(x--) == 1)
                    x++;
            }
            else
            {
                printf("\a");
                printf("\033[1;31m");
                printf("\n\n\t\t");
                char s[3][27] = {"1-------------------------2",
                                 "|Wrong user ID or password|",
                                 "3-------------------------4"};
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 27; j++)
                    {
                        if (s[i][j] == '-')
                            printf("\U00002550");
                        else if (s[i][j] == '1')
                            printf("\U00002554");
                        else if (s[i][j] == '2')
                            printf("\U00002557");
                        else if (s[i][j] == '3')
                            printf("\U0000255A");
                        else if (s[i][j] == '4')
                            printf("\U0000255D");
                        else if (s[i][j] == '|')
                            printf("\U00002551");
                        else
                            printf("%c", s[i][j]);
                    }
                    printf("\n\t\t");
                }
                printf("\033[0m");
                
                printf("  \n\n  Enter any key to go back...");
                pause();
            }
        }
        else if (n == 7)
        {
            if (in_app_login(x) == 1)
            {
                settings();
            }
            else
            {
                printf("\a");
                printf("\033[1;31m");
                printf("\n\n\t\t");
                char s[3][27] = {"1-------------------------2",
                                 "|Wrong user ID or password|",
                                 "3-------------------------4"};
                for (i = 0; i < 3; i++)
                {
                    for (j = 0; j < 27; j++)
                    {
                        if (s[i][j] == '-')
                            printf("\U00002550");
                        else if (s[i][j] == '1')
                            printf("\U00002554");
                        else if (s[i][j] == '2')
                            printf("\U00002557");
                        else if (s[i][j] == '3')
                            printf("\U0000255A");
                        else if (s[i][j] == '4')
                            printf("\U0000255D");
                        else if (s[i][j] == '|')
                            printf("\U00002551");
                        else
                            printf("%c", s[i][j]);
                    }
                    printf("\n\t\t");
                }
                printf("\033[0m");
                
                printf("  \n\n  Enter any key to go back...");
                pause();
            }
        }
    }
}

int login(int n)
{
    // return 1;//This line is to stop login again and again....................................

    system("clear");
    TEM();
    int f = 1, m = 0, a, i, j;
    char s[100], k[100];

    user_information = fopen("user_information.txt", "r");
    for (i = 0; i < n; i++)
    {
        fscanf(user_information, "%d %s %d %s %d", &userLog[i].user_no, userLog[i].name, &userLog[i].id, userLog[i].pass, &userLog[i].gen);
    }
    fclose(user_information);

    printf("\n\n  Enter your military ID: ");
    scanf(" %d", &a);
    printf("  Enter your password: ");
    scanf(" %s", s);

    for (i = 0; i < n; i++)
    {
        if (userLog[i].id == a)
        {
            save_loger = i;
            m = 1;
            strcpy(k, userLog[i].pass);
            if (strlen(s) == strlen(k))
            {
                for (j = 0; s[j] != 0 && k[j] != 0; j++)
                {
                    if (k[j] != s[j])
                    {
                        f = 0;
                        break;
                    }
                }
            }
            else
            {
                f = 0;
            }
            break;
        }
    }

    if (f == 1 && m == 1)
        return 1;
    else
        return 0;
}

int in_app_login(int n)
{
    if (lock % 2 == 0)
        return 1;

    system("clear");
    TEM();
    int f = 1, a, i, j;
    char nam[100], k[100], s[100];

    user_information = fopen("user_information.txt", "r");
    for (i = 0; i < n; i++)
    {
        fscanf(user_information, "%d %s %d %s %d", &userLog[i].user_no, userLog[i].name, &userLog[i].id, userLog[i].pass, &userLog[i].gen);
    }
    fclose(user_information);

    printf("\033[1;32m");
    strcpy(nam, userLog[save_loger].name);
    for (j = 0; nam[j] != 0; j++)
    {
        if (nam[j] == '_')
            nam[j] = ' ';
    }
    printf("  %s", nam);
    printf("\033[0m");
    if (userLog[save_loger].gen == 2)
        printf(" madam,");
    else
        printf(" sir,");
    printf(" you have to enter your password again for confirmation............\n\n");
    printf("  Enter your password: ");
    scanf(" %s", s);

    strcpy(k, userLog[save_loger].pass);
    if (strlen(s) == strlen(k))
    {
        for (j = 0; s[j] != 0 && k[j] != 0; j++)
        {
            if (k[j] != s[j])
            {
                f = 0;
                break;
            }
        }
    }
    else
    {
        f = 0;
    }

    if (f == 1)
        return 1;
    else
        return 0;
}

int add_id(int n)
{
    system("clear");
    TEM();
    char s1[100], s2[100], nam[50];
    int d, f, i, j;

    printf("\033[1;32m");
    strcpy(nam, userLog[save_loger].name);
    for (j = 0; nam[j] != 0; j++)
    {
        if (nam[j] == '_')
            nam[j] = ' ';
    }
    printf("  %s", nam);
    printf("\033[0m");
    if (userLog[save_loger].gen == 2)
        printf(" madam,");
    else
        printf(" sir,");
    printf(" you are about to give a new user the access to use the enigma..........\n\n");

    userLog[n].user_no = n;
    printf("  Enter new user name user no.%d: ", n);
    scanf(" %[^\n]", s1);
    for (i = 0; s1[i] != 0; i++)
    {
        if (s1[i] == ' ')
        {
            s1[i] = '_';
        }
    }
    printf("  Enter your military ID no: ");
    scanf(" %d", &d);
    printf("  Enter your gender [1.Male] [2.Female] [3.Others]: ");
    scanf(" %d", &f);
    printf("\033[1;30m");
    printf("  You are not allowed to use space(' ') in the password..........\n");
    printf("\033[0m");
    printf("  Enter a password under 50 characters: ");
    scanf(" %[^\n]", s2);
    for (i = 0; s2[i] != 0; i++)
    {
        if (s2[i] == ' ')
        {
            printf("\a");
            printf("\033[1;31m");
            printf("\n\n\t\t");
            char s[3][33] = {"1-------------------------------2",
                             "|It's not an acceptable password|",
                             "3-------------------------------4"};
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 33; j++)
                {
                    if (s[i][j] == '-')
                        printf("\U00002550");
                    else if (s[i][j] == '1')
                        printf("\U00002554");
                    else if (s[i][j] == '2')
                        printf("\U00002557");
                    else if (s[i][j] == '3')
                        printf("\U0000255A");
                    else if (s[i][j] == '4')
                        printf("\U0000255D");
                    else if (s[i][j] == '|')
                        printf("\U00002551");
                    else
                        printf("%c", s[i][j]);
                }
                printf("\n\t\t");
            }
            printf("\033[0m");
            printf("  \n\n  Enter any key to go back...");
            pause();
            return 1;
        }
    }
    userLog[n].id = d;
    userLog[n].gen = f;
    strcpy(userLog[n].name, s1);
    strcpy(userLog[n].pass, s2);

    printf("\033[1;32m");
    printf("\n\n\t\t");
    char s[3][34] = {"1--------------------------------2",
                     "|User has been added successfully|",
                     "3--------------------------------4"};
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 34; j++)
        {
            if (s[i][j] == '-')
                printf("\U00002550");
            else if (s[i][j] == '1')
                printf("\U00002554");
            else if (s[i][j] == '2')
                printf("\U00002557");
            else if (s[i][j] == '3')
                printf("\U0000255A");
            else if (s[i][j] == '4')
                printf("\U0000255D");
            else if (s[i][j] == '|')
                printf("\U00002551");
            else
                printf("%c", s[i][j]);
        }
        printf("\n\t\t");
    }
    printf("\033[0m");
    printf("  \n\n  Enter any key to go back...");
    pause();

    user_information = fopen("user_information.txt", "a");
    fprintf(user_information, "%d", userLog[n].user_no);
    fprintf(user_information, "\t%s", userLog[n].name);
    fprintf(user_information, "\t\t%d", userLog[n].id);
    fprintf(user_information, "\t\t%s", userLog[n].pass);
    fprintf(user_information, "\t\t%d\n", userLog[n].gen);
    fclose(user_information);

    return 0;
}

void user_data(int n)
{
    system("clear");
    TEM();
    char nam[50], ccc[61];
    int i, j;

    printf("\033[1;32m");
    strcpy(nam, userLog[save_loger].name);
    for (j = 0; nam[j] != 0; j++)
    {
        if (nam[j] == '_')
            nam[j] = ' ';
    }
    printf("  %s", nam);
    printf("\033[0m");
    if (userLog[save_loger].gen == 2)
        printf(" madam,");
    else
        printf(" sir,");
    printf(" these are the users who have access to the enigma..........\n\n");

    user_information = fopen("user_information.txt", "r");
    for (i = 0; i < n; i++)
    {
        fscanf(user_information, "%d %s %d %s %d", &userLog[i].user_no, userLog[i].name, &userLog[i].id, userLog[i].pass, &userLog[i].gen);
    }
    fclose(user_information);

    printf("\033[1;30m");
    printf("\n  ");
    strcpy(ccc, "|___-___________________________-_______________-__________=");
    for (i = 0; i < 60; i++)
    {
        if (ccc[i] == '_')
            printf("\U00002550");
        else if (ccc[i] == '-')
            printf("\U00002566");
        else if (ccc[i] == '=')
            printf("\U00002557");
        else if (ccc[i] == '|')
            printf("\U00002554");
    }
    printf("\n  \U00002551");
    printf("\033[1;33m");
    printf("no ");
    printf("\033[1;30m");
    printf("\U00002551\t");
    printf("\033[1;33m");
    printf("   NAME");
    printf("\033[1;30m");
    printf("\t\t\t  \U00002551");
    printf("\033[1;33m");
    printf("   ID");
    printf("\033[1;30m");
    printf("\t  \U00002551");
    printf("\033[1;33m");
    printf("  Gender  ");
    printf("\033[1;30m");
    printf("\U00002551\n  ");
    strcpy(ccc, "|___-___________________________-_______________-__________=");
    for (i = 0; i < 60; i++)
    {
        if (ccc[i] == '_')
            printf("\U00002550");
        else if (ccc[i] == '-')
            printf("\U0000256C");
        else if (ccc[i] == '=')
            printf("\U00002563");
        else if (ccc[i] == '|')
            printf("\U00002560");
    }
    printf("\n\033[0m");

    for (i = 0; i < n; i++)
    {
        if (i == save_loger)
        {
            printf("\033[1;30m");
            printf("  \U00002551");
            printf("\033[1;32m");
            printf(" %d ", userLog[i].user_no);
            printf("\033[1;30m");
            printf("\U00002551");
            strcpy(nam, userLog[i].name);
            printf("\t");
            for (j = 0; nam[j] != 0; j++)
            {
                if (nam[j] == '_')
                    nam[j] = ' ';
            }
            printf("\033[1;32m");
            printf("%s", nam);
            printf("\033[1;30m");
            printf("\t\t  \U00002551");
            printf("\033[1;32m");
            printf(" %d\t", userLog[i].id);
            printf("\033[1;30m");
            printf("  \U00002551");
            printf("\033[1;32m");
            if (userLog[save_loger].gen == 1)
                printf("  MALE    ");
            else if (userLog[save_loger].gen == 2)
                printf("  FEMALE  ");
            else if (userLog[save_loger].gen == 3)
                printf("  Others  ");
            printf("\033[1;30m");
            printf("\U00002551   <<< you are here\n  ");
            if (i == n - 1)
            {
                strcpy(ccc, "|___-___________________________-_______________-__________=");
                for (j = 0; j < 60; j++)
                {
                    if (ccc[j] == '_')
                        printf("\U00002550");
                    else if (ccc[j] == '-')
                        printf("\U00002569");
                    else if (ccc[j] == '=')
                        printf("\U0000255D");
                    else if (ccc[j] == '|')
                        printf("\U0000255A");
                }
            }
            else
            {
                strcpy(ccc, "|___-___________________________-_______________-__________=");
                for (j = 0; j < 60; j++)
                {
                    if (ccc[j] == '_')
                        printf("\U00002550");
                    else if (ccc[j] == '-')
                        printf("\U0000256C");
                    else if (ccc[j] == '=')
                        printf("\U00002563");
                    else if (ccc[j] == '|')
                        printf("\U00002560");
                }
            }
            printf("\n\033[0m");
        }
        else
        {
            printf("\033[1;30m");
            printf("  \U00002551");
            printf("\033[0m");
            printf(" %d ", userLog[i].user_no);
            printf("\033[1;30m");
            printf("\U00002551");
            printf("\033[0m");
            strcpy(nam, userLog[i].name);
            printf("\t");
            for (j = 0; nam[j] != 0; j++)
            {
                if (nam[j] == '_')
                    nam[j] = ' ';
            }
            printf("%s", nam);
            printf("\033[1;30m");
            printf("\t\t  \U00002551");
            printf("\033[0m");
            printf(" %d\t", userLog[i].id);
            printf("\033[1;30m");
            printf("  \U00002551");
            printf("\033[0m");
            if (userLog[i].gen == 1)
                printf("  MALE    ");
            else if (userLog[i].gen == 2)
                printf("  FEMALE  ");
            else if (userLog[i].gen == 3)
                printf("  Others  ");
            printf("\033[1;30m");
            printf("\U00002551\n  ");
            if (i == n - 1)
            {
                strcpy(ccc, "|___-___________________________-_______________-__________=");
                for (j = 0; j < 60; j++)
                {
                    if (ccc[j] == '_')
                        printf("\U00002550");
                    else if (ccc[j] == '-')
                        printf("\U00002569");
                    else if (ccc[j] == '=')
                        printf("\U0000255D");
                    else if (ccc[j] == '|')
                        printf("\U0000255A");
                }
            }
            else
            {
                strcpy(ccc, "|___-___________________________-_______________-__________=");
                for (j = 0; j < 60; j++)
                {
                    if (ccc[j] == '_')
                        printf("\U00002550");
                    else if (ccc[j] == '-')
                        printf("\U0000256C");
                    else if (ccc[j] == '=')
                        printf("\U00002563");
                    else if (ccc[j] == '|')
                        printf("\U00002560");
                }
            }
            printf("\n\033[0m");
        }
    }
    printf("  \n\n  Enter any key to go back...");
    pause();
}

int remove_id(int a)
{
    int n, i, j;
    char nam[50], ccc[61];
    system("clear");
    TEM();

    printf("\033[1;32m");
    strcpy(nam, userLog[save_loger].name);
    for (j = 0; nam[j] != 0; j++)
    {
        if (nam[j] == '_')
            nam[j] = ' ';
    }
    printf("  %s", nam);
    printf("\033[0m");
    if (userLog[save_loger].gen == 2)
        printf(" madam,");
    else
        printf(" sir,");
    printf(" you should be careful about who you remove..........\n\n");

    user_information = fopen("user_information.txt", "r");
    for (i = 0; i < a; i++)
    {
        fscanf(user_information, "%d %s %d %s %d", &userLog[i].user_no, userLog[i].name, &userLog[i].id, userLog[i].pass, &userLog[i].gen);
    }
    fclose(user_information);

    printf("\033[1;30m");
    printf("\n  ");
    strcpy(ccc, "|___-___________________________-_______________-__________=");
    for (i = 0; i < 60; i++)
    {
        if (ccc[i] == '_')
            printf("\U00002550");
        else if (ccc[i] == '-')
            printf("\U00002566");
        else if (ccc[i] == '=')
            printf("\U00002557");
        else if (ccc[i] == '|')
            printf("\U00002554");
    }
    printf("\n  \U00002551");
    printf("\033[1;33m");
    printf("no ");
    printf("\033[1;30m");
    printf("\U00002551\t");
    printf("\033[1;33m");
    printf("   NAME");
    printf("\033[1;30m");
    printf("\t\t\t  \U00002551");
    printf("\033[1;33m");
    printf("   ID");
    printf("\033[1;30m");
    printf("\t  \U00002551");
    printf("\033[1;33m");
    printf("  Gender  ");
    printf("\033[1;30m");
    printf("\U00002551\n  ");
    strcpy(ccc, "|___-___________________________-_______________-__________=");
    for (i = 0; i < 60; i++)
    {
        if (ccc[i] == '_')
            printf("\U00002550");
        else if (ccc[i] == '-')
            printf("\U0000256C");
        else if (ccc[i] == '=')
            printf("\U00002563");
        else if (ccc[i] == '|')
            printf("\U00002560");
    }
    printf("\n\033[0m");

    for (i = 0; i < a; i++)
    {
        if (i == save_loger)
        {
            printf("\033[1;30m");
            printf("  \U00002551");
            printf(" %d ", userLog[i].user_no);
            printf("\U00002551");
            strcpy(nam, userLog[i].name);
            printf("\t");
            for (j = 0; nam[j] != 0; j++)
            {
                if (nam[j] == '_')
                    nam[j] = ' ';
            }
            printf("%s", nam);
            printf("\t\t  \U00002551");
            printf(" %d\t", userLog[i].id);
            printf("  \U00002551");
            if (userLog[i].gen == 1)
                printf("  MALE    ");
            else if (userLog[i].gen == 2)
                printf("  FEMALE  ");
            else if (userLog[i].gen == 3)
                printf("  Others  ");
            printf("\U00002551   <<< you are here\n  ");
            if (i == a - 1)
            {
                strcpy(ccc, "|___-___________________________-_______________-__________=");
                for (j = 0; j < 60; j++)
                {
                    if (ccc[j] == '_')
                        printf("\U00002550");
                    else if (ccc[j] == '-')
                        printf("\U00002569");
                    else if (ccc[j] == '=')
                        printf("\U0000255D");
                    else if (ccc[j] == '|')
                        printf("\U0000255A");
                }
            }
            else
            {
                strcpy(ccc, "|___-___________________________-_______________-__________=");
                for (j = 0; j < 60; j++)
                {
                    if (ccc[j] == '_')
                        printf("\U00002550");
                    else if (ccc[j] == '-')
                        printf("\U0000256C");
                    else if (ccc[j] == '=')
                        printf("\U00002563");
                    else if (ccc[j] == '|')
                        printf("\U00002560");
                }
            }
            printf("\n\033[0m");
        }
        else if (i == 0)
        {
            printf("\033[1;30m");
            printf("  \U00002551");
            printf(" %d ", userLog[i].user_no);
            printf("\U00002551");
            strcpy(nam, userLog[i].name);
            printf("\t");
            for (j = 0; nam[j] != 0; j++)
            {
                if (nam[j] == '_')
                    nam[j] = ' ';
            }
            printf("%s", nam);
            printf("\t\t  \U00002551");
            printf(" %d\t", userLog[i].id);
            printf("  \U00002551");
            if (userLog[i].gen == 1)
                printf("  MALE    ");
            else if (userLog[i].gen == 2)
                printf("  FEMALE  ");
            else if (userLog[i].gen == 3)
                printf("  Others  ");
            printf("\U00002551\n  ");
            if (i == a - 1)
            {
                strcpy(ccc, "|___-___________________________-_______________-__________=");
                for (j = 0; j < 60; j++)
                {
                    if (ccc[j] == '_')
                        printf("\U00002550");
                    else if (ccc[j] == '-')
                        printf("\U00002569");
                    else if (ccc[j] == '=')
                        printf("\U0000255D");
                    else if (ccc[j] == '|')
                        printf("\U0000255A");
                }
            }
            else
            {
                strcpy(ccc, "|___-___________________________-_______________-__________=");
                for (j = 0; j < 60; j++)
                {
                    if (ccc[j] == '_')
                        printf("\U00002550");
                    else if (ccc[j] == '-')
                        printf("\U0000256C");
                    else if (ccc[j] == '=')
                        printf("\U00002563");
                    else if (ccc[j] == '|')
                        printf("\U00002560");
                }
            }
            printf("\n\033[0m");
        }
        else
        {
            printf("\033[1;30m");
            printf("  \U00002551");
            printf("\033[0m");
            printf(" %d ", userLog[i].user_no);
            printf("\033[1;30m");
            printf("\U00002551");
            printf("\033[0m");
            strcpy(nam, userLog[i].name);
            printf("\t");
            for (j = 0; nam[j] != 0; j++)
            {
                if (nam[j] == '_')
                    nam[j] = ' ';
            }
            printf("%s", nam);
            printf("\033[1;30m");
            printf("\t\t  \U00002551");
            printf("\033[0m");
            printf(" %d\t", userLog[i].id);
            printf("\033[1;30m");
            printf("  \U00002551");
            printf("\033[0m");
            if (userLog[i].gen == 1)
                printf("  MALE    ");
            else if (userLog[i].gen == 2)
                printf("  FEMALE  ");
            else if (userLog[i].gen == 3)
                printf("  Others  ");
            printf("\033[1;30m");
            printf("\U00002551\n  ");
            if (i == a - 1)
            {
                strcpy(ccc, "|___-___________________________-_______________-__________=");
                for (j = 0; j < 60; j++)
                {
                    if (ccc[j] == '_')
                        printf("\U00002550");
                    else if (ccc[j] == '-')
                        printf("\U00002569");
                    else if (ccc[j] == '=')
                        printf("\U0000255D");
                    else if (ccc[j] == '|')
                        printf("\U0000255A");
                }
            }
            else
            {
                strcpy(ccc, "|___-___________________________-_______________-__________=");
                for (j = 0; j < 60; j++)
                {
                    if (ccc[j] == '_')
                        printf("\U00002550");
                    else if (ccc[j] == '-')
                        printf("\U0000256C");
                    else if (ccc[j] == '=')
                        printf("\U00002563");
                    else if (ccc[j] == '|')
                        printf("\U00002560");
                }
            }
            printf("\n\033[0m");
        }
    }

    printf("\n  Enter the user no. to remove from the enigma: \n\n  \U000025BA  ");
    scanf("%d", &n);

    if (n == save_loger)
    {
        printf("\a");
        printf("\033[1;33m");
        printf("\n\n\t\t");
        char s[3][39] = {"1-------------------------------------2",
                         "|You can't remove yourself from enigma|",
                         "3-------------------------------------4"};
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 39; j++)
            {
                if (s[i][j] == '-')
                    printf("\U00002550");
                else if (s[i][j] == '1')
                    printf("\U00002554");
                else if (s[i][j] == '2')
                    printf("\U00002557");
                else if (s[i][j] == '3')
                    printf("\U0000255A");
                else if (s[i][j] == '4')
                    printf("\U0000255D");
                else if (s[i][j] == '|')
                    printf("\U00002551");
                else
                    printf("%c", s[i][j]);
            }
            printf("\n\t\t");
        }
        printf("\033[0m");
        printf("  \n\n  Enter any key to go back...");
        pause();
        return 1;
    }
    else if (n == 0)
    {
        printf("\a");
        printf("\033[1;31m");
        printf("\n\n\t\t");
        char s[3][44] = {"1------------------------------------------2",
                         "|You can't remove General Rubai from enigma|",
                         "3------------------------------------------4"};
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 44; j++)
            {
                if (s[i][j] == '-')
                    printf("\U00002550");
                else if (s[i][j] == '1')
                    printf("\U00002554");
                else if (s[i][j] == '2')
                    printf("\U00002557");
                else if (s[i][j] == '3')
                    printf("\U0000255A");
                else if (s[i][j] == '4')
                    printf("\U0000255D");
                else if (s[i][j] == '|')
                    printf("\U00002551");
                else
                {
                    if (i == 1 && j >= 18 && j <= 31)
                    {
                        printf("\033[1;33m");
                        printf("%c", s[i][j]);
                        printf("\033[1;31m");
                    }
                    else
                        printf("%c", s[i][j]);
                }
            }
            printf("\n\t\t");
        }
        printf("\033[0m");
        printf("  \n\n  Enter any key to go back...");
        pause();
        return 1;
    }
    else if (n < a)
    {
        for (i = n; i < a; i++)
        {
            userLog[i].id = userLog[i + 1].id;
            userLog[i].gen = userLog[i + 1].gen;
            strcpy(userLog[i].name, userLog[i + 1].name);
            strcpy(userLog[i].pass, userLog[i + 1].pass);
        }

        printf("\033[1;32m");
        printf("\n\n\t\t");
        char s[3][23] = {"1---------------------2",
                         "|User has been removed|",
                         "3---------------------4"};
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 23; j++)
            {
                if (s[i][j] == '-')
                    printf("\U00002550");
                else if (s[i][j] == '1')
                    printf("\U00002554");
                else if (s[i][j] == '2')
                    printf("\U00002557");
                else if (s[i][j] == '3')
                    printf("\U0000255A");
                else if (s[i][j] == '4')
                    printf("\U0000255D");
                else if (s[i][j] == '|')
                    printf("\U00002551");
                else
                    printf("%c", s[i][j]);
            }
            printf("\n\t\t");
        }
        printf("\033[0m");
        printf("  \n\n  Enter any key to go back...");
        pause();
    }
    else
    {
        printf("\a");
        printf("\033[1;31m");
        printf("\n\n\t\t");
        char s[3][37] = {"1-----------------------------------2",
                         "|There is no user with this user no.|",
                         "3-----------------------------------4"};
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 37; j++)
            {
                if (s[i][j] == '-')
                    printf("\U00002550");
                else if (s[i][j] == '1')
                    printf("\U00002554");
                else if (s[i][j] == '2')
                    printf("\U00002557");
                else if (s[i][j] == '3')
                    printf("\U0000255A");
                else if (s[i][j] == '4')
                    printf("\U0000255D");
                else if (s[i][j] == '|')
                    printf("\U00002551");
                else
                    printf("%c", s[i][j]);
            }
            printf("\n\t\t");
        }
        printf("\033[0m");
        printf("  \n\n  Enter any key to go back...");
        pause();
        return 1;
    }
    if (n < save_loger)
        --save_loger;

    user_information = fopen("user_information.txt", "w");
    for (i = 0; i < a - 1; i++)
    {
        fprintf(user_information, "%d", i);
        fprintf(user_information, "\t%s", userLog[i].name);
        fprintf(user_information, "\t\t%d", userLog[i].id);
        fprintf(user_information, "\t\t%s", userLog[i].pass);
        fprintf(user_information, "\t\t%d\n", userLog[i].gen);
    }
    fclose(user_information);
    return 0;
}

void encrypt(int f)
{
    system("clear");
    TEM();

    char s[100], p[100], b[100], e[100], d;
    int n = 0, a = 1, g = 0, c, x, i, j, ddd;

    user_information = fopen("user_information.txt", "r");
    for (i = 0; i < f; i++)
    {
        fscanf(user_information, "%d %s %d %s %d", &userLog[i].user_no, userLog[i].name, &userLog[i].id, userLog[i].pass, &userLog[i].gen);
    }
    fclose(user_information);

    store_room = fopen("store_room.txt", "r");
    fscanf(store_room, " %d %s %s %d", &x, b, e, &ddd);
    while (1)
    {
        fscanf(store_room, " %d %s %s %d", &x, b, e, &ddd);
        if (feof(store_room))
            break;
    }
    x++;
    fclose(store_room);

    printf("  Enter a string: ");
    scanf(" %[^\n]", s);

    c = strlen(s);
    while (a < 4)
    {
        for (i = 0; i < c; i++)
        {
            char f = s[i];
            p[i] = switch_box1(f, n);
            n++;
        }

        for (i = 0; i < c; i++)
        {
            s[i] = p[c - 1 - i];
        }
        a++;
    }
    c = n;
    while (c != 0)
    {
        g += (c % 10);
        c /= 10;
    }
    n *= (g * 1000);
    n += g;

    printf("\n  \033[1;33m%s\033[0m", s);
    printf("\n\n  Your decrypt code is: ");
    printf("\033[1;31m");
    printf("%x", n);
    printf("\033[0m");

    for (i = 0; s[i] != 0; i++)
    {
        if (s[i] == ' ')
            s[i] = '_';
    }

    if (x < 100)
    {
        store_room = fopen("store_room.txt", "a");
        fprintf(store_room, "%d", x);
        fprintf(store_room, "\t%s", userLog[save_loger].name);
        fprintf(store_room, "\t\t%s", s);
        fprintf(store_room, "\t\t\t\t%d\n", n);
        fclose(store_room);
    }
    printf("  \n\n  Enter any key to go back...");
    pause();
}

void decrypt()
{
    system("clear");
    TEM();

    char s[100], p[100], hex[20], x, y;
    int n = 0, b = 1, a = 1, c, size, i, j;

    printf("  Enter a string: ");
    scanf(" %[^\n]", p);
    printf("  Enter your code: ");
    scanf(" %s", hex);

    size = strlen(hex);
    for (i = size - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            n += (hex[i] - 48) * b;
            b *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            n += (hex[i] - 87) * b;
            b *= 16;
        }
    }
    n /= ((n % 1000) * 1000);
    n--;

    c = strlen(p);
    while (a < 4)
    {
        for (i = 0; i < c; i++)
        {
            s[i] = p[c - 1 - i];
        }

        for (i = 0; i < c; i++)
        {
            char f = s[c - 1 - i];
            x = switch_box2(f);
            if (f < 'a' || f > 'z')
            {
                p[c - 1 - i] = s[c - 1 - i];
            }
            else if (x - (n % 26) < 97)
            {
                p[c - 1 - i] = 123 - (97 - (x - (n % 26)));
            }
            else
            {
                p[c - 1 - i] = x - (n % 26);
            }
            n--;
        }
        a++;
    }

    printf("\n  \033[1;32m%s\033[0m\n ", p);
    printf("  \n\n  Enter any key to go back...");
    pause();
}

void history()
{
    system("clear");
    TEM();

    char s[100], p[100], b[100], e[100];
    int n = 0, a = 1, g = 0, c, x, d, i, j;

    user_information = fopen("user_information.txt", "r");
    for (i = 0; i < n; i++)
    {
        fscanf(user_information, "%d %s %d %s %d", &userLog[i].user_no, userLog[i].name, &userLog[i].id, userLog[i].pass, &userLog[i].gen);
    }
    fclose(user_information);

    store_room = fopen("store_room.txt", "r");
    fscanf(store_room, " %d %s %s %d", &x, b, e, &d);
    while (1)
    {
        fscanf(store_room, " %d %s %s %d", &x, b, e, &d);
        if (feof(store_room))
            break;
    }
    fclose(store_room);

    store_room = fopen("store_room.txt", "r");
    fscanf(store_room, " %d %s %s %d", &a, b, e, &d);
    if (x > 0)
    {
        for (i = 0; i < x; i++)
        {
            fscanf(store_room, " %d %s %s %d", &a, b, e, &d);
            printf("  %d.", a);
            for (j = 0; b[j] != 0; j++)
            {
                if (b[j] == '_')
                    b[j] = ' ';
            }
            printf("\033[1;32m");
            printf(" %s.....\n\n", b);
            printf("\033[0m");
            for (j = 0; e[j] != 0; j++)
            {
                if (e[j] == '_')
                    e[j] = ' ';
            }
            printf("  %s\n\n", e);
            printf("  The decrypt code is: ");
            printf("\033[1;31m");
            printf("%x\n ", d);
            printf("\033[1;30m");
            for (j = 0; j < 80; j++)
                printf("\U00002584");
            printf("\n\n");
            printf("\033[0m");
        }
    }
    else
    {
        printf("\033[1;31m");
        printf("  No history found.........");
        printf("\033[0m");
    }
    fclose(store_room);
    printf("  \n\n  Enter any key to go back...");
    pause();
}

void settings()
{
    system("clear");
    TEM();

    int f, x, c, e, i, j, a;
    char b[100], d[100], nam[100];

    user_information = fopen("user_information.txt", "r");
    fscanf(user_information, " %d %s %d %s %d", &x, b, &c, d, &e);
    while (1)
    {
        fscanf(user_information, " %d %s %d %s %d", &x, b, &c, d, &e);
        if (feof(user_information))
            break;
    }
    x++;
    fclose(user_information);

    user_information = fopen("user_information.txt", "r");
    for (i = 0; i < x; i++)
    {
        fscanf(user_information, "%d %s %d %s %d", &userLog[i].user_no, userLog[i].name, &userLog[i].id, userLog[i].pass, &userLog[i].gen);
    }
    fclose(user_information);

    printf("\033[1;32m");
    strcpy(nam, userLog[save_loger].name);
    for (j = 0; nam[j] != 0; j++)
    {
        if (nam[j] == '_')
            nam[j] = ' ';
    }
    printf("  %s", nam);
    printf("\033[0m");
    if (userLog[save_loger].gen == 2)
        printf(" madam,");
    else
        printf(" sir,");
    printf(" you can change your enigma use experience here.....\n\n");

    printf("  1. In-app login");
    printf("\n  2. Clear encryption history");
    printf("\n  0. Go back\n\n  \U000025BA  ");
    scanf("%d", &f);

    if (f == 1)
    {
        system("clear");
        TEM();

        printf("  Do you want to change your current in-app login setting ?...\n\n");
        printf("  1. Yes\n");
        printf("  2. No\n\n  \U000025BA  ");
        scanf("%d", &a);

        if (a == 1)
        {
            lock++;
            printf("\033[1;32m");
            printf("\n\n\t\t");
            char s[3][10] = {"1--------2",
                             "|  Done  |",
                             "3--------4"};
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    if (s[i][j] == '-')
                        printf("\U00002550");
                    else if (s[i][j] == '1')
                        printf("\U00002554");
                    else if (s[i][j] == '2')
                        printf("\U00002557");
                    else if (s[i][j] == '3')
                        printf("\U0000255A");
                    else if (s[i][j] == '4')
                        printf("\U0000255D");
                    else if (s[i][j] == '|')
                        printf("\U00002551");
                    else
                        printf("%c", s[i][j]);
                }
                printf("\n\t\t");
            }
            printf("\033[0m");
            printf("  \n\n  Enter any key to go back...");
            pause();
            settings();
            return;
        }
        else
        {
            settings();
            return;
        }
    }
    else if (f == 2)
    {
        system("clear");
        TEM();

        printf("  Are you sure you want to clear encryption history ?...\n\n");
        printf("  1. Yes\n");
        printf("  2. No\n\n  \U000025BA  ");
        scanf("%d", &a);

        if (a == 1)
        {
            store_room = fopen("store_room.txt", "w");
            fprintf(store_room, "%d", 0);
            fprintf(store_room, "\t%s", "no_user");
            fprintf(store_room, "\t\t%s", "this_line_is_blank");
            fprintf(store_room, "\t\t\t\t\t\t\t%d\n", 666666);
            fclose(store_room);

            printf("\033[1;33m");
            printf("\n\n\t\t");
            char s[3][26] = {"1------------------------2",
                             "|History has been cleared|",
                             "3------------------------4"};
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 26; j++)
                {
                    if (s[i][j] == '-')
                        printf("\U00002550");
                    else if (s[i][j] == '1')
                        printf("\U00002554");
                    else if (s[i][j] == '2')
                        printf("\U00002557");
                    else if (s[i][j] == '3')
                        printf("\U0000255A");
                    else if (s[i][j] == '4')
                        printf("\U0000255D");
                    else if (s[i][j] == '|')
                        printf("\U00002551");
                    else
                        printf("%c", s[i][j]);
                }
                printf("\n\t\t");
            }
            printf("\033[0m");
            printf("  \n\n  Enter any key to go back...");
            pause();
            settings();
            return;
        }
        else
        {
            settings();
            return;
        }
    }
    return;
}

char switch_box1(char a, int n)
{
    char ff = a, nn = a;
    int mm = ff;

    if (ff >= 'A' && ff <= 'Z')
        ff -= 32;

    if (mm + (n % 26) > 122)
    {
        ff = 96 + (mm + (n % 26)) - 122;
    }
    else
    {
        ff += (n % 26);
    }

    switch (ff)
    {
        case 'a': return 'n';
        case 'b': return 'y';
        case 'c': return 'i';
        case 'd': return 'z';
        case 'e': return 'a';
        case 'f': return 'h';
        case 'g': return 'w';
        case 'h': return 'o';
        case 'i': return 'b';
        case 'j': return 'j';
        case 'k': return 'm';
        case 'l': return 'c';
        case 'm': return 's';
        case 'n': return 'x';
        case 'o': return 'd';
        case 'p': return 'v';
        case 'q': return 'p';
        case 'r': return 'e';
        case 's': return 'k';
        case 't': return 'q';
        case 'u': return 'f';
        case 'v': return 'u';
        case 'w': return 'r';
        case 'x': return 'g';
        case 'y': return 'l';
        case 'z': return 't';
        default: return nn;
    }
}

char switch_box2(char a)
{
    switch (a)
    {
        case 'a': return 'e';
        case 'b': return 'i';
        case 'c': return 'l';
        case 'd': return 'o';
        case 'e': return 'r';
        case 'f': return 'u';
        case 'g': return 'x';
        case 'h': return 'f';
        case 'i': return 'c';
        case 'j': return 'j';
        case 'k': return 's';
        case 'l': return 'y';
        case 'm': return 'k';
        case 'n': return 'a';
        case 'o': return 'h';
        case 'p': return 'q';
        case 'q': return 't';
        case 'r': return 'w';
        case 's': return 'm';
        case 't': return 'z';
        case 'u': return 'v';
        case 'v': return 'p';
        case 'w': return 'g';
        case 'x': return 'n';
        case 'y': return 'b';
        case 'z': return 'd';
        default: return a;
    }
}

void pause(){
    struct termios info;
    tcgetattr(0, &info);         
    info.c_lflag &= ~ICANON;  
    info.c_cc[VMIN] = 1;      
    info.c_cc[VTIME] = 0;   
    tcsetattr(0, TCSANOW, &info); 
    char ch;

    getchar();
    ch = getchar();
}

void TEM()
{
    char tme[8][95] = {"5652226 526  526 522226     522226 5222226526 5652226 52652226 5222222226 52222226",
                       "111   1 1 1  1 1 1    1     1    1 1     11 1 111   1 1 11   1 1        1 1      1",
                       "341 524 1 1  1 1 1 5224     1 5224 1 526 11 1 341 524 1 132224 1 526 56 1 1 5226 1",
                       "  1 1   1 1524 1 1 326      1 326  1 1 1 11 1   1 1   1 1 5226 1 1 1 11 1 1 1  1 1",
                       "  1 1   1 1326 1 1 524      1 524  1 1 1 11 1   1 1   1 1 36 1 1 1 1 11 1 1 3224 1",
                       "  1 1   1 1  1 1 1 1        1 1    1 1 1 11 1   1 1   1 1  1 1 1 1 1 11 1 1 5226 1",
                       "  1 1   1 1  1 1 1 3226     1 3226 1 1 1 34 1 561 326 1 1524 1 1 1 1 11 1 1 1  1 1",
                       "  324   324  324 322224     322224 324 322224 3432224 32432224 324 324324 324  324"};

    printf("\033[1;37m");
    for (int i = 0; i < 8; i++)
    {
        printf("\n\t\t ");
        for (int j = 0; j < 95; j++)
        {
            if (tme[i][j] == '1')
                printf("\U00002551");
            else if (tme[i][j] == '2')
                printf("\U00002550");
            else if (tme[i][j] == '3')
                printf("\U0000255A");
            else if (tme[i][j] == '4')
                printf("\U0000255D");
            else if (tme[i][j] == '5')
                printf("\U00002554");
            else if (tme[i][j] == '6')
                printf("\U00002557");
            else if (tme[i][j] == '7')
                printf("%c", 206);
            else
                printf(" ");
        }
    }
    printf("\033[0m");
    printf("\n\n");
}

void abt_enigma()
{
    system("clear");
    TEM();

    int i;
    printf("\033[1;30m");
    printf("        ");
    for (i = 0; i < 100; i++)
    {
        printf("\U00002588");
    }
    printf("\n        \U00002588\U00002588                                                                                                \U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m          Enigma  machine  basically looks like a  typewriter  but serve's  for  a  different   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   purpose such  as delivering encrypted  and decrypted messages. It works by  scrambling the   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   wires inside the machine  as a result if we  type 'A' we get  another  letter like 'D' But   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   an interesting  mechanism  about  enigma  machine is if we press a same  letter  again and   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   again,  we  will get a  different output  every time. It  has an  electromechanical  rotor   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   mechanism that  scrambles the  26  letters of the alphabet. Combining three  rotors from a   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   set of five, each of the 3 rotor  settings with 26  positions, and the  plugboard with ten   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   pairs  of letters connected, the military Enigma has ");
    printf("\033[0;36m");
    printf("158,962,555,217,826,360,000 ");
    printf("\033[0m");
    printf("different   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   settings (nearly 159 quintillion or about 67 bits.) The  security of the system depends on   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   machine  settings that were generally changed daily, based on secret key lists distributed   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   in advance, and on  the other settings that were  changed for each message. The  receiving   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   station would have to know and use the exact settings employed by the transmitting station   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   to successfully decrypt a message. It was the greatest encrypting and decrypting device of   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   that time designed, developed  and use by the  NAZI in world war II. It took more then two   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   years for US, UK  and USSR combined  to be able to  build a  machine that can  decrypt the   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   code of Enigma in less then 20 minutes. ");
    printf("\033[0;36mAlan Turing\033[0m");
    printf(" was a great mathematician of that time   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   was able  to build a huge machine  called ");
    printf("\033[0;36mThe BOMBE\033[0m");
    printf(" also known as ");
    printf("\033[0;36mThe TURING machine\033[0m");
    printf(" which   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   was the first machine that was able to decrypt Enigma  successfully. On July 9th, 1941 the   \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588\033[0m   Turing machine broke the Enigma key for the first time.                                      \033[1;30m\U00002588\U00002588\n");
    printf("        \U00002588\U00002588                                                                                                \U00002588\U00002588\n");
    printf("        ");
    for (i = 0; i < 100; i++)
    {
        printf("\U00002588");
    }
    printf("\033[0m");
    printf("  \n\n  Enter any key to go back...");
    pause();
}

void abt_dev()
{
    system("clear");
    TEM();

    char ccc[110];
    int i;
    printf("\n\n  ");
    strcpy(ccc, "|---------------------------------_----------------------------------_--------------------------------------+");
    for (i = 0; ccc[i] != 0; i++)
    {
        if (ccc[i] == '-')
            printf("\U00002550");
        else if (ccc[i] == '_')
            printf("\U00002566");
        else if (ccc[i] == '+')
            printf("\U00002557");
        else if (ccc[i] == '|')
            printf("\U00002554");
    }
    printf("\n  \U00002551  ");
    printf("\033[1;32m");
    printf("Washio Ferdous");
    printf("\033[0m");
    printf("                 \U00002551  ");
    printf("\033[1;32m");
    printf("Mumtahina ");
    printf("\033[0m");
    printf("                      \U00002551  ");
    printf("\033[1;32m");
    printf("Nazifa Anjum ");
    printf("\033[0m");
    printf("                       \U00002551\n  \U00002551  ");
    printf("\033[1;32m");
    printf("2231107642");
    printf("\033[0m");
    printf("                     \U00002551  ");
    printf("\033[1;32m");
    printf("2231749642 ");
    printf("\033[0m");
    printf("                     \U00002551  ");
    printf("\033[1;32m");
    printf("2233406642 ");
    printf("\033[0m");
    printf("                         \U00002551\n  \U00002551  ");
    printf("\033[1;32m");
    printf("washio.ferdous@northsouth.com");
    printf("\033[0m");
    printf("  \U00002551  ");
    printf("\033[1;32m");
    printf("mumtahina@northsouth.com      ");
    printf("\033[0m");
    printf("  \U00002551  ");
    printf("\033[1;32m");
    printf("nazifa.anjum@northsouth.com   ");
    printf("\033[0m");
    printf("      \U00002551\n  \U00002551  ");
    printf("\033[1;32m");
    printf("+8801912653657");
    printf("\033[0m");
    printf("                 \U00002551  ");
    printf("\033[1;32m");
    printf("+8801734061536");
    printf("\033[0m");
    printf("                  \U00002551  ");
    printf("\033[1;32m");
    printf("+8801873227799");
    printf("\033[0m");
    printf("                      \U00002551\n  ");
    strcpy(ccc, "|---------------------------------_----------------------------------_--------------------------------------+");
    for (i = 0; ccc[i] != 0; i++)
    {
        if (ccc[i] == '-')
            printf("\U00002550");
        else if (ccc[i] == '_')
            printf("\U00002569");
        else if (ccc[i] == '+')
            printf("\U0000255D");
        else if (ccc[i] == '|')
            printf("\U0000255A");
    }
    
    printf("  \n\n  Enter any key to go back...");
    pause();
}
