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
