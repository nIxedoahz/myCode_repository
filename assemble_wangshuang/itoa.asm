assume cs:code
data segment
	dd 123456
	;db 'Welcome to masm!','$'
	data ends
result segment
	db 16 dup (0)
	result ends
code segment
start:	;mov ax,data
		;mov ds,ax
		;call itoa	;ͨ��ds�����������intֵת�����ַ�������result��
		mov ah,2
		mov bh,0
		mov dh,5
		mov dl,12
		int 10h		
		mov ax,data
		mov ds,ax
		mov ax,result
		mov ss,ax
		
		call itoa
		mov ax,result
		mov ds,ax
		mov si,0
		mov cx,di
s1:		mov al,[si]
		push ax
		inc si
		loop s1

		mov cx,di
s2:		pop ax
		mov [si+2],al
		inc si
		loop s2
		mov [si+2],24h
		
;		mov dx,8
		mov dx,0
		mov ah,9
		int 21h
		
		mov ah,4ch
		int 21h
		
itoa:	mov si,0
		mov bp,0
		mov ax,[si]
		mov dx,[si+2]
transfer:	mov cx,10
		call my_div		;����Ϊ10��cx�е��������Ϊ9��ȥcl�е���
		inc di			;��¼���ݵ�λ��������ʮ���Ƽ���
		mov [bp][si],cl
;		push cx				;��������ջ����ջ˳��Ϊԭ���ݵ�˳�� 
							;���ӳ����У�push�ͱ���pop����Ȼ��ret��ʱ��ipָ��ᱻ���ǣ�������ת������λ�ã����´���
		add [bp][si],30h	;��30h,ת���������ַ�
		inc si			;��¼�˸�ʮ��������λ��
		push ax
		or ax,dx
		mov cx,ax
		pop ax
		jcxz return
		jmp transfer
return:	;mov [bp][si],24h	;�ַ�'$'
		ret
		
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
		
		
		
		



