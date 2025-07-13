# 🚀 Implementação

> **Nota**  
> Relatar o processo de implementação do problema, incluindo as ferramentas e bibliotecas utilizadas.

A implementação do projeto foi realizada utilizando ferramentas de desenvolvimento embarcado e de desenho eletrônico. O processo envolveu tanto a parte de software (firmware) quanto a de hardware (placa do carregador).

## 🛠️ Ferramentas Utilizadas

- **Altium Designer** – Projeto da placa de circuito impresso (PCB);
- **Proteus 8.16** – Simulação de circuitos;
- **Atmel Studio** – Desenvolvimento do firmware em C para ATmega328P;
- **Git/GitHub** – Controle de versão do projeto;
- **VS Code + PlatformIO** – Alternativa usada em testes locais;
- **Multímetro e Fonte AC** – Testes em bancada.
- **USBasp** - Programador que permite gravar firmware e bootloaders em microcontroladores AVR;

---
## 📚 Bibliotecas Utilizadas
- **avr/io.h** – Biblioteca AVR C (avr-libc) que fornece definições para acessar e controlar os pinos de entrada/saída (IO) e registradores de funções especiais (SFRs) dos microcontroladores Atmel AVR;

---

## 🖼️ Visual da Placa no Altium

<div align="center">
  <img src="img/layout_pci.png" alt="Imagem da placa desenvolvida no Altium" width="600"/>
  <img src="img/layout_pci_3d.png" alt="Imagem da placa desenvolvida no Altium" width="600"/>
  <br>
  <em>Figura: Layout da PCB desenvolvida no Altium Designer</em>
</div>

---

## 🧑‍🏭 Soldagem da PCI

<div align="center">
  <img src="img/manufatura.png" alt="" width="600"/>
  <img src="img/soldagem.png" alt="" width="600"/>
  <br>
  <em>Figura: Desenvolvimento da Soldagem da PCI</em>
</div>

---

<div align="center">

[⬅️ Retroceder](projeto.md) | [🏠 Início](analise.md)

</div>
