#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
	float x;
	float y;
}Pi;

int pontosQuadrado();
void geraValor(Pi*, int);
int conta_pontos_circulo(Pi*, int);
float calcula_distancia(Pi*, int);
float valorPi(float, int);
void mostraValorPi(float);
Pi* criaPi(int);

int main(){

    float pCirc, valor_pi;
    Pi* pi;
    
 	int tam = pontosQuadrado();
 	pi = criaPi(tam);

    geraValor(pi, tam);

	pCirc = conta_pontos_circulo(pi, tam);

	valor_pi = valorPi(pCirc,tam);
	
	mostraValorPi(valor_pi);

}

int pontosQuadrado(){
	int num_max;
	printf("Digite o maximo de pontos que tera no quadrado: ");
	scanf("%i",&num_max);

	return num_max;
}

void geraValor(Pi* pi, int tam){
	srand(time(NULL));
	int i;

	for(i = 0; i < tam; i++){
        pi[i].x = rand()  / (float)RAND_MAX;
    	pi[i].y = rand()  / (float)RAND_MAX;
//        pi[i].x = rand()  % 1;
//    	pi[i].y = rand()  % 1;

        if(pi[i].x < 0){
            pi[i].x * (-1);
        }
        if(pi[i].y < 0){
            pi[i].y * (-1);
        }
	}
}

int conta_pontos_circulo(Pi* pi, int tam){
	float distancia_eixo;
	int i, pCirc=0;

	for(i = 0; i < tam; i++){
        distancia_eixo = calcula_distancia(pi, i);
        
        if(distancia_eixo < 0.5){
            pCirc ++;
        }
	}
    
    return pCirc;
}

float calcula_distancia(Pi* pi, int ponto){
	float delta_x, delta_y, distancia_eixo;

	delta_x = pow((pi[ponto].x - 0.5), 2);
	delta_y = pow((pi[ponto].y - 0.5), 2);

	distancia_eixo = sqrt(delta_x + delta_y);


	return distancia_eixo;
}

float valorPi(float pCirc, int tam){
	return (float) (4 * (pCirc / tam));
}

void mostraValorPi(float pi){

	printf("\nValor de PI: %.5f",pi);
}

Pi* criaPi(int tam){
 	Pi* pi;
 	pi = (Pi*) malloc(tam * sizeof(Pi));
 	
 	return pi;
 	
 	//return (Pi*) malloc(tam * sizeof(Pi));
}
