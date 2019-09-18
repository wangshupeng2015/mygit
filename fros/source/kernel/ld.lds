

OUTPUT_FORMAT("elf32-littlearm") /*定义输出文件的格式*/

OUTPUT_ARCH(arm) /*设置输出文件的体系架构*/
ENTRY(_start_) /*将_start这个全局符号设置为入口地址*/
TARGET(binary) 

SECTIONS{ /*文件内容布局*/
    . = 0x80010000;
    .init :
     {
        *(.init)
        *(.init.*)
     }
    .text : {
       *(.text)  	
 	 } 
 	 .data :{ 
 	   *(.data)  
 	 }
 	 .bss :{ 
 	   *(.bss)
 	 }
 	 . = ALIGN(0x1000);
 	 _stack_start = .;	
 	 _stack_end = _stack_start + 0x20000*2;
}