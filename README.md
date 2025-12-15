# Arduino Home Automation

## Project Overview / Visão Geral (EN/PT)

**EN:**
Arduino Home Automation is a small-scale home automation project developed with Arduino. The system receives text commands via Bluetooth and interprets them using keyword matching to control simple devices such as lights and a fan. The project focuses on clear logic and direct hardware control.

**PT:**
Arduino Home Automation é um projeto de automação residencial de pequeno porte desenvolvido com Arduino. O sistema recebe comandos de texto via Bluetooth e os interpreta por meio de palavras-chave para controlar dispositivos simples, como luzes e ventilador. O foco do projeto é a lógica clara e controle direto do hardware.

---

## Key Features / Recursos Principais (EN/PT)

**EN:**

* Keyword-based command interpretation
* Bluetooth communication with external device
* Independent control of multiple outputs
* Serial feedback for debugging and monitoring
* Flexible commands (not restricted to fixed phrases)

**PT:**

* Interpretação de comandos baseada em palavras-chave
* Comunicação via Bluetooth com dispositivo externo
* Controle independente de múltiplas saídas
* Feedback via monitor serial para depuração
* Comandos flexíveis (não dependem de frases fixas)

---

## Command Interpretation Logic / Lógica de Interpretação de Comandos (EN/PT)

**EN:**
The system does not rely on predefined full sentences. Instead, it analyzes incoming text and searches for keywords related to actions (such as turning on or off) and target devices (room, living room, fan). Once a valid combination is detected, the corresponding output is activated.

**PT:**
O sistema não depende de frases completas pré-definidas. Em vez disso, ele analisa o texto recebido e procura palavras-chave relacionadas à ação (ligar ou desligar) e ao dispositivo alvo (quarto, sala, ventilador). Ao identificar uma combinação válida, a saída correspondente é acionada.

---

## Architecture / Arquitetura (EN/PT)

**EN:**

* Arduino as the main control unit
* Bluetooth module for command input
* SoftwareSerial for communication handling
* Digital outputs controlling external devices

**PT:**

* Arduino como unidade central de controle
* Módulo Bluetooth para entrada de comandos
* Uso da biblioteca SoftwareSerial para comunicação
* Saídas digitais controlando dispositivos externos

---

## Technologies / Tecnologias (EN/PT)

**EN:**

* Arduino (Clike language)
* SoftwareSerial library
* Bluetooth module
* Arduino IDE

**PT:**

* Arduino (linguagem Clike)
* Biblioteca SoftwareSerial
* Módulo Bluetooth
* Arduino IDE

---

## Status / Status Atual (EN/PT)

**EN:**
The project is functionally complete in its current scope. The code is intentionally kept close to its original form to accurately represent the author’s logic and implementation choices.

**PT:**
O projeto está funcionalmente completo dentro do seu escopo atual. O código foi mantido propositalmente próximo da sua forma original para representar fielmente a lógica e as decisões de implementação do autor.

---

## Known Limitations / Limitações Conhecidas (EN/PT)

**EN:**

* Use of the String class in an embedded environment
* Simple keyword-based parsing
* Substring matching may cause ambiguity between similar commands (e.g. "ligar" and "desligar")
* No explicit command termination validation

**PT:**

* Uso da classe String em ambiente embarcado
* Análise baseada em palavras-chave simples
* Correspondência por substrings pode gerar ambiguidade entre comandos semelhantes (ex: "ligar" e "desligar")
* Ausência de validação explícita de fim de comando

---

## Future Plans / Planos Futuros (EN/PT)

**EN:**

* Improve memory usage and command parsing
* Add support for additional devices
* Migrate to Wi-Fi-based communication (ESP32)
* Integrate with a backend or web interface

**PT:**

* Melhorar o uso de memória e a interpretação de comandos
* Adicionar suporte a novos dispositivos
* Migrar para comunicação via Wi-Fi (ESP32)
* Integrar com backend ou interface web

