# Amplificador y Filtro Opcional - Optional Amplifier and Filter

## Español

### Amplificador de RF Clase A Simple

Este diseño amplifica la señal del Si5351 (~2-8mA) a un nivel más útil (~100mW).

#### Componentes Necesarios
- Transistor: 2N3904, 2N2222 o similar (NPN)
- Resistencias: 10kΩ, 1kΩ, 100Ω
- Condensadores: 100nF (2x), 10µF
- Inductor: según banda (ver tabla)
- Transformador RF: Toroide FT37-43 o similar

#### Esquema Básico
```
        VCC (+12V)
         |
         R1 (1kΩ)
         |
    C1   |   C2
  --||---+---||--- RF Out
         |
      B -|- C
    ----|  |----
      E -|- 
         |
        R2 (100Ω)
         |
        GND

R1: Resistencia de colector
R2: Resistencia de emisor
C1, C2: Acoplo de entrada/salida
```

### Filtro Paso Bajo (LPF)

Para eliminar armónicos y cumplir con regulaciones:

#### Diseño 7-polos Chebyshev

**Para 40m (7 MHz):**
- L1, L3, L5: 2.2 µH
- C2, C4: 470 pF
- C1, C3, C5: 220 pF

**Para 20m (14 MHz):**
- L1, L3, L5: 1.0 µH
- C2, C4: 220 pF
- C1, C3, C5: 100 pF

```
IN ---L1---+---L2---+---L3--- OUT
           |        |
          C1       C2
           |        |
          GND      GND
```

### Construcción Práctica

1. **Usar placa de circuito impreso**
   - Doble cara con plano de tierra
   - Componentes SMD si es posible

2. **Montaje en caja metálica**
   - Blindaje RF completo
   - Conectores SMA o BNC

3. **Ajuste y Prueba**
   - Medir potencia de salida
   - Verificar armónicos con analizador de espectro
   - Ajustar filtro para mínimas pérdidas

### Especificaciones Típicas

- **Ganancia**: 10-15 dB
- **Potencia de salida**: 50-100 mW
- **Atenuación armónicos**: >40 dB
- **Impedancia**: 50Ω

---

## English

### Simple Class A RF Amplifier

This design amplifies the Si5351 signal (~2-8mA) to a more useful level (~100mW).

#### Required Components
- Transistor: 2N3904, 2N2222 or similar (NPN)
- Resistors: 10kΩ, 1kΩ, 100Ω
- Capacitors: 100nF (2x), 10µF
- Inductor: according to band (see table)
- RF Transformer: FT37-43 toroid or similar

#### Basic Schematic
```
        VCC (+12V)
         |
         R1 (1kΩ)
         |
    C1   |   C2
  --||---+---||--- RF Out
         |
      B -|- C
    ----|  |----
      E -|- 
         |
        R2 (100Ω)
         |
        GND

R1: Collector resistor
R2: Emitter resistor
C1, C2: Input/output coupling
```

### Low Pass Filter (LPF)

To eliminate harmonics and comply with regulations:

#### 7-pole Chebyshev Design

**For 40m (7 MHz):**
- L1, L3, L5: 2.2 µH
- C2, C4: 470 pF
- C1, C3, C5: 220 pF

**For 20m (14 MHz):**
- L1, L3, L5: 1.0 µH
- C2, C4: 220 pF
- C1, C3, C5: 100 pF

```
IN ---L1---+---L2---+---L3--- OUT
           |        |
          C1       C2
           |        |
          GND      GND
```

### Practical Construction

1. **Use PCB**
   - Double-sided with ground plane
   - SMD components if possible

2. **Metal enclosure mounting**
   - Complete RF shielding
   - SMA or BNC connectors

3. **Adjustment and Testing**
   - Measure output power
   - Verify harmonics with spectrum analyzer
   - Adjust filter for minimum loss

### Typical Specifications

- **Gain**: 10-15 dB
- **Output power**: 50-100 mW
- **Harmonic attenuation**: >40 dB
- **Impedance**: 50Ω
