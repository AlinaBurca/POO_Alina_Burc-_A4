
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int convert(char v[])
{
    int i= 0,c=0;
    while (v[i] >= '0' and v[i] <= '9')
    {
        c = c * 10 + (v[i] - '0');
        i++;
    }
    return c;
}
int main()
{
    FILE* p;
    p = fopen("in.txt", "r");
    char sir[30];
    int s = 0;
    if (p != NULL)

    {
        while (fgets(sir,30,p)!=NULL)
        {
            s = s + convert(sir);

        }
        printf("%d", s);
    }

    else
        printf("Fisierul nu exista.");
    fclose(p);
}
