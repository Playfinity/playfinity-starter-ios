/*!
 *  \author         Ole A. Torvmark <o.a.torvmark@ti.com , torvmark@stalliance.no>
 *  \brief          OAD Service defines
 *  \copyright      Copyright (c) 2013 Texas Instruments Inc.
 *  \file           oad.h
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
#ifndef TI_BLE_Multitool_oad_h
#define TI_BLE_Multitool_oad_h

#define uint16 uint16_t
#define uint8 uint8_t
#define HAL_FLASH_WORD_SIZE 4

/**************************************************************************************************
 Filename:       oad.h
 
 Description:    This file contains OAD Profile header file.
 
 The orginal embedded version has been modified to compile with Qt.
 svn://lpw-svn.sand.design.ti.com/r1/trunk/Projects/ble/Profiles/OAD/oad.h
 
 **************************************************************************************************/
#ifndef OAD_H
#define OAD_H

#ifdef __cplusplus
extern "C"
{
#endif
    
    /*********************************************************************
     * INCLUDES
     */
#define ATT_UUID_SIZE 128
#define KEY_BLENGTH    16
    
    /*********************************************************************
     * CONSTANTS
     */
    
#if !defined OAD_IMG_A_PAGE
#define OAD_IMG_A_PAGE        1
#define OAD_IMG_A_AREA        62
#endif
    
#if !defined OAD_IMG_B_PAGE
    // Image-A/B can be very differently sized areas when implementing IBM vice OAD boot loader.
#if defined FEATURE_OAD_IBM
#define OAD_IMG_B_PAGE        8
#else
#define OAD_IMG_B_PAGE        63
#endif
#define OAD_IMG_B_AREA       (124 - OAD_IMG_A_AREA)
#endif
    
#if defined HAL_IMAGE_B
#define OAD_IMG_D_PAGE        OAD_IMG_A_PAGE
#define OAD_IMG_D_AREA        OAD_IMG_A_AREA
#define OAD_IMG_R_PAGE        OAD_IMG_B_PAGE
#define OAD_IMG_R_AREA        OAD_IMG_B_AREA
#else   //#elif defined HAL_IMAGE_A or a non-IBM-enabled OAD Image-A w/ constants in Bank 1 vice 5.
#define OAD_IMG_D_PAGE        OAD_IMG_B_PAGE
#define OAD_IMG_D_AREA        OAD_IMG_B_AREA
#define OAD_IMG_R_PAGE        OAD_IMG_A_PAGE
#define OAD_IMG_R_AREA        OAD_IMG_A_AREA
#endif
    
#define OAD_IMG_CRC_OSET      0x0000
#if defined FEATURE_OAD_SECURE
#define OAD_IMG_HDR_OSET      0x0000
#else  // crc0 is calculated and placed by the IAR linker at 0x0, so img_hdr_t is 2 bytes offset.
#define OAD_IMG_HDR_OSET      0x0002
#endif
    
#define OAD_CHAR_CNT          2
    
#define OAD_CHAR_IMG_NOTIFY   0
#define OAD_CHAR_IMG_BLOCK    1
    
#define OAD_LOCAL_CHAR        0 // Local OAD characteristics
#define OAD_DISC_CHAR         1 // Discovered OAD characteristics
    
    // OAD Parameter IDs
#define OAD_LOCAL_CHAR_NOTIFY 1 // Handle for local Image Notify characteristic. Read only. size uint16.
#define OAD_LOCAL_CHAR_BLOCK  2 // Handle for local Image Block characteristic. Read only. size uint16.
#define OAD_DISC_CHAR_NOTIFY  3 // Handle for discovered Image Notify characteristic. Read/Write. size uint16.
#define OAD_DISC_CHAR_BLOCK   4 // Handle for discovered Image Block characteristic. Read/Write. size uint16.
    
    // Image Identification size
#define OAD_IMG_ID_SIZE       4
    
    // Image header size (version + length + image id size)
#define OAD_IMG_HDR_SIZE      ( 2 + 2 + OAD_IMG_ID_SIZE )
    
    // The Image is transporte in 16-byte blocks in order to avoid using blob operations.
#define OAD_BLOCK_SIZE        16
#define OAD_BLOCKS_PER_PAGE  (HAL_FLASH_PAGE_SIZE / OAD_BLOCK_SIZE)
#define OAD_BLOCK_MAX        (OAD_BLOCKS_PER_PAGE * OAD_IMG_D_AREA)
    
    /*********************************************************************
     * GLOBAL VARIABLES
     */
    
    // OAD Service UUID
    //extern CONST uint8 oadServUUID[ATT_UUID_SIZE];
    
    // OAD Image Notify, OAD Image Block Request, OAD Image Block Response UUID's:
    //extern CONST uint8 oadCharUUID[OAD_CHAR_CNT][ATT_UUID_SIZE];
    
    /*********************************************************************
     * TYPEDEFS
     */
    
    // The Image Header will not be encrypted, but it will be included in a Signature.
    typedef struct {
#if defined FEATURE_OAD_SECURE
        // Secure OAD uses the Signature for image validation instead of calculating a CRC, but the use
        // of CRC==CRC-Shadow for quick boot-up determination of a validated image is still used.
        uint16 crc0;       // CRC must not be 0x0000 or 0xFFFF.
#endif
        uint16 crc1;       // CRC-shadow must be 0xFFFF.
        // User-defined Image Version Number - default logic uses simple a '<' comparison to start an OAD.
        uint16 ver;
        uint16 len;        // Image length in 4-byte blocks (i.e. HAL_FLASH_WORD_SIZE blocks).
        uint8  uid[4];     // User-defined Image Identification bytes.
        uint16  addr;       // Image start address
        uint8  imgType;    // Image type
        uint8  res[1];     // Reserved space for future use.
    } img_hdr_t;
#if defined FEATURE_OAD_SECURE
    static_assert((sizeof(img_hdr_t) == 16), "Bad SBL_ADDR_AES_HDR definition.");
    static_assert(((sizeof(img_hdr_t) % KEY_BLENGTH) == 0),
                  "img_hdr_t is not an even multiple of KEY_BLENGTH");
#endif
    
    // The AES Header must be encrypted and the Signature must include the Image Header.
    typedef struct {
        uint8 signature[KEY_BLENGTH];  // The AES-128 CBC-MAC signature.
        uint8 nonce12[12];             // The 12-byte Nonce for calculating the signature.
        uint8 spare[4];
    } aes_hdr_t;
    
    
    // OAD2 used on CC26xx version
    typedef struct {
        // Secure OAD uses the Signature for image validation instead of calculating a CRC, but the use
        // of CRC==CRC-Shadow for quick boot-up determination of a validated image is still used.
        uint16 crc0;       // CRC must not be 0x0000 or 0xFFFF.
        uint16 crc1;       // CRC-shadow must be 0xFFFF.
        // User-defined Image Version Number - default logic uses simple a '<' comparison to start an OAD.
        uint16 ver;
        uint16 len;        // Image length in 4-byte blocks (i.e. HAL_FLASH_WORD_SIZE blocks).
        uint8  uid[4];     // User-defined Image Identification bytes.
        uint16  addr;       // Image start address
        uint8  imgType;    // Image type
        uint8  status;     // Status used by BIM_extFlash to indicate written to internal
    } img_hdr_t2;
    
    
    
    
#ifdef __cplusplus
}
#endif

#endif
/*********************************************************************
 *********************************************************************/
#endif
