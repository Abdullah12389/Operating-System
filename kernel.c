void clear_screen(){
    volatile unsigned short* const vga_buffer = (unsigned short*) 0xB8000;
    for(int i=0;i<25*80;i++){
        vga_buffer[i] = 0x0F20;
    }
}
void kernel_main(){
    clear_screen();
    char *video_memory = (char*) 0xB8000;
    const char* str = "Hello From MinOS";
    int i = 0;
    while(str[i]!='\0'){
        video_memory[i*2] = str[i];
        video_memory[i*2+1] = 0x1F;
        i++;
    }
    while(1);
}