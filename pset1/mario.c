#include <stdio.h>
#include <cs50.h>

int main(void)
{
int n;

do
{
    printf("Height: ");
    n = GetInt();
}
while (n < 0 || n >23);

for ( int i = 1; i <= n; i++)
{
    printf("%.*s", n - i, "                        ");
    printf("%.*s\n", i + 1, "########################");
}
}
