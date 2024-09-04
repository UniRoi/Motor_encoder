#include <stdint.h>
#include <stdbool.h>
#include <digital_in.h>

class encoder
{
private:
    uint8_t encoder_pin;
    Digital_in EncoderAPin;
    Digital_in EncoderBPin;
    volatile uint16_t ui16EncoderPos = 0;
public:

    void init(void);
    int16_t position(void);
    void update(void);

    encoder(int8_t pin_A_number, int8_t pin_B_number);
    ~encoder();
};

