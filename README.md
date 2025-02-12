# Controle de Servomotor e LED RGB com PWM no RP2040

📋 **Descrição do Projeto**

Este projeto demonstra o controle de um servomotor e um LED RGB utilizando o sinal PWM (Pulse Width Modulation) com o microcontrolador RP2040 da placa BitDogLab. O objetivo é ajustar o ângulo do servomotor e observar o comportamento do LED RGB em resposta ao mesmo sinal PWM.

🚀 **Funcionalidades**

- Controle de Posição do Servomotor nas posições de 0°, 90° e 180°.
- Movimentação suave entre 0° e 180° com incrementos de 5 µs.
- Controle de Brilho do LED RGB (GPIO 12) baseado na largura do pulso PWM.

📡 **Configuração do Hardware**

- **Servomotor**: Conectado à GPIO 22.
- **LED RGB**: Conectado à GPIO 12.
- **Microcontrolador**: RP2040 da BitDogLab.

⚙️ **Funcionamento**

- O sinal PWM gerado pelo RP2040 controla tanto o servomotor quanto o LED RGB.
- O servomotor é posicionado em 0°, 90° ou 180° dependendo da largura do pulso PWM. Para um controle suave, a movimentação entre os ângulos é realizada com incrementos pequenos.
- O LED RGB responde ao sinal PWM, ajustando seu brilho conforme a largura do pulso. Pulso curto resulta em brilho fraco, enquanto pulso longo resulta em brilho intenso.

📐 **Parâmetros do PWM**

- **Frequência do PWM**: Para o controle do servomotor, utilizamos uma frequência de 50 Hz, com um período de 20 ms.
- **Ciclo Ativo**: A largura do pulso PWM determina a posição do servomotor e a intensidade do LED:
  - 0°: Pulso de 500 µs.
  - 90°: Pulso de 1470 µs.
  - 180°: Pulso de 2400 µs.
  
🔧 **Controle de PWM**

- A frequência do sinal PWM é controlada pelo valor de `wrap`, que determina o período de cada ciclo do PWM. O valor do `wrap` é configurado para garantir que o período do PWM corresponda a 20 ms (50 Hz).
- A largura do pulso, que controla o movimento do servomotor ou o brilho do LED, é ajustada em torno desse valor de período.

💡 **Observações do Comportamento do LED**

O LED RGB varia seu brilho em função da largura do pulso PWM:
- Pulso curto (500 µs): brilho fraco.
- Pulso médio (1470 µs): brilho médio.
- Pulso longo (2400 µs): brilho intenso.

Isso demonstra como o PWM pode ser usado não apenas para controlar a posição de um servomotor, mas também para ajustar a intensidade luminosa de um LED RGB.

---

## Como Executar

### Pré-requisitos

- **Raspberry Pi Pico** com o **RP2040**.
- **Placa BitDogLab**.
- **VS Code** com o **Pico SDK** instalado.

 ### Passos

1. Clone o repositório em sua máquina local:
   ```bash
   git clone https://github.com/Luizgvv/servomotor.git
2. Compile.
3. Verifique o funcionamento no Wokwi Simulador.
4. Conecte a placa BitDogLab ao computador.
5. Carregue o código na placa RP2040.
6. Observe o comportamento do led descritas no projeto em execução.

---

**Tecnologias Utilizadas**
- Microcontrolador RP2040 (BitDogLab)
- PWM (Pulse Width Modulation)
- Servomotor
- LED RGB
- GPIO (General Purpose Input/Output)

   
### Vídeo de Demonstração

[![Demonstração na Placa]() .

Um vídeo de demonstração com a explicação e exibição do funcionamento do projeto foi produzido. Clique na imagem acima ou no link abaixo para assistir:

🔗 [Assistir no YouTube])  .

**Autor**
- Luiz Gustavo do Valle Vieira
