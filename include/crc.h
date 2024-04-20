#ifndef _CRC_H_
#define _CRC_H_

#include <common.h>
#include <define.h>
//                                      |       //Address       Default         Description
typedef struct
{
  unsigned long DR;                              //              0xFFFF'FFFF     Data register
  unsigned long IDR;                             //              0x0000'0000     Independent data register       (8 bits low is used)
  unsigned long RESET;                           //              0               Resets the CRC calculation unit and sets the data register to 0xFFFF FFFF
} CRC_TypeDef;

typedef struct
{
  unsigned long DR[32];                          //              0xFFFF'FFFF     Data register  
  unsigned long IDR[32];                         //              0x0000'0000     Independent data register       (8 bits low is used)
  unsigned long RESET[32];                       //              0               Resets the CRC calculation unit and sets the data register to 0xFFFF FFFF
} CRC_BITBAND_TypeDef;
//==============================================================================================================================================================
//===========================================================       LEVEL 1      ===============================================================================
//==============================================================================================================================================================
/*
 CRC-32 (Ethernet) polynomial: 0x4C11DB7
  X32 + X26 + X23 + X22 + X16 + X12 + X11 + X10 +X8 + X7 + X5 + X4 + X2+ X + 1
*/
unsigned long CRC_Calculator(CRC_TypeDef* CRC, unsigned long InitValue, unsigned long* Input, unsigned long Length);

#endif