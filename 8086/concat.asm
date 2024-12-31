DATA SEGMENT
    ; For DOS function 0AH:
    ; First byte = maximum number of characters allowed
    ; Second byte = number of characters actually read (filled by DOS)
    ; Remaining bytes = actual characters + enter key (0DH)
    str1 DB 20, 0, 20 DUP('$')  ; Max 20 chars, actual length, buffer
    str2 DB 20, 0, 20 DUP('$')  ; Max 20 chars, actual length, buffer
    result DB 40 DUP('$')       ; Buffer for concatenated result
    msg1 DB 13,10, 'Enter first string: $'
    msg2 DB 13,10, 'Enter second string: $'
    msg3 DB 13,10, 'Concatenated result: $'
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX
    MOV ES, AX              ; Set ES for string operations
    
    ; Display first prompt
    LEA DX, msg1
    MOV AH, 09H
    INT 21H
    
    ; Read first string
    LEA DX, str1
    MOV AH, 0AH
    INT 21H
    
    ; Add string terminator after first string
    XOR BH, BH
    MOV BL, str1[1]        ; Get number of chars read
    MOV SI, OFFSET str1 + 2 ; Point to start of string
    ADD SI, BX             ; Point to position after last char
    MOV BYTE PTR [SI], '$' ; Add terminator
    
    ; Display second prompt
    LEA DX, msg2
    MOV AH, 09H
    INT 21H
    
    ; Read second string
    LEA DX, str2
    MOV AH, 0AH
    INT 21H
    
    ; Add string terminator after second string
    XOR BH, BH
    MOV BL, str2[1]        ; Get number of chars read
    MOV SI, OFFSET str2 + 2 ; Point to start of string
    ADD SI, BX             ; Point to position after last char
    MOV BYTE PTR [SI], '$' ; Add terminator
    
    ; Concatenate strings
    LEA SI, str1 + 2       ; Point to first string's content
    LEA DI, result         ; Point to result buffer
    
COPY_STR1:
    MOV AL, [SI]           ; Get character from first string
    CMP AL, '$'            ; Check for end of string
    JE START_STR2          ; If end, start copying second string
    MOV [DI], AL           ; Copy character to result
    INC SI                 ; Move to next source character
    INC DI                 ; Move to next destination position
    JMP COPY_STR1
    
START_STR2:
    LEA SI, str2 + 2       ; Point to second string's content
    
COPY_STR2:
    MOV AL, [SI]           ; Get character from second string
    MOV [DI], AL           ; Copy character to result
    CMP AL, '$'            ; Check for end of string
    JE SHOW_RESULT         ; If end, go to display result
    INC SI                 ; Move to next source character
    INC DI                 ; Move to next destination position
    JMP COPY_STR2
    
SHOW_RESULT:
    ; Display final message
    LEA DX, msg3
    MOV AH, 09H
    INT 21H
    
    ; Display concatenated result
    LEA DX, result
    MOV AH, 09H
    INT 21H
    
    ; Exit program
    MOV AH, 4CH
    INT 21H
CODE ENDS
END START