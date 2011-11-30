section .text
global _start

extern main
_start:
      mov ebx, esp
      add ebx, 4
      push ebx
      push DWORD [esp+4]
      call main
      ;mov ebx,eax
      ;mov eax,1
      ;int 0x80
pop ebp
ret
 
