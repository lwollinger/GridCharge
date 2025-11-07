# Resultados Experimentais

A placa desenvolvida, foi projetada para gerenciar o processo de recarga em corrente alternada (CA), incorporando todos os circuitos necessários para detecção de estados, controle do relé e geração do sinal PWM (Pulse Width Modulation) que é responsável por indicar ao veículo a corrente máxima disponível de carregamento.

<div align="center">
<em>Figura - Placa de Circuito Impresso EVSE AC Tipo 2<em>
  <img src="img/placa_de_circuito_impresso _evse_ac_tipo_2.png" alt="Exemplo ilustrativo dos carregadores CA e CC" width="600"/>
  <br>
  <em>Fonte: Autoria própria (2025).</em>
</div>

Após a montagem do protótipo, foram conduzidos testes funcionais e de segurança elétrica para validação do sistema. Os resultados obtidos confirmaram a geração e leitura do sinal PWM conforme o padrão SAE J1772, apresentando frequência de 1 kHz e ciclo ativo proporcional à corrente configurada. Também foram verificados os níveis de tensão dos estados de A a F, garantindo o correto reconhecimento da conexão do veículo e o acionamento seguro do relé de carga.
Além disso, realizaram-se testes de carga real, nos quais o circuito controlou o fornecimento de energia para simular a recarga do veículo, validando o desempenho do sistema em diferentes níveis de corrente. Foram ainda executados testes de segurança, com simulações de desconexão abrupta, surtos elétricos e fugas de corrente, a fim de comprovar a eficiência dos mecanismos de proteção implementados.


# CONSIDERAÇÕES FINAIS

O projeto resultou em um protótipo funcional de um sistema de recarga de corrente alternada (AC) para veículos elétricos, projetado segundo o padrão da SAE J1772 e as normas IEC 62196. A arquitetura proposta demonstrou viabilidade técnica e flexibilidade para adaptação a diferentes padrões de conectores e níveis de potência. Como continuidade, prevê-se a integração do sistema com módulos de comunicação, gerenciamento e controle de energia em rede, visando aplicações em smart grids e infraestruturas públicas de recarga.

# AGRADECIMENTOS

Este trabalho foi desenvolvido como desdobramento do projeto Embrapii “Soluções Facilitadoras para Mobilidade Elétrica”, vinculado ao Polo de Inovação do IFSC – Câmpus Florianópolis, na modalidade Basic Funding Alliance da Empresa Brasileira de Pesquisa e Inovação Industrial (Embrapii). O projeto conta com o apoio das empresas CPFL Energia, FuelTech, ARPAC, Skyvideo, Arrow Mobility e eiON Veículos Elétricos, que contribuíram para o avanço da mobilidade elétrica no país.


#  REFERÊNCIAS
UNITED STATES. Department of Transportation. Charger Types and Speeds. Disponível em: https://www.transportation.gov/rural/ev/toolkit/ev-basics/charging-speeds. Acesso em: 29 set. 2025.

OPENEV. Basics of SAE J1772. Disponível em: https://openev.freshdesk.com/support/solutions/articles/6000052074-basics-of-sae-j1772. Acesso em: 2 out. 2025.

OBJECT MANAGEMENT GROUP (OMG). Unified Modeling Language (UML) Specification, Version 2.5.1. Disponível em: https://www.omg.org/spec/UML/2.5.1
. Acesso em: 7 nov. 2025.

BOOCH, G.; RUMBAUGH, J.; JACOBSON, I. The Unified Modeling Language User Guide. 2. ed. Boston: Addison-Wesley, 2005.
