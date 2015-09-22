assume cs:code
code segment
string1: db '1. clear screen',13,10,'$'
string2: db '2. set foreground color',13,10,'$'
string3: db '3. set background color',13,10,'$'
string4: db '4. up-roll one line',13,10,'$'
string: dw offset string1,offset string2,offset string3,offset string4
row:	db 2,4,6,8
input:	db 'input your selection: ','$'
color:	db '1.red	2.green	  3.blue: ','$'
foregroundColor:	db 0,04h,02h,01h
backgroundColor: db 0,40h,20h,10h
;showStr db 'Helloworld'

start:	mov ax,cs
		mov ds,ax
		mov si,offset int7cStart
		mov ax,0
		mov es,ax
		mov di,200h
		mov cx,offset int7cStart
		mov cx,offset int7cEnd-offset int7cStart
		cld
		rep movsb
		
		;�����ж�������λ��
		mov ax,0
		mov es,ax
		mov word ptr es:[4*7ch],200h
		mov word ptr es:[4*7ch+2],0
		
		mov cx,4
		mov si,offset row
		mov bx,offset string
Hint:	mov dh,[si]
		mov dl,12
		mov ah,02h
		int 10h
		
		mov dx,[bx]
		mov ah,09h
		int 21h
		inc si
		add bx,2
		loop Hint	
		
		;����int 7ch
		;mov bx,0b800h
		;mov es,bx
		;mov cx,10
		;mov si,0
		;mov di,0
;s:		mov bl,showStr[di]
		;mov byte ptr es:[si],bl
		;add si,2
		;inc di
		;loop s
		
		mov dh,10
		mov dl,12
		mov ah,02h
		int 10h
		mov dx,offset input
		mov ah,09h
		int 21h
		
		mov ah,01h	;ѡ����Ҫ���еĲ���
		int 21h		;�Ӽ��������ַ��������ԣ��ַ�������al
		
		sub al,31h	;�������1234������ֻ��ʶ��0123�����Լ�ȥ30h��Ȼ���ټ�1
		mov ah,al
		cmp ah,0	;ֻ��1��2�Ų���Ҫѡ����ɫ
		jna next1	
		cmp ah,3
		jnb next1
		
		push ax
		mov dh,12
		mov dl,12
		mov ah,02h
		int 10h
		mov dx,offset color	;����ַ���
		mov ah,09h
		int 21h
		mov ah,01h	;ѡ����ɫ
		int 21h
		sub al,30h
		
		;��Ϊ����ɫ��ǰ��ɫ
		pop bx
		mov ah,bh
		cmp ah,1
		je foreground
		cmp ah,2
		je background
		
foreground:	push bx
			push ax
			mov bx,offset foregroundColor
			mov ah,0
			mov si,ax
			mov byte ptr al,[bx+si]
			pop bx
			mov ah,bh
			pop bx
			jmp next1
background:	push bx
			push ax
			mov bx,offset backgroundColor
			mov ah,0
			mov si,ax
			mov byte ptr al,[bx+si]
			pop bx
			mov ah,bh
			pop bx
			jmp next1
		
next1:	int 7ch
		
		mov ax,4c00h
		int 21h

int7cStart:	jmp short set
;		table dw sub1,sub2,sub3,sub4
set:	push bx
		cmp ah,3
		ja sret
		mov bl,ah
;		mov bh,0
;		shl bl,1
;		call table[bx]		;Ѱַ����ȷ��why????
							;ԭ����table��¼���ǵ�ǰ�����е�ƫ�Ƶ�ַ�������ж������е�ƫ�ƣ�����ת�����ӳ����У�how to do
;		call sub2
		cmp bl,0			;
		je do1
		cmp bl,1
		je do2
		cmp bl,2
		je do3
		cmp bl,3
		je do4

do1:	call sub1
		jmp short sret
do2:	call sub2
		jmp short sret
do3:	call sub3
		jmp short sret
do4:	call sub4
		jmp short sret
		
sret:	pop bx
		mov ax,4c00h
		int 21h

;ÿҳ������ʾ4000�ֽڣ�������ʾ2000���ַ�
;�������ܣ�����
sub1:	push bx
		push cx
		push es
		mov bx,0b800h
		mov es,bx
		mov cx,2000
		mov bx,0
subs1:	mov word ptr es:[bx],' '
		add bx,2
		loop subs1
		pop es
		pop cx
		pop bx
		ret

;�������ܣ�����ǰ��ɫ
;ǰ��ɫΪ�����ֽ��е�0��1��2��λ		
sub2:	push bx
		push cx
		push es
		mov bx,0b800h
		mov es,bx
		mov bx,1
		mov cx,2000
subs2:	mov byte ptr es:[bx],11111000b
		or es:[bx],al
		add bx,2
		loop subs2
		
		pop es
		pop cx
		pop bx
		ret

;�������ܣ����ñ���ɫ
;����ɫΪ�����ֽ��е�4��5��6λ		
sub3:	push bx
		push cx
		push es
		mov bx,0b800h
		mov es,bx
		mov cx,2000
		mov bx,1
subs3:	mov byte ptr es:[bx],10001111b
		or es:[bx],al
		add bx,2
		loop subs3
		
		pop es
		pop cx
		pop bx
		ret
		
;�������ܣ����Ϲ���һ��
;ÿҳ��ʾ4000�ֽڣ���2000���ַ���ÿ��160���ֽڣ�������ʾ25��/ҳ		
sub4:	push bx
		push es
		push cx
		push di
		push si
		mov bx,0b800h
		mov es,bx
		mov ds,bx
		mov si,160	;�ڶ���
		mov di,0
		mov cx,24
		cld 
subs4:	push cx
		mov cx,160
		rep movsb
		pop cx
		loop subs4
		
		mov cx,80
		mov di,0
subs4s1:mov byte ptr es:[160*24+di],' '	;���һ�У���25�����
		add di,2
		loop subs4s1
		
		pop si
		pop di
		pop cx
		pop es
		pop bx
		ret

int7cEnd:	nop

code ends
end start








