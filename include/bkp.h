#ifndef _BKP_H_
#define _BKP_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  unsigned long _reserved;
  unsigned long DR_1_10[10];                     //              0x0000'0000     Backup data register
  BUNION(RTCCR, unsigned long,                   //              0x0000'0000     RTC clock calibration register
    CAL                                 , 7,    //0:6           0               Calibration value
    CCO                                 , 1,    //7             0               Calibration clock output
    ASOE                                , 1,    //8             0               Alarm or second output enable
    ASOS                                , 1,    //9             0               Alarm or second output selection
    _reserved                           , 22);
  BUNION(CR, unsigned long,                      //              0x0000'0000     Backup control register
    TPE                                 , 1,    //0             0               TAMPER pin enable
    TPAL                                , 1,    //1             0               TAMPER pin active level
    _reserved                           , 30);
  BUNION(CSR, unsigned long,                     //              0x0000'0000     Backup control/status register
    CTE                                 , 1,    //0             0               Clear tamper event
    CTI                                 , 1,    //1             0               Clear tamper interrupt
    TPIE                                , 1,    //2             0               TAMPER pin interrupt enable
    _reserved                           , 5,
    const TEF                           , 1,    //8             0               Tamper event flag
    const TIF                           , 1,    //9             0               Tamper interrupt flag
    _reserved1                          , 22);
  unsigned long _reserved1[2];
  unsigned long DR_11_42[32];                    //              0x0000'0000     Backup data register
} BKP_TypeDef;

typedef struct
{
  unsigned long _reserved[32];
  unsigned long DR_1_10[10][32];                 //              0x0000'0000     Backup data register
  RSTRUCT(RTCCR, unsigned long,                  //              0x0000'0000     RTC clock calibration register
    CAL                                 [7],    //0:6           0               Calibration value
    CCO                                    ,    //7             0               Calibration clock output
    ASOE                                   ,    //8             0               Alarm or second output enable
    ASOS                                   ,    //9             0               Alarm or second output selection
    _reserved                           [22]);
  RSTRUCT(CR, unsigned long,                     //              0x0000'0000     Backup control register
    TPE                                    ,    //0             0               TAMPER pin enable
    TPAL                                   ,    //1             0               TAMPER pin active level
    _reserved                           [30]);
  RSTRUCT(CSR, unsigned long,                    //              0x0000'0000     Backup control/status register
    CTE                                    ,    //0             0               Clear tamper event
    CTI                                    ,    //1             0               Clear tamper interrupt
    TPIE                                   ,    //2             0               TAMPER pin interrupt enable
    _reserved                           [5],
    const TEF                              ,    //8             0               Tamper event flag
    const TIF                              ,    //9             0               Tamper interrupt flag
    _reserved1                          [22]);
  unsigned long _reserved1[2][32];
  unsigned long DR_11_42[32][32];                //              0x0000'0000     Backup data register
} BKP_BITBAND_TypeDef;

#endif