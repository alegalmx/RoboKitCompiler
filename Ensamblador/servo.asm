LIST P=16F887
INCLUDE <P16F887.INC>
__CONFIG _CONFIG1, _FOSC_INTRC_NOCLKOUT & _WDTE_OFF & _PWRTE_OFF & _LVP_OFF

CBLOCK  0x20
highfactor1
timer0_counter1
highfactor2
timer0_counter2
highfactor3 ; Nueva variable para Servo3
timer0_counter3 ; Nueva variable para Servo3
ENDC

TMR0_LOAD equ   .164 ; Valor aproximado para 100 us de temporización.

#define OUTPUT1 PORTB,0 ; Renombrar RB0 como OUTPUT1 (Servo Motor 1)
#define OUTPUT2 PORTB,1 ; Renombrar RB1 como OUTPUT2 (Servo Motor 2)
#define OUTPUT3 PORTB,2 ; Nueva definición para OUTPUT3 (Servo Motor 3)
 
#define LED PORTC,2 ; Foco Afuera
#define LED_MiniSplit PORTC, 3 ; MiniSplit
#define LED_Sala PORTC, 4 ; MiniSplit

#define INPUT1  PORTA,0 ; Renombrar RA0 como INPUT1
#define INPUT2  PORTA,1 ; Renombrar RA1 como INPUT2
#define INPUT3  PORTA,2 ; Renombrar RA2 como INPUT3
#define INPUT4  PORTA,3 ; Renombrar RA3 como INPUT4

org     0x00  
goto    Main
org     0x04
goto    TIMER0_Interrupt ; Vector de interrupción.

Main
    bsf STATUS,6 ; Seleccionar banco 3.
    bsf STATUS,5
    clrf ANSEL ; PORTA y PORTB funcionan digitalmente,
    clrf ANSELH
    movlw 0xD8
    movwf OPTION_REG ; La frecuencia del TIMER0 es igual a Fosc/4, prescaler para WDT.
    bcf STATUS,6 ; Seleccionar banco 1.
    movlw 0x61
    movwf OSCCON ; Oscilador interno predeterminado de 4MHz
    bcf TRISB,0 ; RB0 funciona como salida para el Servo Motor 1.
    bcf TRISB,1 ; RB1 funciona como salida para el Servo Motor 2.
    bcf TRISB,2 ; RB2 funciona como salida para el Servo Motor 3.
    bcf	TRISC,2
    bcf TRISC,3
    bcf	TRISC,4
    bcf STATUS,5 ; seleccionar el banco 0.
    clrf PORTB
    clrf PORTC
    movlw TMR0_LOAD
    movwf TMR0 ; TIMER0 es igual a 164.
    movlw 0xA0
    movwf INTCON ; GIE = 1 e interrupción de desbordamiento del Timer0
    ;bsf LED ; Enciende el LED
    Loop
movlw .22          ; Puerta
    movwf highfactor1
    movlw 0xFF
    movwf timer0_counter1 ; Establecer timer0_counter1 al valor máximo
movlw .5           ; vantana1
    movwf highfactor2
    movlw 0xFF
    movwf timer0_counter2 ; Establecer timer0_counter1 al valor máximo
movlw .22           ; venana2
    movwf highfactor3
    movlw 0xFF
    movwf timer0_counter3 ; Establecer timer0_counter1 al valor máximo
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
movlw .5           ; Puerta
    movwf highfactor1
    movlw 0xFF
    movwf timer0_counter1 ; Establecer timer0_counter1 al valor máximo
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
bsf LED_MiniSplit 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
bsf LED_Sala 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
bsf LED 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
call  Delay_1s 
movlw .22          ; Puerta
    movwf highfactor1
    movlw 0xFF
    movwf timer0_counter1 ; Establecer timer0_counter1 al valor máximo
bcf LED 
bcf LED_Sala 
bcf LED_MiniSplit 
Goto Loop
TIMER0_Interrupt
    movlw TMR0_LOAD ; Load TIMER0 with the value of TMR0_LOAD
    movwf TMR0
    ; Servo Motor 1
    decfsz timer0_counter1 ; Decrements by one unit, jump if it's zero
    goto Servo1 ; Go to Servo1
    btfsc OUTPUT1 ; Complements the value of OUTPUT1.
    goto HighS1
    
LowS1 ; Set OUTPUT1 to zero.
    bsf OUTPUT1
    movf highfactor1,W ; Time the signal is high.
    movwf timer0_counter1
    goto Servo1

HighS1
    bcf OUTPUT1 ; Set OUTPUT1 to one.
    movf highfactor1,W
    sublw .200 ; Time the signal is low.
    movwf timer0_counter1
    goto Servo1

Servo1
    ; Servo Motor 2
    decfsz timer0_counter2 ; Decrements by one unit, jump if it's zero
    goto Servo2 ; Go to Servo2
    btfsc OUTPUT2 ; Complements the value of OUTPUT2.
    goto HighS2
    
LowS2 ; Set OUTPUT2 to zero.
    bsf OUTPUT2
    movf highfactor2,W ; Time the signal is high.
    movwf timer0_counter2
    goto Servo2

HighS2
    bcf OUTPUT2 ; Set OUTPUT2 to one.
    movf highfactor2,W
    sublw .200 ; Time the signal is low.
    movwf timer0_counter2
    goto Servo2

Servo2
    ; Servo Motor 3
    decfsz timer0_counter3 ; Decrements by one unit, jump if it's zero
    goto EndInterrupt ; Go to EndInterrupt
    btfsc OUTPUT3 ; Complements the value of OUTPUT3.
    goto HighS3
    
LowS3 ; Set OUTPUT3 to zero.
    bsf OUTPUT3
    movf highfactor3,W ; Time the signal is high.
    movwf timer0_counter3
    goto EndInterrupt

HighS3
    bcf OUTPUT3 ; Set OUTPUT3 to one.
    movf highfactor3,W
    sublw .200 ; Time the signal is low.
    movwf timer0_counter3
    goto EndInterrupt

EndInterrupt
    bcf INTCON,2 ; Clear interrupt bit of TIMER0.
    retfie
    INCLUDE <C:\Users\Alex\Downloads\DELAYS.inc>
    END ; Linea de fin