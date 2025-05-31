#include <stdio.h>
#include <stdlib.h>

#define INFINIT 10000
#define MAX 20

int a[MAX][MAX];
int vizitat[MAX];
int tata[MAX];
int nr_noduri=0;

void initializeaza_matrice(int n)
{
    int i=0,j=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            a[i][j]=INFINIT;
        }
    }
    for(i=1;i<=n;i++)
    {
        a[i][i]=0;
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
void citire(FILE *fis)
{
    int nr_arce=0;
    int x=0,y=0,p=0;
    fscanf(fis,"%d",&nr_arce);
    for(int i=0;i<nr_arce;i++)
    {
        fscanf(fis,"%d",&x);
        fscanf(fis,"%d",&y);
        fscanf(fis,"%d",&p);
        a[x][y]=p;
        a[y][x]=p;
    }
}
void prim(int nod_start)
{   
    int i=0,k=0,min=0,p=0;
    vizitat[nod_start]=1;
    for(i=1;i<=nr_noduri;i++)
        tata[i]=nod_start;
    tata[nod_start]=0;
    for(k=1;k<=nr_noduri-1;k++)
    {
        min=INFINIT;
        p=0;
        for(i=1;i<=nr_noduri;i++)
        {
            if(vizitat[i]==0&&a[i][tata[i]]<min)
            {
                min=a[i][tata[i]];
                p=i;
            }
        }
        vizitat[p]=1;
        for(i=1;i<=nr_noduri;i++)
        {
            if(vizitat[i]==0&&a[i][tata[i]]>a[i][p])
                tata[i]=p;
        }
    }
    int cost_total=0;
    for(i=1;i<=nr_noduri;i++)
    {   
        cost_total=cost_total+a[i][tata[i]];
        printf("%d %d %d\n",tata[i],i,a[i][tata[i]]);
    }
    printf("%d\n",cost_total);
}

int main(void)
{   
    FILE *fis=NULL;
    fis=fopen("prim.txt","r");
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
    prim(nod_start);
    fclose(fis);

    return 0;
}