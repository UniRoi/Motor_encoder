#include <encoder.h>
#include <util/delay.h>
#include <digital_out.h>
#include <Arduino.h>



static uint16_t lastEncCnt = 0;


int part2_main(void)
{

  uint16_t ui16EncCnt = 0;
  
  Digital_out Led(5);
  Led.init();

  encoder encoder(0, 1);
  encoder.init();

  // Add serial for part 2
  Serial.begin(115200);
  
  while (1)
  {
    /* infinity loop */
    _delay_us(250);

    encoder.update();
    ui16EncCnt = encoder.position();

    if(ui16EncCnt != lastEncCnt)
    {
      // Led.toggle();
      Led.set_hi();
      lastEncCnt = ui16EncCnt;

      // print counter to serial
      Serial.print(ui16EncCnt);
      Serial.println();
    }
    else
    {
      Led.set_lo();
    }
  }
  return 0;
}