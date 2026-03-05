#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
#define VOLUME 1200
const unsigned int maxLedsPerStrip = 128;
#define CLASH_THRESHOLD_G 4.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL
#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE

#define DISABLE_DIAGNOSTIC_COMMANDS
#define FETT263_MULTI_PHASE

#define FETT263_TWIST_ON_NO_BM 
#define FETT263_TWIST_ON 
#define FETT263_TWIST_OFF    

#define FETT263_STAB_ON_NO_BM                                              
#define FETT263_STAB_ON                                

#define FETT263_SWING_ON_SPEED 500
#define FETT263_SWING_ON_NO_BM
#define FETT263_SWING_ON
#define FETT263_SWING_OFF

#define MOTION_TIMEOUT 60 * 3 * 1000  

#define FETT263_THRUST_ON
#define FETT263_THRUST_OFF
#define FETT263_DISABLE_COPY_PRESET

// #define ENABLE_SSD1306
// // Max 20 characters
// #define BLE_PASSWORD "your password"
// // Max 32 characters.
// #define BLE_NAME "Your Saber Name"
// // Max 9 characters
// #define BLE_SHORTNAME "Saber"

#define MOTION_TIMEOUT 60 * 3 * 800               
#endif

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"

#endif


#ifdef CONFIG_PRESETS
Preset presets[] = {  
   { "CalKestis-Blue;common", "tracks/venus.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Blue,White>,AudioFlicker<Blue,White>>,White>,300,800>>(),
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Blue,White>,AudioFlicker<Blue,White>>,White>,300,800>>(), "blue"},
   { "CalKestis-Cyan;common", "tracks/venus.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Cyan,White>,AudioFlicker<Cyan,White>>,White>,400,800>>(),
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Cyan,White>,AudioFlicker<Cyan,White>>,White>,400,800>>(), "cyan"},
   { "CalKestis-Indigo;common", "tracks/venus.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<DeepPink,White>,AudioFlicker<DeepPink,White>>,White>,300,800>>(),
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<DeepPink,White>,AudioFlicker<DeepPink,White>>,White>,300,800>>(), "indigo"},
   { "CalKestis-Magenta;common", "tracks/venus.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Magenta,White>,AudioFlicker<Magenta,White>>,White>,300,800>>(),
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Magenta,White>,AudioFlicker<Magenta,White>>,White>,300,800>>(), "magenta"},
   { "CalKestis-Purple;common", "tracks/venus.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Rgb16<43654,0,65535>,White>,AudioFlicker<Rgb16<43654,0,65535>,White>>,White>,300,800>>(),
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Rgb16<43654,0,65535>,White>,AudioFlicker<Rgb16<43654,0,65535>,White>>,White>,300,800>>(), "purple"},
   { "CalKestis-Green;common", "tracks/venus.wav",
    StylePtr<InOutHelper<EasyBlade<OnSpark<Sparkle<Green,Yellow>>,GreenYellow>,300,800>>(),
    StylePtr<InOutHelper<EasyBlade<OnSpark<Sparkle<Green,Yellow>>,GreenYellow>,300,800>>(), "green"},
   { "CalKestis-Yellow;common", "tracks/venus.wav",
    StylePtr<InOutHelper<EasyBlade<OnSpark<Sparkle<Yellow,Yellow>>,GreenYellow>,300,800>>(),
    StylePtr<InOutHelper<EasyBlade<OnSpark<Sparkle<Yellow,Yellow>>,GreenYellow>,300,800>>(), "yellow"},
   { "CalKestis-Orange;common", "tracks/venus.wav",
    StylePtr<InOutHelper<EasyBlade<OnSpark<Sparkle<DarkOrange,Yellow>>,Yellow>,300,800>>(),
    StylePtr<InOutHelper<EasyBlade<OnSpark<Sparkle<DarkOrange,Yellow>>,Yellow>,300,800>>(), "orange"},
   { "BodeAkuna;common", "tracks/uranus.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OrangeRed,White>,AudioFlicker<OrangeRed,White>>,White>,300,800>>(),
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<OrangeRed,White>,AudioFlicker<OrangeRed,White>>,White>,300,800>>(), "orangered"},
   { "SecondSister;common", "tracks/mars.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Red,White>,AudioFlicker<Red,White>>,White>,400,800>>(),
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Red,White>,AudioFlicker<Red,White>>,White>,400,800>>(), "red"},
   { "DarthVader;common", "tracks/mars.wav",
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Red,White>,AudioFlicker<Red,White>>,White>,400,800>>(),
    StylePtr<InOutHelper<SimpleClash<Lockup<Blast<Red,White>,AudioFlicker<Red,White>>,White>,400,800>>(), "red"},
};

BladeConfig blades[] = {
 { 0, WS281XBladePtr<128, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
    WS281XBladePtr<30, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4, bladePowerPin5> >()
  , CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
