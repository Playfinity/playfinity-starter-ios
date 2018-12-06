/*!
 *  \author         Ole A. Torvmark <o.a.torvmark@ti.com , torvmark@stalliance.no>
 *  \brief          Adaption of Madgwick to iOS
 *  \copyright      Copyright (c) 2015 Texas Instruments Inc.
 *  \file           AHRSAlgo.h
 */

#import <Foundation/Foundation.h>

@interface AHRSAlgo : NSObject


//=====================================================================================================
// AHRS.h
// S.O.H. Madgwick
// 25th August 2010
//=====================================================================================================
//
// See AHRS.c file for description.
//
//=====================================================================================================
#ifndef AHRS_h
#define AHRS_h

//----------------------------------------------------------------------------------------------------
// Variable declaration
@property float q0;
@property float q1;
@property float q2;
@property float q3;
@property float q4;

@property float beta;
@property float halfT;


@property float exInt;
@property float eyInt;
@property float ezInt;	// scaled integral error

//---------------------------------------------------------------------------------------------------
// Function declaration

-(instancetype) init:(float) sampleFrequency;

-(void) AHRSupdate:(float)gx gy:(float) gy gz:(float) gz ax:(float) ax ay:(float) ay az:(float) az mx:(float) mx my:( float) my mz:(float) mz;

+(void) quaternionToEuler:(float)q0 q1:(float)q1 q2:(float)q2 q3:(float)q3 roll:(float*)roll pitch:(float*)pitch yaw:(float*)yaw ;

#endif
//=====================================================================================================
// End of file
//=====================================================================================================

@end
