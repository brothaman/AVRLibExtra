/**
 * GPIO - Tools for AVR MCU UART, I2C, and SPI communications protocols
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


#ifndef COMMS_HH
#define COMMS_HH

#ifndef F_CPU
#error "F_CPU Not defined. Required for Serial"
#endif

// TODO: add support for serial (TX/RX)
// BASE CLASS FOR SERIAL
class BaseSerial
{
    public:
        /**
         * init
         *
         * Initialize the comm port
         */
        void init(uint16_t _baud);
        void setBaud(uint16_t _baud);
        short int getBaud(void);
        void printConfig(void);
        void send(uint8_t byte);
        int send(char * byte_array, int len);
        void readBuffer(char * c);
        int readBufferUntil(char c, char * buffer, int len);
        void loadBuffer(char c);
        int loadBuffer(char * buffer, int len);

    private:
        /**
         * setUBRRH
         *
         * set the high byte UART BAUD Rate Register
         *
         * @param
         */
        void setUBRRH(volatile uint8_t * _ubrrh);

        /**
         * setUBRRL
         *
         * set the low byte of UART BAUD Rate Register
         *
         * @param _ubrrl - pointer to UBRRL
         */
        void setUBRRL(volatile uint8_t * _ubrrl);
        /* UART baud rate register high */
        volatile uint8_t * ubrrh;

        /* UART baud rate register low */
        volatile uint8_t * ubrrl;

        /* UART Status control register A */
        volatile uint8_t * ucsra;

        /* UART Status control register B */
        volatile uint8_t * ucsrb;

        /* UART Status control register C */
        volatile uint8_t * ucrsc;

        /* UART Data Register */
        volatile uint8_t * udr;

        /* BAUDRATE */
        uint16_t baud;

} Serial0, Serial1, Serial2;
// CLASS FOR EACH SERIAL PORT

// TODO: add support for i2c
// TODO: add support for SPI

#endif
