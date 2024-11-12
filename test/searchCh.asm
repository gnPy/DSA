data segment 
    msg1 db 'Enter the Character to be found: $'
    found db 'character found.$'
    notfound db 'character not found.$'
    search db ?
    text db 'this is my game.$' 
    count dw 17  
    linefeed db 13 , 10  '$' 


data ends

code segment
assume cs:code ds:data

start:
    mov ax , data
    mov ds , ax
    mov es , ax
    mov cx , count   
    mov di , offset text
    
    lea dx , msg1
    mov ah,09h
    int 21h
    
    mov ah,01h
    int 21h
    mov search , al  
    
    mov ah , 09h
    mov 
    
    mov al , search 
    
    repne scasb
    
    jz yes
    mov dx , offset notfound
    mov ah , 09h
    int 21h
    jmp exit
yes:
    mov dx , offset found
    mov ah , 09h
    int 21h

exit:
    mov ah , 04ch
    int 21h

code ends
end start
    
     
    
    
    
    
    