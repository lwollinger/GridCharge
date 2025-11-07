# Testes

O processo de testes após a realização do software embarcado foi baseado em duas etapas:

### 1. Testes Iniciais no Software Proteus

- Teste dos LEDs de sinalização;
- Teste dos relés de controle;
- Geração do sinal PWM e mudança de estados conforme a lógica da máquina de estados J1772;
- Identificação da conexão com o sinal **Proximity Pilot**.

### 2. Testes em Bancada com o Hardware do Carregador Level 1

- Validação de todos os testes realizados no Proteus;
- Execução completa da máquina de estados no ambiente real de hardware;
- Avaliação do comportamento dos componentes em tempo real.

---
#### 2.1 Teste Estado A - Não Conectado
<div align="center">
  <img src="img/estado_a_ociloscopio.png" alt="" width="600"/>
  <img src="img/estado_a_bancada.png" alt="" width="600"/>
  <br>
  <em>Figura: Estado A</em>
</div>

--- 
#### 2.2 Teste Estado B - Conectado Não Carregando
<div align="center">
  <img src="img/estado_b_ociloscopio.png" alt="" width="600"/>
  <img src="img/estado_b_bancada.png" alt="" width="600"/>
  <br>
  <em>Figura: Estado B</em>
</div>

--- 
#### 2.3 Teste Estado C - Carregando
<div align="center">
  <img src="img/estado_c_ociloscopio.png" alt="" width="600"/>
  <img src="img/estado_c_bancada.png" alt="" width="600"/>
  <br>
  <em>Figura: Estado C</em>
</div>

---
#### 2.4 Teste Estado E - Desernegizado
<div align="center">
  <img src="img/estado_E_ociloscopio.png" alt="" width="600"/>
  <img src="img/estado_e_bancada.png" alt="" width="600"/>
  <br>
  <em>Figura: Estado E</em>
</div>

---
### 3. Resultado Final
<div align="center">
  <img src="img/estado_geral_bancada.png" alt="" width="600"/>
  <br>
  <em>Figura: Estado C com Acionando os Relés</em>
</div>

--- 
<div align="center">

[⬅️ Retroceder](implementacao.md) | [🏠 Início](README.md)

</div>
