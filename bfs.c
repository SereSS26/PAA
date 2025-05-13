#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int nr_noduri=0;
int nr_arce=0;
int a[MAX][MAX];
int vizitat[MAX];
int coada[MAX];

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
void bfs(int curent)
{   
    int stanga=0,dreapta=0,i=0,aux=0;
    stanga=1;
    dreapta=1;
    vizitat[curent]=1;
    coada[1]=curent;
    while(stanga<=dreapta)
    {
        aux=coada[stanga];
        printf("%d ",aux);
        for(i=1;i<=nr_noduri;i++)
        {
            if(vizitat[i]==0&&a[aux][i]==1)
            {
                vizitat[i]=1;
                dreapta++;
                coada[dreapta]=i;
            }
        }
        stanga++;
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
    printf("BFS\n");
    int nod_initial=2;//aici poti alege orice nod de start
    bfs(nod_initial);
    printf("\n");
    fclose(fis);

    return 0;
}