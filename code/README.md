# ⚙️ Instruções para Compilação e Execução do Sistema

> 🛠️ **IMPORTANTE:**  
> Para compilar e executar o programa corretamente, siga **todos os passos abaixo** na ordem indicada.

---

## 1️⃣ Baixar o `avrdude`

Baixe a ferramenta **`avrdude-6.4-mingw32`** (ou versão mais recente) através do site oficial ou repositório confiável.

Extraia a pasta em um diretório acessível.

💡 Dica: Lembre-se do caminho onde você extraiu o **`avrdude`**, pois ele será usado mais adiante.

---

## 2️⃣ Configurar o arquivo `platformio.ini`

Abra o arquivo `platformio.ini` no seu projeto e insira a seguinte configuração:

```ini
[env:ATmega328P]
platform = atmelavr
board = ATmega328P

board_build.f_cpu = 16000000UL
upload_protocol = custom
upload_flags = 
        -pm328p
        -Pusb
        -B4
        -cusbasp

upload_command = "C:\Users\lucas\Downloads\Sistema\avrdude-6.4-mingw32\avrdude.exe" $UPLOAD_FLAGS -U flash:w:$SOURCE:i
```
## 3️⃣ Configurar os Fusíveis do ATmega328P

Para utilizar o cristal externo e rodar o microcontrolador a 16 MHz, é necessário configurar corretamente os fusíveis do ATmega328P.

Crie um arquivo .bat com o conteúdo abaixo:

```ini
@echo off
echo Regravando FUSES corretos para cristal de 16 MHz...

"C:\Users\lucas\Downloads\Sistema\avrdude-6.4-mingw32\avrdude.exe" -p m328p -c usbasp ^
    -U lfuse:w:0xFF:m ^
    -U hfuse:w:0xDA:m ^
    -U efuse:w:0xFD:m

pause
```

## 4️⃣ Compilar e fazer o upload

```ini
pio run --target upload
```