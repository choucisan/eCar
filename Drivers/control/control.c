#include "line.h"
#include "ti_msp_dl_config.h"
#include "motor.h"
#include "motor.h"
#include "control.h"
#include "printf.h"
#include "Delay.h"
#include "sensor.h"

extern uint8_t Gray_Line[8];
extern unsigned char Digtal;
float     Kp1=0.5;  
float	  Ki1=0;
float	  Kd1=0.05;

float Speed_Middle=25;				//中值速度

uint8_t ledbegin=0,lednum=0,ledflag=0,ledflag1=0,ledflag2=0;
uint8_t begingray=0,grayflag=0;
uint8_t a=0; 

float PID_Gray(void)
{
	static float err, Last_err,Sum_err;
	float Pwm;
	Last_err = err;			//记录误差
	err = Line_Control();  	//计算误差
	Sum_err+=err;				//累加误差	
    Sum_err=PWM_Limit(Sum_err,50,-50);			                                                
	//积分限幅
	Pwm = Kp1 * err+ Ki1 * Sum_err + Kd1 * (err - Last_err);   	//位置式PID控制器
    PWM_Limit(Pwm,Limit, -Limit);
	return Pwm;           
}
uint8_t straight_flag=0;
uint8_t n=0,cnt_flag=0;
uint8_t run=4;
uint8_t cycle_speedl=5,cycle_speedr=18;
uint8_t timeslow=0;

void title_1(void)                       //模式一
{
    uint8_t i=0;
    for(i=0;i<8;i++)
	{
		Gray_Line[i]=(Digtal>>i)&0x01;
	}
    float Motor_Left, Motor_Right;            //电机赋值
    float bias;                             //差速值
    if(((Gray_Line[0]==0)&&(Gray_Line[2]==0))||((Gray_Line[0]==0)&&(Gray_Line[3]==0))||((Gray_Line[0]==0)&&(Gray_Line[4]==0))||((Gray_Line[1]==0)&&(Gray_Line[3]==0))||((Gray_Line[1]==0)&&(Gray_Line[4]==0))||((Gray_Line[2]==0)&&(Gray_Line[4]==0)))
    //13  识别到转弯口                                              14                                  15                                                  24                                25                                          35
    {
        straight_flag=1;//开始直角转弯
    }
    if(straight_flag==1)//转弯
    {
        if(n==run)//走到指定圈速
        {
            DL_GPIO_clearPins(GPIO_STBY_PORT,GPIO_STBY_PIN_STBY_PIN);
        }
        begingray=1;//转弯等待0.3s后开始监测是否进入巡线轨道（防止误触）
        if(grayflag==1)        //只有四或者五寻到黑线
        {
            //if(((Gray_Line[3]==1)&&(Gray_Line[2]==1)&&(Gray_Line[1]==1)&&(Gray_Line[0]==0))||((Gray_Line[3]==1)&&(Gray_Line[2]==1)&&(Gray_Line[1]==0)))
            if(((Gray_Line[3]==1)&&(Gray_Line[2]==0))||((Gray_Line[4]==1)&&(Gray_Line[3]==0))||((Gray_Line[5]==1)&&(Gray_Line[4]==0)))
            {
                straight_flag=0;
                grayflag=0;
            }
        }
        Set_Pwm(cycle_speedl, cycle_speedr);
        cnt_flag=0;
    }
    else if(straight_flag==0) 
    {
        if(cnt_flag==0)
        {
            cnt_flag=1;
            n=n+1;
        }
        begingray=0;
        grayflag=0;
        bias=PID_Gray();
        Motor_Left=Speed_Middle+bias;
        Motor_Right=Speed_Middle-bias;
        Motor_Left=PWM_Limit(Motor_Left,100,-100);
        Motor_Right=PWM_Limit(Motor_Right,100,-100);  
        Set_Pwm(Motor_Left, Motor_Right);
    }
}
