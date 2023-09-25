#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h> // Necessário para usar setlocale

#include "Area_poligono.h"// Minha biblioteca criada realiza o calculo da area do poligono, "#incluide" necessario para o funcionamneto da execução

int main() {
	
    FILE *arquivo;
    arquivo = fopen("vertices.txt", "r"); // Abre e lê o arquivo ja criado previamente
    
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo"); // caso de erro ao abrir o arquivo
        return 1;
    }

    int numVertices;
    fscanf(arquivo, "%d", &numVertices);

    Ponto *pontos = (Ponto*)malloc(numVertices * sizeof(Ponto));

    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &pontos[i].X, &pontos[i].Y);
    }

    fclose(arquivo); // Fecha o arquivo
    setlocale(LC_ALL, "Portuguese");

    float area = calcularArea(pontos, numVertices);
    printf("A área do polígono é: %.2f\n", area);// Mensagem exibida no painel terminal 

    return 0;
}
