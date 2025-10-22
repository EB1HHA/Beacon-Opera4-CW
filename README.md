# Beacon Opera4 and CW

Baliza para Opera4 y CW utilizando un ESP01 o Arduino y un Si5351 como oscilador.

## Descripción

Este proyecto implementa una baliza de radio que puede transmitir en modo Opera4 y CW (Código Morse) utilizando un microcontrolador ESP01 o Arduino junto con un oscilador Si5351.

## Características

- **Soporte para Opera4**: Transmisión de mensajes en modo Opera4 (4-FSK)
- **Soporte para CW**: Transmisión de mensajes en código Morse
- **Control de frecuencia**: Generación precisa de frecuencias mediante Si5351
- **Bajo consumo**: Ideal para balizas autónomas
- **Fácil configuración**: Comunicación I2C simple

## Hardware Requerido

- ESP01 (ESP8266) o Arduino (Uno, Nano, etc.)
- Si5351 Breakout Board
- Fuente de alimentación 3.3V
- Cables de conexión
- (Opcional) Amplificador y filtro de RF

## Conexiones Hardware

La comunicación entre el oscilador Si5351 y el microcontrolador se hace mediante el BUS I2C:

```
Si5351          ESP01
VCC ........... 3.3V
GND ........... GND
SDA ........... GPIO0
SCL ........... GPIO2
```

Para más detalles, consulta el archivo `circuit_diagram.txt`.

## Instalación

### Requisitos Previos

1. Arduino IDE 1.8.x o superior
2. Biblioteca Si5351 de Etherkit
3. Para ESP01: Soporte de placa ESP8266

Ver `README_DEPENDENCIES.md` para instrucciones detalladas de instalación.

### Pasos de Instalación

1. Clona este repositorio:
   ```bash
   git clone https://github.com/EB1HHA/Beacon-Opera4-CW.git
   ```

2. Instala las bibliotecas necesarias:
   - En Arduino IDE: Tools -> Manage Libraries -> Buscar "Si5351" -> Instalar "Etherkit Si5351"

3. Abre `Beacon-Opera4-CW.ino` en Arduino IDE

4. Selecciona tu placa:
   - Para ESP01: Tools -> Board -> ESP8266 Boards -> Generic ESP8266 Module
   - Para Arduino: Tools -> Board -> Arduino AVR Boards -> Arduino Uno/Nano

5. Conecta tu dispositivo y haz clic en Upload

## Configuración

### Cambiar la Frecuencia

Edita la línea en el código:
```cpp
#define DEFAULT_FREQUENCY   7000000ULL  // 7 MHz para banda de 40m
```

### Seleccionar Modo

Cambia entre Opera4 y CW modificando:
```cpp
uint8_t beaconMode = BEACON_MODE_OPERA4;  // o BEACON_MODE_CW
```

### Ajustar Timing CW

Modifica las constantes de tiempo para ajustar la velocidad del código Morse:
```cpp
#define CW_DOT_TIME         100    // Duración del punto (ms)
#define CW_DASH_TIME        300    // Duración de la raya (ms)
```

## Uso

1. Conecta el hardware según el diagrama de conexiones
2. Alimenta el circuito con 3.3V
3. El sistema iniciará automáticamente
4. Observa el monitor serial (115200 baud) para mensajes de debug
5. La baliza transmitirá periódicamente según el modo seleccionado

## Modos de Operación

### Opera4
- Transmisión de 16 símbolos
- 4 segundos por símbolo
- Modulación 4-FSK
- Total: ~64 segundos por mensaje

### CW (Código Morse)
- Ejemplo: Transmite "CQ"
- Velocidad configurable
- Compatible con estándares de código Morse

## Mejoras y Optimización

Posteriormente esta señal se puede amplificar y filtrar en función de las frecuencias seleccionadas para mejorar y optimizar su funcionamiento:

- **Amplificador**: Clase A o AB con transistores 2N3904, 2N2222
- **Filtro Paso Bajo**: 7 polos Chebyshev según la banda
- **Blindaje RF**: Recomendado para operación estable
- **Plano de tierra**: Mejora la estabilidad

## Características Técnicas

- **Rango de Frecuencia**: 8 kHz - 160 MHz (limitado por Si5351)
- **Resolución de Frecuencia**: 0.01 Hz
- **Consumo**: <100 mA típico
- **Voltaje**: 3.3V
- **Interface**: I2C (400 kHz máx)

## Troubleshooting

### "Si5351 not found"
- Verifica las conexiones I2C
- Comprueba la alimentación 3.3V
- Añade resistencias pull-up de 4.7kΩ en SDA y SCL si es necesario

### Error de compilación
- Verifica que la biblioteca Si5351 esté instalada
- Asegúrate de haber seleccionado la placa correcta

### ESP01 no sube el sketch
- Durante la carga, GPIO0 debe estar a LOW (modo boot)
- Usa un adaptador USB-Serial de 3.3V

## Contribuciones

Las contribuciones son bienvenidas. Por favor:
1. Fork el proyecto
2. Crea una rama para tu feature
3. Commit tus cambios
4. Push a la rama
5. Abre un Pull Request

## Licencia

Este proyecto está licenciado bajo GPL v3. Ver archivo LICENSE para más detalles.

## Autor

**EB1HHA**

## Referencias

- [Si5351 Library](https://github.com/etherkit/Si5351Arduino)
- [Opera4 Protocol](https://www.physics.princeton.edu/pulsar/k1jt/opera.html)
- [Morse Code Standard](https://en.wikipedia.org/wiki/Morse_code)

## Agradecimientos

- Jason Milldrum (NT7S) por la excelente biblioteca Si5351
- Comunidad radioaficionada por el soporte y documentación
