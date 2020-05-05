/*
 *  NB Micro TWI Master Library
 *  Author: Gustavo Casanova
 *  ...........................................
 *  File: NbMicro.h (Header)
 *  ........................................... 
 *  Version: 1.0.0 / 2020-04-29
 *  gustavo.casanova@gmail.com
 *  ...........................................
 *  This library handles the communication protocol with devices
 *  that implement the NB command set over a TWI (I2C) bus.
 */

#ifndef _NBMICRO_H_
#define _NBMICRO_H_

#include <Arduino.h>
#include <nb-twi-cmd.h>

#include <unordered_set>

#include "Wire.h"
#include "libconfig.h"

typedef uint8_t byte;

// Store of TWI addresses in use ...
static std::unordered_set<byte> active_addresses;

/* 
 * ===================================================================
 * Class NbMicro: Represents a slave microcontroller
 * using the NB command set connected to the TWI bus
 * ===================================================================
 */
class NbMicro {
   public:
    NbMicro(byte twi_address = 0, byte sda = 0, byte scl = 0);
    ~NbMicro();
    byte GetTwiAddress(void);
    byte SetTwiAddress(byte twi_address);
    byte TwiCmdXmit(byte twi_cmd, byte twi_reply,
                    byte twi_reply_arr[] = nullptr, byte reply_size = 0);
    byte TwiCmdXmit(byte twi_cmd_arr[], byte cmd_size, byte twi_reply,
                    byte twi_reply_arr[] = nullptr, byte reply_size = 0);

   protected:
    byte InitMicro(void);
    byte addr_ = 0, sda_ = 0, scl_ = 0;
    bool reusing_twi_connection_ = true;

   private:
};

#endif /* _NBMICRO_H_ */
