#include "line.h"
#include "ti_msp_dl_config.h"
#include "motor.h"
uint8_t Gray_Line[8];

float Line_Control(void)
{
    if(Gray_Line[7] == 0) return 15;
    else if(Gray_Line[6] == 0) return 6;
    else if(Gray_Line[5] == 0) return 4;
    else if(Gray_Line[4] == 0) return 2;

    else if(Gray_Line[0] == 0) return -15;
    else if(Gray_Line[1] == 0) return -6;
    else if(Gray_Line[2] == 0) return -4;
    else if(Gray_Line[3] == 0) return -2;
    else return 0;
}

// float Line_Control(void)
// {
//     uint32_t value  = 0;
//     value=DL_GPIO_readPins(Line_PORT,Line__1_PIN|Line__2_PIN|Line__3_PIN|Line__4_PIN|Line__5_PIN|Line__6_PIN|Line__7_PIN|Line__8_PIN);
//     if(value & Line__1_PIN) Gray_Line[0] = 1;
//     else Gray_Line[0] = 0;
//     if(value & Line__2_PIN) Gray_Line[1] = 1;
//     else Gray_Line[1] = 0;
//     if(value & Line__3_PIN) Gray_Line[2] = 1;
//     else Gray_Line[2] = 0;
//     if(value & Line__4_PIN) Gray_Line[3] = 1;
//     else Gray_Line[3] = 0;
//     if(value & Line__5_PIN) Gray_Line[4] = 1;
//     else Gray_Line[4] = 0;
//     if(value & Line__6_PIN) Gray_Line[5] = 1;
//     else Gray_Line[5] = 0;
//     if(value & Line__7_PIN) Gray_Line[6] = 1;
//     else Gray_Line[6] = 0;
//     if(value & Line__8_PIN) Gray_Line[7] = 1;
//     else Gray_Line[7] = 0;
//     //val记录哪一个GPIO读取到了0，即识别到黑线,赋值给Gray_Line[8]
//     if(Gray_Line[7] == 0) return 15;
//     else if(Gray_Line[6] == 0) return 6;
//     else if(Gray_Line[5] == 0) return 4;
//     else if(Gray_Line[4] == 0) return 2;

//     else if(Gray_Line[0] == 0) return -15;
//     else if(Gray_Line[1] == 0) return -6;
//     else if(Gray_Line[2] == 0) return -4;
//     else if(Gray_Line[3] == 0) return -2;


//     //     //if(Gray_Line[7] == 0) return 20;
//     // //else if(Gray_Line[6] == 0) return 15;
//     //  if(Gray_Line[5] == 0) return 8;
//     // else if(Gray_Line[4] == 0) return 2;

//     // //else if(Gray_Line[0] == 0) return -20;
//     // //else if(Gray_Line[1] == 0) return -15;
//     // else if(Gray_Line[2] == 0) return -8;
//     // else if(Gray_Line[3] == 0) return -2;
//     else return 0;
// }

