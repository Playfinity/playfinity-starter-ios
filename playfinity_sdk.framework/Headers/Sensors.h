/*!
 *  \author         Ole A. Torvmark <o.a.torvmark@ti.com , torvmark@stalliance.no>
 *  \brief          Contains all the functions for SensorTag Sensors
 *  \copyright      Copyright (c) 2013 Texas Instruments Inc.
 *  \file           Sensors.h
 */

/*
 IMPORTANT: Your use of this Software is limited to those specific rights
 granted under the terms of a software license agreement between the user
 who downloaded the software, his/her employer (which must be your employer)
 and Texas Instruments Incorporated (the "License").  You may not use this
 Software unless you agree to abide by the terms of the License. The License
 limits your use, and you acknowledge, that the Software may not be modified,
 copied or distributed unless embedded on a Texas Instruments microcontroller
 or used solely and exclusively in conjunction with a Texas Instruments radio
 frequency transceiver, which is integrated into your product.  Other than for
 the foregoing purpose, you may not use, reproduce, copy, prepare derivative
 works of, modify, distribute, perform, display or sell this Software and/or
 its documentation for any purpose.
 
 YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
 PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
 NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
 TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
 NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
 LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
 INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
 OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
 OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
 (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 
 Should you have any questions regarding your right to use this Software,
 contact Texas Instruments Incorporated at www.TI.com.
 */


#import <Foundation/Foundation.h>
#import "BLEUtility.h"

@interface  sensorC953A: NSObject


#define TEMP_T0 298.15
#define R 287.05
#define G 9.80665


///Calibration values unsigned
@property UInt16 c1,c2,c3,c4;
///Calibration values signed
@property int16_t c5,c6,c7,c8;

@property float calibPress;
@property float lastPress;
@property BOOL isSfloat;
@property BOOL isNormalFloat;

-(id) initWithCalibrationData:(NSData *)data;
-(id) initSfloatVersion;
-(id) initNormalfloatVersion;

-(float) calcPressure:(NSData *)data;
-(void) calibrateHeight;
-(float) calcHeight;
-(float) calcTemp:(NSData *)data;
+(float) calcHeight:(float)pres calibPres:(float)calibPres;

@end

@interface sensorIMU3000: NSObject

@property float lastX,lastY,lastZ;
@property float calX,calY,calZ;

#define IMU3000_RANGE 500.0

-(id) init;

-(void) calibrate;
-(float) calcXValue:(NSData *)data;
-(float) calcYValue:(NSData *)data;
-(float) calcZValue:(NSData *)data;
+(float) getRange;

@end

@interface sensorKXTJ9 : NSObject

#define KXTJ9_RANGE 16.0

+(float) calc16XValue:(NSData *)data;
+(float) calc16YValue:(NSData *)data;
+(float) calc16ZValue:(NSData *)data;

+(float) calcXValue:(NSData *)data;
+(float) calcYValue:(NSData *)data;
+(float) calcZValue:(NSData *)data;
+(float) getRange;

@end

@interface sensorMAG3110 : NSObject

@property float lastX,lastY,lastZ;
@property float calX,calY,calZ;

#define MAG3110_RANGE 2000.0

-(id) init;
-(void) calibrate;
-(float) calcXValue:(NSData *)data;
-(float) calcYValue:(NSData *)data;
-(float) calcZValue:(NSData *)data;
+(float) getRange;

@end

@interface sensorTMP007 : NSObject

@property double *transientBuffer;

+(float) calcTAmb:(NSData *)data;
+(float) calcTAmb:(NSData *)data offset:(int)offset;
+(float) calcTObj:(NSData *)data;

@end

@interface sensorTMP006 : NSObject

@property double *transientBuffer;

-(id) init;

+(float) calcTAmb:(NSData *)data;
+(float) calcTAmb:(NSData *)data offset:(int)offset;
-(float) calcTObj:(NSData *)data;
@end

@interface sensorSHT21 : NSObject

+(float) calcRH:(NSData *)data;
+(float) calcPress:(NSData *)data;
+(float) calcTemp:(NSData *)data;

@end

@interface filterLP : NSObject

@property int filterLength;
@property float *filter;

-(id)initWithLength:(int)len;
-(void) input:(float)val;
-(float)output;

@end

@interface conversions : NSObject

+(float) toFahrenheit:(float)centigrade;
+(float) toCentigrade:(float)fahrenheit;
+(float) toFeet:(float)meter;

@end




