/*
GPIO Driver

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

// Include Headers -----------------------------------------------------------------------------------------------------

#include "gpio.h"

// Private Pre-Processor Definitions -----------------------------------------------------------------------------------

#define GPIO_DEVICE_ID XPAR_XGPIOPS_0_DEVICE_ID

// Private Type Definitions --------------------------------------------------------------------------------------------

// Private Function Prototypes -----------------------------------------------------------------------------------------

// Public Global Variables ---------------------------------------------------------------------------------------------

XGpioPs Gpio;

// Private Global Variables --------------------------------------------------------------------------------------------

XGpioPs_Config *gpioConfig;

// Interrupt Handlers --------------------------------------------------------------------------------------------------

// Public Function Definitions -----------------------------------------------------------------------------------------

void gpioInit(void)
{
	gpioConfig = XGpioPs_LookupConfig(GPIO_DEVICE_ID);
	XGpioPs_CfgInitialize(&Gpio, gpioConfig, gpioConfig->BaseAddr);

    // Set all EMIO GPIO to output low.
    for(u32 i = GPIO1_PIN; i <= T_EXP2_PIN; i++)
    {
    	XGpioPs_SetDirectionPin(&Gpio, i, 1);
    	XGpioPs_SetOutputEnablePin(&Gpio, i, 1);
    	XGpioPs_WritePin(&Gpio, i, 0);
    }
}

// Private Function Definitions ----------------------------------------------------------------------------------------
