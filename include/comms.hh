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
