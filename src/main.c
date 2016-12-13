#include <stdint.h>
#include <xc.h>

#include "../inc/usb.h"
#include "../inc/usb_device_hid.h"

#include "../inc/system.h"
#include "../inc/app_keyboard.h"

// initialize I/O pins
void pinInit(void);

void interrupt sysInterrupt(void){
  USBDeviceTasks();
}

int main(void){
  pinInit();

  USBDeviceInit();
  USBDeviceAttach();

  while (1){
    APP_KeyboardTask();
  }
}

// initialize I/O pins
void pinInit(void){
  // for status display LED
  TRISCbits.TRISC7 = 0; 

  // set all digital port
  ANSEL = 0x00;
  ANSELH = 0x00;
  
  LED_STAT_OFF();
}
