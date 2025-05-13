#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int nr_noduri=0;
int nr_arce=0;
int a[MAX][MAX];
int vizitat[MAX];
int nr_componente_conexe=0;

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
void conex(int curent)
{
    int i=0;
    vizitat[curent]=nr_componente_conexe;
    for(i=1;i<=nr_noduri;i++)
    {
        if(a[curent][i]==1&&vizitat[i]==0)
        {
            conex(i);
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
    printf("COMPONENTE CONEXE\n");
    int i=0;
    for(i=1;i<=nr_noduri;i++)
    {
        if(vizitat[i]==0)
        {   
            nr_componente_conexe++;
            conex(i);
        }
    }
    printf("%d\n",nr_componente_conexe);
    ///valoarea din vectorul de vizitat e componenta conexa din care face parte nodul
    for(i=1;i<=nr_noduri;i++)
    {
        printf("%d ",vizitat[i]);
    }
    printf("\n");
    fclose(fis);

    return 0;
}