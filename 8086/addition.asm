.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 13,10, 'ENTER FIRST NUMBER: $'
MSG2 DB 13,10, 'ENTER SECOND NUMBER: $'
MSG3 DB 'SUM= $'
OVER DB 'OVERFLOW OCCURED!$'
NL DB 0DH,0AH,'$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    LEA DX, MSG1
    MOV AH, 9
    INT 21H
    
    CALL HEX_INPUT    
    MOV BH, AL        
    
    LEA DX, NL
    MOV AH, 9
    INT 21H
    
    LEA DX, MSG2
    MOV AH, 9
    INT 21H
    
    CALL HEX_INPUT    
    MOV BL, AL        
    
    LEA DX, NL
    MOV AH, 9
    INT 21H
    
    LEA DX, MSG3
    MOV AH, 9
    INT 21H
    
    MOV AL, BH       
    ADD AL, BL      
    JC OVERFLOW       
    
    MOV CL, AL
    
    XOR AX, AX      
    MOV AL, CL     
    
    MOV CX, 0      
    MOV BX, 10  
    
CONVERT:
    XOR DX, DX       
    DIV BX           
    PUSH DX          
    INC CX          
    TEST AX, AX      
    JNZ CONVERT     
    
DISPLAY:
    POP DX           
    ADD DL, '0'     
    MOV AH, 2       
    INT 21H
    LOOP DISPLAY    
    
    JMP EXIT

OVERFLOW:
    LEA DX, OVER
    MOV AH, 9
    INT 21H

EXIT:
    MOV AH, 4CH
    INT 21H
MAIN ENDP

HEX_INPUT PROC
    MOV AH, 1
    INT 21H
    
    CMP AL, '0'    
    JL ERROR
    CMP AL, 'F'     
    JG ERROR
    CMP AL, '9'    
    JG LETTER1
    
    SUB AL, '0'    
    JMP SAVE1
    
LETTER1:
    SUB AL, 'A'-10  
    
SAVE1:
    MOV BL, AL      
    MOV CL, 4       
    SHL BL, CL      
    
    MOV AH, 1
    INT 21H
    
    CMP AL, '0'     
    JL ERROR
    CMP AL, 'F'     
    JG ERROR
    CMP AL, '9'     
    JG LETTER2
    
    SUB AL, '0'     
    JMP COMBINE
    
LETTER2:
    SUB AL, 'A'-10  
    
COMBINE:
    OR AL, BL       
    RET
    
ERROR:
    MOV AL, 0       
    RET
HEX_INPUT ENDP

END MAIN