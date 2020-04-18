/* ** SOLUÇÃO DE EQUAÇÕES LINEARES POR MÉTODOS ITERATIVOS **
 *  Por: Lincoln M.
 *LIVRO REFERÊNCIA: CÁLCULO NUMERICO COMPUTACIONAL PETERS,S., SZEREMETA, J.F. EDITORA UFSC, 2018.
 *
 *  Quando o sistema de equações lineares A * X = B tiver algumas
características especiais, como: a ordem n elevada (n é o número de equações);
a matriz dos coeficientes A possuir grande quantidade de elementos
nulos (matriz esparsa); e os coeficientes puderem ser gerados através de
alguma lei de formação; em geral, será mais eficiente resolvê-lo através de
um método iterativo (repetitivo), sem operar com os coeficientes nulos,
desde que a convergência seja possível.
 *  
 * Observe que as soluções de sistemas de equações lineares obtidas por
métodos iterativos são soluções aproximadas a cada iteração k (contador de
repetições), portanto têm erros de truncamento, além de erros de arredondamento;
mas, nesse caso, os arredondamentos não são acumulados, uma
vez que os coeficientes das equações não são alterados ao longo do processo.

Teorema de convergência – critério de Scarborough
Segundo o teorema de convergência de Scarborough: se o sistema A * X = B tiver diagonal dominante, ou diagonal estritamente
dominante, tanto a sequência construída pelo método de Jacobi quanto a pelo de Gauss-Seidel convergirão para a solução S.

O teorema de convergência contém uma condição suficiente, porém, não necessária. Portanto, se o teorema for verdadeiro, a sequencia
convergirá; se não for, nada podemos  afirmar.

Digonal dominante é quando :

3 *x1 + 1 *x2 - 1 *x3 = 1     |3| > ou = |1| + |-1|
1 *x1 + 6 *x2 - 1 *x3 = 5     |6| > ou = |1| + |-1|
1 *x1 - 1 *x2 - 2 *x3 = 2     |-2|> ou = |-1| + |-1|
 * 
 * Consideramos, por simplificação, que este algoritmo será capaz de resolver equações lineares 
com 3 equações e o sistema é determinado. pag.111.
Ex.:

|ax1 + bx2 + cx3 = b1
|dx1 + ex2 + fx3 = b2
|gx1 + hx2 + ix3 = b3
 * 
 * MÉTODO UTILIZADO DE JACOBI E Gauss-Seidel
 */

////Definindo uma matriz no arduino do tipo 3x3 na forma de matriz expandida:
float equacao[3][4] =  {

  {3,  -1,   -1,  1 },
  
  {1,  3,    1,   5 },

  {1,  -1,   2,   2 }

};
//
//
//float equacao[3][4] =  {
//
//  {1,  1,  -1, 0 },
//  
//  {1,  -2,  5, 21 },
//
//  {4,  1,   4, 31 }
//
//};

//float equacao[3][4] =  {
//
//  {0.421,  0.784,  -0.207, 0 },
//  
//  {-0.319,  0.884,  0.279, 0 },
//
//  {0.448,  0.832,   0.193, 1 }
//
//};


void setup() {
  
// Inicializando a porta Serial
Serial.begin(9600);

}

void loop() {

  //Inicializando as incógnita x1, x2 e x3
  float x1=0, x2=0,x3=0;
  float x1i=0, x2i=0,x3i=0;
  
  //Inicializando o numero de iterações
  int iteracao = 0;
  int metodo =0;

  //Recebe as iterações e o método de resolução por meio da porta serial do arduino
  Serial.println("Digite o Numero de Iteracoes desejada:");
  
  while(1){
          
                      if (Serial.available() > 0) {
                        // read the incoming byte:
                        
                        iteracao = Serial.parseInt();
                        // say what you got:
                        Serial.print("Valor desejado de iteracoes: ");
                        Serial.println(iteracao);
                        break;
          
                      }
            }

  // Recebe o método a ser escolhido para a resolução da iteração
  Serial.println("Digite 1 se deseja utilizar o Método de Jacobi ou 2 se Método GAUSS-SOBEL");

              while(1){
                // send data only when you receive data:
                
                if (Serial.available() > 0) {
                            // read the incoming byte:
                          
                          metodo = Serial.parseInt();
                          
                          if (metodo == 1) {
                            Serial.println("Método iterativo de Jacobi Selecionado. ");
                            break; 
                          }

                          if (metodo == 2) {
                            Serial.println("Método iterativo de Gauss-Seidel Selecionado. ");
                            break; 
                          }
                }
            }
          
  //Método iterativo de Jacobi
  if (metodo==1){
                    
                    for( int flag=0; flag< iteracao ; flag++ ){
                  
                          x1i = (equacao[0][3]-equacao[0][2]*x3-equacao[0][1]*x2)/equacao[0][0];
                          x2i = (equacao[1][3]-equacao[1][2]*x3-equacao[1][0]*x1)/equacao[1][1];
                          x3i = (equacao[2][3]-equacao[2][0]*x1-equacao[2][1]*x2)/equacao[2][2];

                          x1 = x1i;
                          x2 = x2i;
                          x3 = x3i;
                  
                          Serial.print("Iteracao no método Jacobi numero: ");
                          Serial.println(flag+1);
                          Serial.print("Valores sendo atualizados: ");
                          Serial.print(x1);
                          Serial.print(", ");
                          Serial.print(x2);
                          Serial.print(", ");
                          Serial.print(x3);
                          Serial.println("; ");
                          
                    }
                    
                    Serial.println("VALORES FINAIS PARA AS VARIÁVEIS:");     
                    Serial.print("Numero de iteracoes no método Jacobi: ");  
                    Serial.println(iteracao);  
                    Serial.println(x1,4);
                    Serial.println(x2,4);
                    Serial.println(x3,4);
                }

  //Método iterativo de Gauss-Seidel
  if (metodo == 2){
    
             for( int flag=0; flag< iteracao ; flag++ ){
              
                        x1 = (equacao[0][3]-equacao[0][2]*x3-equacao[0][1]*x2)/equacao[0][0];
                        x2 = (equacao[1][3]-equacao[1][2]*x3-equacao[1][0]*x1)/equacao[1][1];
                        x3 = (equacao[2][3]-equacao[2][0]*x1-equacao[2][1]*x2)/equacao[2][2];

                        Serial.println("VALORES FINAIS PARA AS VARIÁVEIS:");     
                        Serial.print("Numero de iteracoes no método Jacobi: ");  
                        Serial.println(iteracao);  
                        Serial.println(x1,4);
                        Serial.println(x2,4);
                        Serial.println(x3,4);
            }                   
            
                    Serial.println("VALORES FINAIS PARA AS VARIÁVEIS:");     
                    Serial.print("Numero de iteracoes no método GAUSS-SOBEL: ");  
                    Serial.println(iteracao);  
                    Serial.println(x1,4);
                    Serial.println(x2,4);
                    Serial.println(x3,4);
      }
  }
