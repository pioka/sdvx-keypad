// Button difinitation
#define SW_BT_A     PORTCbits.RC0
#define SW_BT_B     PORTCbits.RC1
#define SW_BT_C     PORTCbits.RC2
#define SW_BT_D     PORTCbits.RC3
#define SW_FX_L     PORTCbits.RC4
#define SW_FX_R     PORTCbits.RC5
#define SW_START_BTN    PORTCbits.RC6
#define SW_VOL_L_CW  PORTBbits.RB7
#define SW_VOL_L_CCW PORTBbits.RB6
#define SW_VOL_R_CW  PORTBbits.RB5
#define SW_VOL_R_CCW PORTBbits.RB4

#define NUM_BT_A 0
#define NUM_BT_B 1
#define NUM_BT_C 2
#define NUM_BT_D 3
#define NUM_FX_L 4
#define NUM_FX_R 5
#define NUM_START_BTN 6
#define NUM_VOL_L_CW 7
#define NUM_VOL_L_CCW 8
#define NUM_VOL_R_CW 9
#define NUM_VOL_R_CCW 10

#define LED_STAT LATCbits.LATC7

// Macro function difinitation
#define IS_SW_PRESSED(b) (!b)

#define LED_STAT_ON() (LED_STAT = 0)
#define LED_STAT_OFF() (LED_STAT = 1)

// CONFIGURATION Bits 
#pragma config CPUDIV = NOCLKDIV
#pragma config USBDIV = OFF
#pragma config FOSC   = HS
#pragma config PLLEN  = ON
#pragma config FCMEN  = OFF
#pragma config IESO   = OFF
#pragma config PWRTEN = OFF
#pragma config BOREN  = OFF
#pragma config BORV   = 30
#pragma config WDTEN  = OFF
#pragma config WDTPS  = 32768
#pragma config MCLRE  = OFF
#pragma config HFOFST = OFF
#pragma config STVREN = ON
#pragma config LVP    = OFF
#pragma config XINST  = OFF
#pragma config BBSIZ  = OFF
#pragma config CP0    = OFF
#pragma config CP1    = OFF
#pragma config CPB    = OFF
#pragma config WRT0   = OFF
#pragma config WRT1   = OFF
#pragma config WRTB   = OFF
#pragma config WRTC   = OFF
#pragma config EBTR0  = OFF
#pragma config EBTR1  = OFF
#pragma config EBTRB  = OFF
