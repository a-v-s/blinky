//------------------------------------------------------------------------------
//
// Blinky Example for Blue Pill STM32F103C8T6 boards
// -------------------------------------------------
// This will assume an LED has been connected to PC13
// The LED will blink at 1 Hz
//
// This is a very basic example, to be used to verify your setup.
// This example does not initialise any clocks and the MCU runs on power on 
// defaults.
//
//------------------------------------------------------------------------------
/*
 MIT License

 Copyright (c) 2021 André van Schoubroeck

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

*/

#include "stm32f1xx_hal.h"

int main(){
    // Initialise the HAL
    HAL_Init();

    // Enable the clock to GPIO PORT C
    __HAL_RCC_GPIOC_CLK_ENABLE();

    // Configure PC13 for output (PushPull mode)
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = (GPIO_PIN_13);
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	while(1){
	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
	    HAL_Delay(500);
	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
	    HAL_Delay(500);
    }
}

// The HAL activates the SysTick, we should handle its interrupt and 
// redirect it into the HAL. The SysTick is used for HAL_Delay()
void SysTick_Handler(void) {
	HAL_IncTick();
}
