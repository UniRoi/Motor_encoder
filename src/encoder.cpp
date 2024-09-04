#include <encoder.h>
#include <avr/interrupt.h>

encoder::encoder(int8_t pin_A_number, int8_t pin_B_number): EncoderAPin(pin_A_number) , EncoderBPin(pin_B_number)
{

}

encoder::~encoder()
{
}

void encoder::init(void)
{
    // use external interrupt 0 
    EICRA = (1 << ISC01) | (1 << ISC00); // The rising edge of INT0 generates an interrupt request.
    EIMSK = (1 << INT0); // External Interrupt Request 0 Enable
}



void encoder::update(void)
{
    bool bDirection = false;

    // state change occured 
    bDirection = EncoderBPin.is_hi();
    
    // rising edge detected
    if(bDirection == true)
    {
        /* negative direction */ 
        ui16EncoderPos--;
    }
    else
    {
        /* positive direction */ 
        ui16EncoderPos++;
    }

}

int16_t encoder::position(void)
{
    return ui16EncoderPos;
}

