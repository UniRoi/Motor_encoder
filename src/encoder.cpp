#include <encoder.h>
// #include <digital_in.h>



encoder::encoder(int8_t pin_A_number, int8_t pin_B_number): EncoderAPin(pin_A_number) , EncoderBPin(pin_B_number)
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
    bool bDirection = false;

    bEncState = EncoderAPin.is_hi();
    if(bEncState != bLastEncState)
    {
        // state change occured 
        bLastEncState = bEncState;
        bDirection = EncoderBPin.is_hi();
        
        if(bEncState == true)
        {
            // rising edge detected
                ui16EncoderPos++;
            // if(bDirection == true)
            // {
            //     /* positive direction */ 
            // }
            // else
            // {
            //     /* negative direction */ 
            //     ui16EncoderPos--;
            // }
            
        }
    }
    
}

int16_t encoder::position(void)
{
    return ui16EncoderPos;
}