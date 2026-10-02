#include<stdarg.h>
#define VGA_ADDRESS 0xB8000
#define WIDTH 80
#define HEIGHT 25

static int cx=0;
static int cy=0;

static volatile unsigned short* const vga_buffer = (unsigned short*) VGA_ADDRESS;

void put_c(char c, char color){
    if(c=='\n'){
        cy++;
        cx=0;
    }
    int index = WIDTH * cy + cx;
    vga_buffer[index] = (unsigned short) c | (unsigned short) color<<8;
    cx++;
    if(cx>WIDTH){
        cx = 0;
        cy++;
    }
}
void vga_print(const char* string, char color){
    for(int i=0;string[i]!='\0';i++){
        put_c(string[i],color);
    }
}
void vga_print_int(int n, char color){
    if(n==0){
        put_c('0',color);
        return;
    }
    if(n<0){
        put_c('-',color);
        n=-n;
    }
    int i = 0;
    char buff[32];
    while(n>0){
        buff[i++] = '0' + (n%10); 
        n = n/10;
    }
    while(i>0){
        put_c(buff[--i],color);  
    }
}
void printf(const char *format, ...){
    va_list args;
    va_start(args,format);
    char color = 0x0F;
    for(int i=0;format[i]!='\0';i++){
        if(format[i]=='%'){
            i++;
            switch (format[i])
            {
                case 'd':
                    int num = va_arg(args,int);
                    vga_print_int(num,color);
                    break;
                case 's':
                    char* s = va_arg(args,char*);
                    vga_print(s?s:"(null)",color);
                    break;
                case 'c':
                    char c = (char)va_arg(args,int);
                    put_c(c,color);
                    break;
                default:
                    put_c('%', color);
                    put_c(format[i], color);
                    break;
            }
        }
        else{
            put_c(format[i],color);
        }
    }
}