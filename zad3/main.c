#include <stdio.h>
#include <stdlib.h>

int swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int sortuj(int tab[], int n)
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        j = i;
        while ((j>0) && (tab[j] < tab[j-1]))
        {
            swap(&tab[j], &tab[j-1]);
            j=j-1;
        }
    }

}

int main()
{
    int n;
    FILE *plik;
    printf("Podaj rozmiar zbioru: ");
    scanf("%d", &n);
    int tab[n];

    if((plik = fopen("liczby.txt","r")) == NULL)
    {
        printf("brak pliku albo plik  nie moze sie otworzyc");
        return 0;
    }

    for(int i = 0; i<n; i++)
    {
        fscanf(plik, "%d", &tab[i]);
    }

    printf("Podany zbior to: \n");

    for(int i = 0; i<n; i++)
    {
        printf("%d ", tab[i]);
    }
    fclose(plik);

    ///////////////////////////////
    ///////////////////////////////

    plik = fopen("liczby.txt","w");
    for(int i = 0; i<n; i++)
    {
        fprintf(plik, "%d\n", tab[i]);
    }

    printf("\n");
    sortuj(tab, n);

    printf("Posortowany: \n");

    for(int i = 0; i<n; i++)
    {
        printf("%d ", tab[i]);
    }

    fprintf(plik, "\n\n");

    for(int i = 0; i<n; i++)
    {
        fprintf(plik, "%d ", tab[i]);
    }
    fclose(plik);

    return 0;
}
