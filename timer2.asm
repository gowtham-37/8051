ORG 0000H        ; Origin, program start address

START:
    CLR P1.1      ; Turn ON LED (Assuming active low LED configuration)
    ACALL DELAY

    SETB P1.1    ; Turn OFF LED
    ACALL DELAY

    SJMP START    ; Repeat forever

;----------------------
; Delay Subroutine
;----------------------
DELAY:
    MOV R1, #5
DELAY1:
    MOV R2, #200
DELAY2:
    MOV R3, #230
DELAY3:
    DJNZ R3, DELAY3
    DJNZ R2, DELAY2
    DJNZ R1, DELAY1
    RET

END
