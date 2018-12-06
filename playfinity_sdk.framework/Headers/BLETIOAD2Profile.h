/*!
 *  \author         Ole A. Torvmark <o.a.torvmark@ti.com , torvmark@stalliance.no>
 *  \brief          BLE Generic Profile for the TI OAD (Over the Air Download) CC26xx Service
 *  \copyright      Copyright (c) 2013 Texas Instruments Inc.
 *  \file           BLETIOAD2Profile.h
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
#import "BLETIOADProfile.h"
#import "oad.h"

@interface BLETIOAD2Profile : BLETIOADProfile

@property (strong,nonatomic) NSData *imageFile;

@property id <BLETIOADNotifications> oadDelegate;
@property int nBlocks;
@property int nBytes;
@property int iBlocks;
@property int iBytes;
@property uint16_t lastblock;
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
@property CBCharacteristic *imageCountChar;
@property CBCharacteristic *imageStatusChar;
@property BOOL hasHeader;

-(void) watchDogTimedOut:(NSTimer *)timer;
-(void) uploadImage:(NSString *)filename;
-(void) prettyPrintImage:(uint8_t *) buf len:(int)len offset:(uint16_t)offset;
-(void) programmingTimerTick:(NSTimer *)timer;

-(BOOL) uploadImageFile:(NSString *)filename;
-(uint16_t) calcImageCRC:(uint16_t) page imageHeader:(img_hdr_t2 *)imageHeader buf:(uint8_t *)buf;
-(BOOL) isCorrectImage;

-(IBAction)safeModeOnOff:(id)sender;
-(void) sendOnePacket;
+(bool) isCorrectService:(CBService *)service;

+(uint16_t) getBlockFromAddress:(uint32_t)addr;

#define FLASH_PAGE_SIZE 0x1000
#define FLASH_WORD_SIZE 4
#define FLASH_NUM_PAGES 32

#define EFL_OAD_IMG_TYPE_APP    1
#define EFL_OAD_IMG_TYPE_STACK  2
#define EFL_OAD_IMG_TYPE_BIM    3

#define CRC_OFFSET 0x00

#define BLOCKS 36
#define TIMER 0.08

@end




