assume cs:code,ds:data

data segment

     db 'welcome to masm!'

data ends

code segment

start:   mov ax,data

     mov ds,ax

     mov bx,0               ;ds:bxָ��data�ַ���

     mov ax,0b800h

     mov es,ax

     mov si,0               ;es:siָ���Դ�

     mov cx,16

s:   mov al,[bx]            ;�ַ���ֵal

     mov ah,02h             ;��ɫ

     mov es:[si].720h,ax    ;д���12��64��

     mov ah,14h             ;�̵׺�ɫ

     mov es:[si].7c0h,ax    ;д���13��64��

     mov ah,71h             ;�׵���ɫ

     mov es:[si].860h,ax    ;д���14��64��

     inc bx                 ;ָ����һ�ַ�

     add si,2               ;ָ����һ�Դ浥Ԫ

     loop s

     mov ax,4c00h

     int 21h

code ends

end start

