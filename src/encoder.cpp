#include <encoder.h>
// #include <digital_in.h>



encoder::encoder(int8_t pin_number): EncoderPin(pin_number) 
{

}

encoder::~encoder()
{
}

void encoder::init(void)
{
    
}



void encoder::update(void)
{
    static bool bLastEncState = false;
    bool bEncState = false;

    bEncState = EncoderPin.is_hi();
    if(bEncState != bLastEncState)
    {
        // state change occured 
        bLastEncState = bEncState;
        
        if(bEncState == true)
        {
            // rising edge detected
            ui16EncoderPos++;
        }
    }
    
}

int16_t encoder::position(void)
{
    return ui16EncoderPos;
}