#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
#define VOLUME 1000
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
//#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
//#define MOUNT_SD_SETTING
#define INCLUDE_SSD1306 //64x32
//#define SAVE_STATE
//#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define NO_REPEAT_RANDOM
#define ENABLE_BLASTER_AUTO
//#define BLASTER_SHOTS_UNTIL_EMPTY 15  // (whatever number)
//#define BLASTER_JAM_PERCENTAGE 5     // if not defined, random.
//#define BLASTER_DEFAULT_MODE MODE_KILL
//#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
#endif

#ifdef CONFIG_PROP
#include "../props/blaster.h"
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {

{ "E-11", "tracks/E11.wav",
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Rgb<180,0,0>,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipeIn<100>,White,TrWipeIn<100>,Red,TrWipeIn<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,DeepSkyBlue,TrWipeIn<100>,Blinking<Black,Blue,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<100>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<32768>,Int<25000>>>,TrFade<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<32768>,Int<25000>>>,TrFade<150>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<150>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrConcat<TrDelay<416>,Black,TrWipeInSparkTip<White,150,150>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<27500>>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
"E-11"},

};

BladeConfig blades[] = {
{ 0, 
	SubBlade(9, 9, WS281XBladePtr<10, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()), /* muzzle */
	SubBlade(0, 8, NULL), /* barrel */
CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");
#endif

#ifdef CONFIG_BOTTOM
BlasterDisplayController<64, uint32_t> display_controller;
SSD1306Template<64, uint32_t> display(&display_controller);
#endif
