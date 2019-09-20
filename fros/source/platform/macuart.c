/*
 * macuart.c
 *
 *  Created on: 2019年9月6日
 *      Author: wangshupeng
 */

#include "platform/macuart.h"

#define  DEF_BIT_FIELD_ENC(field_val, field_mask)       (((field_val) * ((field_mask) & ((~(field_mask)) + 1u))) & (field_mask))


/*
*********************************************************************************************************
*                                           DEF_BIT_FIELD_WR()
*
* Description : Writes 'field_val' field at position given by mask 'field_mask' in variable 'var'.
*
* Argument(s) : var         Variable to write field to. See note #2.
*
*               field_val   Desired value for field. See note #2.
*
*               field_mask  Mask of field to write to. See note #1 and #2.
*
* Return(s)   : None.
*
* Caller(s)   : Application.
*
* Note(s)     : (1) 'field_mask' argument must contain a mask with contiguous set bits.
*
*               (2) 'var', 'field_val' & 'field_mask' SHOULD be unsigned integers.
*********************************************************************************************************
*/

#define  DEF_BIT_FIELD_WR(var, field_val, field_mask)   (var) = (((var) & ~(field_mask)) | DEF_BIT_FIELD_ENC((field_val), (field_mask)))

/*
*********************************************************************************************************
*                                          DEF_BIT_FIELD_ENC()
*
* Description : Encodes given 'field_val' at position given by mask 'field_mask'.
*
* Argument(s) : field_val   Value to encode.
*
*               field_mask  Mask of field to read. See note #1 and #2.
*
* Return(s)   : Field value, masked and left-shifted to field position.
*
* Caller(s)   : Application.
*
* Note(s)     : (1) 'field_mask' argument must contain a mask with contiguous set bits.
*
*               (2) 'field_val' & 'field_mask' SHOULD be unsigned integers.
*********************************************************************************************************
*/

#define  DEF_BIT_FIELD_ENC(field_val, field_mask)       (((field_val) * ((field_mask) & ((~(field_mask)) + 1u))) & (field_mask))


/*
*********************************************************************************************************
*                                           DEF_BIT_FIELD_WR()
*
* Description : Writes 'field_val' field at position given by mask 'field_mask' in variable 'var'.
*
* Argument(s) : var         Variable to write field to. See note #2.
*
*               field_val   Desired value for field. See note #2.
*
*               field_mask  Mask of field to write to. See note #1 and #2.
*
* Return(s)   : None.
*
* Caller(s)   : Application.
*
* Note(s)     : (1) 'field_mask' argument must contain a mask with contiguous set bits.
*
*               (2) 'var', 'field_val' & 'field_mask' SHOULD be unsigned integers.
*********************************************************************************************************
*/

#define  DEF_BIT_FIELD_WR(var, field_val, field_mask)   (var) = (((var) & ~(field_mask)) | DEF_BIT_FIELD_ENC((field_val), (field_mask)))

#define  DEF_BIT(bit)                                                   (1u << (bit))

#define  DEF_BIT_IS_SET(val, mask)                    (((((val) & (mask)) == (mask)) && \
                                                         ((mask)          !=  0u))    ? (1) : (0))
#define  DEF_BIT_SET(val, mask)                        ((val) = ((val) | (mask)))


#define  DEF_BIT_FIELD(bit_field, bit_shift)                                 ((((bit_field) >= 32) ? (4294967295u)     \
                                                                                                                     : (DEF_BIT(bit_field) - 1uL)) \
                                                                                                                            << (bit_shift))
#define CPU_REG32 volatile unsigned long
                                                             /* ------------------- BIT DEFINES -------------------- */
#define  DEF_BIT_NONE                                   0x00u

#define  DEF_BIT_00                                     0x01u
#define  DEF_BIT_01                                     0x02u
#define  DEF_BIT_02                                     0x04u
#define  DEF_BIT_03                                     0x08u
#define  DEF_BIT_04                                     0x10u
#define  DEF_BIT_05                                     0x20u
#define  DEF_BIT_06                                     0x40u
#define  DEF_BIT_07                                     0x80u

#define  DEF_BIT_08                                   0x0100u
#define  DEF_BIT_09                                   0x0200u
#define  DEF_BIT_10                                   0x0400u
#define  DEF_BIT_11                                   0x0800u
#define  DEF_BIT_12                                   0x1000u
#define  DEF_BIT_13                                   0x2000u
#define  DEF_BIT_14                                   0x4000u
#define  DEF_BIT_15                                   0x8000u

#define  DEF_BIT_16                               0x00010000u
#define  DEF_BIT_17                               0x00020000u
#define  DEF_BIT_18                               0x00040000u
#define  DEF_BIT_19                               0x00080000u
#define  DEF_BIT_20                               0x00100000u
#define  DEF_BIT_21                               0x00200000u
#define  DEF_BIT_22                               0x00400000u
#define  DEF_BIT_23                               0x00800000u

#define  DEF_BIT_24                               0x01000000u
#define  DEF_BIT_25                               0x02000000u
#define  DEF_BIT_26                               0x04000000u
#define  DEF_BIT_27                               0x08000000u
#define  DEF_BIT_28                               0x10000000u
#define  DEF_BIT_29                               0x20000000u
#define  DEF_BIT_30                               0x40000000u
#define  DEF_BIT_31                               0x80000000u
#define  DEF_BIT_32                       0x0000000100000000u
#define  DEF_BIT_33                       0x0000000200000000u
#define  DEF_BIT_34                       0x0000000400000000u
#define  DEF_BIT_35                       0x0000000800000000u
#define  DEF_BIT_36                       0x0000001000000000u
#define  DEF_BIT_37                       0x0000002000000000u
#define  DEF_BIT_38                       0x0000004000000000u
#define  DEF_BIT_39                       0x0000008000000000u
#define  MPCORE_PRIV_PERIPH_BASE  (0x31000000u)

#define  MPCORE_GIC_DIST_BASE  (MPCORE_PRIV_PERIPH_BASE + 0x1000u)
#define  MPCORE_GIC_IF_BASE  (MPCORE_PRIV_PERIPH_BASE + 0x2000u)

#define  IMX_UART1_BASE (0x30860000u)


#define  IMX_REG_AIPSTZ1_MPR0    (*((CPU_REG32 *)0x30000000))
#define  IMX_REG_AIPSTZ1_MPR1    (*((CPU_REG32 *)0x30000004))
#define  IMX_REG_AIPSTZ1_OPACR0  (*((CPU_REG32 *)0x30000040))
#define  IMX_REG_AIPSTZ1_OPACR1  (*((CPU_REG32 *)0x30000044))
#define  IMX_REG_AIPSTZ1_OPACR2  (*((CPU_REG32 *)0x30000048))
#define  IMX_REG_AIPSTZ1_OPACR3  (*((CPU_REG32 *)0x3000004C))
#define  IMX_REG_AIPSTZ1_OPACR4  (*((CPU_REG32 *)0x30000050))

#define  IMX_REG_AIPSTZ2_MPR0    (*((CPU_REG32 *)0x30400000))
#define  IMX_REG_AIPSTZ2_MPR1    (*((CPU_REG32 *)0x30400004))
#define  IMX_REG_AIPSTZ2_OPACR0  (*((CPU_REG32 *)0x30400040))
#define  IMX_REG_AIPSTZ2_OPACR1  (*((CPU_REG32 *)0x30400044))
#define  IMX_REG_AIPSTZ2_OPACR2  (*((CPU_REG32 *)0x30400048))
#define  IMX_REG_AIPSTZ2_OPACR3  (*((CPU_REG32 *)0x3040004C))
#define  IMX_REG_AIPSTZ2_OPACR4  (*((CPU_REG32 *)0x30400050))

#define  IMX_REG_AIPSTZ3_MPR0    (*((CPU_REG32 *)0x30800000))
#define  IMX_REG_AIPSTZ3_MPR1    (*((CPU_REG32 *)0x30800004))
#define  IMX_REG_AIPSTZ3_OPACR0  (*((CPU_REG32 *)0x30800040))
#define  IMX_REG_AIPSTZ3_OPACR1  (*((CPU_REG32 *)0x30800044))
#define  IMX_REG_AIPSTZ3_OPACR2  (*((CPU_REG32 *)0x30800048))
#define  IMX_REG_AIPSTZ3_OPACR3  (*((CPU_REG32 *)0x3080004C))
#define  IMX_REG_AIPSTZ3_OPACR4  (*((CPU_REG32 *)0x30800050))

#define  IMX6_UART_UART1_UCRX (*((CPU_REG32 *)(IMX_UART1_BASE + 0x00)))
#define  IMX6_UART_UART1_UCTX (*((CPU_REG32 *)(IMX_UART1_BASE + 0x40)))

#define  IMX6_UART_UART1_UCR1 (*((CPU_REG32 *)(IMX_UART1_BASE + 0x80)))
#define  IMX6_UART_UART1_UCR2 (*((CPU_REG32 *)(IMX_UART1_BASE + 0x84)))
#define  IMX6_UART_UART1_UCR3 (*((CPU_REG32 *)(IMX_UART1_BASE + 0x88)))

#define  IMX6_UART_UART1_UBIR (*((CPU_REG32 *)(IMX_UART1_BASE + 0xA4)))
#define  IMX6_UART_UART1_UBMR (*((CPU_REG32 *)(IMX_UART1_BASE + 0xA8)))

#define  IMX6_UART_UART1_UFCR (*((CPU_REG32 *)(IMX_UART1_BASE + 0x90)))

#define  IMX6_UART_UART1_ONEMS (*((CPU_REG32 *)(IMX_UART1_BASE + 0xB0)))

#define  IMX6_UART_UART1_UTS (*((CPU_REG32 *)(IMX_UART1_BASE + 0xB4)))


/*
*********************************************************************************************************
*                                         LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*********************************************************************************************************
*                                            GLOBAL FUNCTIONS
*********************************************************************************************************
*********************************************************************************************************
*/

#define CCGR148 (*((CPU_REG32 *)0x30384940u))

static void configure_uart_pins(unsigned long instance)
{
	return ;
}
#ifdef xxx
static void initalps(){
    IMX_REG_AIPSTZ1_MPR0 = 0x77777777;
    IMX_REG_AIPSTZ1_MPR1 = 0x77777777;

    IMX_REG_AIPSTZ2_MPR0 = 0x77777777;
    IMX_REG_AIPSTZ2_MPR1 = 0x77777777;


    IMX_REG_AIPSTZ1_OPACR0 = 0x0;
    IMX_REG_AIPSTZ1_OPACR1 = 0x0;
    IMX_REG_AIPSTZ1_OPACR2 = 0x0;
    IMX_REG_AIPSTZ1_OPACR3 = 0x0;
    IMX_REG_AIPSTZ1_OPACR4 = 0x0;


    IMX_REG_AIPSTZ2_OPACR0 = 0x0;
    IMX_REG_AIPSTZ2_OPACR1 = 0x0;
    IMX_REG_AIPSTZ2_OPACR2 = 0x0;
    IMX_REG_AIPSTZ2_OPACR3 = 0x0;
    IMX_REG_AIPSTZ2_OPACR4 = 0x0;


}
#endif
void uart_init(){
	configure_uart_pins(0u);
	configure_uart_pins(1u);
	configure_uart_pins(2u);

	//initalps();

    CCGR148 = 0x3333; //0x3

    DEF_BIT_FIELD_WR(IMX6_UART_UART1_UFCR, 0x5, DEF_BIT_FIELD(3u, 7u)); /* Divide by 1.                                 */

    IMX6_UART_UART1_UCR2 = 0;
    DEF_BIT_SET(IMX6_UART_UART1_UCR2, DEF_BIT_05);              /* 8 bit word size.                                     */
    IMX6_UART_UART1_UCR3 = DEF_BIT_02;

    IMX6_UART_UART1_UCR1 = DEF_BIT_00;

    DEF_BIT_SET(IMX6_UART_UART1_UCR2, DEF_BIT_14);              /* Ignore CTS.                                          */
    DEF_BIT_SET(IMX6_UART_UART1_UCR2, DEF_BIT_01);              /* Enable RX.                                           */
    DEF_BIT_SET(IMX6_UART_UART1_UCR2, DEF_BIT_02);              /* Enable TX.                                           */
    DEF_BIT_SET(IMX6_UART_UART1_UCR2, DEF_BIT_00);              /* De-assert reset.                                     */

    /* Default configuration for 115200 at 80Mhz ref clock. */

    IMX6_UART_UART1_UBIR = 0xf; //99u; //0xf
    IMX6_UART_UART1_UBMR = 0x68;//1307u; //0x68

    /* Disable debug halt. */
    IMX6_UART_UART1_UTS |= DEF_BIT_11 | DEF_BIT_09;

    //uart_send('A');
}


int uart_send(const char  c)
{

    /*
    #define  IMX6_UART_UART1_UTS (*((CPU_REG32 *)(IMX_UART1_BASE + 0xB4)))
    #define  DEF_BIT_04                                     0x10u
     */
    while (DEF_BIT_IS_SET(IMX6_UART_UART1_UTS, DEF_BIT_04)) {
        ;
    }

    IMX6_UART_UART1_UCTX = c;

    return c;
}



int uart_recv (void)
{
    //RTOS_ERR  rtos_err;
	unsigned long c;

    //KAL_SemPend(BSP_SerLock, 0u, 0u, &rtos_err);

    while (DEF_BIT_IS_SET(IMX6_UART_UART1_UTS, DEF_BIT_05)) {
        ;
    }

    c = IMX6_UART_UART1_UCRX;

    //KAL_SemPost(BSP_SerLock, 0u, &rtos_err);

    return (int)c;
}

