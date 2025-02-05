# Projeto de Temporizador Periódico - Semáforo com Raspberry Pi Pico W

## Descrição
Este projeto foi desenvolvido por mim, Hilquias Rodrigues de Oliveira, para demonstrar o uso de temporizadores periódicos no microcontrolador Raspberry Pi Pico W. O objetivo é controlar um semáforo utilizando a função `add_repeating_timer_ms()` do Pico SDK, alternando os LEDs vermelho, amarelo e verde a cada 3 segundos.

## Funcionalidades
- Controle de um semáforo com LEDs vermelho, amarelo e verde.
- Alternância de cores a cada 3 segundos utilizando um temporizador periódico.
- Impressão de mensagens pela porta serial a cada 1 segundo.

## Componentes Utilizados
- Raspberry Pi Pico W
- 3 LEDs (vermelho, amarelo e verde)
- 3 resistores de 330Ω

## Como Executar
### Requisitos
- Pico SDK instalado
- VS Code com extensões do Raspberry Pi Pico, CMake e C/C++

### Passos
1. Clone este repositório e abra a pasta do projeto no VS Code.
2. Realize a compilação
3. Abra o arquivo `diagram.json` e dê play no simulador
