#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 2
#define VOLUME 650
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
//#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define SAVE_STATE
#define DISABLE_DIAGNOSTIC_COMMANDS
#define DISABLE_BASIC_PARSER_STYLES
#define NO_REPEAT_RANDOM
#define DELAYED_OFF
#define ENABLE_BLASTER_AUTO
//#define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
#endif

#ifdef CONFIG_PROP
#include "../props/blaster.h"
#endif

#ifdef CONFIG_STYLES
	InMemoryDisplay<4, 64, 3> my_small_display;
	StandarColorDisplayController<4, 64> my_small_display_controller(&my_small_display);
	NAME_INSTANCE(my_small_display, MYDISPLAY);
	
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {

// Custom Wipe to tip blast

{ "NN14", "tracks/NN14.wav",
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

// accents
  StylePtr<Layers<
    DisplayStyle<MYDISPLAY>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Rgb<180,120,0>,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
},

};

BladeConfig blades[] = {
{ 0, 
	SubBlade(9, 9, WS281XBladePtr<10, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()), /* muzzle */
	SubBlade(0, 8, NULL), /* barrel */
	DimBlade(8.0, WS281XBladePtr<64, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >()), /* accents */
CONFIGARRAY(presets) },
};

#endif

#ifdef CONFIG_BUTTONS
Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");

#endif