// ProffieOS7 Config File
#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 4
#define NUM_BUTTONS 2
const unsigned int maxLedsPerStrip = 144;
#define EXTRA_COLOR_BUFFER_SPACE 60
#define VOLUME 1200
#define CLASH_THRESHOLD_G 1.8
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define MOTION_TIMEOUT 60 * 15 * 1000  
#define IDLE_OFF_TIME 60 * 15 * 1000
#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
#define FETT263_DISABLE_CHANGE_FONT
#define FETT263_DISABLE_CHANGE_STYLE
#define FETT263_DISABLE_COPY_PRESET 
#define DISABLE_BASIC_PARSER_STYLES
#define DISABLE_DIAGNOSTIC_COMMANDS
#define ENABLE_ALL_EDIT_OPTIONS
#define NO_REPEAT_RANDOM
#define COLOR_CHANGE_DIRECT
#define FETT263_LOCKUP_DELAY 200
#define FETT263_BM_CLASH_DETECT 6
#define FETT263_MULTI_PHASE
#define FETT263_TWIST_ON 
#define FETT263_TWIST_OFF    
#endif

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif

#ifdef CONFIG_PRESETS

Preset presets[] = {

  { "Unstable;common", "tracks/KyloRenTLJ.wav",
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),  
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),  
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>>>,Pink>,Pink>,Pink,400>,200,500>>(),  
    StylePtr<InOutHelper<OnSpark<Blast<LocalizedClash<Lockup<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>>,Gradient<HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<DarkOrange,BrownNoiseFlicker<Red,Black,50>,15>,HumpFlicker<Yellow,Green,50>>>,Pink>,Pink>,Pink,400>,200,500>>(), "KRTLJ"},    
};

BladeConfig blades[] = {
 { 0,
     SubBlade(8, 15, WS2811BladePtr<16, bladePin, Color8::GRB, PowerPINS<bladePowerPin1>>()), // b1 front green scanny thing
     SubBlade(0, 3, NULL),  // b2 big blue scanny thing
     SubBlade(4, 5, NULL),  // b3 side by side green
     SubBlade(6, 7, NULL),  // b4 up down red
//     SubBlade(0, 2, WS2811BladePtr<14, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin2>>()), // b5 front 3 green
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
