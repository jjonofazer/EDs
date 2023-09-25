// struct para as variaveis X e Y que coresponde as coordenadas
typedef struct {
    float X;
    float Y;
} Ponto;

// Calculo da area do poligono 

float calcularArea(Ponto* pontos, int vertices) {
    float area = 0.0;

    for (int i = 1; i < vertices - 1; i++) {
        float calculo = (pontos[i].X * pontos[i + 1].Y - pontos[i + 1].X * pontos[i].Y);
        area += calculo;
    }

    area = fabs(area) / 2.0; // Valor absoluto da área dividido por 2
    return area;
}
