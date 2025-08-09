#include "ti_msp_dl_config.h"
#include "eCar.h"
#include "stdio.h"
#include "motor.h"
#include "line.h"
#include "Delay.h"
#include "control.h"
#include "printf.h"
#include "interrupt.h"
#include "control.h"
#include "sensor.h"


char oled_buffer[30];
uint16_t cx;
int8_t motor_left,motor_right;//占空比
 
//extern声明一下方便按键调节数值
extern float Kp1;
extern float Kd1;
extern float Ki1;
extern float Speed_Middle;
extern uint8_t run;//小车转圈标志位控制转几圈
extern uint8_t cycle_speedl,cycle_speedr;//转弯时左右轮差速
extern uint8_t Gray_Line[8];

uint8_t mode=0;     //小车运动模式    ：1，2，3，4，0
uint8_t begin=0;      //小车启动标志位：1启动、0停止

uint8_t cycle=1;
uint8_t change=0;


//无mcu定义变量
unsigned short Anolog[8]={0};
unsigned short white[8]={ 3100,3170,3185,3185,3180,3080,3190,2780};
unsigned short black[8]={1060,1780,1470,1360,1530,600,1040,310};
unsigned short Normal[8];
unsigned char Digtal;
void button(void)
{
        //速度切换
        if(!DL_GPIO_readPins(MODE_PORT, MODE_ctrl_PIN))            //模式切换
        {
            Delay_ms(10);//软件消抖
            if(!DL_GPIO_readPins(MODE_PORT, MODE_ctrl_PIN))
            {
                Speed_Middle=Speed_Middle+3;
            }
            while(!DL_GPIO_readPins(MODE_PORT, MODE_ctrl_PIN));
        }
        //小车启动
        if(!DL_GPIO_readPins(BEGIN_PORT, BEGIN_GO_PIN))       //小车启动
        {
            Delay_ms(10);//软件消抖
            if(!DL_GPIO_readPins(BEGIN_PORT, BEGIN_GO_PIN))
            {
                Delay_ms(700);//启动延时
                DL_GPIO_setPins(GPIO_STBY_PORT,GPIO_STBY_PIN_STBY_PIN);
                begin=1;
            }
            while(!DL_GPIO_readPins(BEGIN_PORT, BEGIN_GO_PIN));
        }
        //状态改变
        if(!DL_GPIO_readPins(Change_PORT, Change_all_PIN))     
        {
            Delay_ms(10);//软件消抖
            if(!DL_GPIO_readPins(Change_PORT, Change_all_PIN))
            {
                change=change+1;
                change=change%2;
            }
            while(!DL_GPIO_readPins(Change_PORT, Change_all_PIN));
        }
        if(change==0)
        {
            //调节左轮差速
            if(!DL_GPIO_readPins(PID_PORT, PID_KP_PIN))    
            {
                Delay_ms(10);//软件消抖
                if(!DL_GPIO_readPins(PID_PORT, PID_KP_PIN))
                {
                    cycle_speedl+=1;
                }
                while(!DL_GPIO_readPins(PID_PORT, PID_KP_PIN));
            }
            //调节右轮差速
            if(!DL_GPIO_readPins(PID_PORT, PID_KI_PIN))      
            {
                Delay_ms(10);//软件消抖
                if(!DL_GPIO_readPins(PID_PORT, PID_KI_PIN))
                {
                    cycle_speedr+=2;
                }
                while(!DL_GPIO_readPins(PID_PORT, PID_KI_PIN));
            }
            //调节转圈数
            if(!DL_GPIO_readPins(PID_PORT, PID_KD_PIN))       
            {
                Delay_ms(10);//软件消抖
                if(!DL_GPIO_readPins(PID_PORT, PID_KD_PIN))
                {
                    cycle=cycle+1;
                    cycle=cycle%6;
                    run=cycle*4;
                }
                while(!DL_GPIO_readPins(PID_PORT, PID_KD_PIN));
            }
        }
        else if(change==1)
        {
            //调节kp
            if(!DL_GPIO_readPins(PID_PORT, PID_KP_PIN))    
            {
                Delay_ms(10);//软件消抖
                if(!DL_GPIO_readPins(PID_PORT, PID_KP_PIN))
                {
                    Kp1+=0.05;
                }
                while(!DL_GPIO_readPins(PID_PORT, PID_KP_PIN));
            }
            //调节ki
            if(!DL_GPIO_readPins(PID_PORT, PID_KI_PIN))      
            {
                Delay_ms(10);//软件消抖
                if(!DL_GPIO_readPins(PID_PORT, PID_KI_PIN))
                {
                    Ki1+=0.05;
                }
                while(!DL_GPIO_readPins(PID_PORT, PID_KI_PIN));
            }
            //调节kd
            if(!DL_GPIO_readPins(PID_PORT, PID_KD_PIN))       
            {
                Delay_ms(10);//软件消抖
                if(!DL_GPIO_readPins(PID_PORT, PID_KD_PIN))
                {
                    Kd1+=0.05;
                }
                while(!DL_GPIO_readPins(PID_PORT, PID_KD_PIN));
            }
        }
}
int main(void)
{
    No_MCU_Sensor sensor;
    
    SYSCFG_DL_init();

    SysTick_Init();
    DL_Timer_startCounter(PWM_Car_INST);                      
    //开启pwm电机调速

    NVIC_ClearPendingIRQ(TIMER_Encoder_Read_INST_INT_IRQN); //清除定时器50ms中断标志位
    NVIC_EnableIRQ(TIMER_Encoder_Read_INST_INT_IRQN);       //使能定时器50ms中断标志位
    DL_Timer_startCounter(TIMER_Encoder_Read_INST);         //50ms定时器开始计时

    OLED_Init(); 
    Delay_ms(200);
    //OLED初始化 
    No_MCU_Ganv_Sensor_Init(&sensor,white,black);
	delay_ms(100);
    //灰度初始化

    while (1) 
    {     
        button();//按键脱机修改参数
        No_Mcu_Ganv_Sensor_Task_Without_tick(&sensor);
        //灰度读取
        Digtal=Get_Digtal_For_User(&sensor);
			
        if(change==0)
        {
            sprintf(oled_buffer, "L:%d R:%d", cycle_speedl,cycle_speedr);
            OLED_ShowString(0,1,(uint8_t *)oled_buffer,8);
            sprintf(oled_buffer, "cycle:%d",cycle);
            OLED_ShowString(0,2,(uint8_t *)oled_buffer,8);
        }
        else if(change==1)
        {
            sprintf(oled_buffer, "KP:%.2f Kd:%.2f", Kp1,Kd1);
            OLED_ShowString(0,1,(uint8_t *)oled_buffer,8);
            sprintf(oled_buffer, "KI:%.2f",Ki1);
            OLED_ShowString(0,2,(uint8_t *)oled_buffer,8);
        }
        sprintf(oled_buffer, "speed:%f",Speed_Middle);
        OLED_ShowString(0,0,(uint8_t *)oled_buffer,8);
    }
}

void TIMER_Encoder_Read_INST_IRQHandler(void)//50ms定时中断
{
	if(DL_TimerA_getPendingInterrupt(TIMER_Encoder_Read_INST))
	{
		if(DL_TIMER_IIDX_ZERO)
		{
            //函数逻辑
            if (begin==1)          title_1();//执行绕任意圈数
            if(begingray==1)
            {
                if(timeslow==10)
                {
                    timeslow=0;
                    begingray=0;
                    grayflag=1;
                }
                timeslow++;
            }
        }

	}
}


void HardFault_Handler(void)
{
     __BKPT();
}


