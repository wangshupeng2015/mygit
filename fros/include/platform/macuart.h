/*
 * macuart.h
 *
 *  Created on: 2019年9月6日
 *      Author: wangshupeng
 */

#ifndef INCLUDE_PLATFORM_MACUART_H_
#define INCLUDE_PLATFORM_MACUART_H_
int uart_send(const char c);

/** @brief Like getc
 *  @param base pl01x's base address.
 *  @return Read from pl01x's FIFO.
 */
int uart_recv();

/** @brief Initializes pl01x.
 *  @param base pl01x's base address.
 *  @param baudrate To set baud rate.
 *  @param input_clock pl01x's clock.
 */
void uart_init();


#endif /* INCLUDE_PLATFORM_MACUART_H_ */
