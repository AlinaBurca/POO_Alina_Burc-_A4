#include <iostream>
#include <stdio.h>
#include <cstring>
#include <bits/stdc++.h>


struct cuv{
    char c[50];
    int l;
}m[1000];

int main()
{ char sir[250];
char *p;
   int nr;
    scanf("%[^\n]s", sir);
    p=strtok(sir," ");
    while(p!=NULL)
    {
        nr++;
        strcpy(m[nr].c,p);
        m[nr].l=strlen(p);
        p=strtok(NULL," .");
    }
  int aux;
  int i, j;
  char auxx[50];
      for( int i=1;i<nr;i++)
    {
        for(int j=i+1;j<=nr;j++)
        {
            if(m[i].l<m[j].l)
            {
                aux=m[i].l;
                m[i].l=m[j].l;
                m[j].l=aux;

                strcpy(auxx, m[i].c);
                strcpy(m[i].c,m[j].c);
                strcpy(m[j].c,auxx);
            }
            else if(m[i].l==m[j].l)
            {
                if(strcmp(m[i].c,m[j].c)<0)
                {
                    aux=m[i].l;
                    m[i].l=m[j].l;
                    m[j].l=aux;

                    strcpy(auxx,m[i].c);
                    strcpy(m[i].c,m[j].c);
                    strcpy(m[j].c,auxx);
                }

            }

        }
    }
    for(i=1;i<=nr;i++)
    {
        printf("%s\n",m[i].c);
    }

    return 0;
}
