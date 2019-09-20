    .arch_extension sec
    .arch_extension virt
.globl _hvc_vector
.global main
.align 8
_hvc_vector:
    .word   0                   /* reset 0x0 */
    b __default4                        /* undef 0x4 */
    b __default8                         /* svc 0x8*/
    b __defaultc                         /* pabt 0xc*/
    b __default10                         /* dabt 0x10*/
    b       __do_hvc            /* hvc 14*/
    b       __do_irq            /* irq 18*/
    b   __default1c             /* fiq 1c*/



.macro __save_return_sp
    push    {r0-r12}
    mrs     r0, SPSR
    mrs     r1, elr_hyp
    push    {r0, r1, lr}
    mov    r0, sp
.endm

.macro __restore
    pop     {r0, r1, lr}
    msr     SPSR, r0
    msr     elr_hyp, r1
    pop     {r0-r12}
    eret
.endm
__default4:
	__save_return_sp
	mov r1,#0x4
    //bl     default_excption    @ r0: HSR
	__restore

__default8:
	__save_return_sp
	mov r1,#0x8
    //bl     default_excption    @ r0: HSR
	__restore
__defaultc:
	__save_return_sp
	mov r1,#0xc
   // bl     default_excption    @ r0: HSR
	__restore
__default10:
	__save_return_sp
	mov r1,#0x10
    //bl     default_excption    @ r0: HSR
	__restore
__default1c:
	__save_return_sp
	mov r1,#0x1c
   // bl     default_excption    @ r0: HSR
	__restore


__do_hvc:
    //汇编都是从后往前
    //现场保护
	push    {r0-r12}
    mrs     r0, SPSR
    mrs     r1, elr_hyp
    push    {r0, r1, lr}

    mov    r0, #0x1d3
    msr     SPSR_hyp, r0

    //现场恢复
    pop     {r0, r1, lr}
    msr     elr_hyp, r1
    pop     {r0-r12}
    
	 //msr     elr_hyp, r4
    msr SP_svc ,sp
    eret

__do_irq:
    @ Push registers
    push    {r0-r12}
    mrs     r0, SPSR
    mrs     r1, elr_hyp
    //mrs 	r2,	lr_svc
    push    {r0, r1, lr}

    @ service other argument values -> trap_irq(sp)
    mov     r0, sp
    //bl      do_irq    @ r0: HSR

    @ DCIMVAC: invalidate data cache.
    //mov     r0, #0
    //write_cp32(r0, DCIMVAC)
    @ TLBIALLH: flust instruction and data TLBs. r0 will be ignored.
    //write_cp32(r0, TLBIALLH)

    @ Pop registers
    pop     {r0, r1, lr}
    msr     SPSR, r0
    msr     elr_hyp, r1
    pop     {r0-r12}

    eret /* ERET的功能在于在 Hyp模式下执行的时候，Spsr_hyp的内容赋给CPSR而ELR_Hyp的值赋给PC*/

/* task switch,need save fpu ctx */


