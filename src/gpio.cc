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

#include <gpio.hh>
#include <assert.h>

/* CONSTRUCTOR */
GPIOPin::GPIOPin(volatile uint8_t * _ddr, volatile uint8_t * _port, uint8_t _pin)
{
    setRegister(_ddr);
    setPort(_port);
    setPin(_pin);
}

/* METHOD DEFINITIONS */

/**
 * setPin
 *
 * Sets the pin of the object. This should only be called once at instantiation
 *
 * @param _pin - GPIO pin represented by the object (ex. PB7)
 */
void GPIOPin::setPin(uint8_t _pin)
{
    this->pin = _pin;
}

/**
 * setPort
 *
 * Sets the port. This should only be called once at instantiation
 *
 * @param _port - pointer to the port
 */
void GPIOPin::setPort(volatile uint8_t * _port)
{
    this->port = _port;
}

/**
 * setRegister
 *
 * Sets the data direction register. THIS REALLY SHOULD ONLY BE CALLED AT
 * INSTATIATION
 *
 * @param _ddr -  pointer to the Data Direction Register. This should only be
 * called once at instantiation
 */
void GPIOPin::setRegister(volatile uint8_t * _ddr)
{
    this->ddr = _ddr;
}

/**
 * setMode
 *
 * Sets the Mode or direction of the data direction register
 *
 * @param _mode - Direction of the register (INPUT or OUTPUT)
 */
void GPIOPin::setMode(volatile uint8_t _mode)
{
    this->mode = _mode;

    // set the direction of the data direction register
    assert(_mode == INPUT || _mode == OUTPUT);
    if (this->mode == INPUT)
    {
        *this->ddr &= ~(1 << this->pin);
        
    }
    else
    {
        *this->ddr |= (1 << this->pin);
    }
}

/**
 * toggle
 *
 * Toggles the pin using XOR
 */
void GPIOPin::toggle(void)
{
		*this->port ^= (1 << this->pin);
}

/**
 * pinIOWrite
 *
 * Writes a value of ON or OFF to the port
 *
 * @param _state - ON or OFF
 */
void GPIOPin::pinIOWrite(uint8_t _state)
{
        assert(this->mode == OUTPUT);
		assert(_state == ON || _state == OFF);
		this->state = _state;

		if (this->state)
		{
				*this->port &= ~(1 << this->pin);
		}
		else
		{
				*this->port |= (1 << this->pin);
		}
}

/**
 * pinIORead
 *
 * Reads the value of the pin
 */
uint8_t GPIOPin::pinIORead(void)
{
        assert(this->mode == INPUT);
        return (*this->port & (1 << this->pin));

}
