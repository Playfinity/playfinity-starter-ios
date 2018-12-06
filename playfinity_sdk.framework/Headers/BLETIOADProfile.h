/*!
 *  \author         Ole A. Torvmark <o.a.torvmark@ti.com , torvmark@stalliance.no>
 *  \brief          BLE Generic Profile for the TI OAD (Over the Air Download) Service
 *  \copyright      Copyright (c) 2013 Texas Instruments Inc.
 *  \file           BLETIOADProfile.h
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

#import "BLEGenericProfile.h"
#import "oad.h"


@protocol BLETIOADNotifications <NSObject>

-(void) didUpdateProgrammingStatus;
-(void) didFinishUploading;
-(void) deviceDisconnected;
-(void) coreBTError;
-(void) didUpdateConnectionParameters:(float)conInt;
-(void) watchdogTimeout;

@end

@interface BLETIOADProfile : BLEGenericProfile

@property (strong,nonatomic) NSData *imageFile;

@property id <BLETIOADNotifications> oadDelegate;
@property int nBlocks;
@property int nBytes;
@property int iBlocks;
@property int iBytes;
@property int blocksPerInterval;
@property float intervalTimer;
@property BOOL canceled;
@property BOOL inProgramming;
@property (nonatomic,retain) NSTimer *imageDetectTimer;
@property uint16_t imgVersion;
@property BOOL notifications;
@property BOOL highSpeedNotify;
@property int sentPackets;
@property NSTimer *watchDog;
@property double startTime;
@property NSTimer *programmingTimer;
@property CBService *service;


-(void) watchDogTimedOut:(NSTimer *)timer;
-(void) uploadImage:(NSString *)filename;

-(void) programmingTimerTick:(NSTimer *)timer;
-(void) imageDetectTimerTick:(NSTimer *)timer;

-(NSMutableArray *) findFWFiles;

-(BOOL) validateImage:(NSString *)filename;
-(BOOL) isCorrectImage;

-(IBAction)safeModeOnOff:(id)sender;
-(void) sendOnePacket;
+(bool) isCorrectService:(CBService *)service;

#define BLOCKS 36
#define TIMER 0.08

@end




