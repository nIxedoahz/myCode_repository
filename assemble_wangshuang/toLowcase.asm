assume cs:code,ds:data
data segment
	db "Beginner's All-purpose Symbolic Instruction code.",'$'
	data ends
code segment
start:	mov ah,2
		mov bh,0
		mov dh,5
		mov dl,12
		int 10h
		
		mov ax,data
		mov ds,ax
		mov si,0
		call letterc
		
		mov dx,0
		mov ah,9
		int 21h
		
		mov ax,4c00h
		int 21h
		
letterc:mov cl,[si]
		mov ch,0
		jcxz return
		mov al,[si]
		cmp al,60h	;ASC����A֮ǰ��һ���ַ�
		jna s1		;˵���Ǵ�д,ֻ�е�ʱСд��ĸʱ�Ż�ת���ɴ�д
		and al,0dfh
		mov [si],al
s1:		inc si
		jmp letterc
return:	ret

code ends
end start
		





