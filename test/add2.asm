org 100h

mov al , 10
mov bl , 20

add al,bl             
add al , 30h


mov dl , al                   
mov ah,2 

int 21h
ret