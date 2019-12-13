/*
Encoder Stage Driver Include

Copyright (C) 2019 by Shane W. Colton

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef __ENCODER_INCLUDE__
#define __ENCODER_INCLUDE__

// Include Headers -----------------------------------------------------------------------------------------------------

#include "main.h"

// Public Pre-Processor Definitions ------------------------------------------------------------------------------------

// Public Type Definitions ---------------------------------------------------------------------------------------------

typedef struct __attribute__((packed))
{
	u32 c_RAM_addr[16];
	u32 c_RAM_addr_update[16];
	u32 q_mult_HH1_HL1_LH1;
	u32 q_mult_HH2_HL2_LH2;
	u32 q_mult_HH3_HL3_LH3;
	u32 control_q_mult_LL3;
	u16 debug_fifo_rd_count[16];
} Encoder_s;

// Public Function Prototypes ------------------------------------------------------------------------------------------

void encoderInit(void);
void encoderServiceRAMAddr(void);

// Externed Public Global Variables ------------------------------------------------------------------------------------

extern Encoder_s * Encoder;

#endif