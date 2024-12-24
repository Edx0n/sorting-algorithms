#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAM 10000


//------------------------ESTRUTURA DADOS------------------------/
typedef struct {
    double peso, altura;
    int idade;
} Data;

//------------------------VETOR ORDENADO DECRESCENTE------------------------/
void vet_ordenado_decrescente(int vet[],int num)
{
     int i;
     printf("Vetor em Ordem Decrescente\n");
     for(i=num;i>0;i--)
     {
           vet[i]=num-i;
     }
}

//------------------------VETOR_ORDENADO CRESCENTE------------------------/

void vet_ordenado(int vet[],int num)
{
     int i;
     printf("Vetor em Ordem Crescente\n");
     for(i=0;i<num;i++)
     {
           vet[i]=1+i;
     }
}

//------------------------VETOR_RANDOMIZADO------------------------/
void randomiza(int vet[],int num)
{
     int i;
     srand(time(NULL));
        printf("Vetor em Ordem Randomica\n");
        for (i=0; i<TAM; i++)
        {
                vet[i]=rand() % TAM;
        }
}

//------------------------ BUBBLE_SORT------------------------/
void bubble(Data* x, int n){
    int flag = 1;
    for(int cont = 1; cont < n && flag != 0; cont++)
    {
        flag = 0;
        for(int j = 0; j < (n - cont); j++)
        {
            if(x[j].altura > x[j+1].altura)
            {
              flag = 1;
            }
        }
    }
}

void Fill(Data* d){
  d->altura = rand() % 10;
  d->peso = rand() % 100;
  d->idade = rand() % 50;
}

//------------------------QUICK_SORT ------------------------/
void ordena_quick(int vet[], int esquerda, int direita)
{
    int i, j;
    int x, y;
    i=esquerda; j=direita;
    x=vet[(esquerda+direita)/2]; //gera a media dos valores para escolher o pivo/

  do
  {
    while(vet[i]<x && i<direita)
    i++;
         while(x<vet[j] && j>esquerda)
     j--;
     if(i<=j)
     {
         y=vet[i];
         vet[i]=vet[j];
         vet[j]=y;
         i++;
         j--;
     }

   }while(i<=j);

    if(esquerda<j)
    ordena_quick(vet, esquerda, j);
           if(i<direita)
           ordena_quick(vet, i, direita);
}
void imprime_quick(int vet[],int num)
{
     int i=0;
     printf("\nORDENADO PELO METODO QUICKSORT:\n");
     while (i<num)
    {
           printf("%d\n", vet[i]);

           i++;
    }
}

//------------------------ INICIO_DA_MAIN ------------------------/

//OBS: Para Ordenar com vetores de ordem Crescente ou decrescenteprecisa comentar as chamdas de fuçoes na main() deixando apenas uma funçao de ordenação. Para vetores de diferentes tamanho mude a Constante TAM nos arquivos cabeçalhos logo abaixo\\

int main()
{
        setlocale(LC_ALL, "portuguese");
        printf("\t\t\PROGRAMA DA 3° ATIVIDADE - 12.05.2022\n\n");
        printf("\t\tCONCEITOS DOS MÉTODOS DE ORDENAÇÃO VISTOS EM AULA\n\n\n");
        printf("Nome: Edson Fernandes Cabral - RA: 21005995\n");
        printf("Nome: Gabriel Oliveira Martins - RA: 21937750\n");
        printf("Nome: Murilo Almeida Trevisan - RA: 21004881\n");
        printf("Nome: Rodrigo Marques Justa - RA: 21002177\n\n\n");


clock_t inicio,fim, inicio_b, fim_b;
        double tempo_d;
        int vet[TAM],i,num=0,opcao,op;
        int size = 10;
        Data a[size];
        double time_quick=0;

    do
    {
      printf("\n------------------------ MENU ------------------------\n\n");
      printf("1 - QuickSort\n2 - BubbleSort-\n3 - Mostrar Tempo\n4 - Sair\n");
      printf("--------------------------------------------------------[Digite a opção: ]\b\b");
      scanf("%d",&opcao);
      if(opcao<1||opcao>3)
      {
          exit(1);
      }
  switch(opcao)
  {
       case 1:
       {
           //vet_ordenado_decrescente(vet,TAM);
           vet_ordenado(vet,TAM);
             randomiza(vet,TAM);

            inicio=clock();
                ordena_quick(vet, 0, TAM-1);
                fim=clock();
                time_quick = /*((double)(fim-inicio))/CLK_TCK;*/(double)(((double)fim-(double)inicio)/CLOCKS_PER_SEC);
                printf("\n%3.3f Segundos para Ordenar %d numeros com o Metodo QuickSort\n\n",time_quick,TAM);
                //imprime_quick(vet,TAM);
                break;
         }

         case 2:
     {
                //srand ((unsigned)time(NULL));
                for(int i = 0; i < size; i++)
                Fill(&a[i]);
                bubble(a, 10);
                for(int i = 0; i < size; i++)
                printf("%.2f %.2f %d\n", a[i].altura, a[i].peso, a[i].idade);
                break;

      }

          case 3:
          {
                      printf("Tempo do QuickSort = %3.3f s\n",time_quick);
                      break;
          }
     }

    }while(opcao>0||opcao<4);
return 0;
 system("clear");
}
