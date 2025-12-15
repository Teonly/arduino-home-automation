# Lógica de Interpretação de Comandos

Este documento descreve como funciona a interpretação de comandos no projeto Arduino Home Automation, explicando o fluxo de dados, as decisões de implementação e as limitações conhecidas.

## Entrada de Dados

Os comandos são recebidos por meio de um módulo Bluetooth (hc-05 ou 06) conectado ao Arduino (utilizei o uno).  
A comunicação ocorre via serial, com os dados sendo lidos caractere por caractere.

Cada caractere recebido é adicionado a uma variável do tipo String, utilizada como buffer temporário para armazenar o comando completo.

## Buffer de Comando

O buffer armazena todo o texto recebido até que o comando seja processado.  
Após o processamento bem-sucedido, o buffer é limpo para evitar que comandos antigos interfiram nos próximos.

Esse modelo foi adotado por simplicidade, evitando estruturas mais complexas de controle de estado.

## Normalização do Texto

Antes da análise, o texto recebido passa por um processo de normalização:
- Conversão para letras minúsculas
- Remoção de espaços extras no início e no fim

Isso permite que os comandos não dependam de capitalização ou formatação específica.

Adotei estas medidas por que o teclado por voz que estava utilizando para enviar os comandos para o bluetooth não tinha constância em questão de letras maiusculas ou minusculas além de alguns caracteres especiais que ele enviava.

## Interpretação por Palavras-Chave

A lógica de interpretação não utiliza frases fixas.  
Em vez disso, o sistema busca por palavras-chave dentro do texto completo.

As palavras-chave são divididas em dois grupos:
- Ações (ligar, desligar, acender, apagar)
- Dispositivos (quarto, sala, ventilador)

Quando uma combinação válida entre ação e dispositivo é encontrada, a saída correspondente é acionada.

## Fluxo de Execução

1. O comando é recebido via Bluetooth
2. Os caracteres são armazenados no buffer
3. O texto é normalizado
4. O sistema procura combinações de palavras-chave
5. A ação correspondente é executada
6. O buffer é limpo após o processamento

## Limitações Conhecidas

A interpretação é baseada em correspondência de substrings, o que pode gerar ambiguidade entre palavras semelhantes, como "ligar" e "desligar".

Além disso, não há um delimitador explícito de fim de comando, o que torna o sistema dependente da forma como os dados são enviados.

Essas limitações são conhecidas e aceitas dentro do escopo atual do projeto.
