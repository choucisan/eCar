#ifndef __CONTROL_H
#define __CONTROL_H
void title_1(void);
void Control_ABCDA(void);
void Control_ACBDA(void);
void Control_ACBDAx4(void);
void openmv_xunxian(void);
#define  Limit		100						//PWM波限幅，百分比制
extern uint8_t ledbegin,lednum,ledflag,ledflag1,ledflag2,timeslow,start_flag,begingray,grayflag;
#endif