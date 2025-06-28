# Projeto orientado a objeto

>[!NOTE]
>O **Projeto orientado a objeto** é composto pelas documentação do projeto descrito em UML. Deve incluir um Diagrama de Classes do sistema projetado, e pelo menos um diagrama de interação de um dos casos de uso. Outros diagramas podem ser apresentados, caso julgue necessário.



**Proximity Pin (PP) no Contexto do Carregamento de Veículos Elétricos**

O pino de proximidade, conhecido como Proximity Pilot (PP), desempenha um papel essencial nos sistemas de carregamento de veículos elétricos (EVs), fornecendo informações sobre o estado físico da conexão entre o conector do carregador e o veículo. O PP também é utilizado para informar a capacidade de corrente do cabo de carregamento (este referênciado pelo resistores presente dentro do próprio carregador).

No padrão SAE J1772, amplamente utilizado atualmente na América do Norte e no Japão, o pino PP é utilizado para detectar a presença física do conector no veículo e gerenciar o processo de desconexão segura durante o carregamento. Seus estágios avisam conexão e desconexão, evitando arcos voltaicos. 

No lado do EVSE, o PP é ligado ao terra de proteção (PE) por meio de um resistor de 150 Ω, em série com uma chave mecânica (S3) acoplada ao mecanismo de travamento do conector.
Ao acionar o botão de liberação do plugue (indicando a intenção de desconexão do plug), a chave S3 comuta e adiciona um segundo resistor de 330 Ω em série com o circuito PP–PE. Essa alteração na resistência resulta em uma variação de tensão detectável na linha PP. O veículo interpreta essa variação como um aviso de que o conector está prestes a ser removido e, assim, interrompe o fornecimento de corrente de forma segura, prevenindo danos ou riscos elétricos.

Vale destacar que muitos carregadores portáteis ou adaptadores simples não implementam esse sistema mecânico de detecção, o que pode comprometer o desligamento seguro.

Funcionamento segundo a norma IEC 62196
No padrão IEC 62196, comumente adotado na Europa e em outros mercados internacionais, o pino PP possui uma função adicional importante: informar a capacidade de corrente do cabo de carregamento. Isso é especialmente relevante em sistemas de carregamento com cabos destacáveis (não integrados ao carregador).

Neste caso, a identificação da capacidade do cabo é feita por meio de um resistor codificado instalado no plugue, também entre o PP e o PE. O valor da resistência indica ao veículo elétrico a corrente máxima suportada pelo cabo. Com base na medição dessa resistência (chamada Rc), o sistema do veículo pode limitar automaticamente a corrente de carregamento para evitar sobrecarga térmica ou riscos de segurança.

Por exemplo:

Um resistor de 220 Ω pode indicar uma capacidade de 32 A.

Um resistor de 480 Ω pode indicar uma capacidade de 20 A.

Assim, o pino PP no padrão IEC 62196 permite que o carregamento ocorra de forma segura e compatível com a infraestrutura disponível, contribuindo para a integridade do sistema e a segurança do usuário.



<div align="center">

[⬅️ Retroceder](analise.md) | [Avançar ➡️](implementacao.md)

</div>