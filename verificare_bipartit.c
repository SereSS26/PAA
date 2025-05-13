#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int nr_noduri=0;
int nr_arce=0;
int a[MAX][MAX];
int vizitat[MAX];
int valoare=1;
int ok=1;

void citire(FILE *fis)
{
    int aux1=0,aux2=0;
    int i=0;
    fscanf(fis,"%d",&nr_noduri);
    fscanf(fis,"%d",&nr_arce);
    for(i=0;i<nr_arce;i++)
    {
        fscanf(fis,"%d",&aux1);
        fscanf(fis,"%d",&aux2);
        a[aux1][aux2]=1;
        a[aux2][aux1]=1;
    }
}
void afisare_matrice_adiacenta()
{
    int i=0,j=0;
    for(i=1;i<=nr_noduri;i++)
    {
        for(j=1;j<=nr_noduri;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void bipartit(int curent,int valoare)
{   
    int i=0;
    int valoare_opusa=0;
    vizitat[curent]=valoare;
    valoare_opusa=3-valoare;
    for(i=1;i<=nr_noduri;i++)
    {
        if(a[curent][i]==1)
        {   
            if(vizitat[i]==0)
            {
                bipartit(i,valoare_opusa);
            }
            else if(vizitat[i]==valoare)
            {
                ok=0;
            }
        }
    }
}

int main(void)
{   
    FILE *fis=NULL;
    fis=fopen("date.txt","r");
    if(fis==NULL)
    {
        perror("Eroare la deschidere fisier intrare\n");
        exit(-1);
    }
    citire(fis);
    afisare_matrice_adiacenta();
    printf("BIPARTIT\n");
    int nod_initial=1;//aici poti alege orice nod de start
    bipartit(nod_initial,valoare);
    int i=0;
    for(i=1;i<=nr_noduri;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for(i=1;i<=nr_noduri;i++)
    {
        printf("%d ",vizitat[i]);
    }
    printf("\n");
    if(ok==1)
    {
        printf("Graful este bipartit\n");
    }
    else
    {
        printf("Graful nu este bipartit\n");
    }
    fclose(fis);

    return 0;
}