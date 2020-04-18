/*
CÁLCULO NUMÉRICO COMPUTACIONAL COM ARDUINO.
LIVRO REFERÊNCIA: CÁLCULO NUMERICO COMPUTACIONAL PETERS,S., SZEREMETA, J.F. EDITORA UFSC

O método desenvolvido neste algoritmo esta relacionado a aplicação do Método de Gauss com 
pivotação total.

Consideramos, por simplificação, que este algoritmo será capaz de resolver equações lineares 
com 3 equações e o sistema é determinado. pag.111.
Ex.:

|ax1 + bx2 + cx3 = b1
|dx1 + ex2 + fx3 = b2
|gx1 + hx2 + ix3 = b3

Sistema determinado: quando o sistema de equações tem
solução única, a matriz de coeficientes é não singular, isto é, o seu
determinante é não nulo. Ocorre quando todas as equações do
sistema são linearmente independentes, ou seja, nenhuma equação
é combinação linear de outras.

Refereências do algoritmo:
https://books.google.com.br/books?id=BxeQiS_M2d0C&pg=PA75&lpg=PA75&dq=pivota%C3%A7%C3%A3o+total+com+arduino&source=bl&ots=6FE5ldR3so&sig=ACfU3U03JHte9BBUlo7HcGdU9jo1G9EMOw&hl=pt-BR&sa=X&ved=2ahUKEwjP54bO8tjoAhUNHrkGHeCjCaQQ6AEwCXoECAwQLA#v=onepage&q&f=false


*/

// Definindo o número k de operações para a resolução das equações:
int k=0;

//Definindo as variaveis i linhas e j colunas
int i=0, j=0;

//Definindo uma matriz no arduino do tipo 3x3 na forma de matriz expandida:
//float equacao[3][4] =  {
//
//  {0.421,  0.784,  -0.207, 0 },
//  
//  {-0.319,  0.884,  0.279, 0 },
//
//  {0.448,  0.832,   0.193, 1 }
//
//};

//float equacao[3][4] =  {
//
//  {1,  1,  -1, 0 },
//  
//  {1,  -2,  5, 21 },
//
//  {4,  1,   4, 31 }
//
//};

float equacao[3][4] =  {

  {2,  5,   3,  20 },
  
  {5,  3,   -10, -39},

  {1,  1,   1,  5 }

};


void setup() {

// Inicializando a porta Serial
Serial.begin(9600);
  

}

void loop() {
  
  //passo 1.1 verificar qual melhor linha para reposicionar na linha 0
  //Caso na linha 0 (zero) o primeiro elemento já seja o de maior valor, não será necessário realizar nenhuma operação, assim verifica-se somente os casos seguintes

  // Verificando se o elemento zero da linha 1 possui o maior valor na matriz e caso positivo realiza-se a substituição da linha
  if (equacao[1][0] > equacao[0][0] && equacao[1][0] > equacao[2][0]){
    float X[1][4] = {0,  0,  0, 0 };
                  for (int f=0;f<=3;f++){
                  X[0][f] = equacao[0][f];
                  equacao[0][f] = equacao[1][f];
                  equacao[1][f] = X[0][f];
                  }
    }
  // Verificando se o elemento zero da linha 2 possui o maior valor na matriz e caso positivo realiza-se a substituição da linha    
  if (equacao[2][0] > equacao[0][0] && equacao[2][0] > equacao[1][0]) {
      float X[1][4] = {0,  0,  0, 0 };
                  for (int f=0;f<=3;f++){
                  X[0][f] = equacao[0][f];
                  equacao[0][f] = equacao[2][f];
                  equacao[2][f] = X[0][f];
                  }
    }
    
    //passo1.2 realizar a eliminação gaussiana correspondente ao passo k=1
    if (k==0){
              float l2=0 , l3=0;
              l2 = float(equacao[1][0] / equacao [0][0]);
              l3 = float(equacao[2][0] / equacao [0][0]);
              
              for (int s=1; s<3; s++){
                                        for(int f=0; f<4; f++){
                                          if(s==1) equacao[s][f] = float(equacao[s][f]) - float(equacao[0][f] * l2);
                                          if(s==2) equacao[s][f] = float(equacao[s][f]) - float(equacao[0][f] * l3);
                                        }
             }

             
             Serial.println("MATRIZ K==0:");
             for (int s=0; s<=2; s++){
                                  for(int f=0; f<=3; f++){
                                      Serial.println(equacao[s][f],4);
                                  }
             }
             k=1;
    }
  
    //passo1.2 realizar a eliminação gaussiana correspondente ao passo k=1
    if (k==1){

              // Verificando se o elemento zero da linha 1 é maior que o da linha 2 da matriz
              if (equacao[2][0] > equacao[1][0]){
                                                float X[1][4] = {0,  0,  0, 0 };
                                                for (int f=0;f<=3;f++){
                                                          X[1][f] = equacao[1][f];
                                                          equacao[1][f] = equacao[2][f];
                                                          equacao[2][f] = X[1][f];
                                                }
              }

              float l3=0;
              l3 = float(equacao[2][1] / equacao [1][1]);
              Serial.print("valor de l3:");
              Serial.println(l3,6);
              
              
              for(int f=1; f<4; f++){
                                      equacao[2][f] = float(equacao[2][f]) - (float(equacao[1][f] * l3));
              }
              
              Serial.println("MATRIZ K==1:");
                            for (int s=0; s<=2; s++){
                                          for(int f=0; f<=3; f++){
                                              Serial.println(equacao[s][f],4);
                                        }
                            }
    //Finalizando o programa com k=2, sendo este um passo que não existe, assim o loop é finalizado
    k=2;

    }

  // Devido a erros computacionais de arredondamento, estouro de variável etc, será necessário zerar manualmente os valores nas posições calculadas proximas de zero
  // Aqui evidencia-se que calculos numericos computacionais terão resultados com grandes propabilidades de aproximações, uma vez que em casos de dizímas periódicas ou 
  // valores numéricos irracionais o computador semrpe terá uma limitação. Esta aproximações causarão erros entre os valores reais e os calculados computacionalmente.
  equacao[2][1] = 0;

  Serial.println("MATRIZ FINAL:");
  for (int s=0; s<=2; s++){
                              for(int f=0; f<=3; f++){
                                  Serial.println(equacao[s][f],4);
                              }
                            }
  

  // processo de determinação dos valores de x1, x2 e x3;
  float x3=0, x2=0, x1=0;

  x3 = float(equacao[2][3]/equacao[2][2]);
  Serial.print("O valor de x3 sera: ");
  Serial.println(x3);

  x2= float((equacao[1][3] - equacao[1][2]*x3)/equacao[1][1]);
  Serial.print("O valor de x2 sera: ");
  Serial.println(x2);

  x1 = float((equacao[0][3] - equacao[0][2]*x3 - equacao[0][1]*x2)/equacao[0][0]);
  Serial.print("O valor de x1 sera: ");
  Serial.println(x1);
 
  delay(100000);
  
  
  }
