data segment
str1 db 30 dup(" $") ; Buffer for main string
msg1 db 13,10,"Enter the main string:$" ; Prompt for main string
msg2 db 13,10,"Enter the character to replace:$" ; Prompt for character to replace
msg3 db 13,10,"Enter the replacement character:$" ; Prompt for replacement character
res db 13,10,"Updated string is:$" ; Message before displaying the result
data ends

stack segment
dw 128 dup(?)
stack ends

code segment
assume cs:code, ds:data

start:
    mov ax, data
    mov ds, ax

    ; Input main string
    lea dx, msg1
    mov ah, 09h
    int 21h

    lea si, str1
    call reader

    ; Input character to replace
    lea dx, msg2
    mov ah, 09h
    int 21h

    mov ah, 01h
    int 21h
    mov bl, al ; Store the character to replace in BL

    ; Input replacement character
    lea dx, msg3
    mov ah, 09h
    int 21h

    mov ah, 01h
    int 21h
    mov cl, al ; Store the replacement character in CL

    ; Replace occurrences
    lea si, str1
    call replacer

    ; Display updated string
    lea dx, res
    mov ah, 09h
    int 21h

    lea dx, str1
    mov ah, 09h
    int 21h

    ; Terminate program
    mov ah, 4Ch
    int 21h

; Procedure to read a string
reader:
    mov ah, 01h
    int 21h
    cmp al, 13 ; Check for Enter key
    je return
    mov [si], al
    inc si
    jmp reader
return:
    mov [si], '$' ; End string with $
    ret

; Procedure to replace characters
replacer:
    mov al, '$' ; End of string marker
replace_loop:
    cmp [si], al ; Check if end of string
    je replacer_end
    cmp [si], bl ; Check if current char matches the target
    jne skip_replace
    mov [si], cl ; Replace with the new character
skip_replace:
    inc si
    jmp replace_loop
replacer_end:
    ret

code ends
end start