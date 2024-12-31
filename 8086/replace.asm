.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 13, 10, 'Enter the string: $'
    MSG2 DB 13, 10, 'Enter the character to replace: $'
    MSG3 DB 13, 10, 'Enter the replacement character: $'
    MSG4 DB 13, 10, 'The updated string is: $'

    STRING DB 50 DUP('$')       
    CHAR_REPLACE DB ?
    CHAR_NEW DB ?

.CODE
MAIN PROC
    MOV AX, @DATA               
    MOV DS, AX

    LEA DX, MSG1
    MOV AH, 9
    INT 21H
    LEA DX, STRING
    MOV AH, 0AH                 
    INT 21H

    LEA DX, MSG2
    MOV AH, 9
    INT 21H
    MOV AH, 1
    INT 21H
    MOV CHAR_REPLACE, AL        

    LEA DX, MSG3
    MOV AH, 9
    INT 21H
    MOV AH, 1
    INT 21H
    MOV CHAR_NEW, AL            

    LEA SI, STRING + 1          
    MOV CL, [STRING]            
REPLACE_LOOP:
    MOV AL, [SI]                
    CMP AL, CHAR_REPLACE       
    JNE NEXT_CHAR               
    MOV CL, CHAR_NEW 
    MOV [SI], CL                
NEXT_CHAR:
    INC SI                      
    LOOP REPLACE_LOOP           

    LEA DX, MSG4
    MOV AH, 9
    INT 21H
    LEA DX, STRING + 2
    MOV AH, 9
    INT 21H

    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
