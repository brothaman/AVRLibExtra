/**
 * GPIO - Tools for AVR MCU General Purpose IO pins
 * Copyright (C) 2022  Robert Brothers
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef GPIO_HH
#define GPIO_HH


#include "avr/io.h"

#define INPUT   0
#define OUTPUT  1
#define ON 		1
#define OFF 	0

/**
 * GPIO Pin
 * A class to generate pin objects.
 * Each pin Consist of
 * @data pin - the pin ex. PB7
 * @data ddr - the data direction register (ex. DDRB)
 * @data mode - the mode of the pin (ex. OUTPUT or INPUT
 */
class GPIOPin
{
    public:
        /* CONSTRUCTOR */
        GPIOPin(volatile uint8_t * _ddr, volatile uint8_t * _port, uint8_t _pin);

        /* GPIO BEHAVIOR */
        void toggle(void);

        /* PIN READ/WRITE */
        void pinIOWrite(uint8_t _state);
        uint8_t pinIORead(void);

        /* SETTERS */
        void setMode(uint8_t _mode);

        /* GETTERS */
        uint8_t getPin(void);
        uint8_t * getDDR(void);
        uint8_t getMode(void);

    private:
        uint8_t pin;
        volatile uint8_t * ddr;
        volatile uint8_t * port;
        uint8_t mode;
        uint8_t state;

        /* SETTERS */
        void setPin(uint8_t _pin);
        void setPort(volatile uint8_t * _ddr);
        void setRegister(volatile uint8_t * _ddr);

};

// TODO: add methods to attach interrupts
// TODO: add support for adcs and dacs
#endif // GPIO_HH
