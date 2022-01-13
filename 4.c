#include <stdio.h>
#include <stdlib.h>

int main(){
    int *disciplinas,*alunos, quant_d,quant_a,faltas,a=1;
    float notas;
    FILE *arquivo;
    char nome[100];
    arquivo = fopen("arquivo.dat","w");  

    printf("Digite a quantidade de disciplinas: ");
    scanf("%d",&quant_d);
    disciplinas = (int *)malloc(quant_d * sizeof(int));

    char nome_d[quant_d][20];

    for (int i = 0; i < quant_d; i++)
    {
        
        printf("Nome da disciplina %d: ", a);
        scanf("%s",nome_d[i]);
        a++;
    }

    for (int i = 0; i < quant_d; i++)
    {
       printf("Quantidade de alunos de %s :",nome_d[i]);
       scanf("%d",&quant_a);
       fprintf(arquivo, "Disciplina: %s\n", nome_d[i]);
       for ( int a = 0; a < quant_a; a++)
       {
           printf("Digite nome, nota e faltas de cada aluno: \n");
           printf("nome aluno %d: ",a);
           scanf("%s",nome);
           printf("Faltas: ");
           scanf("%d",&faltas);
           printf("Nota: ");
           scanf("%f",&notas);
           fprintf(arquivo, "Nome do aluno: %s - Quantidade de faltas: %d  - Nota: %.f \n", nome,faltas,notas);


       }
       
       fprintf (arquivo, "\n");
       
    }
    fclose(arquivo);

    printf("Deseja consultar ? 1-sim 2-nao: ");
    int op;
    scanf("%d",&op);
    if (op==1)
    {
      arquivo = fopen("arquivo.dat","r"); 
    int i = 1;
    char *result;
     char leitura[100];
    while (!feof(arquivo))
    {
	
      result = fgets(leitura, 100, arquivo);  
      if (result)  
	  printf("Linha %d : %s",i,leitura);
      i++;
     }  
     fclose(arquivo);
    }
    

    
    

return 0;
}


