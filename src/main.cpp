#include <encoder.h>
#include <util/delay.h>
#include <digital_out.h>
#include <Arduino.h>

#include <avr/interrupt.h>

static uint16_t lastEncCnt = 0;
encoder Encoder(2, 3);
Digital_out Led(5);

int main(void)
{

  uint16_t ui16EncCnt = 0;
  
  
  Led.init();

  // here interrupt registers are set
  Encoder.init();
  sei();

  // Add serial for part 2
  Serial.begin(115200);
  
  while (1)
  {
    /* infinity loop */
    _delay_us(50);

    // Encoder.update();
    ui16EncCnt = Encoder.position();

    if(ui16EncCnt != lastEncCnt)
    {
      
      lastEncCnt = ui16EncCnt;

      // print counter to serial
      Serial.print(ui16EncCnt);
      Serial.println();
    }
    
  }
  return 0;
}

// interupt service routine of external int0
ISR(INT0_vect)
{
    Led.set_hi();
    Encoder.update();
    Led.set_lo();
}