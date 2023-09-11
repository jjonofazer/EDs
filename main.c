#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //necess�rio para usar setlocale

int main() {
	// Utilizado para que possa ser usasdo caracteres especias da lingua portuguesa como "n�mero"
	setlocale(LC_ALL,"portuguese");
		
	// Declarando uma vari�vel do tipo arquivo.
    FILE *csv, *saida;
    
	// Leitura do arquivo de entrada 'DadosEntrada.csv'
    csv = fopen("DadosEntrada.csv", "r");
    
	// Cria um arquivo 'Saida.csv' e o abrir� para escrita
    saida = fopen("SituacaoFinal.csv", "w");
    
	// Vari�veis para o armazenamento dos campos dos alunos
    char nome_aluno[50];
    char tel_aluno[50];
    char curso_aluno[50];
    float n1, n2;
	
	// Para indicar se est� na primeira linha do arquivo 'DadosEntrada.csv'
	int	 Linha = 1;
    int i = 1, resultado;
    float media_final;
    char aprovado[] = "APROVADO";
    char reprovado[] = "REPROVADO";

    if (csv == NULL) {
        printf("Falha para abrir o arquivo 'DadosEntrada.csv'\n");
        return 1; // Iformar que ouve uma falha ao abrir o arquivo 'DadosEntrada.csv', return 1 � frequentemente usado para indicar erro ou falha
    }

    if (saida == NULL) {
        printf("Erro para criar o arquivo 'SituacaoFinal.cvs'\n");
        return 1; // Iformar que ouve uma falha ao criar o arquivo 'SituacaoFinal.cvs', return 1 � frequentemente usado para indicar erro ou falha
    }

    char linha[256]; // Um armazen para cada linha j� lida do arquivo de entrada

    while (fgets(linha, sizeof(linha), csv) != NULL) {
        if (Linha) {
        	
        	// Usado para ignorar a primeira linha do 'DadosEntrada.csv'
            Linha = 0;
            continue;
        }
        // Usamos 'strtok' como um separador para dividir a linha em campos usando a v�rgula
        char *token = strtok(linha, ",");

        // Aqui ser� feito a atribui��o dos valores aos campos para a grava��o
        if (token != NULL) {
            strcpy(nome_aluno, token);
            token = strtok(NULL, ",");
            
            strcpy(tel_aluno, token);
            token = strtok(NULL, ",");
            
            strcpy(curso_aluno, token);
            token = strtok(NULL, ",");
            
            n1 = atof(token);
            token = strtok(NULL, ",");// sem esta linha n�o ser� utilizado a nota 1 para o calculo da m�dia e gerar� uma nota que faltar� 0,5 de pontua��o, Documenta��o ERRO LINHA 66
            
            n2 = atof(token);
            // token = strtok(NULL, ","); Documenta��o ERRO LINHA 69
        }

        
        if (token != NULL){
        	media_final = (n1 + n2)/2;
        	if(media_final >= 7) {
        		resultado = aprovado; // Mostar� que o aluno foi APROVADO
			} else {
				resultado = reprovado; // Mostr� que o aluno foi REPROVADO
			}
		}

        // Escreve os dados dos alunos no arquivo 'SituacaoFinal.cvs'
        fprintf(saida, "%s, %0.2f, %s\n", nome_aluno, media_final, resultado);
        i++;
    }

    fclose(csv);
    fclose(saida);
	
	printf(" \n\n\n\n\n ");
    printf("-----------------------Arquivo 'SituacaoFinal.csv' teve exito ao ser criado e est� salvo em sua pasta!!-----------------------");
    printf(" \n\n\n\n\n\n ");

    return 0; // return 0; � usado para indicar�sucesso
}
