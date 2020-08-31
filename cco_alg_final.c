#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


typedef struct sPi{

	float x;
	float y;
}Pi;

int pontosQuadrado();
void geraValor(Pi* pi,int tam);
float conta(Pi* pi,int tam);
void valorPi(float pCirc,int tam);

int pontosQuadrado(){

	int num_max;
	printf("Digite o maximo de pontos que tera no quadrado: ");
	scanf("%i",&num_max);

	return num_max;
}

void geraValor(Pi* pi,int tam){

	srand(time(NULL));
	int i;

	for(i = 0;i < tam;i++){


        pi[i].x = rand()  / (float)RAND_MAX;
    	pi[i].y = rand()  / (float)RAND_MAX;

        if(pi[i].x < 0){
            pi[i].x * (-1);
        }
        if(pi[i].y < 0){
            pi[i].y * (-1);
        }
	}
}



float conta(Pi* pi,int tam){
    int i;
	float delta_x;
	float delta_y;
	float distancia_eixo;
	float pCirc;

	for(i = 0;i < tam;i++){

		delta_x = pow((pi[i].x - 0.5),2);
   	 	delta_y = pow((pi[i].y - 0.5),2);


    	distancia_eixo = sqrt(delta_x + delta_y);

    	if(distancia_eixo < 0.5){
    		pCirc ++;
		}

	}

	return pCirc;
}

void valorPi(float pCirc,int tam){

	float pi = 4 * (pCirc / tam);

	printf("\nValor de PI: %.5f",pi);
}

int main(){

 	int i = pontosQuadrado();
 	Pi* pi = (Pi*) malloc(i * sizeof(Pi));

    geraValor(pi, i);

    float j;
	j = conta(pi,i);

	valorPi(j,i);

}


