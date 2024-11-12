data SEGMENT 
    text db 'this my world' , 0
    search db 'w'
    count dw 13
    found db 'string found$'
    notfound db 'not found$'
data ends

code SEGMENT
    ASSUME cs:code ds:data
    start:
        mov ax , data
        mov ds , ax 
        mov es , ax
        mov cx , count
        mov di , offset text
        mov al , search 
        repne scasb
        jz yes
        mov dx , offset notfound
        mov ah,09h
        int 21h
        jmp exit
    yes:
        mov dx , offset found
        mov ah , 09h
        int 21h
    exit:
        mov ah , 4ch
        int 21h
code ENDS
end start
    