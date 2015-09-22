assume cs:code,ds:data,es:table

data segment

    db '1975','1976','1977','1978','1979','1980','1981','1982','1983'

    db '1984','1985','1986','1987','1988','1989','1990','1991','1992'

    db '1993','1994','1995'
    ;21 years

    dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514

    dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
    ;21 �������

    dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226

    dw 11452,14430,15257,17800
    ;21 ��Ա������
data ends

table segment
	db 21 dup ('year summ ne ?? ',0)
table ends

code segment
START:  mov ax,data
		mov ds,ax
		mov ax,table
		mov ss,ax
		mov dh,6	;��8��
		mov dl,3	;��3��
;		mov cl,72h	;green
		
		;�������
		mov bx,0
		mov si,0
		mov bp,0
		mov cx,21
		
s1:		mov ax,[bx][si]
		mov [bp+0],ax
		;���Ϊ�ĸ��ֽڵ��ַ����������ζ�ȡ
		add si,2
		mov ax,[bx][si]
		mov [bp+2],ax
		add bp,10h
		;��tableת����һ��
		add si,2
		loop s1
		
		;�������� dd
		mov cx,21
		mov si,0
		mov bp,0
		mov bx,0
		
s2:		mov ax,84[bx][si]
		mov [bp+5],ax
		;����Ϊdd���ͣ�Ϊ�ĸ��ֽڣ������ζ�ȡ
		add si,2
		mov ax,84[bx][si]
		mov [bp+7],ax
		add bp,10h
		add si,2
		loop s2
		
		;�������� dw
		mov cx,21
		mov bp,0
		mov si,0
		mov bx,0
		
s3:		mov ax,168[bx][si]
		mov [bp+10],ax
		add si,2
		add bp,10h
		loop s3
		
		;����ÿ����˾�����
		mov bp,0
		mov cx,21
		push dx
		
s4:		push cx
		mov ax,[bp+5]
		mov dx,[bp+7]
		mov cx,[bp+10]
		call my_div
		mov [bp+13],ax
		add bp,10h
		pop cx
		loop s4
		
		mov bp,0
		mov cx,21
s6:		push cx
		mov ax,[bp+5]
		mov dx,[bp+7]
		mov si,0
		mov di,0
transfer:	mov cx,10
		call my_div		;����Ϊ10��cx�е��������Ϊ9��ȥcl�е���
		inc di			;��¼���ݵ�λ��������ʮ���Ƽ���
		add cl,30h
		push cx			;��������ջ����ջ˳��Ϊԭ���ݵ�˳�� 
				;���ӳ����У�push�ͱ���pop����Ȼ��ret��ʱ��ipָ��ᱻ���ǣ�������ת������λ�ã����´���
		push ax
		or ax,dx
		mov cx,ax
		pop ax
		jcxz return
		jmp transfer
return:	mov cx,di
		mov si,0
		mov [bp+si+4],20h
itoa:	pop ax	;���ַ���д��ԭ�����ڴ�
;		mov [bp+si+4],20h	;���������֮���һ��
		mov [bp+si+5],al	
		inc si
		loop itoa
		mov [bp+si+5],0		;���ַ������һ������Ϊ0��Ȼ�������jcxz
		pop cx
		add bp,10h
		loop s6
		
		
		pop dx
		mov bp,0
		mov cx,21
s5: 	call show_str
		add bp,10h
		inc dh
		loop s5
		
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
		
show_str:  push bx
		   push si
		   push cx
		   push dx
		   mov ax,0b800h
		   mov es,ax
		   sub dh,1
		   mov al,0a0h
		   mul byte ptr dh	;����ڰ��У�������ǰ�����У�160*7
		   push ax
		   xor ax,ax
		   sub dl,1
		   mov al,2
		   mul byte ptr dl
		   pop bx
		   add bx,ax	;�����8�е�3��
		   mov di,0
		   mov si,0
;		   mov cx,9
	show:  mov cl,[bp][si]
		   mov ch,0
		   mov al,[bp][si]
		   mov ah,72h	;green
		   mov es:[bx+di],ax
		   inc si
		   add di,2
		   jcxz ok
		   jmp show
ok:		   pop dx
		   pop cx
		   pop si
		   pop bx
		   ret

		
code ends
end START











