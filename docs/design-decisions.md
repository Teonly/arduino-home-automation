# Decisões de Projeto

Este documento descreve as principais decisões técnicas adotadas no projeto Arduino Home Automation e os motivos por trás dessas escolhas.

## Foco em Simplicidade

O projeto foi desenvolvido com o objetivo de validar a lógica de interpretação de comandos e o controle de dispositivos físicos, priorizando clareza e funcionamento previsível em vez de soluções complexas.

Por esse motivo, optou-se por uma arquitetura simples, sem o uso de máquinas de estados ou estruturas avançadas de parsing.

## Uso da Classe String

A classe String foi utilizada para armazenar e manipular os comandos recebidos via Bluetooth.

Embora o uso de String em sistemas embarcados possa impactar o uso de memória, essa escolha foi feita para manter o código mais legível e direto, considerando o escopo reduzido do projeto e seu caráter demonstrativo.

## Interpretação por Palavras-Chave

A lógica de comandos é baseada na busca por palavras-chave dentro do texto recebido, em vez de frases fixas ou comandos estruturados.

Essa abordagem permite maior flexibilidade na forma como os comandos são enviados, ao custo de possíveis ambiguidades entre palavras semelhantes, limitação que é conhecida e documentada.

## Ausência de Delimitador de Comando

Não foi implementado um delimitador explícito de fim de comando.  
O processamento ocorre com base no conteúdo acumulado no buffer.

Essa decisão simplifica a comunicação, mas torna o sistema dependente da forma como os dados são transmitidos pelo dispositivo externo, por conta do teclado por voz que estava sendo utilizado durande a produção do prjoeto já possuir essa delimitação essa função acabou por não ser uma prioridade inicial.

## Escopo Atual

As decisões adotadas refletem o escopo atual do projeto, que tem como objetivo demonstrar integração entre eletrônica e programação embarcada, e não atender a requisitos de produção ou robustez industrial.

Evoluções futuras podem revisar essas escolhas conforme novas necessidades sejam introduzidas.
