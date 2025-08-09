#include "ti_msp_dl_config.h"
#include "Delay.h"

void Delay_us(uint32_t us){
    while(us--){
        delay_cycles(80);
    }
}
void Delay_ms(uint32_t ms){
    while(ms--){
        Delay_us(1000);
    }
}
void Delay_s(uint32_t s){
    while(s--){
        Delay_ms(1000);
    }
}