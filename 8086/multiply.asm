DATA SEGMENT
    MSG1 DB 10,13,'Enter first hex number (0-FF): $'
    MSG2 DB 10,13,'Enter second hex number (0-FF): $'
    MSG3 DB 10,13,'Product in decimal is: $'
    MSG4 DB 10,13,'Overflow occurred!$'
    NUM1 DB ?
    NUM2 DB ?
    RESULT DW ?
    TEMP DB 5 DUP('$')
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
    
START:
    MOV AX, DATA
    MOV DS, AX
    
    ; Display first message
    LEA DX, MSG1
    MOV AH, 09H
    INT 21H
    
    ; Input first hex number
    CALL INPUT_HEX
    MOV NUM1, AL
    
    ; Display second message
    LEA DX, MSG2
    MOV AH, 09H
    INT 21H
    
    ; Input second hex number
    CALL INPUT_HEX
    MOV NUM2, AL
    
    ; Multiply numbers
    MOV AL, NUM1
    MUL NUM2        ; Result in AX
    MOV RESULT, AX
    
    ; Check for overflow (if AH != 0)
    CMP AH, 0
    JNE OVERFLOW
    
    ; Display result message
    LEA DX, MSG3
    MOV AH, 09H
    INT 21H
    
    ; Convert result to decimal
    MOV AX, RESULT
    CALL DECIMAL_OUT
    JMP EXIT
    
OVERFLOW:
    LEA DX, MSG4
    MOV AH, 09H
    INT 21H

EXIT:
    MOV AH, 4CH
    INT 21H

; Subroutine to input hex number
INPUT_HEX PROC
    XOR BX, BX      ; Clear BX
    MOV CX, 2       ; Counter for 2 digits
    
INPUT_NEXT:
    MOV AH, 01H
    INT 21H
    
    CMP AL, 0DH     ; Check for Enter key
    JE DONE_INPUT
    
    CMP AL, '0'
    JL INPUT_NEXT
    CMP AL, '9'
    JLE NUMERIC
    
    CMP AL, 'A'
    JL INPUT_NEXT
    CMP AL, 'F'
    JLE LETTER
    
    CMP AL, 'a'
    JL INPUT_NEXT
    CMP AL, 'f'
    JLE SMALL_LETTER
    JMP INPUT_NEXT

NUMERIC:
    SUB AL, '0'
    JMP PROCESS

LETTER:
    SUB AL, 'A'
    ADD AL, 10
    JMP PROCESS

SMALL_LETTER:
    SUB AL, 'a'
    ADD AL, 10

PROCESS:
    MOV CL, 4
    SHL BL, CL
    OR BL, AL
    DEC CX
    JNZ INPUT_NEXT

DONE_INPUT:
    MOV AL, BL
    RET
INPUT_HEX ENDP

; Subroutine to output decimal number
DECIMAL_OUT PROC
    LEA SI, TEMP
    ADD SI, 4       ; Point to end of buffer
    
CONVERT_LOOP:
    XOR DX, DX
    MOV BX, 10
    DIV BX          ; Divide AX by 10
    ADD DL, '0'     ; Convert remainder to ASCII
    DEC SI
    MOV [SI], DL
    
    ; Continue if quotient is not zero
    CMP AX, 0
    JNE CONVERT_LOOP
    
DISPLAY_LOOP:
    MOV DL, [SI]
    CMP DL, '$'     ; Check for end of string
    JE DISPLAY_DONE
    MOV AH, 02H
    INT 21H
    INC SI
    JMP DISPLAY_LOOP
    
DISPLAY_DONE:
    RET
DECIMAL_OUT ENDP

CODE ENDS
END START