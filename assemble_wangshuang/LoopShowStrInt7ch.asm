assume cs:code,ds:data
data segment
	db 'I want to change the world!',0
	data ends
code segment
start:	;��װ�ж�����
		mov ax,cs
		mov ds,ax
		mov si,offset AsLoop
		mov ax,0
		mov es,ax
		mov di,200h
		mov cx,offset AsLoopEnd-offset AsLoop
		cld
		rep movsb
		
		;�����ж�����
		mov ax,0
		mov es,ax
		mov es:[7ch*4],200h
		mov es:[7ch*4+2],0
		
		;ʹ���ж�����7ch�����û�����
		mov ax,data
		mov ds,ax
		mov si,0
		mov ax,0b800h
		mov es,ax
		mov di,160*12+12*4
		mov bx,offset s-offset se
	s:	cmp byte ptr [si],0
		je ok
		mov al,[si]
		mov ah,72h
		mov es:[di],ax
		inc si
		add di,2
		int 7ch		;ʹ���Զ�����жϳ���
	se: nop
	ok:	mov ax,4c00h
		int 21h
		
		;�ж�����,bx����ת��λ��,���ж�ģ��jmp near s��ת�Ĺ���
AsLoop:	push bp
		mov bp,sp
		add [bp+2],bx
		pop bp
		iret
		
		mov ax,4c00h
		int 21h
AsLoopEnd: nop
code ends
end start




