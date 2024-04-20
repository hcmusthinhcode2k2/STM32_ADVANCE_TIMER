#include <stm32f103c8t6.h>

//static unsigned char count=0;
//void TIM1_UP_IRQHandler()
//{
//  TIM1.SR.REG = 0;
//  GPIOB.ODR.BITS.b13 = !GPIOB.ODR.BITS.b13;
//  if (count<10)
//  {
//    count++;
//    if (count==10)
//    {
//       *((unsigned long*)0xE000E100) = 0;
//    }
//  }
//}
void main()
{
    //B13 (TIM1_CH1N) is output AF 
    RCC.APB2_ENR.BITS.IOPB = 1;
    GPIO_Mode(&GPIOB,BIT13,GPIO_MODE_AF_OUTPUT_PUSHPULL_50MHz);
    //A8  (TIM1_CH1) is output AF
    RCC.APB2_ENR.BITS.IOPA = 1;
    GPIO_Mode(&GPIOA,BIT8,GPIO_MODE_AF_OUTPUT_PUSHPULL_50MHz);
    
    //TIM1 :base clock = 8MHz ,IDR =1ms
//    TIM1.CR2.REG = 0;
//    TIM1.SMCR.REG = 0;
//    TIM1.DIER.REG = BIT0;
//    TIM1.ARR = 7999;
//    TIM1.CR1.REG = BIT7 | BIT2 | BIT0;
    RCC.APB2_ENR.BITS.TIM1 = 1;
     

    TIM1.CCMR.OUTPUT.CH1.BITS.OCM = 6;
    TIM1.CCMR.OUTPUT.CH1.BITS.CCS = 0;
    
   
    TIM1.BDTR.BITS.MOE  =1;
    TIM1.BDTR.BITS.OSSI =1;
    TIM1.BDTR.BITS.OSSR =1;
     TIM1.BDTR.BITS.DT = 8; //DEAD-TIME : 1us
    
    TIM1.CCER.BITS.CC1E = 1;
    TIM1.CCER.BITS.CC1NE = 1;
    TIM1.CCR1 = 3200;
    
    TIM1.CR2.REG = 0;
    TIM1.SMCR.REG = 0;
    TIM1.DIER.REG = 0;
    TIM1.ARR = 7999;
    
    TIM1.EGR.BITS.UG = 1;
//    TIM1.BDTR.BITS.MOE  =1;
    TIM1.CR1.REG = BIT7 | BIT2 | BIT0;
    
    
    while(1)
      
    {
      
    }
}
//void main()
//{
//
//   RCC.APB2_ENR.BITS.IOPB=1;
//   GPIO_Mode(&GPIOB,BIT13,GPIO_MODE_OUTPUT_PUSHPULL_50MHz);
//   
//   RCC.APB2_ENR.BITS.TIM1=1;
//   TIM1.CR2.REG = 0;
//   TIM1.SMCR.REG=0;
//   TIM1.DIER.REG = BIT0;
//   TIM1.ARR = 7999;
//   TIM1.CR1.REG = BIT7 | BIT2 | BIT0;
//   *((unsigned long*)0xE000E100) = BIT25;
//   while(1)
//   {
//     
//   }
//}
