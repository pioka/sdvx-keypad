#include <stdint.h>

#include "../inc/system.h"

#include "../inc/usb.h"
#include "../inc/usb_device_hid.h"

#include "../inc/app_keyboard.h"

volatile signed int SOFCounter = 0;

bool USER_USB_CALLBACK_EVENT_HANDLER(USB_EVENT event, void *pdata, uint16_t size) {
  switch((int)event) {
    case EVENT_TRANSFER:
      break;

    case EVENT_SOF:
      if(SOFCounter < 32767) {
        SOFCounter++;
      }
      else {
        SOFCounter = 0;
      }
      break;

    case EVENT_SUSPEND:
      break;

    case EVENT_RESUME:
      break;

    case EVENT_CONFIGURED:
      APP_KeyboardInit();
      break;

    case EVENT_SET_DESCRIPTOR:
      break;

    case EVENT_EP0_REQUEST:
      USBCheckHIDRequest();
      break;

    case EVENT_BUS_ERROR:
      break;

    case EVENT_TRANSFER_TERMINATED:
      break;

    default:
      break;
  }

  return true;
}
