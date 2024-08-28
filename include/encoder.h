#include <stdint.h>
#include <stdbool.h>
#include <digital_in.h>

class encoder
{
private:
    /* data */
    uint8_t encoder_pin;
    Digital_in EncoderPin;
    uint16_t ui16EncoderPos = 0;
public:

    void init(void);
    int16_t position(void);
    void update(void);

    encoder(int8_t pin_number = -1);
    ~encoder();
};

