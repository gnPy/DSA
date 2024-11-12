org 100h

MOV AX, 2000h       ; Load the base address (2000h) into AX
MOV DS, AX          ; Set DS to 2000h, allowing us to reference memory locations relative to this

MOV AL, 5           ; Load immediate value 5 into AL
MOV [0], AL         ; Store AL at DS:0 (which is 2000h)

MOV AL, 10          ; Load immediate value 10 into AL
MOV [2], AL         ; Store AL at DS:2 (which is 2002h)

MOV AL, [0]         ; Load the byte at DS:0 (2000h) into AL
MOV BL, [2]         ; Load the byte at DS:2 (2002h) into BL
ADD AL, BL          ; Add BL to AL
MOV [4], AL         ; Store the result at DS:4 (which is 2004h)

; Now print the result stored in AL (which is the sum)
MOV AH, 0Eh         ; BIOS teletype function (print character)

; Handle case when AL has a single digit or multi-digit result
MOV BL, AL          ; Copy the result to BL
MOV CL, 10          ; Set up divisor for decimal conversion (base 10)

; If the result is greater than 9, we need to print each digit
; First handle the case for values greater than or equal to 10
CMP BL, 10
JL PRINT_SINGLE_DIGIT ; If less than 10, print directly
DIV CL              ; Divide BL by 10 to get the first digit
ADD AH, '0'         ; Convert the first digit to ASCII
INT 10h             ; Print first digit

MOV BL, DL          ; Move remainder (second digit) to BL
ADD AH, '0'         ; Convert the second digit to ASCII
INT 10h             ; Print second digit
RET

PRINT_SINGLE_DIGIT:
ADD AH, '0'         ; Convert result to ASCII
INT 10h             ; Print the result directly
RET
