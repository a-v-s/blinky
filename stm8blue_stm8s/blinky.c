//------------------------------------------------------------------------------
//
// Blinky Example for (what to name it?) STM8S103 boards
// -------------------------------------------------
// This will assume an LED has been connected to PB5
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

#include "stm8s.h"
#include <stdint.h>

int main(){

    PB_DDR |= (1 << 5);
    PB_CR1 |= (1 << 5);
    while(1) {
        for (uint32_t j = 1 ; j < 5; j++) {
            PB_ODR ^= (1 << 5);
            for (uint32_t i = 0; i <  (j*100000); i++) {
                __asm__("nop");
            }
        }
    }
}


