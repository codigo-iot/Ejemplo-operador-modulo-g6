/*
 * Ejemplo de operadores
 * Por: Hugo Vargas
 * Fecha: 8 de abril del 2022
 * 
 * Este programa me permite experimentar el uso y aplicaciones del
 * operador módulo
 */

// Bibliotecas
//#include <Serial.h>//Opcional

// Constantes

// Variables
int dato = 0;
double timeStart, timeFinish;

// Definición de objetos

// Condiciones iniciales - Se ejecuta sólo una vez al energizar
void setup() {// Inicio de void setup ()
  // Aquí va tu código
  Serial.begin (115200);//Iniciar comunicacion Serial
  Serial.println ("Comuniacion Serial Iniciada");
  delay (5000);

}// Fin de void setup

// Cuerpo del programa - Se ejecuta constamente
void loop() {// Inicio de void loop
  // put your main code here, to run repeatedly:

  timeStart = micros ();//Inicia el conteo de tiempo

  //Ejecuta el contador de anillo 10 mil veces
  for (int i = 0; i < 10000; i++) {
    dato++;//Incremento
    //Comparación
    if (dato > 8) {
      dato = 0;
    }
  }

  timeFinish = micros ();//Termina el conteo de tiempo

  //Reporte en monitor serial
  Serial.print ("Con if ");
  Serial.println (timeFinish - timeStart); //Imprimir el valor del contador
  delay (10000); //Espera antes de la siguiente prueba

  timeStart = micros ();//Inicia el conteo de tiempo

  //Ejecuta el contador de anillo 10 mil veces
  for (int i = 0; i < 10000; i++) {
    dato++;
    //Incremento
    //Modulo
    dato %= 8;
  }

  timeFinish = micros ();//Termina el conteo de tiempo

  //Reporte en monitor serial
  Serial.print ("Con operadores ");
  Serial.println (timeFinish - timeStart); //Imprimir el valor del contador

  //Espera antes de la siguiente prueba
  delay (10000);

}// Fin de void loop

// Funcioes del usuario
