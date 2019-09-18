#include "bsp/xil_errata.h"

.globl _svc_vector
//.global vPortInstallFreeRTOSVectorTable

.align 8
_svc_vector:
	.word   0      /*reset 0x0 */
	B	Undefined   /* undef 0x4 */
	B	SVCHandler   /* svc 0x8*/
	B	PrefetchAbortHandler /* pabt 0xc*/
	B	DataAbortHandler /* dabt 0x10*/
	NOP	            /* Placeholder for address exception vector*//* svc 14*/
	B	IRQHandler /* irq 18*/
	B	FIQHandler /* fiq 1c*/


Undefined:					/* Undefined handler */
	stmdb	sp!,{r0-r3,r12,lr}		/* state save from compiled code */
	ldr     r0, =UndefinedExceptionAddr
	sub     r1, lr, #4
	str     r1, [r0]            		/* Store address of instruction causing undefined exception */

	bl	UndefinedException		/* UndefinedException: call C function here */
	ldmia	sp!,{r0-r3,r12,lr}		/* state restore from compiled code */
	movs	pc, lr


SVCHandler:					/* SWI handler */
	stmdb	sp!,{r0-r3,r12,lr}		/* state save from compiled code */

	tst	r0, #0x20			/* check the T bit */
	ldrneh	r0, [lr,#-2]			/* Thumb mode */
	bicne	r0, r0, #0xff00			/* Thumb mode */
	ldreq	r0, [lr,#-4]			/* ARM mode */
	biceq	r0, r0, #0xff000000		/* ARM mode */

	bl	SWInterrupt			/* SWInterrupt: call C function here */

	ldmia	sp!,{r0-r3,r12,lr}		/* state restore from compiled code */

	movs	pc, lr		/*return to the next instruction after the SWI instruction */


DataAbortHandler:				/* Data Abort handler */
#ifdef CONFIG_ARM_ERRATA_775420
	dsb
#endif
	stmdb	sp!,{r0-r3,r12,lr}		/* state save from compiled code */
	ldr     r0, =DataAbortAddr
	sub     r1, lr, #8
	str     r1, [r0]            		/* Stores instruction causing data abort */

	bl	DataAbortInterrupt		/*DataAbortInterrupt :call C function here */

	ldmia	sp!,{r0-r3,r12,lr}		/* state restore from compiled code */

	subs	pc, lr, #8			/* points to the instruction that caused the Data Abort exception */


PrefetchAbortHandler:				/* Prefetch Abort handler */
#ifdef CONFIG_ARM_ERRATA_775420
	dsb
#endif
	stmdb	sp!,{r0-r3,r12,lr}		/* state save from compiled code */
	ldr     r0, =PrefetchAbortAddr
	sub     r1, lr, #4
	str     r1, [r0]            		/* Stores instruction causing prefetch abort */

	bl	PrefetchAbortInterrupt		/* PrefetchAbortInterrupt: call C function here */

	ldmia	sp!,{r0-r3,r12,lr}		/* state restore from compiled code */

	subs	pc, lr, #4			/* points to the instruction that caused the Prefetch Abort exception */


IRQHandler:					/* IRQ vector handler */

	stmdb	sp!,{r0-r3,r12,lr}		/* state save from compiled code*/
#ifdef __ARM_NEON__
	vpush {d0-d7}
	vpush {d16-d31}
	vmrs r1, FPSCR
	push {r1}
	vmrs r1, FPEXC
	push {r1}
#endif

#ifdef PROFILING
	ldr	r2, =prof_pc
	subs	r3, lr, #0
	str	r3, [r2]
#endif

	bl	IRQInterrupt			/* IRQ vector */

#ifdef __ARM_NEON__
	pop 	{r1}
	vmsr    FPEXC, r1
	pop 	{r1}
	vmsr    FPSCR, r1
	vpop    {d16-d31}
	vpop    {d0-d7}
#endif
	ldmia	sp!,{r0-r3,r12,lr}		/* state restore from compiled code */


	subs	pc, lr, #4			/* adjust return */




FIQHandler:					/* FIQ vector handler */
	stmdb	sp!,{r0-r3,r12,lr}		/* state save from compiled code */
#ifdef __ARM_NEON__
	vpush {d0-d7}
	vpush {d16-d31}
	vmrs r1, FPSCR
	push {r1}
	vmrs r1, FPEXC
	push {r1}
#endif

FIQLoop:
	bl	FIQInterrupt			/* FIQ vector */

#ifdef __ARM_NEON__
	pop 	{r1}
	vmsr    FPEXC, r1
	pop 	{r1}
	vmsr    FPSCR, r1
	vpop    {d16-d31}
	vpop    {d0-d7}
#endif
	ldmia	sp!,{r0-r3,r12,lr}		/* state restore from compiled code */
	subs	pc, lr, #4			/* adjust return */


