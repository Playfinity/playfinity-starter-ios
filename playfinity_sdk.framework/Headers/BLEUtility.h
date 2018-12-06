/*!
 *  \author         Ole A. Torvmark <o.a.torvmark@ti.com , torvmark@stalliance.no>
 *  \brief          Utility functions for Multitool
 *  \copyright      Copyright (c) 2013 Texas Instruments Inc.
 *  \file           BLEUtility.h
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
#import <CoreBluetooth/CoreBluetooth.h>
#import "BLEDevice.h"


//#define DEBUG_LOW_VERBOSE 1
//#define DEBUG_MEDIUM_VERBOSE 1
#define DEBUG_HIGH_VERBOSE 1


// Bitfield operations

#define HI_UINT16(a) (((a) >> 8) & 0xff)
#define LO_UINT16(a) ((a) & 0xff)
#define BE_UINT16(a) (((a) >> 8) & 0xff) | (((a) << 8) & 0xff00)
#define SWAP_UINT16(a) a = (((a & 0x00FF) << 8) | ((a & 0xFF00) >> 8))

#define TI_BASE_LONG_UUID @"F0000000-0451-4000-B000-000000000000"

#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v) ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)


@interface BLEUtility : NSObject

+(NSString *) manufacturerStringFrom:(uint16_t)manuID;

+(NSString*) machineName;

+(void)readCharacteristic:(CBPeripheral *)peripheral sUUID:(NSString *)sUUID cUUID:(NSString *)cUUID;

+(void)setNotificationForCharacteristic:(CBPeripheral *)peripheral sUUID:(NSString *)sUUID cUUID:(NSString *)cUUID enable:(BOOL)enable;

+(void)writeCharacteristic:(CBPeripheral *)peripheral sUUID:(NSString *)sUUID cUUID:(NSString *)cUUID data:(NSData *)data;
+(void)writeCharacteristic:(CBPeripheral *)peripheral sCBUUID:(CBUUID *)sCBUUID cCBUUID:(CBUUID *)cCBUUID data:(NSData *)data;

+(void)writeNoResponseCharacteristic:(CBPeripheral *)peripheral sUUID:(NSString *)sUUID cUUID:(NSString *)cUUID data:(NSData *)data;
+(void)writeNoResponseCharacteristic:(CBPeripheral *)peripheral sCBUUID:(CBUUID *)sCBUUID cCBUUID:(CBUUID *)cCBUUID data:(NSData *)data;


+(void)readCharacteristic:(CBPeripheral *)peripheral sCBUUID:(CBUUID *)sCBUUID cCBUUID:(CBUUID *)cCBUUID;
+(void)setNotificationForCharacteristic:(CBPeripheral *)peripheral sCBUUID:(CBUUID *)sCBUUID cCBUUID:(CBUUID *)cCBUUID enable:(BOOL)enable;

+(bool) isCharacteristicNotifiable:(CBPeripheral *)peripheral sCBUUID:(CBUUID *)sCBUUID cCBUUID:(CBUUID *) cCBUUID;


/// Function to expand a TI 16-bit UUID to TI 128-bit UUID
+(CBUUID *) expandToTIUUID:(CBUUID *)sourceUUID;
/// Function to convert an CBUUID to NSString
+(NSString *) CBUUIDToString:(CBUUID *)inUUID;

+(float) ieee11073SfloatToFloat:(uint16_t) sfloat;
+(float) ieee11073FloattoFloat:(uint32_t) conv;


+(double) sfloatExp2ToDouble:(uint16_t) sfloat;




+(NSInteger) countofDevicesWithType:(NSMutableArray *)devs type:(int)type;

+(BLEDevice *) getObjectWithIndexPath:(NSMutableArray *)devs iP:(NSIndexPath *)iP;
+(BLEDevice *) getObjectFromPeripheral:(NSMutableArray *)devs peripheral:(CBPeripheral *)peripheral;

+(NSInteger) getTypeOfDevice:(NSMutableArray *) devs peripheral:(CBPeripheral *)peripheral;

+(BOOL) containsCBPeripheral:(NSMutableArray *)devs peripheral:(CBPeripheral *)peripheral;

+(BOOL) replaceDevice:(NSMutableArray *)devs device:(BLEDevice *)device;
+(BOOL) setTypeOfDevice:(NSMutableArray *)devs peripheral:(CBPeripheral *)peripheral type:(int)type;

+(void) disconnectAllDevicesFromCB:(NSMutableArray *)devs;

+(NSIndexPath *) getIndexPathFromDevice:(NSMutableArray *) devs dev:(BLEDevice *)dev;
+(int) getIndexfromDevice:(NSMutableArray *)devs dev:(BLEDevice *)dev;

+(NSString *) prettyPrintUUID:(CBUUID *) uuid;

+(BOOL) runnningiOSSeven;
+(BOOL) runnningiOSSevenOne;
+(BOOL) runningOnIpad;

#pragma naming functions
+(void) writeNameForIdentifier:(NSUUID *) identifier name:(NSString *)name;
+(void) writeNameForMACAddress:(NSString *) MACAddress name:(NSString *)name;
+(NSString *) readNameForIdentifier:(NSUUID *) identifier;
+(NSString *) readNameForMACAddress:(NSString *)MACAddress;

+(NSString *) readValueForKey:(NSString *) key;
+(void) writeValueForKey:(NSString *) key value:(NSString *)value;

+(unsigned long) readGroupIndexForIdentifier:(NSUUID *) identifier;
+(void) writeGroupIndexForIdentifier:(NSUUID *) identifier groupIndex:(int)groupIndex;
#pragma mark Device list checking functions

+(int) countBroadcastersInList:(NSMutableArray *)devices;

#pragma mark Debug functions

+(void) debugPrintAllProfileStatistics:(BLEDevice *)dev;

+(NSString *)getVersionNumberFromVersionString:(NSString *)versionString;

@end
