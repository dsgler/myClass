   1              		.file	"asca.c"
   2              		.text
   3              	.Ltext0:
   4              		.file 0 "/home/dsgler/cla/dump" "asca.c"
   5              		.section	.rodata
   6              	.LC0:
   7 0000 256400   		.string	"%d"
   8              		.text
   9              		.globl	main
  11              	main:
  12              	.LFB0:
  13              		.file 1 "asca.c"
   1:asca.c        **** #include <stdio.h>
   2:asca.c        **** 
   3:asca.c        **** int main(){
  14              		.loc 1 3 11
  15              		.cfi_startproc
  16 0000 F30F1EFA 		endbr64
  17 0004 55       		pushq	%rbp
  18              		.cfi_def_cfa_offset 16
  19              		.cfi_offset 6, -16
  20 0005 4889E5   		movq	%rsp, %rbp
  21              		.cfi_def_cfa_register 6
  22 0008 4883EC10 		subq	$16, %rsp
   4:asca.c        ****     unsigned char a=255;
  23              		.loc 1 4 19
  24 000c C645FEFF 		movb	$-1, -2(%rbp)
   5:asca.c        ****     unsigned char b=255;
  25              		.loc 1 5 19
  26 0010 C645FFFF 		movb	$-1, -1(%rbp)
   6:asca.c        ****     printf("%d",a+b);
  27              		.loc 1 6 5
  28 0014 0FB655FE 		movzbl	-2(%rbp), %edx
  29 0018 0FB645FF 		movzbl	-1(%rbp), %eax
  30 001c 01D0     		addl	%edx, %eax
  31 001e 89C6     		movl	%eax, %esi
  32 0020 488D0500 		leaq	.LC0(%rip), %rax
  32      000000
  33 0027 4889C7   		movq	%rax, %rdi
  34 002a B8000000 		movl	$0, %eax
  34      00
  35 002f E8000000 		call	printf@PLT
  35      00
  36 0034 B8000000 		movl	$0, %eax
  36      00
   7:asca.c        **** }...
  37              		.loc 1 7 1
  38 0039 C9       		leave
  39              		.cfi_def_cfa 7, 8
  40 003a C3       		ret
  41              		.cfi_endproc
  42              	.LFE0:
  44              	.Letext0:
  45              		.file 2 "/usr/include/stdio.h"
 322              		.section	.note.gnu.property,"a"
 323              		.align 8
 324 0000 04000000 		.long	1f - 0f
 325 0004 10000000 		.long	4f - 1f
 326 0008 05000000 		.long	5
 327              	0:
 328 000c 474E5500 		.string	"GNU"
 329              	1:
 330              		.align 8
 331 0010 020000C0 		.long	0xc0000002
 332 0014 04000000 		.long	3f - 2f
 333              	2:
 334 0018 03000000 		.long	0x3
 335              	3:
 336 001c 00000000 		.align 8
 337              	4:
