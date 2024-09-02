;***********************************Librery "Delays.INC"*********************
;Autor: Ing. Marcos Becerra Zárate.
;Frecuency oscillator: 4Mhz.
;
;This library contain subroutines of time,starting with:
;   -4 us.	    -500 ms.
;   -5 us.	    -1 s.
;   -10 us.	    -2 s.
;   -20 us.	    -5 s.
;   -50 us.	    -10 s.
;   -100 us.	    -20 s.
;   -200 us.	    
;   -500 us.
;   -1 ms.
;   -2 ms.
;   -5 ms.
;   -10 ms.
;   -20 ms.
;   -50 ms.
;   -100 ms.
;   -200 ms.

;Data area**********************************************************************

	CBLOCK
	T1
	T2
	T3
	ENDC

;Delay from 4 to 10 us----------------------------------------------------------
	
	Delay_10us				;Provides 2 machine cicle.
	nop					;Provides 1 machine cicle.
	nop					;Provides 1 machine cicle.
	nop					;Provices 1 machine cicle.
	nop					;Provices 1 machine cicle.
	nop					;Provices 1 machine cicle.
	Delay_5us				;Provides 2 machine cicle.
	nop					;Provides 1 machine cicle.
	Delay_4us				;Provides 2 machine cicle.
	return					;Provides 2 machine cicle.

;Delay 20 to 500 us-------------------------------------------------------------

	Delay_500us				;Provides 2 machine cicle.
	movlw	d'123'				;Provides 1 machine cicle.
	movwf	T1				;Provides 1 machine cicle.
	nop					;Provides 1 machine cicle.
	goto	Bucle_Interno_us		;Provides 2 machine cicle.
	
	Delay_200us				;Provides 2 machine cicle.
	movlw	d'48'				;Provides 1 machine cicle.
	movwf	T1				;Provides 1 machine cicle.
	nop					;Provides 1 machine cicle.
	goto	Bucle_Interno_us		;Provides 2 machine cicle.
	
	Delay_100us				;Provides 2 machine cicle.
	movlw	d'23'				;Provides 1 machine cicle.
	movwf	T1				;Provides 1 machine cicle.
	nop					;Provides 1 machine cicle.
	goto	Bucle_Interno_us		;Provides 2 machine cicle.
	
	Delay_50us				;Provides 2 machine cicle.
	movlw	d'10'				;Provides 1 machine cicle.
	movwf	T1				;Provides 1 machine cicle.
	nop					;Provides 1 machine cicle.
	nop					;Provides 1 machine cicle.
	nop					;Provides 1 machine cicle.
	goto	Bucle_Interno_us		;Provides 2 machine cicle.
	
	Delay_20us				;Provides 2 machine cicle.
	movlw	d'3'				;Provides 1 machine cicle.
	movwf	T1				;Provides 1 machine cicle.
	nop					;Provides 1 machine cicle.
	nop					;Provides 1 machine cicle.
	nop					;Provides 1 machine cicle.

 Bucle_Interno_us					
	nop					;Provides 1 machine cicle.
	decfsz	T1,F				;Provides 1 machine cicle and 2.
	goto	Bucle_Interno_us		;Provides 2 machine cicle.
	return					;Provides 2 machine cicle.
	
;Delay 1 to 200 ms--------------------------------------------------------------
	
	Delay_200ms				;Provides 2 machine cicle.
	movlw	d'200'				;Provides 1 machine cicle.
	movwf	T2				;Provides 1 machine cicle.
	goto	Bucle_Externo_ms		;Provides 2 machine cicle.
	
	Delay_100ms				;Provides 2 machine cicle.
	movlw	d'100'				;Provides 1 machine cicle.
	movwf	T2				;Provides 1 machine cicle.
	goto	Bucle_Externo_ms		;Provides 2 machine cicle.
	
	Delay_50ms				;Provides 2 machine cicle.
	movlw	d'50'				;Provides 1 machine cicle.
	movwf	T2				;Provides 1 machine cicle.
	goto	Bucle_Externo_ms		;Provides 2 machine cicle.
	
	Delay_20ms				;Provides 2 machine cicle.
	movlw	d'20'				;Provides 1 machine cicle.
	movwf	T2				;Provides 1 machine cicle.
	goto	Bucle_Externo_ms		;Provides 2 machine cicle.
	
	Delay_10ms				;Provides 2 machine cicle.
	movlw	d'10'				;Provides 1 machine cicle.
	movwf	T2				;Provides 1 machine cicle.
	goto	Bucle_Externo_ms		;Provides 2 machine cicle.
	
	Delay_5ms				;Provides 2 machine cicle.
	movlw	d'5'				;Provides 1 machine cicle.
	movwf	T2				;Provides 1 machine cicle.
	goto	Bucle_Externo_ms		;Provides 2 machine cicle.
	
	Delay_2ms				;Provides 2 machine cicle.
	movlw	d'2'				;Provides 1 machine cicle.
	movwf	T2				;Provides 1 machine cicle.
	goto	Bucle_Externo_ms		;Provides 2 machine cicle.
	
	
	Delay_1ms				;Provides 2 machine cicle.
	movlw	d'1'				;Provides 1 machine cicle.
	movwf	T2				;Provides 1 machine cicle.
	
Bucle_Externo_ms					
	movlw	d'249'				;Provides 1 machine cicle.
	movwf	T1				;Provides 1 machine cicle.
	
Bucle_Interno_ms
	nop					;Provides 1 machine cicle.
	decfsz	T1,F				;Provides 1 machine cicle and 2.
	goto	Bucle_Interno_ms		;Provides 2 machine cicle.
	decfsz	T2,F				;Provides 1 machine cicle and 2.
	goto	Bucle_Externo_ms		;Provides 2 machine cicle.
	return					;Provides 2 machine cicle.

;Delay 500 ms to 20 seconds-----------------------------------------------------
	
	Delay_20s				;Provides 2 machine cicle.
	movlw	d'200'				;Provides 1 machine cicle.  
	movwf	T3				;Provides 1 machine cicle.
	goto	Loop_Second			;Provides 2 machine cicle.
	
	Delay_10s				;Provides 2 machine cicle.
	movlw	d'100'				;Provides 1 machine cicle.  
	movwf	T3				;Provides 1 machine cicle.
	goto	Loop_Second			;Provides 2 machine cicle.
	
	Delay_5s				;Provides 2 machine cicle.
	movlw	d'50'				;Provides 1 machine cicle.  
	movwf	T3				;Provides 1 machine cicle.
	goto	Loop_Second			;Provides 2 machine cicle.
	
	Delay_2s				;Provides 2 machine cicle.
	movlw	d'20'				;Provides 1 machine cicle.  
	movwf	T3				;Provides 1 machine cicle.
	goto	Loop_Second			;Provides 2 machine cicle.
	
	Delay_1s				;Provides 2 machine cicle.
	movlw	d'10'				;Provides 1 machine cicle.  
	movwf	T3				;Provides 1 machine cicle.
	goto	Loop_Second			;Provides 2 machine cicle.
	
	Delay_500ms				;Provides 2 machine cicle.
	movlw	d'5'				;Provides 1 machine cicle.  
	movwf	T3				;Provides 1 machine cicle.
	
Loop_Second
	movlw	d'100'				;Provides 1 machine cicle.
	movwf	T2				;Provides 1 machine cicle.
	
Loop_First	    
	movlw	d'249'				;Provides 1 machine cicle.
	movwf	T1				;Provides 1 machine cicle.
	
Bucle_Interno
	nop
	decfsz	T1,F				;Provides 1 and 2 machine cicle.
	goto	Bucle_Interno			;Provides 2 machine cicle.
	decfsz	T2,F				;Provides 1 and 2 machine cicle.
	goto	Loop_First			;Provides 2 machine cicle.
	decfsz	T3,F				;Provides 1 and 2 machine cicle.
	goto	Loop_Second			;Provides 2 machine cicle.
	return					;Provides 2 machine cicle.