#ifndef _IDWG_H_
#define _IDWG_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  unsigned long KEY;                             //              0x0000'0000     Key register (16 bits low is used)
  unsigned long PR;                              //              0x0000'0000     Prescaler register (3 bits low is used)
  unsigned long PLR;                             //              0x0000'0FFF     Reload register (12 bits low is used)
  BUNION(SR, unsigned long,                      //              0x0000'0000     Status register
    PVU                                 , 1,    //0             0               Watchdog prescaler value update
    RVU                                 , 1,    //1             0               Watchdog counter reload value update
    _reserved                           , 30);
} IDWG_TypeDef;

typedef struct
{
  unsigned long KEY[32];                         //              0x0000'0000     Key register (16 bits low is used)
  unsigned long PR[32];                          //              0x0000'0000     Prescaler register (3 bits low is used)
  unsigned long PLR[32];                         //              0x0000'0FFF     Reload register (12 bits low is used)
  RSTRUCT(SR, unsigned long,                     //              0x0000'0000     Status register
    PVU                                    ,    //0             0               Watchdog prescaler value update
    RVU                                    ,    //1             0               Watchdog counter reload value update
    _reserved                           [30]);
} IDWG_BITBAND_TypeDef;

#endif