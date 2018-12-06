/*!
 *  \author         Ole A. Torvmark <o.a.torvmark@ti.com , torvmark@stalliance.no>
 *  \brief          Top class for all Profiles used in Multitool
 *  \copyright      Copyright (c) 2013 Texas Instruments Inc.
 *  \file           BLEGenericProfile.h
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
#import "BLEDevice.h"


typedef enum {
    ///Configuration of sensor code
    cconfiguration,
    ///Deconfiguration of sensor code
    cdeconfiguration,
    ///Read of sensor code
    cread,
} codeType;

@protocol BLEGenericProfileDelegate <NSObject>

-(void) exchangeDataCellWithConfigCell:(id)prof;

@end

/*!
 *  \brief          This is the top level class for all profiles. All profiles have two tableViewCells, one for presenting configuration of the cell and one for presenting the graphics/values of the profile.
 *                  The profiles are used in the following way:
 *                  1. All profiles are detected in BLEDevice.m
 *                  2. After detection of a certain profile, the makeConfigurationForProfile routine of the profile is called
 *                  4. When entering the display tableView (genericProfileViewController) the configureProfile() routine is called.
 *                  5. When exiting the display tableView the deconfigureProfile() is called
 *                  6. When entering the profiles configuration tableView (BLEProfileSettingsViewController) the configuration cell is shown in the "profiles" section.
 *                  7. When a notification, read or write callback comes from CoreBluetooth, it is relayed from genericProfileViewController to profiles via the didUpdateValueForProfile, didWriteValueForProfile,deviceDisconnected,deviceConnected, didUpdateNotificationStateForProfile functions
 *                  8. The profile may also contain an UIActionSheet when the cell is pressed, and underlying OpenGL ES Graphics etc.
 *
 */
@interface BLEGenericProfile : NSObject
@property id<BLEGenericProfileDelegate> delegate;

/// BLE Device for this profile
@property (strong,nonatomic) CBPeripheral *p;
/// BLE Device for this profile
@property (strong,nonatomic) BLEDevice *d;
/// Array storing all devices known, will be used in the future.
@property (strong,nonatomic) NSMutableArray *allDevices;
/// Imperial units should be used
@property BOOL isImperial;
/// Profile is configured and running, all notifications are on
@property BOOL isConfigured;
/// Profiles default sampling period (1/sampling rate)
@property int defaultPeriod;
/// Profiles sampling timer, if notifications are not used
@property (strong,nonatomic) NSTimer *samplingTimer;
/// Number of data points collected (if any)
@property uint32_t rcvDataCount;
@property uint32_t sndDataCount;
/// Services of this profile
@property NSMutableArray *services;
/// Characteristics used in this profile
@property NSMutableArray *characteristics;

@property BOOL settingsMode;

@property BOOL isShowingConfig;


@property BOOL isInLowPowerMode;


// All these methods must be overrided...

-(id) initWithPeripheral:(CBPeripheral *) peripheral serv:(CBService *) serv;

/// Class initialization function
-(id) initWithDevice:(BLEDevice *) dev;
/// Class initialization function (new version)
-(id) initWithDevice:(BLEDevice *) dev serv:(CBService *) serv;
/// Return the icon for this profile on the value cell
-(NSString *) getIconForProfile;
/// configureProfile does all the neccessary steps to enable a profile
-(void) configureProfile;
/// deconfigureProfile does all the neccessary steps to disable a profile
-(void) deconfigureProfile;
/// called everytime any value is updated by CoreBluetooth
-(void) didUpdateValueForProfile:(CBCharacteristic *) characteristic;
/// called everytime any value is written by CoreBluetooth
-(void) didWriteValueForProfile:(CBCharacteristic *) characteristic error:(NSError *)error;
/// Called when device has been disconnected
-(void) deviceDisconnected:(CBPeripheral *)peripheral;
/// Called when device has been (re)connected
-(void) deviceConnected:(CBPeripheral *)peripheral;
/// Called everytime any notification is turned on or off
-(void) didUpdateNotificationStateForProfile:(CBCharacteristic *)characteristic;
/// caleld when setup of this profile is needed
-(void) makeConfigurationForProfile;
/// Return if profile is enabled
-(bool) isEnabled;
/// Return true if service is the same as this profile
-(bool) isCorrectService:(CBService *)service;
/// Returns if this cell can be clicked or not
-(bool) hasDetailViewController;
/// Other profiles must be turned off when this profile is enabled
-(bool) isExclusive;
/// Source code generation for this profile if any
-(NSString *) sourceCode:(codeType)cT;
/// Returns current sample rate for the data in this profile (Hz)
-(float) sampleRate;
/// Called when configuration of a profile has been done to update all timers etc.
-(void) didUpdateConfiguration;
/// Called to check the version of device FW is up to date
-(BOOL) checkLatestFW;
/// Sampling routine, does BLE reads at intervals set by period.
-(void) sampleData:(NSTimer *)timer;

/// Called when RSSI update is called
-(void) didUpdateRSSI:(CBPeripheral *)peripheral RSSI:(NSNumber *)RSSI;

-(BOOL) isMQTTPublisher;

-(void) MQTTObject:(NSString *)object;

-(NSArray *) MQTTPublish;



@end
