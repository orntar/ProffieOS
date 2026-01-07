#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BUTTONS 2
#define NUM_BLADES 1
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

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
	
	{ "Unstable;common", "tracks/KyloRen.wav",
	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //1
    "ky"},
		{ "tng;common", "tracks/mercury.wav",
	StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Green,White>,AudioFlicker<Green,White>>,White>,300,800>>(), //1
    "ky"},
	
};

BladeConfig blades[] = {
 { 0, 
    WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin1> >(),
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