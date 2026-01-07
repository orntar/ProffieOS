#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 2
#define VOLUME 600
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

// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipeIn<100>,White,TrWipeIn<100>,Red,TrWipeIn<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,DeepSkyBlue,TrWipeIn<100>,Blinking<Black,Blue,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipeIn<50>,Red,TrWipeIn<100>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<150>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<150>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeInX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// accents
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

// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipeIn<100>,Red,TrWipeIn<100>,Black,TrWipeIn<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,White,TrWipeIn<100>,Blinking<Black,Red,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipeIn<50>,Red,TrWipeIn<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeInX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// accents
  StylePtr<Layers<
  Mix<Bump<Sin<Int<18>>,Int<20000>>,Black,Red>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Blinking<Black,Red,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
},

{ "Westar", "tracks/Westar.wav",
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,DarkOrange,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,Green,TrFade<200>,Blinking<Black,Yellow,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,DeepSkyBlue,TrFade<50>,DarkOrange,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipeIn<100>,DarkOrange,TrWipeIn<100>,Black,TrWipeIn<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,Green,TrWipeIn<100>,Blinking<Black,Yellow,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipeIn<50>,DarkOrange,TrWipeIn<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<DeepSkyBlue,Bump<Int<0>,Int<25000>>>,TrFade<200>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,25,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeInX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// accents
  StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipeIn<1250>,Gradient<DarkOrange,Yellow,Green>,TrWipe<1250>>>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,DarkOrange,TrWipeIn<100>,Black,TrWipeIn<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,Green,TrFade<200>,Blinking<Black,Yellow,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
},

{ "BadBatch", "tracks/BadBatch.wav",
// muzzle
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrDelay<100>,White,TrFade<200>,Blue,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<100>,Magenta,TrFade<200>,Blinking<Black,Black,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<25>,Blue,TrFade<100>>>>,TrInstant,TrConcat<TrInstant,Rgb<0,0,50>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipeIn<100>,White,TrWipeIn<100>,Blue,TrWipeIn<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,Magenta,TrWipeIn<100>,Blinking<Black,Black,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrWipeIn<25>,Blue,TrWipeIn<50>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<150>>>,
      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<150>>>>,TrConcat<TrInstant,Rgb<0,0,50>,TrFade<150>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<225,225,225>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeInX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// accents
  StylePtr<Layers<
  TransitionLoop<Green,TrConcat<TrBoing<5000,9>,Black,TrDelay<2000>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,Magenta,TrWipeIn<100>,Blinking<Black,Black,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
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

// barrel
  StylePtr<Layers<
    Black,
    TransitionEffectL<TrConcat<TrWipeIn<100>,White,TrWipeIn<100>,Black,TrWipeIn<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,White,TrWipeIn<100>,Blinking<Black,Black,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
     TransitionLoopL<TrConcat<TrWipeIn<50>,White,TrWipeIn<150>>>,
     TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>,
     TransitionLoopL<TrConcat<TrFade<1600>,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrInstant>>>,TrConcat<TrInstant,Stripes<3500,-2500,White,White,Black,Black>,TrDelay<1600>>,TrJoin<TrConcat<TrInstant,AlphaL<Black,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeInX<Int<400>>,TrWaveX<Rgb<225,225,225>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// accents
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
	SubBlade(9, 9, WS281XBladePtr<10, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()), /* muzzle */
	SubBlade(0, 8, NULL), /* barrel */
	DimBlade(5.0, WS281XBladePtr<64, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >()), /* accents */
CONFIGARRAY(presets) },
};

#endif

#ifdef CONFIG_BUTTONS
Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");

#endif