 # Semáforo 

__Atividade 1 da Traefa 2 - Aula Síncrona 29/01__<br>
Repositório criado com o intuito de realizar a Atividade 1 da Tarefa 2 da aula Síncrona do dia 29 de janeiro de 2025 sobre Clocks e Temporizadores.

__Responsável pelo desenvolvimento:__
Andressa Sousa Fonseca

## Descrição Da Tarefa 
__Aplicação de temporizadores__  <br>

__Os Componentes necessários para a simulação da atividade no Wokwi Integrado ao VS Code:__
1) Microcontrolador Raspberry Pi Pico W.
2) 03 LEDs (vermelho, amarelo e verde).
3) 03 Resistores de 330 Ω.

Os componentes acima já estão presente no kit de Desenvolvimento Bit Dog Lab.

__As funcionalidade básicas especificadas para a atividade são:__
1) Acionar os leds um a uma cada 3 segundos, na seguinte ordem: Vermelho, Amarelo, Verde.

Ao executar o código no simulador, o Led Amarelo será visível. No entanto, ao executar na placa, o led Azul será visto no lugar do Amarelo.


__A simulação do projeto pode ser visualizada no seguinte link: [Simulação com Wokwi Web - Semáforo](https://wokwi.com/projects/421970356059537409).__

## Detalhamento do Funcionamento

O presente código consiste em simular um semáforo. Ao iniciar o programa, o Led Vermelho será ligado e a seguinte mensagem aparecerá:
```bash
Sinal Vermelho! Pare!
```
Após 3 segundos, o Led Vermelho é desligado e o Led Amarelo passa a ficar ligado, com a seguinte mensagem:
```bash
Sinal Vermelho! Pare!
```
Novamente após 3 segundos, o led ligado, amarelo, é desligado e o próximo led é ligado, o Verde. E a mensagem abaixo aparece:
```bash
Sinal Verde! Siga!
```
Os passos acima repetem enquanto o programa estiver rodando.
Ademais, a cada 1 segundo um outra mensagem aparece:
```bash
Obedeça a sinalização!
```

## Passos para uso do código

Os arquivos presentes no repositório são fundamentais para a execução do projeto. Assim, o primeiro passo é clonar o atual repositório 'Semaforo' no seu computador para poder rodá-lo no VS Code. Vale resaltar que para o devido funcionamento do simulador é necessário ter o Wokwi Integrado.
###1° Passo: Clonar repositório
```bash
git clone 'endereço do respositório'
```

###2° Passo: Abrir Projeto
Após clonar, é necessário abrir a pasta do projeto para que o VS Code possa reconstruir a pasta 'build' e assim poder executar o código com sucesso.

###3° Passo: Executar diagram.json
Após os passos acima, o último passo necessário é selecionar o arquivo diagram.json. Assim, o simulador Integrado irá iniciar e o projeto poderá ser visualizado.

###Extra: Placa
Os passos acima, são os mesmos para poder carregar o programa na placa. A única diferença é que o 3° passo não é essencila. Assim, depois de abrir o arquivo, basta selecionar a opção 'Run' para que o Semáforo passe a funcionar na placa.

<div align="center">
  <img src="https://github.com/Dreh3/Tarefa1/blob/fb1782612d69e62c9580bbad365e0a59a8eaa65a/zero.png?raw=true" alt="imagem" width="300"/>
</div>
