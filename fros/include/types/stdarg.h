/*
 * stdarg.h
 *
 *  Created on: 2019年9月6日
 *      Author: wangshupeng
 */

//#ifndef INCLUDE_TYPES_STDARG_H_
//#define INCLUDE_TYPES_STDARG_H_
//
//
//
//#endif /* INCLUDE_TYPES_STDARG_H_ */

#pragma once

/* standard args */
#define va_start(v,l) __builtin_va_start(v,l)
#define va_end(v) __builtin_va_end(v)
#define va_arg(v,l) __builtin_va_arg(v,l)
typedef __builtin_va_list va_list;
