
.arch_extension sec
.arch_extension virt
.extern _stack_end
.extern _hvc_vector
.extern _svc_vector
.extern main
.section .init
.globl _start_
_start_:
	ldr sp,=_stack_end //给栈顶指针sp赋值
	ldr r1,=_hvc_vector //获得hyp模式下中断向量表的地址
	mcr p15, 4, r1, c12, c0, 0  //HVBAR，安装hyp模式的中断向量表

	//判断是否需要切换模式
	mrs  r2,cpsr //获得cpsr的值
	bic  r2,r2,#0xffffffe0 //将
	mov  r3, #0x1a

	cmp  r2,r3
	bne switch_to_svc

switch_to_svc:  //完成从hyp到svc模式切换的函数
	svc #0
	




	//设置svc模式下的中断向量表
	ldr r1, =_svc_vector
	mcr	p15, 0, r1, c12, c0, 0

	bl main


/*当在裸板上执行时，系统一开始会进入hyp模式，我们最终要将系统移植到虚拟机上执行，虚拟机上已经将模式切换为svc模式，
因此，我们要将模式切换到svc来执行。从hyp切换到svc需要通过中断来进行，需要实现一个hyp模式下的中断向量表
在_do_svc_函数中只完成模式的切换，然后返回到中断之后的下一条语句继续执行， */
