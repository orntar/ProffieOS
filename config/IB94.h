#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 2
#define VOLUME 1800
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

#ifdef CONFIG_PRESETS
Preset presets[] = {

// Emitter and single accent

{ "IB94", "tracks/mando1.wav",
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,Red,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,OrangeRed,TrFade<200>,Blinking<Black,Black,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<25>,OrangeRed,TrFade<100>>>>,TrInstant,TrConcat<TrInstant,Rgb<0,0,50>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accent
  StylePtr<Layers<
  TransitionLoop<ImperialYellow,TrConcat<TrBoing<5000,9>,Black,TrDelay<2000>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,Magenta,TrWipeIn<100>,Blinking<Black,Black,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
},

{ "NN14", "tracks/NN14.wav",
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Rgb<180,0,0>,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accent
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Rgb<180,120,0>,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
},

{ "A180", "tracks/A180.wav",
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accent
  StylePtr<Layers<
  TransitionLoop<Yellow,TrConcat<TrBoing<3200,5>,Rgb<20,20,0>,TrFade<2000>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
},

{ "DL44", "tracks/DL44.wav",
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,Red,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Blinking<Black,Red,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accent
  StylePtr<Layers<
  Mix<Bump<Sin<Int<18>>,Int<20000>>,Black,Red>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Blinking<Black,Red,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
},

{ "MouthBlaster", "tracks/medley1.wav",
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Blinking<Black,Black,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,White,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<225,225,225>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accent
  StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrJoinR<TrWipe<500>,TrWipeIn<500>>,DeepSkyBlue,TrJoin<TrWipe<500>,TrWipeIn<500>>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Blinking<Black,Black,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
},

};

BladeConfig blades[] = {
  { 0, 
    WS281XBladePtr<20, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
	WS281XBladePtr<1, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >(),
    CONFIGARRAY(presets) },
};

#endif

#ifdef CONFIG_BUTTONS
Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");
#endif