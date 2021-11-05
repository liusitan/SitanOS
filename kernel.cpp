void printf(const char* str){
    static unsigned short* videomem = (unsigned short*)0xb8000;
    for(int i = 0; str[i] != '\0'; ++i){
        // videomem[i] = (videomem[i] && 0xFF00) | str[i];
        volatile char *video = (volatile char*)0xB8000;
        while( *str != 0 )
        {
            *video++ = *str++;
            *video++ = 0x2a;
        }
    }
}
extern "C" void kernelMain(void* multiboot_structure,unsigned int magicnumber){
//  
    printf("Hello sitan, I am your kernel written by you!");
    while(1);
}