 # Semáforo 

__Atividade 1 da Tarefa 2 - Aula Síncrona 29/01__<br>
Repositório criado com o intuito de realizar a Atividade 1 da Tarefa 2 da aula Síncrona do dia 29 de janeiro de 2025 sobre Clocks e Temporizadores.

__Responsável pelo desenvolvimento:__
Andressa Sousa Fonseca

## Descrição Da Tarefa 


__Os Componentes necessários para a simulação da atividade no Wokwi Integrado ao VS Code:__
1) Microcontrolador Raspberry Pi Pico W.
2) 03 LEDs (vermelho, amarelo e verde).
3) 03 Resistores de 330 Ω.

Os componentes acima já estão presente no kit de Desenvolvimento Bit Dog Lab.

__As funcionalidade básicas especificadas para a atividade são:__
1) Acionar os leds um a um a cada 3 segundos, na seguinte ordem: vermelho, amarelo, verde.

Ao executar o código no simulador, o Led Amarelo será visível. No entanto, ao executar na placa, o led amarelo é substituído pelo azul.

__Aplicação de temporizadores__  <br>

A atividade 1 utiliza temporizadores periódicos para fazer o acionamento dos Leds no tempo especificado. Para isso, é necessário criar a seguinte função:
```bash
bool repeating_timer_callback(struct repeating_timer *t)
```
Essa função contém a lógica para acionamento intercalado dos leds, que é chamada na main pela função callback a cada 3 segundos. É preciso adicionar as seguintes linhas de código na main:
```bash
struct repeating_timer timer;
add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
```

__A simulação do projeto pode ser visualizada no seguinte link: [Simulação com Wokwi Web - Semáforo](https://wokwi.com/projects/421970356059537409).__

## Detalhamento do Funcionamento

O presente código consiste em simular um semáforo. Ao iniciar o programa, o Led Vermelho será ligado e a seguinte mensagem aparecerá:
```bash
Sinal Vermelho! Pare!
```
Após 3 segundos, o Led Vermelho é desligado e o Led Amarelo passa a ficar ligado, com a seguinte mensagem:
```bash
Sinal Amrarelo! Atenção!
```
Após outros 3 segundos, o Led Amarelo é desligado e o próximo led é ligado, Led Verde. E a mensagem abaixo aparece:
```bash
Sinal Verde! Siga!
```
Os passos acima repetem enquanto o programa estiver rodando.
Ademais, a cada 1 segundo uma outra mensagem aparece:
```bash
Obedeça a sinalização!
```

## Passos para uso do código

Os arquivos presentes no repositório são fundamentais para a execução do projeto. Assim, o primeiro passo é clonar o atual repositório 'Semaforo' no seu computador para poder rodá-lo no VS Code. Vale ressaltar que para o devido funcionamento do simulador é necessário ter o Wokwi Integrado.

### 1. Clonar repositório
Abra a pasta que deseja armazenar o projeto no VS Code. Depois, abra um Terminal e cole a linha de comando abaixo:
```bash
git clone https://github.com/Dreh3/Semaforo.git
```

### 2. Abrir a pasta do projeto
Após clonar, é necessário abrir a pasta do projeto para que o VS Code possa reconstruir a pasta 'build' e assim poder executar o código com sucesso.

### 3. Compilar o código
Compilar o código é um passo essencial para gerar os arquivos necessários para usra o simulador e adicionar as bibliotecas do CMakeLists.txt.

### 4. Simulador Wokwi 
Após os passos acima, o último passo necessário é abrir o arquivo diagram.json. Assim, o simulador Wokwi integrado irá iniciar e o projeto poderá ser visualizado.

### 5. Placa
Todos os passos citados aplicam-se para carregar o código no ki de Desenvolvimento Bit Dog Lab. A única diferença é que o 4° passo não é essencial. Assim, após o passo 3, basta selecionar a opção 'Run' na barra inferior do VS Code para que o Semáforo passe a funcionar na placa.

<div align="center">
  <img src="https://github.com/Dreh3/Semaforo/blob/main/semaforoImagem.png?raw=true" alt="imagem do simulador" width="300"/>
</div>
