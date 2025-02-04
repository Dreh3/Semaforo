//Código desenvolvido por Andressa Sousa Fonseca

/*
O presente código simula um semáforo. E o intervalo entre as cores
é de 3 segundos. Para isso, utilizei um temporizador periódico.
*/

#include "pico/stdlib.h"   
#include "hardware/timer.h" 
#include <stdio.h>

// Definindo os pinos para o LEDs 
#define LedR 13 //Led Vermelho no pino 13
#define LedY 12 //Led Amarelo no pino 12, o que na placa correspondente ao Led Azul
#define LedG 11 //Led Verde no pino 11

// Variáveis globais uteis no código
absolute_time_t turn_off_time;  // Armazena o tempo em que o led deverá ser desligado
static volatile uint ordem =1; //Indica a ordem de acionamento dos leds  

//Função para inicializar e configurar pinos dos Leds
void config(){
  //Inicializando pinos
  gpio_init(LedR);
  gpio_init(LedY);
  gpio_init(LedG);

  //Definindo pinos como saída
  gpio_set_dir(LedR, GPIO_OUT);
  gpio_set_dir(LedY, GPIO_OUT);
  gpio_set_dir(LedG, GPIO_OUT);

  //Leds Amarelo e Verde desligados
  gpio_put(LedG, 0);
  gpio_put(LedY, 0);
  gpio_put(LedR, 1); //Led vermelho inicia já ligado

}

// Função de callback que será chamada pelo temporizador repetidamente a cada 3 segundo para alternar entre os leds
bool repeating_timer_callback(struct repeating_timer *t) {

   
      if(ordem == 0){       //Verifica se a variável 'ordem' tem valor 0
        gpio_put(LedR, 1);  //Se tiver, é a vez de ligar o led Vermelho
        printf("\nSinal Vermelho! Pare!\n\n"); //Mensagem para descrever o momento atual do código
        
        //Verifica se o led verde está ligado, porque no primeiro momento 
        //porque na primeira vez que o código roda, o led vermelho é o primeiro a ligar
        //evitando assim, um desligamento desnecessário
        if(gpio_get(LedG)){     
          gpio_put(LedG, 0);
        };
        
        //Incrementa 'ordem' para permitir identificar o próximo led
        ordem=1;

      }else if(ordem ==1){ //Verifica se a variável 'ordem' tem valor 1
        gpio_put(LedR,0);   //Desliga o led Vermelho
        gpio_put(LedY,1);   //É a vez de ligar o led Amarelo (Azul, na placa)
        printf("\nSinal Amarelo! Atenção!\n\n"); //Mensagem de aviso
        
        //Incrementa 'ordem' para permitir identificar o próximo led
        ordem=2;

      }else{
        gpio_put(LedY,0); //Desliga o led Amarelo (Azul, na placa)
        gpio_put(LedG,1); //É a vez de ligar o led Verde
        printf("\nSinal Verde! Siga!\n\n"); //Mensagem de aviso

        //Retorna valor de 'ordem' para 0, indicando que o led vermelho é o próximo
        ordem=0;
      };

    //Permite que a função repita
    return true;
}

int main() {
    
    stdio_init_all();  //Habilita a comunicação padrão  

    config(); //Função que configura e inicializa pinos dos leds

    // Configura um temporizador repetitivo que chama a função de callback a cada 3 segundo (3000 ms).
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    //Assim, os leds vão alternar no tempo desejado
    
    while (true) {
        //Mensagem que aparecerá a cada 1 segundo (1000 ms)
        printf("Obedeça a sinalização!\n");
        sleep_ms(1000); //Tempo de pausa para a repetição da mensagem anterior
    }

    return 0;
}
