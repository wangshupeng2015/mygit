/*
 * print.c
 *
 *  Created on: 2019年9月6日
 *      Author: wangshupeng
 */

void printString(const char *str){
	while(*str){
		uart_send(*str);
		str++;
	}
}
