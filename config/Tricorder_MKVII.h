#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BUTTONS 2
#define NUM_BLADES 4
#define VOLUME 2000
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SPIDISPLAY
#define ENABLE_DEVELOPER_COMMANDS
#endif

//EYESPI 	PBV3 	function

//TCS 	data4 	Chip Select
//DC 	Free3 	Command Select
//MOSI 	Data3 	Data
//SCK 	Free1 	Clock
//Gnd 	GND 	power
//Lite 	Free2 	Backlight control
//Vin 	SD_VDD 	power

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
	
	{ "tng;common", "tracks/tng.wav",
	StylePtr<Layers<Black,Cylon<Green,5,20,Red,5,20,1>>>(), //1
	StylePtr<Layers<Black,Cylon<DeepSkyBlue,5,20,Red,5,20,1>>>(), //2
	StylePtr<Layers<Black,Cylon<Green,5,20,Red,5,20,1>>>(), //3
	StylePtr<Layers<Black,Cylon<Red,5,20,Red,5,20,1>>>(), //4
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //5
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //6
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //7
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //8
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //9
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //10
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //11
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //12
    ""},
	{ "Unstable;common", "tracks/KyloRen.wav",
	StylePtr<Layers<Black,Sequence<Cyan,Black,100,37,0b1010101010101,0b111000111000111,0b100000000000000>>>(), //1
	StylePtr<Layers<Black,Sequence<Red,Black,100,37,0b1010100011100,0b111000111000101,0b100000000000000>>>(), //2
	StylePtr<Layers<Black,Cylon<Green,5,20,Red,5,20,1>>>(), //3
	StylePtr<Layers<Black,Cylon<Red,5,20,Red,5,20,1>>>(), //4
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //5
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //6
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //7
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //8
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //9
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //10
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //11
//	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //12
    ""},
	
};

BladeConfig blades[] = {
 { 0,
     SubBlade(8, 15, WS281XBladePtr<16, bladePin, Color8::GRB, PowerPINS<bladePowerPin2>>()), // test change
//     SubBlade(8, 15, WS281XBladePtr<16, bladePin, Color8::GRB, PowerPINS<bladePowerPin1>>()), // b1 front green scanny thing
     SubBlade(0, 3, NULL),  // b2 big blue scanny thing
     SubBlade(4, 5, NULL),  // b3 side by side green
     SubBlade(6, 7, NULL),  // b4 up down red
//     SubBlade(0, 2, WS281XBladePtr<14, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2>>()), // b5 front 3 green
//     SubBlade(3, 5, NULL),  // b6 geo met bio
//     SubBlade(6, 9, NULL),  // b7 alpha beta gamma delta
//     SubBlade(10, 10, NULL),  // b8 front power red light
//     SubBlade(11, 12, NULL),  // b9 upper front green lights
//     SubBlade(13, 13, NULL),  // b10 upper front red light
//     SimpleBladePtr<CH1LED, NoLED, NoLED, NoLED, bladePowerPin4, -1, -1, -1>(), // b11 lower lights (two red leds)
//     SimpleBladePtr<CH1LED, NoLED, NoLED, NoLED, bladePowerPin3, -1, -1, -1>(), // b12 front dim lights (warm white)
     CONFIGARRAY(presets) },
  };
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif

#ifdef CONFIG_BOTTOM
SPIDisplay_AdaFruit5206<3> display;                                                                                         
StandarColorDisplayController<280, 240> display_controller(&display);
#endif