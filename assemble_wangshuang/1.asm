assume cs:abc
abc segment

mov ax,2h
add ax,ax
add ax,ax

mov ax,4c00h
int 21h

abc ends
end