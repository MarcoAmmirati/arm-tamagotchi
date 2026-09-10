# ARM Tamagotchi — Embedded Virtual Pet su LPC1768

Progetto individuale realizzato per il corso di **Architetture dei Sistemi di Elaborazione** (Politecnico di Torino). Implementa un "Tamagotchi" virtuale — un animaletto digitale interattivo — su un microcontrollore ARM Cortex-M3, sviluppato e testato su **scheda fisica LANDTIGER** (LPC1768), non solo in emulazione.

Il progetto corrisponde alla consegna "Extra Point #2", versione finale ed estesa di una prima implementazione base: aggiunge interazione tramite touchscreen, effetti sonori e controllo del volume.

## Cosa fa

- Un personaggio virtuale ("Mooncake") si muove sullo schermo GLCD e reagisce alle azioni dell'utente
- **Movimento** controllabile via joystick
- **Alimentazione**: menu Meal/Snack che modifica i livelli di sazietà (satiety) e felicità (happiness) del personaggio
- **Coccole via touchscreen**: toccando il personaggio sul touch panel si attiva un'animazione dedicata che aumenta la felicità
- **Effetti sonori** su ogni animazione principale (click dei menu, pasto, coccole, morte/fuga del personaggio)
- **Controllo del volume** tramite potenziometro, letto via ADC campionando ogni 50 ms
- Invecchiamento del personaggio nel tempo, gestito tramite timer hardware

## Architettura e concetti implementati

Il progetto è stato l'occasione per applicare concreamente concetti di architettura dei sistemi embedded:

- **Gestione degli interrupt**: interrupt handler dedicati per timer, RIT (Repetitive Interrupt Timer), pulsanti (EXINT) e ADC
- **Timer multipli** per orchestrare in parallelo: animazione base, invecchiamento del personaggio ogni secondo, ed eventi periodici a granularità più fine (50 ms)
- **Comunicazione con periferiche esterne**: display GLCD via bus parallelo, touch panel resistivo, joystick analogico, ADC per il potenziometro del volume
- **Programmazione low-level su registri di periferica** (accesso diretto ai registri del microcontrollore LPC17xx, senza librerie di alto livello)
- **Vincoli di sincronizzazione**: ad esempio, il RIT (che rileva il tocco sul touchscreen) viene disabilitato durante altre animazioni per evitare sovrapposizioni, e riabilitato al termine

Il documento [`docs/Application Note.pdf`](docs/Application%20Note.pdf) descrive in dettaglio, in stile tecnico, l'implementazione dell'animazione delle coccole (gestione degli interrupt RIT/Timer0 coinvolti).

## Struttura del repository

```
├── src/
│   ├── sample.c              # Entry point, inizializzazione periferiche e timer
│   ├── functions.c/.h        # Logica del gioco: menu, animazioni, stati del personaggio
│   ├── core_cm3.c            # Core ARM Cortex-M3 (CMSIS)
│   ├── system_LPC17xx.c      # Inizializzazione di sistema (clock, PLL)
│   ├── startup_LPC17xx.s     # Startup assembly del microcontrollore
│   ├── adc/                  # Lettura ADC (potenziometro volume)
│   ├── button_EXINT/         # Gestione interrupt esterni sui pulsanti
│   ├── joystick/              # Input joystick e movimento del personaggio
│   ├── led/                   # Gestione LED
│   ├── RIT/                    # Repetitive Interrupt Timer (rilevamento tocco)
│   ├── timer/                  # Timer hardware (animazioni, invecchiamento)
│   ├── TouchPanel/             # Driver del touch panel resistivo
│   └── GLCD/                   # Driver del display grafico e libreria font
├── keil_project/
│   ├── sample.uvprojx         # Progetto Keil µVision
│   └── sample.sct              # Scatter file (memory layout del linker)
└── docs/
    ├── ExtraPoint2.pdf         # Specifica della consegna
    ├── Application Note.pdf    # Approfondimento tecnico sull'animazione coccole
    └── hardware_setup.jpg       # Foto del setup hardware
```

## Come compilarlo/eseguirlo

Richiede [Keil µVision (MDK-ARM)](https://www.keil.com/) con supporto per Cortex-M3.

1. Aprire `keil_project/sample.uvprojx` in Keil µVision
2. Collegare la scheda LANDTIGER (LPC1768) via debugger J-Link, oppure configurare il simulatore integrato
3. Compilare (Build) e caricare (Flash/Download) sulla scheda
4. All'accensione, il personaggio appare sul display GLCD ed è pronto per l'interazione

## Stack tecnico

`C` · `ARM Cortex-M3 (LPC1768)` · `Keil µVision / MDK-ARM` · `CMSIS` · Programmazione bare-metal su registri di periferica

## Note

Questo progetto è stato sviluppato nell'ambito di un corso universitario e ha finalità didattiche. Il template di base del progetto Keil (struttura cartelle, driver GLCD/TouchPanel di libreria) è stato fornito nel materiale del corso; la logica del Tamagotchi, la gestione delle animazioni, l'integrazione touchscreen/audio/volume e la relativa documentazione tecnica sono lavoro originale.
