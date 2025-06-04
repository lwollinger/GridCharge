# ⚙️ Instruções para Compilação e Execução do Sistema

> 🛠️ **IMPORTANTE:**  
> Para compilar e executar o programa corretamente, siga **todos os passos abaixo** na ordem indicada.

---

## 1️⃣ Baixar o `avrdude`

Baixe a ferramenta **`avrdude-6.4-mingw32`** (ou versão mais recente) através do site oficial ou repositório confiável.

Extraia a pasta em um diretório acessível.

Obs: Lembre-se onde foi baixado o seu **`avrdude`**

---

## 2️⃣ Configurar o arquivo `platformio.ini`

Abra o arquivo `platformio.ini` no seu projeto e insira a seguinte configuração:

```ini
[env:ATmega328P]
platform = atmelavr
board = ATmega328P

board_build.f_cpu = 1000000UL

upload_protocol = custom
upload_flags = 
    -pm328p
    -Pusb
    -B4
    -cusbasp

upload_command = "C:\\Users\\SeuDiretório\\avrdude-6.4-mingw32\\avrdude.exe" $UPLOAD_FLAGS -U flash:w:$SOURCE:i
```

## 3️⃣ Compilar e fazer o upload

```ini
pio run --target upload
```