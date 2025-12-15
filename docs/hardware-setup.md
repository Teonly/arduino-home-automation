# Configuração de Hardware

Este documento descreve a configuração de hardware utilizada no projeto Arduino Home Automation, incluindo a placa, os dispositivos conectados e a finalidade de cada conexão.

## Placa Utilizada

- Arduino (modelo compatível com SoftwareSerial, como Arduino Uno)

A placa é responsável por receber os comandos via Bluetooth, interpretar a lógica de controle e acionar as saídas digitais.

## Módulo Bluetooth

- Módulo Bluetooth hc-05 ou similar
- Comunicação realizada por meio da biblioteca SoftwareSerial
- Pinos utilizados:
  - RX: pino digital 10
  - TX: pino digital 11

O módulo Bluetooth é utilizado como interface de entrada de comandos, permitindo o envio de texto a partir de um dispositivo externo, como um smartphone.

## Dispositivos Controlados

### Iluminação (representada por LEDs)

- LED do quarto:
  - Pino digital 13
- LED da sala:
  - Pino digital 12

Os LEDs são utilizados como representação visual das luzes dos ambientes, facilitando testes e validações do sistema.

### Ventilador

- Controle realizado por dois pinos digitais:
  - VENT_PIN1: pino 8
  - VENT_PIN2: pino 9

Essa configuração permite simular o acionamento de um ventilador ou motor simples, podendo ser adaptada para uso com relés ou drivers apropriados em aplicações reais.

## Alimentação

- Alimentação via porta USB do Arduino

Para fins de desenvolvimento e testes, a alimentação padrão via USB é suficiente para o funcionamento do sistema, essa mesma conexão serve para a comunicação entre o arduino e o visor serial.

## Observações

Este projeto foi desenvolvido com foco em lógica de controle e comunicação.  
A configuração de hardware apresentada representa um ambiente de testes e pode ser adaptada conforme a necessidade, utilizando relés, módulos de potência ou outros atuadores adequados.
