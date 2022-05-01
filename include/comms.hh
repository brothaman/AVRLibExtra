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
        void setBaud(short int _baud);
        short int getBaud(void);

    private:
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
        short int baud;

} Serial0, Serial1, Serial2;
// CLASS FOR EACH SERIAL PORT

// TODO: add support for i2c
// TODO: add support for SPI

#endif
