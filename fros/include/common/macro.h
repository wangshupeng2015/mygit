#pragma once

/*
 * macro.h
 *
 *  Created on: 2019年9月6日
 *      Author: wangshupeng
 */

#ifndef INCLUDE_COMMON_MACRO_H_
#define INCLUDE_COMMON_MACRO_H_

#define MASK(n) (BIT(n)-1ul)
#define IS_ALIGNED(n, b) (!((n) & MASK(b)))
#define ROUND_DOWN(n, b) (((n) >> (b)) << (b))
#define ROUND_UP(n, b) (((((n) - 1ul) >> (b)) + 1ul) << (b))
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define PASTE(a, b) a ## b
#define _STRINGIFY(a) #a
#define STRINGIFY(a) _STRINGIFY(a)


#ifndef __ASSEMBLY__
#ifndef NULL
#define NULL ((void *)0)
#endif
#define BIT(n) (1ul << (n))
#define UL_CONST(x) PASTE(x, ul)
#else
#define BIT(n) (1 << (n))
#define UL_CONST(x) x
#endif

#ifndef __ASSEMBLY__
#ifndef NULL
#define NULL ((void *)0)
#endif
//#define TRUE 1
//#define FALSE 0
#define BIT(n) (1ul << (n))
#define UL_CONST(x) PASTE(x, ul)

//#define offsetof(type, member) ((bsize_t) &((type *)0)->member)


#endif


#endif /* INCLUDE_COMMON_MACRO_H_ */




