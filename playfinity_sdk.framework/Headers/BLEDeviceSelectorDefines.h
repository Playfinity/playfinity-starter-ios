/*!
 *  \author         Ole A. Torvmark <o.a.torvmark@ti.com , torvmark@stalliance.no>
 *  \brief          Defines for Multitool
 *  \copyright      Copyright (c) 2013 Texas Instruments Inc.
 *  \file           BLEDeviceSelectorDefines.h
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
#ifndef Conlib_Tester_BLEDeviceSelectorDefines_h
#define Conlib_Tester_BLEDeviceSelectorDefines_h

#define BLE_DEVICE_SELECTOR_SECTIONS @"Connected devices",@"Devices",@"WiFi Devices"/*,@"Saved devices available",@"Saved devices not available"*/,@"Information"

#define BLE_DEVICE_SELECTOR_FOOTER @"Press device cell to connect to device, press accessory button to se more information about the device"

#define BLE_DEVICE_SELECTOR_LINKS @"SensorTag page",@"http://www.ti.com/sensortag",@"SensorTag Wiki",@"http://www.ti.com/sensortag-wiki",@"TI Bluetooth Smart forum",@"http://www.ti.com/ble-forum",@"SensorTag IBM Cloud Recipe",@"https://developer.ibm.com/iot/recipes/texas-instruments-cc2650-sensortag/",@"Third-party components",@"",@"Cloud Configuration",@"2"

#define BLE_DEVICE_SELECTOR_CONNECTED 0
#define BLE_DEVICE_SELECTOR_AVAILABLE_DEVICES 1
#define BLE_DEVICE_SELECTOR_NEW_DEVICES 1
#define BLE_DEVICE_SELECTOR_UNDISCOVERED_DEVICES 2


#define BLE_DEVICE_SELECTOR_DETAIL_SECTION_INFO 0
#define BLE_DEVICE_SELECTOR_DETAIL_SECTION_ACTIONS 1



#define BLE_DEVICE_SELECTOR_SECTION_CON 0 /* 0 */
#define BLE_DEVICE_SELECTOR_SECTION_SCANNED 1 /* 1 */
#define BLE_DEVICE_SELECTOR_SECTION_DISCOVERED 2 /* 1 */
#define BLE_DEVICE_SELECTOR_SECTION_LINKS 3 /* 4 */
#define BLE_DEVICE_SELECTOR_SECTION_INFO 4 /* 5 */



#define BLE_DEVICE_ADVERTISEMENT_TIMEOUT 6
#define BLE_DEVICE_BROADCASTER_UPDATE_COUNT 1
#define BLE_DEVICE_CONNECTION_TIMEOUT 3


#endif
