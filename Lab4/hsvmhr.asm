section .text
global hsvmhr
hsvmhr:
push ebp
mov ebp, esp
.L5:
mov eax, [ebp+8] ; we put the value in ebp+8 in eax.this value is an adress -( "[]" = * )
mov eax, [eax] ;we put the value in the adreess in ebp+8 (= **)
mov edx, [ebp+12]
mov edx, [edx]
movzx eax, al ; takes the first byte of the word(the first half of ax) and puts it in eax
movzx edx, dl ; takes the first byte of the word(the first half of dx) and puts it in edx
sub eax, edx ;מחשבים את ההפרש בין הערכים של חצאי המילים AX ו DX 
je .L2 ;if (the above is zero)
jmp .L3
.L2:
test dl, dl ; compare dl to zero
jne .L4 ;if not (the above is zero)
xor eax, eax ; eaxמאפס את  
jmp .L3
.L4:
add DWORD [ebp+8], 1
add DWORD [ebp+12], 1
jmp .L5
.L3:
pop ebp
ret


