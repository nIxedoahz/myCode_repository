assume cs:code
code segment
unit: db 0,2,4,7,8,9	;�� �� ʱ �� �� ��

start:	mov bx,offset unit+5
		mov ax,cs
		mov ds,ax
		mov cx,6
		mov si,32
		
s1:		mov al,[bx]
		out 70h,al
		in al,71h
		mov ah,al
		push cx
		mov cl,4
		shr ah,cl
		and al,0fh
		add al,30h
		add ah,30h
		pop cx
		mov dx,0b800h
		mov es,dx
		mov es:[160*12+si],ah	;�����Դ�����ʾ
		add si,2
		mov es:[160*12+si],al
		add si,2
		
		cmp cx,4	;��date��time��ʾ�ÿո�ֿ�
		jne s3
		mov al,20h
		mov es:[160*12+si],al
		add si,2
		
s3:		cmp cx,3
		jna next1
					;ǰ������ʾ��������
		cmp cx,5	;'\'ֻ��Ҫ��ʾ����
		jb next2
		mov al,2fh	;��ʾ�ַ�'\'
		mov es:[160*12+si],al
		add si,2
		jmp next2
		
next1:	mov al,3ah	;��ʾʱ����
		cmp cx,2
		jb next2
		mov es:[160*12+si],al
		add si,2
next2:	dec bx
		loop s1
					
		mov ax,4c00h
		int 21h
code ends
end start


