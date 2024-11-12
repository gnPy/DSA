; add two 16-bit numbers

org 1000h

MOV [2000h], 30       ; Store 30 at memory location 2000h
MOV [2002h], 5        ; Store 5 at memory location 2002h

MOV AX, [2000h]       ; Load 30 into AX
MOV BX, [2002h]       ; Load 5 into BX

SUB AX, BX            ; AX = AX - BX (AX = 30 - 5 = 25)

MOV DX, AX            ; Store the result in DX

MOV BX, 0             ; Initialize BX to 0
L1:
    ADD BL, 1         ; Increment the lower byte of BX
    DAA               ; Adjust AL (or BL) to maintain BCD format
    DEC DX            ; Decrement DX (not AX, to avoid infinite loop)
    JNZ L1            ; If DX is not zero, repeat the loop


HLT                   ; Halt the program
