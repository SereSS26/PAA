#include <stdio.h>
#include <stdlib.h>

#define INFINIT 10000
#define MAX_MUCHII 2000
#define MAX_NODURI 20

int nr_noduri=0;
int nr_muchii=0;
int tata[MAX_NODURI];

typedef struct{
    int x;
    int y;
    int p;
}muchii;

muchii lista_muchii[MAX_MUCHII];

void citire(FILE *fis)
{
    int x=0,y=0,p=0;
    while(fscanf(fis,"%d",&x)==1)
    {
        fscanf(fis,"%d",&y);
        fscanf(fis,"%d",&p);
        lista_muchii[nr_muchii].x=x;
        lista_muchii[nr_muchii].y=y;
        lista_muchii[nr_muchii].p=p;
        nr_muchii++;
    }
}
void bubbleSort(muchii v[], int n) 
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(v[j].p>v[j+1].p)
            {
                // interschimbare muchii
                muchii aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}
void kruskal()
{
    int i=0,j=0;
    int cost_total=0;
    int aux_i=0;
    int aux_j=0;
    for(i=1;i<=nr_noduri;i++)
    {
        tata[i]=i;
    }
    for(i=0;i<nr_muchii;i++)
    {
        if(tata[lista_muchii[i].x]!=tata[lista_muchii[i].y])
        {
            cost_total=cost_total+lista_muchii[i].p;
            aux_i=tata[lista_muchii[i].x];
            aux_j=tata[lista_muchii[i].y];
            for(j=1;j<=nr_noduri;j++)
            {
                if(tata[j]==aux_j)
                    tata[j]=aux_i;
            }
        }
    }
    printf("%d\n",cost_total);
}

int main(void)
{   
    FILE *fis=NULL;
    fis=fopen("kruskal.txt","r");
    if(fis==NULL)
    {
        perror("Eroare la deschidere fisier de intrare\n");
        exit(-1);
    }
    fscanf(fis,"%d",&nr_noduri);
    citire(fis);
    bubbleSort(lista_muchii,nr_muchii);
    kruskal();
    fclose(fis);

    return 0;
}