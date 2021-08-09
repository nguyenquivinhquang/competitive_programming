#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
struct information {
    int ID, Post_code;
    char *First_name, *Last_name, *email;
    //char First_name[30], Last_name[30];
    float rating;
} employee[MAXN];
int n;
void input() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        employee[i].First_name = malloc(sizeof(char) * 30);
        printf("First Name: ");
        fgets(employee[i].First_name, 30, stdin);
        //employee[i].First_name = t;
        printf("Last Name: ");
        fgets(employee[i].Last_name, 30, stdin);
    }
    for (int i = 1; i <= n; i++)
        printf("%s", employee[i].First_name);
}
int main() {
    input();
}