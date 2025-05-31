#include <stdio.h>
#include <stdlib.h>

#define INFINIT 10000
#define MAX 20

int a[MAX][MAX];
int d[MAX];
int f[MAX];

void initializeaza_matrice(int n)
{
    int i=0,j=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j]=INFINIT;
    }
    for(i=1;i<=n;i++)
        a[i][i]=0;
}
void citire(FILE *fis)
{
    int x=0,y=0,p=0;
    while(fscanf(fis,"%d",&x)==1)
    {
        fscanf(fis,"%d",&y);
        fscanf(fis,"%d",&p);
        a[x][y]=p;
    }
}
void afisare_matrice(int n)
{
    int i=0,j=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void dijskstra(int s,int n)
{
    int i=0,k=0,pmax=0;
    for(i=1;i<=n;i++)
    {
        f[i]=0;
        d[i]=a[s][i];
    }
    f[s]=1;
    d[s]=0;
    d[0]=INFINIT;
    for(k=1;k<=n;k++)
    {
        pmax=0;
        for(i=1;i<=n;i++)
        {
            if(f[i]==0&&d[i]<d[pmax])
                pmax=i;
        }
        if(pmax>-1)
        {
            f[pmax]=1;
            for(i=1;i<=n;i++)
            {
                if(f[i]==0&&d[i]>d[pmax]+a[pmax][i])
                    d[i]=d[pmax]+a[pmax][i];
            }
        }
    }
}

int main(void)
{   
    FILE *fis=NULL;
    int nr_noduri=0;
    fis=fopen("dijskstra.txt","r");
    if(fis==NULL)
    {
        perror("Eroare la deschidere fisier de intrare\n");
        exit(-1);
    }
    fscanf(fis,"%d",&nr_noduri);
    initializeaza_matrice(nr_noduri);
    citire(fis);
    //afisare_matrice(nr_noduri);
    int nod_start=1;
    dijskstra(nod_start,nr_noduri);
    int i=0;
    for(i=1;i<=nr_noduri;i++)
    {
        printf("%d ",d[i]);
    }
    printf("\n");
    fclose(fis);

    return 0;
}