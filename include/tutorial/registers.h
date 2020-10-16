#ifndef __GBA_REGISTERS_H__
#define __GBA_REGISTERS_H__


#include <stdint.h>
#include <stdbool.h>
#include <string.h>



#pragma region intTypeDefs
typedef uint8_t     u8;
typedef uint16_t    u16;
typedef uint32_t    u32;

typedef int8_t      s8;
typedef int16_t     s16;
typedef int32_t     s32;
#pragma endregion
#pragma region volIntTypeDefs
typedef volatile uint8_t    v_u8;
typedef volatile uint16_t   v_u16;
typedef volatile uint32_t   v_u32;
typedef volatile int8_t     v_s8;
typedef volatile int16_t    v_s16;
typedef volatile int32_t    v_s32;
#pragma endregion
#pragma region Display
#define REG_BASE 0x04000000
#define SCREEN_W 240
#define SCREEN_H 160

#define REG_VCOUNT (*(v_u16*)(REG_BASE + 0x06))
#define REGDISCNT  *((v_u32*)(REG_BASE))



#define SCREENBUFFER ((u16*)(0x6000000))

#define VIDEOMODE_0 0x0000
#define VIDEOMODE_1 0x0001
#define VIDEOMODE_2 0x0002
#define VIDEOMODE_3 0x0003
#define VIDEOMODE_4 0x0004
#define VIDEOMODE_5 0x0005

#define BGMODE_0 0x0100
#define BGMODE_1 0x0200
#define BGMODE_2 0x0400
#define BGMODE_3 0x0800
#define OBJMODE  0x1000 


#pragma endregion
#pragma region RAM Locations
#define EWRAM       0x02000000
#define EWRAM_END   0z02040000

#define IWRAM       0x03000000

#define VRAM        0x06000000
#define SRAM        0x0E000000
#pragma endregion
#pragma region external functions
extern s32 abs(s32 a_val);
extern s32 __gba_rand_seed;
extern s32 seed_gba_rand(s32 a_seed);
extern s32 gba_rand();
extern s32 gba_rand_range(s32 a_min, s32 a_max);


extern u16 setColour(u8 a_red,u8 a_green,u8 a_blue);
extern void PlotPixel(s32 a_x, s32 a_y, u16 a_colour);
extern void DrawLine( s32 a_x, s32 a_y, s32 a_x2, s32 a_y2, u16 a_colour);
extern void DrawRect( s32 a_left, s32 a_top, s32 a_width, s32 a_height, u16 a_colour);
extern void vsync();
#pragma endregion

#pragma region Input
#define REG_KEYINPUT		*(vu16*)(REG_BASE+0x0130)

#define KEY_A			0x0001	//!< Button A
#define KEY_B			0x0002	//!< Button B
#define KEY_SELECT		0x0004	//!< Select button
#define KEY_START		0x0008	//!< Start button
#define KEY_RIGHT		0x0010	//!< Right D-pad
#define KEY_LEFT		0x0020	//!< Left D-pad
#define KEY_UP			0x0040	//!< Up D-pad
#define KEY_DOWN		0x0080	//!< Down D-pad
#define KEY_R			0x0100	//!< Shoulder R
#define KEY_L			0x0200	//!< Shoulder L

#define KEY_ANY			0x03FF	//!< any key
#define KEY_DIR			0x00F0	//!< any-dpad
#define KEY_ACCEPT		0x0009	//!< A or start
#define KEY_CANCEL		0x0002	//!< B (well, it usually is)
#define KEY_SHOULDER	0x0300	//!< L or R

#define KEY_RESET		0x000F	//!< St+Se+A+B

#define KEY_MASK		0x03FF
#pragma endregion


#endif


