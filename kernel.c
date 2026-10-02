void printf(const char *format, ...);
void clear_screen(){
    volatile unsigned short* const vga_buffer = (unsigned short*) 0xB8000;
    for(int i=0;i<25*80;i++){
        vga_buffer[i] = 0x0F20;
    }
}
void kernel_main(){
    clear_screen();
    printf("Hello this is %s computer with price %d and %c range %m and it is really great to see you suceed","Abdullah",1000,'M');
    while(1);
}