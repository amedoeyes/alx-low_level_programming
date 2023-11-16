section .data
msg     db "Hello, Holberton", 10, 0

section .text
global  main
extern  printf

main:
	mov  rdi, msg
	mov  rsi, 0
	mov  eax, 0
	call printf

	mov eax, 0
	xor rdi, rdi
	syscall

