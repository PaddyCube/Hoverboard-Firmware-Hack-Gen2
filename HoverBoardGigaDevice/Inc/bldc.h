/*
* This file is part of the hoverboard-firmware-hack-V2 project. The 
* firmware is used to hack the generation 2 board of the hoverboard.
* These new hoverboards have no mainboard anymore. They consist of 
* two Sensorboards which have their own BLDC-Bridge per Motor and an
* ARM Cortex-M3 processor GD32F130C8.
*
* Copyright (C) 2018 Florian Staeblein
* Copyright (C) 2018 Jakob Broemauer
* Copyright (C) 2018 Kai Liebich
* Copyright (C) 2018 Christoph Lehnert
*
* The program is based on the hoverboard project by Niklas Fauth. The 
* structure was tried to be as similar as possible, so that everyone 
* could find a better way through the code.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BLDC_H
#define BLDC_H

#include "gd32f1x0.h"
#include "config.h"


//----------------------------------------------------------------------------
// Set motor enable
//----------------------------------------------------------------------------
void setBldcEnable(FlagStatus setEnable);

//----------------------------------------------------------------------------
// Set pwm -1000 to 1000
//----------------------------------------------------------------------------
void setBldcPWM(int16_t setPwm);

//----------------------------------------------------------------------------
// Calculation-Routine for BLDC => calculates with 16kHz
//----------------------------------------------------------------------------
void CalculateBLDC(void);

void BLDC_Init(void);


extern uint8_t bldc_enable;
extern uint8_t bldc_enableFin;
extern volatile int pwml;
extern int ul, vl, wl;
extern int wheel_pos;
extern int16_t batVoltage;
extern int16_t curL_DC;
extern int16_t curL_phaA;
extern int16_t curL_phaB;
extern int16_t offset_current_dc;
extern int16_t odom_l;

extern long wheel_speed_rpm;
extern long wheel_speed_rpm_filtered;
extern long wheel_angle;

#endif
