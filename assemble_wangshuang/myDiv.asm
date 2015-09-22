assume cs:code,ds:data
data segment
	dd 10000000
	dw 100
	data ends
result segment
	db 16 dup (0)
	result ends
code segment
	start:  mov ax,data
			mov ds,ax
			mov ax,result
			mov ss,ax
			
			mov si,0
			mov ax,[si]
			mov dx,[si+2]
			mov cx,[si+4]
			call my_div
			
			mov bp,0
			mov [bp],ax
			mov [bp+2],dx
			mov ax,4c00h
			int 21h
			
my_div:		push ax
			mov ax,dx	;ax=0,dx,(h/n)*65536
			mov dx,0
			div cx		;axΪ�̣�dxΪ����
			mov bx,dx	;��bx����һ�¸�λ���������
			mov dx,ax
			pop ax
			push dx		;dx�����int(h/n)*65536
			mov dx,bx	;(rem(h/n)*65536+L)/n	����65536���൱�ڷ��ڸ�16��
			div cx		;axΪ�̣�dxΪ������������������cx��
			mov cx,dx
			pop dx
			ret
			
code ends
end start
