#include <stdio.h>
#include "pico/stdlib.h"

#define RED_LED 11 // Pino do LED vermelho
#define YELLOW_LED 12 // Pino do LED amarelo
#define GREEN_LED 13 // Pino do LED verde

int8_t count = 1; // Variável de controle para alternar entre os LEDs

// Função para inicializar os pinos dos LEDs
void SetOutputs(int pins[], size_t size)
{
    // Loop para inicializar cada pino
    for (size_t i = 0; i < size; i++)
    {
        gpio_init(pins[i]);
        gpio_set_dir(pins[i], GPIO_OUT); // Define a direção do pino como saída
    }
}

// Função de call-back, chamada pelo temporizador a cada intervalo
bool TrafficLightUpdate(struct repeating_timer *t)
{
    // Controla os LEDs de acordo com o valor de 'count'
    switch (count)
    {
    case 0: // Sinal vermelho
        gpio_put(GREEN_LED, false); // Desliga o LED verde
        gpio_put(RED_LED, true);    // Liga o LED vermelho
        break;
    case 1: // Sinal amarelo
        gpio_put(RED_LED, false);   // Desliga o LED vermelho
        gpio_put(YELLOW_LED, true); // Liga o LED amarelo
        break;
    case 2: // Sinal verde
        gpio_put(YELLOW_LED, false); // Desliga o LED amarelo
        gpio_put(GREEN_LED, true);   // Liga o LED verde
        count = -1;                  // Reinicia o ciclo de contagem
        break;
    }

    count++; // Incrementa o contador para a próxima transição dos sinais

    return true; // Retorna true para continuar chamando o temporizador
}

int main()
{
    stdio_init_all(); // Inicializa a biblioteca padrão de entrada/saída

    // Inicializa todos os LEDs
    int led_pins[] = {RED_LED, YELLOW_LED, GREEN_LED};
    SetOutputs(led_pins, sizeof(led_pins) / sizeof(led_pins[0]));

    // Inicializa o LED vermelho (inicia com o sinal vermelho)
    gpio_put(RED_LED, true);

    // Configura o temporizador para chamar a função 'TrafficLightUpdate' a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, TrafficLightUpdate, NULL, &timer);


    while (true)
    {
        sleep_ms(1000000);
    }
}
