# Guía de Inicio Rápido - Quick Start Guide

## Español

### Montaje Rápido

1. **Conectar el Hardware**
   ```
   Si5351 -> ESP01
   VCC    -> 3.3V
   GND    -> GND
   SDA    -> GPIO0
   SCL    -> GPIO2
   ```

2. **Instalar Arduino IDE**
   - Descargar de https://www.arduino.cc/en/software
   - Instalar soporte para ESP8266
   - Instalar biblioteca "Etherkit Si5351"

3. **Configurar**
   - Abrir `Beacon-Opera4-CW.ino`
   - Modificar frecuencia si es necesario (línea ~17)
   - Seleccionar modo: Opera4 o CW (línea ~23)

4. **Subir el Código**
   - Conectar ESP01 con adaptador USB-Serial
   - Poner GPIO0 a GND para modo programación
   - Subir sketch
   - Quitar conexión GPIO0-GND
   - Reset ESP01

5. **Verificar Funcionamiento**
   - Abrir monitor serial (115200 baud)
   - Verificar mensajes de inicialización
   - Verificar salida RF con osciloscopio o receptor

### Frecuencias Recomendadas

- **40m**: 7.000 - 7.040 MHz
- **30m**: 10.140 MHz (específico para Opera4)
- **20m**: 14.000 - 14.070 MHz

### Solución de Problemas

**Error "Si5351 not found"**
- Verificar conexiones
- Verificar voltaje 3.3V
- Añadir resistencias pull-up 4.7kΩ

**No sube el sketch**
- GPIO0 debe estar a GND durante programación
- Usar adaptador 3.3V (NO 5V)

---

## English

### Quick Assembly

1. **Connect Hardware**
   ```
   Si5351 -> ESP01
   VCC    -> 3.3V
   GND    -> GND
   SDA    -> GPIO0
   SCL    -> GPIO2
   ```

2. **Install Arduino IDE**
   - Download from https://www.arduino.cc/en/software
   - Install ESP8266 support
   - Install "Etherkit Si5351" library

3. **Configure**
   - Open `Beacon-Opera4-CW.ino`
   - Modify frequency if needed (line ~17)
   - Select mode: Opera4 or CW (line ~23)

4. **Upload Code**
   - Connect ESP01 with USB-Serial adapter
   - Pull GPIO0 to GND for programming mode
   - Upload sketch
   - Remove GPIO0-GND connection
   - Reset ESP01

5. **Verify Operation**
   - Open serial monitor (115200 baud)
   - Check initialization messages
   - Verify RF output with oscilloscope or receiver

### Recommended Frequencies

- **40m**: 7.000 - 7.040 MHz
- **30m**: 10.140 MHz (specific for Opera4)
- **20m**: 14.000 - 14.070 MHz

### Troubleshooting

**"Si5351 not found" error**
- Check connections
- Verify 3.3V voltage
- Add 4.7kΩ pull-up resistors

**Upload fails**
- GPIO0 must be pulled to GND during programming
- Use 3.3V adapter (NOT 5V)
