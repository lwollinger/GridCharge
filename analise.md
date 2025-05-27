# Análise orientada a objeto
> [!NOTE]
> A **análise** orientada a objeto consiste na descrição do problema a ser tratado, duas primeiras etapas da tabela abaixo, a definição de casos de uso e a definição do domínio do problema.

## Descrição Geral do domínio do problema

O domínio do problema está centrado no controle de um sistema de carregamento de veículos elétricos (EV), especificamente utilizando um carregador AC Tipo 1. Esse tipo de carregador segue padrões como o SAE J1772, amplamente utilizado em veículos elétricos para carregamento em corrente alternada. O projeto visa desenvolver um sistema embarcado que automatize o processo de carregamento garantindo segurança, eficiência e conformidade com os estados definidos pelo protocolo.

A operação do carregamento envolve diferentes estágios que precisam ser identificados e controlados corretamente, para assim evitar possíveis falhas. Para isso, o sistema deverá interagir com o circuito de controle do carregador, sensores e atuadores (como relés, LEDs, GFCI, etc), e ser capaz de interpretar corretamente o estado de carga e conexão com o veículo, garantindo a segurança veicular e do próprio sistema.

**Requisitos Funcionais (RF)**
-  Controlar os estados de operação do carregador conforme o protocolo do Tipo 1 (ex: Desconectado, Conectado, Carregando, Erro), a partir do conector "*Control Pilot* (CP)".

- Acionar e desligar os relés das fases conforme o estado de carregamento.

- Identificar a conexão com o veículo elétrico por meio do sinal de controle "*Proximity Pilot* (PP)".

-  Indicar o estado atual do carregamento com LEDs (ex: LED verde para pronto, azul para carregando, vermelho para erro).

-  Monitorar e reagir a falhas de conexão ou sobrecargas, se necessário.

**Requisitos Não Funcionais (RNF)**

-  Deve garantir a segurança do carregamento, evitando acionamento de relés fora dos estados apropriados.

## Diagrama de Casos de Uso

Apresentar o diagram de casos de uso, identificando as funcionalidades do sistema assim como os atores envolvidos
 
## Diagrama de Domínio do problema

Elaborar um diagrama conceitual do domínio do problema.


<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>