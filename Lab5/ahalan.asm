section .text
  global ahalan
    extern puts

ahalan: ;void ahalan()
      push ebp
      mov ebp, esp
      push msg ;put the string i want to use as an arument for the function puts
      call puts ;calling the function puts which we implemented in c, and using the argumant at the head of the stack 
      add esp,4 ;here we want to free the head of the stack (when we will do "pop ebp",befor ret, we want it to be at the correct place)
      ;mov edx,len
      ;mov ecx,msg ;message to write
      ;mov ebx,1 ;file descriptor (stdout)
      ;mov eax,4 ;system call number (sys_write)
      ;int 0x80 ;call kernel
      pop ebp
      ret

section .data

msg 	db 	'ahalan!',0xa,0 ;our dear string


 
