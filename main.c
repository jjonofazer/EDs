#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> //necessário para usar setlocale

int main() {
	// Utilizado para que possa ser usasdo caracteres especias da lingua portuguesa como "nÚmero"
	setlocale(LC_ALL,"portuguese");
		
	// Declarando uma variável do tipo arquivo.
    FILE *csv, *saida;
    
	// Leitura do arquivo de entrada 'DadosEntrada.csv'
    csv = fopen("DadosEntrada.csv", "r");
    
	// Cria um arquivo 'Saida.csv' e o abrirá para escrita
    saida = fopen("SituacaoFinal.csv", "w");
    
	// Variáveis para o armazenamento dos campos dos alunos
    char nome_aluno[50];
    char tel_aluno[50];
    char curso_aluno[50];
    float n1, n2;
	
	// Para indicar se está na primeira linha do arquivo 'DadosEntrada.csv'
	int	 Linha = 1;
    int i = 1, resultado;
    float media_final;
    char aprovado[] = "APROVADO";
    char reprovado[] = "REPROVADO";

    if (csv == NULL) {
        printf("Falha para abrir o arquivo 'DadosEntrada.csv'\n");
        return 1; // Iformar que ouve uma falha ao abrir o arquivo 'DadosEntrada.csv', return 1 é frequentemente usado para indicar erro ou falha
    }

    if (saida == NULL) {
        printf("Erro para criar o arquivo 'SituacaoFinal.cvs'\n");
        return 1; // Iformar que ouve uma falha ao criar o arquivo 'SituacaoFinal.cvs', return 1 é frequentemente usado para indicar erro ou falha
    }

    char linha[256]; // Um armazen para cada linha já lida do arquivo de entrada

    while (fgets(linha, sizeof(linha), csv) != NULL) {
        if (Linha) {
        	
        	// Usado para ignorar a primeira linha do 'DadosEntrada.csv'
            Linha = 0;
            continue;
        }
        // Usamos 'strtok' como um separador para dividir a linha em campos usando a vírgula
        char *token = strtok(linha, ",");

        // Aqui será feito a atribuição dos valores aos campos para a gravação
        if (token != NULL) {
            strcpy(nome_aluno, token);
            token = strtok(NULL, ",");
            
            strcpy(tel_aluno, token);
            token = strtok(NULL, ",");
            
            strcpy(curso_aluno, token);
            token = strtok(NULL, ",");
            
            n1 = atof(token);
            token = strtok(NULL, ",");// sem esta linha não será utilizado a nota 1 para o calculo da média e gerará uma nota que faltará 0,5 de pontuação, Documentação ERRO LINHA 66
            
            n2 = atof(token);
            // token = strtok(NULL, ","); Documentação ERRO LINHA 69
        }

        
        if (token != NULL){
        	media_final = (n1 + n2)/2;
        	if(media_final >= 7) {
        		resultado = aprovado; // Mostará que o aluno foi APROVADO
			} else {
				resultado = reprovado; // Mostrá que o aluno foi REPROVADO
			}
		}

        // Escreve os dados dos alunos no arquivo 'SituacaoFinal.cvs'
        fprintf(saida, "%s, %0.2f, %s\n", nome_aluno, media_final, resultado);
        i++;
    }

    fclose(csv);
    fclose(saida);
	
	printf(" \n\n\n\n\n ");
    printf("-----------------------Arquivo 'SituacaoFinal.csv' teve exito ao ser criado e está salvo em sua pasta!!-----------------------");
    printf(" \n\n\n\n\n\n ");

    return 0; // return 0; é usado para indicar sucesso
}
