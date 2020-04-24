// ARDUINO MATEMÁTICO PARTE 3 - GERANDO GRÁFICOS
// CRIADO POR LINCOLN MOURA
// OBJETIVO:
// O OBJETIVO DESTE CÓDIGO É APRESENTAR A CAPACIDADE DO ARDUINO EM GERAR GRÁFICOS A PARTIR 
// DO PLOTTER SERIAL. 
//


// IMPORTANDO A BIBLIOTECA METAMÁTICA DO ARDUINO
#include <math.h> 

void setup()
{
  //INICIALIZAÇÃO DA PORTA SERIAL
  Serial.begin(115200);
}

void loop()
{
// Descomente as linhas abaixo comentadas caso deseje ver os resultados numericos na aba do Monitor Serial.
// obs: Habilitar estas linhas poderá trazer problemas de configuração na lengenda do Serial Plotter.
//
//  Serial.println("Digite um método a ser utilizado:");
//  
//  char *Menu[]= {" 1 : Função de um reta tipo y = x",
//                 " 2 : Função do 1º Grau tipo y = a*x + b"
//                 " 3 : Função do 2º Grau do tipo y = a*x potencia (2) + b*x + c ",
//                 " 4 : Função do 3º Grau do tipo y = a*x potencia (3) + b*x potencia (2) + c*x +d ",
//                 " 5 : Função do 4º Grau do tipo y = a*x potencia (4) + b*x potencia (3) + c*x potencia (2) + d*x + e",
//                 " 6 : Função exponencial tipo y = a potencia(x) = b",
//                 " 7 : Função logarítmica base 10 tipo y = log_base10 (x) ",
//                 " 8 : Função Modular de 1º grau tipo: ",
//                 "y = | modulo (x), se x<0; ",
//                 "    | x, se x>0; ",
//                 " 9 : Função Modular de 2º grau tipo: ",
//                 "y = |  x*potencia(2) - 4, se x<0; ",
//                 "    | -x*potencia(2) + 4, se x>0; "
//                 " 10 : Função Seno "
// };
//
//  for (int menu=0; menu <12;menu++){
//    Serial.println(Menu[menu]);
//    }
  

//Inicializando a variável que receberá o gráfico a ser plotado;
int iteracao = 0;
//velocidade de plotagem dos graficos
int vel=40;
  
  while(iteracao==0){
          
                      if (Serial.available() > 0) {
                                                    iteracao = Serial.parseInt();
                                                    //Serial.print("Gráfico desejado: ");
                                                    break;
          
                      }
            }
  
  //1 : Função de um reta tipo y = x
  if (iteracao == 1){
                      // Linha abaixo para visualização do Monitor Serial
                      //Serial.println(Menu[iteracao-1]);
                                  Serial.print("X: ");
                                  Serial.print("  ");
                                  Serial.print("Funcao_Identidade: ");
                                  Serial.print("  ");
                                  Serial.println("");
                                
                      for (float i=-10; i < 10; i+=0.1){                                  
                                  Serial.print(0); 
                                  Serial.print("  ");
                                  Serial.print(i); 
                                  Serial.print("  ");
                                  Serial.println("");
                                  delay(vel);
                        }
                       // Retornando ao Menu
                       iteracao=0;

  }
    
    //2 : Função do 1º Grau tipo y = a*x + b
    if (iteracao == 2){

                      // Linha abaixo para visualização do Monitor Serial
                      //Serial.println(Menu[iteracao-1]);
                                  Serial.print("X: ");
                                  Serial.print("  ");
                                  Serial.print("Funcao_1_grau: ");
                                  Serial.print("  ");
                                  Serial.println("");
                      // y = a*x +b a=2 e b = 10      
                      for (float i=-10; i < 10; i+=0.1){                                  
                                  Serial.print(0); 
                                  Serial.print("  ");
                                  Serial.print(2*i+10); 
                                  Serial.print("  ");
                                  Serial.println("");
                                  delay(vel);
                        }
                       // Retornando ao Menu
                       iteracao=0;

  }

    //3 : Função do 2º Grau do tipo y = a*x potencia (2) + b*x + c
    if (iteracao == 3){

                      // Linha abaixo para visualização do Monitor Serial
                      //Serial.println(Menu[iteracao-1]);
                                  Serial.print("X: ");
                                  Serial.print("  ");
                                  Serial.print("Funcao_2_grau: ");
                                  Serial.print("  ");
                                  Serial.println("");
                      
                      // y = a*x2 +bx +c  a = 2 b = 6 c = -20     
                      for (float i=-10; i < 7; i+=0.1){                                  
                                  Serial.print(0); 
                                  Serial.print("  ");
                                  Serial.print(2*pow(i,2)+6*i-20); 
                                  Serial.print("  ");
                                  Serial.println("");
                                  delay(vel);
                        }
                       // Retornando ao Menu
                       iteracao=0;

  }

   //4 : Função do 3º Grau do tipo y = a*x potencia (3) + b*x potencia (2) + c*x +d
   if (iteracao == 4){

                      // Linha abaixo para visualização do Monitor Serial
                      //Serial.println(Menu[iteracao-1]);
                                  Serial.print("X: ");
                                  Serial.print("  ");
                                  Serial.print("Funcao_3_grau: ");
                                  Serial.print("  ");
                                  Serial.println("");
                                  
                      // y = a*x3 +b*x2 +c*x +d  a=1 b = 5 c=10 d=20    
                      for (float i=-10; i < 10; i+=0.1){                                  
                                  Serial.print(0); 
                                  Serial.print("  ");
                                  Serial.print(1*pow(i,3)+3*pow(i,2)+5*i+20); 
                                  Serial.print("  ");
                                  Serial.println("");
                                  delay(vel);
                        }
                       // Retornando ao Menu
                       iteracao=0;

  }

     //5 : Função do 4º Grau do tipo y = a*x potencia (4) + b*x potencia (3) + c*x potencia (2) + d*x + e
     if (iteracao == 5){

                      // Linha abaixo para visualização do Monitor Serial
                      //Serial.println(Menu[iteracao-1]);
                                  Serial.print("X: ");
                                  Serial.print("  ");
                                  Serial.print("Funcao_4_grau: ");
                                  Serial.print("  ");
                                  Serial.println("");
                      // y = a*x4 +b*x3 +c*x2 +dx + e  a=1 b = 5 c=2 d=10 e=20
                      for (float i=-11; i < 5; i+=0.1){                                  
                                  Serial.print(0); 
                                  Serial.print("  ");
                                  Serial.print(1*pow(i,4)+10*pow(i,3)+12*pow(i,2)+10*i+20); 
                                  Serial.print("  ");
                                  Serial.println("");
                                  delay(vel);
                        }
                       // Retornando ao Menu
                       iteracao=0;

  }

     //6 : Função exponencial tipo y = a potencia(x) = b
     if (iteracao == 6){

                      // Linha abaixo para visualização do Monitor Serial
                      //Serial.println(Menu[iteracao-1]);
                                  Serial.print("X: ");
                                  Serial.print("  ");
                                  Serial.print("Funcao_Exponencial ");
                                  Serial.print("  ");
                                  Serial.println("");
                      // y = a potencia (x)
                      for (float i=-2; i < 3; i+=0.1){                                  
                                  Serial.print(0); 
                                  Serial.print("  ");
                                  Serial.print(pow(10,i)); 
                                  Serial.print("  ");
                                  Serial.println("");
                                  delay(vel);
                        }
                       // Retornando ao Menu
                       iteracao=0;

  }

    //7 : Função logarítmica base 10 tipo y = log_base10 (x)
    if (iteracao == 7){

                      // Linha abaixo para visualização do Monitor Serial
                      //Serial.println(Menu[iteracao-1]);
                                  Serial.print("X: ");
                                  Serial.print("  ");
                                  Serial.print("Funcao_log ");
                                  Serial.print("  ");
                                  Serial.println("");
                      // y = a potencia (x)
                      for (float i=0.0001; i < 20; i+=0.1){                                  
                                  Serial.print(0); 
                                  Serial.print("  ");
                                  Serial.print(5*log10(i)); 
                                  Serial.print("  ");
                                  Serial.println("");
                                  delay(vel);
                        }
                       // Retornando ao Menu
                       iteracao=0;

  }
  

//                 " 8 : Função Modular de 1º grau tipo: ",
//                 "y = | modulo (x), se x<0; ",
//                 "    | x, se x>0; ",
     if (iteracao == 8){

                      // Linha abaixo para visualização do Monitor Serial
                      //Serial.println(Menu[iteracao-1]);
                                  Serial.print("X: ");
                                  Serial.print("  ");
                                  Serial.print("Funcao_modular_1_grau");
                                  Serial.print("  ");
                                  Serial.println("");
                      // y = a potencia (x)
                      for (float i=-10; i < 10; i+=0.1){
                                  if (i<0){                                  
                                            Serial.print(0); 
                                            Serial.print("  ");
                                            Serial.print(-1*i); 
                                            Serial.print("  ");
                                            Serial.println("");
                                            delay(vel);
                                  }
                                  if (i>=0){                                  
                                            Serial.print(0); 
                                            Serial.print("  ");
                                            Serial.print(i); 
                                            Serial.print("  ");
                                            Serial.println("");
                                            delay(vel);
                                  }
                        }
                       // Retornando ao Menu
                       iteracao=0;

  }

  
//                 " 9 : Função Modular de 2º grau tipo: ",
//                 "y = | x^2-4x+3, se x<=1 ou x>=3; ",
//                 "    | -x^2+4x-3, se x<1 && x< 3; "
   if (iteracao == 9){

                      // Linha abaixo para visualização do Monitor Serial
                      //Serial.println(Menu[iteracao-1]);
                                  Serial.print("X: ");
                                  Serial.print("  ");
                                  Serial.print("Funcao_modular_2_grau");
                                  Serial.print("  ");
                                  Serial.println("");
                      // y = a potencia (x)
                      for (float i=0; i < 4; i+=0.05){
                                  if (i<=1 || i>=3){                                  
                                            Serial.print(0); 
                                            Serial.print("  ");
                                            Serial.print(pow(i,2)-4*i+3); 
                                            Serial.print("  ");
                                            Serial.println("");
                                            delay(vel);
                                  }
                                  if (i>1 && i< 3){                                  
                                            Serial.print(0); 
                                            Serial.print("  ");
                                            Serial.print(-1*pow(i,2)+4*i-3); 
                                            Serial.print("  ");
                                            Serial.println("");
                                            delay(vel);
                                  }
                        }
                       // Retornando ao Menu
                       iteracao=0;

  }

   //10 : Função Seno
   if (iteracao == 10){

                      // Linha abaixo para visualização do Monitor Serial
                      //Serial.println(Menu[iteracao-1]);
                                  Serial.print("X: ");
                                  Serial.print("  ");
                                  Serial.print("Funcao_seno");
                                  Serial.print("  ");
                                  Serial.println("");
                      // y = a potencia (x)
                      for (float i=0; i < 4*PI; i+=0.1){
                                            
                                            Serial.print(0); 
                                            Serial.print("  ");
                                            Serial.print(10*sin(i)); 
                                            Serial.print("  ");
                                            Serial.println("");
                                            delay(vel);

                        }
                       // Retornando ao Menu
                       iteracao=0;

  }


}
