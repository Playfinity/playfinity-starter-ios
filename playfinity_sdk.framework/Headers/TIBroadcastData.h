/*!
 *  \author         Ole A. Torvmark <o.a.torvmark@ti.com , torvmark@stalliance.no>
 *  \brief          Contains Broadcast data parsing functions
 *  \copyright      Copyright (c) 2014 Texas Instruments Inc.
 *  \file           TIBroadcastData.h
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

#define TIBROADCASTDEVICEID_WEATHERSTATION                          0x00
#define TIBROADCASTDEVICEID_UTAG                                    0x01
#define TIBROADCASTDEVICEID_DUALBANDSHOWCASE                        0x02
#define TIBROADCASTDEVICEID_SENSORTAG2                              0x03
#define TIBROADCASTDEVICEID_SUB1NODE                                0x04
#define TIBROADCASTDEVICEID_SUB1NODE_WITH_BLE                       0x05
#define TIBROADCASTDEVICEID_TEAMBUILDING                            0xAA

#define TIBROADCAST_MINIMAL_ADVDATA_LEN                             4


#define TIBROADCAST_UTAG_DATATYPE_TEMPERATURE                       0x00
#define TIBROADCAST_UTAG_DATATYPE_ACCELEROMETER                     0x01
#define TIBROADCAST_UTAG_DATATYPE_PHYSICAL_ATTACHEMENT              0x02

#define TIBROADCAST_WEATHERSTATION_DATATYPE_CALIBRATE               0x0A
#define TIBROADCAST_WEATHERSTATION_DATATYPE_IMMEDIATE               0xBB
#define TIBROADCAST_WEATHERSTATION_DATATYPE_HISTORIC1               0xF1

#define TIBROADCAST_SUB1NODE_DATATYPE_COMPOUND_DATA                 0x00

#define TIBROADCAST_SUB1NODE_WITH_BLE_DATATYPE_COMPOUND_DATA        0x00

#define UINT16FLIP(a,b) a = ((b >> 8) & 0xff) | ((b & 0xff) << 8)
#define UINT32FLIP(a,b) a = ((b >> 24) & 0xff) | ((b >> 8) & 0xFF00) | ((b << 8) & 0xFF0000) | ((b << 16) & 0xFF000000)


@interface TIBroadcastData : NSObject

@property uint16_t  manifacturer;
@property uint8_t   deviceId;
@property uint8_t   dataType;
@property NSData    *profileData;

+(TIBroadcastData *) parseTIBroadcastData:(NSData *)advManifData;

@end


typedef struct __attribute__((packed)) {
    uint8_t ieeeAddr[8];        //8
    int8_t rssi;                //9
    uint8_t switchLed;          //10
    uint16_t batVoltage;        //13
    uint16_t objTemp;           //15
    int16_t accelX;            //17
    uint16_t opt;              //19
}dualBandCompoundedData_t;


@interface TIDualBandConcentratorData : NSObject




-(instancetype) initWithTIBroadcastData:(TIBroadcastData *)bData;
@property TIBroadcastData *bDat;

-(BOOL) isSubOneMessage;
-(uint8_t *) getIEEEAddress;
-(uint8_t) getSwitchLed;
-(float) getBatteryVoltage;
-(float) getObjTemperature;
-(float) getAccelX;
-(float) getOpt;
-(int8_t) getRSSI;



@end



@interface TIDualBandShowcaseData : NSObject

@property uint32_t timeStamp;
@property uint8_t subOneledStatus;
@property uint16_t subOneBatStatus;
@property uint16_t subOneTemperature;
@property int8_t subOneRSSI;
@property uint16_t gwBatteryStatus;
@property uint16_t gwTemperature;
@property NSDate *startDate;


-(instancetype) initWithTIBroadcastData:(TIBroadcastData *)bData;

-(NSDate *) getTimeStamp;
-(BOOL) getSubOneLedStatus;
-(int) getSubOneBatStatus;
-(float) getSubOneTemperature;
-(int) getSubOneRSSI;
-(int) getGWBatteryStatus;
-(float) getGWTemperature;


@end

typedef enum {
    ONE_G = 0x1,
    TWO_G,
    FOUR_G,
    EIGHT_G,
    SIXTEEN_G,
} accRange_t;


typedef enum {
    STAND_ALONE = 0x0,
    CLOTHING = 0x1,
    BODY = 0x2,
    TOY = 0x3,
} physicalAttachment_t;

@interface TIuTagBroadcastData : TIBroadcastData

@property uint16_t  temperatureRawData;
@property uint64_t  accelerationDataPacked;

@property int16_t  x;
@property int16_t  y;
@property int16_t  z;

@property accRange_t accRange;

@property physicalAttachment_t physicalAttachment;

+(TIuTagBroadcastData *) parseTIuTagBroadcastData:(NSData *)advManifData;
-(float) getTemperature;
-(float) getAccX;
-(float) getAccY;
-(float) getAccZ;
@end







