// Programa serial para cálculo de números primos
// Disciplina: Programação Paralela
// Prof. Francisco (Kiko)
// Data: 30/05/17

#include <stdio.h>
//#include <mpi.h>
#include <time.h>

#define max_lin 10000000

int primos[max_lin];
clock_t inicioTempo, fimTempo;

int calculaPrimo(int teste, int *vetPrimos){
 int primo=1; //Todo número é primo
 int pos=0;
 if(teste!=2)
  while (vetPrimos[pos]){
   if((teste % vetPrimos[pos])==0) primo=0;
   pos++;
  }
 return primo;
}

main(int argc, char **argv){
	int tam; 	/* Último número que será verificado */
	primos[0]=1; 	/* primeiro número primo */

	printf("Serao analisados os números primos entre 1 e o valor digitado pelo usuario\n");
	printf("Qual o ultimo numero do intervalo a ser verificado? ");
        scanf("%i", &tam); /* Último número do intervalo de primos */

	if ((tam <= 1)||(tam > max_lin)){ /* Número Inválido */
		printf("Valor digitado pelo usuario e invalido!");
		return(1);
	}

	/* Marcando o início do relógio */
	inicioTempo= clock();

	int num_teste = 2; //Número atual a ser testado	
	int pos = 1; //Posição de teste
	int ult_primo = 0; //Posição do último número primo encontrado
	//int primo = 1; //Inicialmente todos os números são primos

	//Rotina de Cálculo
	for (num_teste=2; num_teste<=tam; num_teste++){
		//primo = 1; //Inicialmente todos os números são primos
		//if (num_teste != 2){
			//for(pos=1; pos<=ult_primo; pos++)
				//if((num_teste % primos[pos])==0) primo=0;
			
		//}
		// Gerando LOGS para debugar
		//printf("%d -> %d\n", num_teste, primo);
		//getchar();
		if (calculaPrimo(num_teste,primos)){
			ult_primo++;
			primos[ult_primo]=num_teste;
		}
	}

	//Exibindo os resultado
	for (pos=0; pos<=ult_primo; pos++)
		printf("%d ", primos[pos]);
	printf("\n");
	printf("Quantidade de primos encontrados: %d", ult_primo+1);

	/* Exibindo o tempo gasto na execução da aplicação */
	fimTempo= clock();
	printf("\n");
	printf("---------------------------------------------------------------------");
	printf("\n");
	printf("%f\n", (float)inicioTempo);
	printf("%f\n", (float)fimTempo);
	printf("Diferença em ms: %f\n",(float)((fimTempo-inicioTempo)/ 1000000.0F ) * 1000);

	return(0); /* Tudo OK. Fim do Programa! */
}

