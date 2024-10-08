#include <stdint.h>
#include <stdbool.h>

class Digital_in
{
private:
    uint8_t pinMask;
public:
    /// @brief init a pin at portc as input
    void init();

    /// @brief reads defined pin value
    /// @return True if pin is high
    bool is_hi();

    /// @brief reads defined pin value
    /// @return True if pin is low
    bool is_lo();

    /// @brief Set a pin of port c as input
    /// @param pin pin number at portc
    Digital_in(uint8_t pin);
    ~Digital_in();
};

