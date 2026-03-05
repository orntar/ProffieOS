#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 6
#define NUM_BUTTONS 2
#define VOLUME 800
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
//#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
//#define SAVE_STATE
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
    Remap<Scale<RampF,Int<32768>,Int<0>>,TransitionLoopL<TrConcat<TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<0>>,Mix<SmoothStep<Int<27500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<350>,Int<300>,Int<350>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<300>,Int<300>,Int<300>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<250>,Int<300>,Int<250>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<200>,Int<300>,Int<200>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrDelay<100>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWipe<100>,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrInstant,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<200>,Int<300>,Int<200>,Int<32768>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<250>,Int<300>,Int<250>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<300>,Int<300>,Int<300>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<350>,Int<300>,Int<350>,Int<32768>>,Mix<SmoothStep<Int<24500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<32768>>,Black,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<32768>>,TrInstant>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Rgb<180,120,0>,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
  StylePtr<Layers<
    Black,
    Remap<Scale<RampF,Int<32768>,Int<0>>,TransitionLoopL<TrConcat<TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<0>>,Mix<SmoothStep<Int<27500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<350>,Int<300>,Int<350>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<300>,Int<300>,Int<300>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<250>,Int<300>,Int<250>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<200>,Int<300>,Int<200>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrDelay<100>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWipe<100>,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrInstant,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<200>,Int<300>,Int<200>,Int<32768>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<250>,Int<300>,Int<250>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<300>,Int<300>,Int<300>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<350>,Int<300>,Int<350>,Int<32768>>,Mix<SmoothStep<Int<24500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<32768>>,Black,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<32768>>,TrInstant>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Rgb<180,120,0>,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
  StylePtr<Layers<
    Black,
    Remap<Scale<RampF,Int<32768>,Int<0>>,TransitionLoopL<TrConcat<TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<0>>,Mix<SmoothStep<Int<27500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<350>,Int<300>,Int<350>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<300>,Int<300>,Int<300>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<250>,Int<300>,Int<250>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<200>,Int<300>,Int<200>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrDelay<100>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWipe<100>,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrInstant,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<200>,Int<300>,Int<200>,Int<32768>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<250>,Int<300>,Int<250>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<300>,Int<300>,Int<300>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<350>,Int<300>,Int<350>,Int<32768>>,Mix<SmoothStep<Int<24500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<32768>>,Black,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<32768>>,TrInstant>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Rgb<180,120,0>,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
  StylePtr<Layers<
    Black,
    Remap<Scale<RampF,Int<32768>,Int<0>>,TransitionLoopL<TrConcat<TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<0>>,Mix<SmoothStep<Int<27500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<350>,Int<300>,Int<350>,Int<0>>,Mix<SmoothStep<Int<22000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<300>,Int<300>,Int<300>,Int<0>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<250>,Int<300>,Int<250>,Int<0>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<200>,Int<300>,Int<200>,Int<0>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrDelay<100>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWipe<100>,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrInstant,Mix<SmoothStep<Int<0>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<200>,Int<300>,Int<200>,Int<32768>>,Mix<SmoothStep<Int<5500>,Int<2000>>,Black,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<250>,Int<300>,Int<250>,Int<32768>>,Mix<SmoothStep<Int<11000>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<300>,Int<300>,Int<300>,Int<32768>>,Mix<SmoothStep<Int<16500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<350>,Int<300>,Int<350>,Int<32768>>,Mix<SmoothStep<Int<24500>,Int<2000>>,Black,RotateColorsX<Variation,HumpFlicker<Rgb16<65535,47835,0>,Rgb<60,15,0>,200>>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<32768>>,Black,TrWaveX<RotateColorsX<Variation,Rgb16<65535,47835,0>>,Int<400>,Int<300>,Int<400>,Int<32768>>,TrInstant>>>,
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
// accents
  StylePtr<Layers<
  TransitionLoop<Yellow,TrConcat<TrBoing<3200,5>,Rgb<20,20,0>,TrFade<2000>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
  StylePtr<Layers<
  TransitionLoop<Yellow,TrConcat<TrBoing<3200,5>,Rgb<20,20,0>,TrFade<2000>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
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
// accents
  StylePtr<Layers<
  Mix<Bump<Sin<Int<18>>,Int<20000>>,Black,Red>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Blinking<Black,Red,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
  StylePtr<Layers<
  Mix<Bump<Sin<Int<18>>,Int<20000>>,Black,Red>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Blinking<Black,Red,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
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
// accents
  StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipeIn<1250>,Gradient<DarkOrange,Yellow,Green>,TrWipe<1250>>>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,DarkOrange,TrWipeIn<100>,Black,TrWipeIn<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,Green,TrFade<200>,Blinking<Black,Yellow,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
  StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipeIn<1250>,Gradient<DarkOrange,Yellow,Green>,TrWipe<1250>>>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,DarkOrange,TrWipeIn<100>,Black,TrWipeIn<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,Green,TrFade<200>,Blinking<Black,Yellow,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
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
    Cylon<Red,5,11,Red,5,11,1>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,Magenta,TrWipeIn<100>,Blinking<Black,Black,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
  StylePtr<Layers<
    Cylon<Red,5,22,Red,5,22,1>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,Magenta,TrWipeIn<100>,Blinking<Black,Black,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
  StylePtr<Layers<
    Cylon<Red,5,25,Red,5,25,1>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,Magenta,TrWipeIn<100>,Blinking<Black,Black,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
  StylePtr<Layers<
    Cylon<Red,5,18,Red,5,18,1>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,Magenta,TrWipeIn<100>,Blinking<Black,Black,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
},

//{ "E-11", "tracks/E-11.wav",
//// barrel
//  StylePtr<Layers<
//    Black,
//    TransitionEffectL<TrConcat<TrWipe<100>,Black,TrWipe<100>,Black,TrWipe<200>>,EFFECT_FIRE>,
//    TransitionEffectL<TrConcat<TrWipe<100>,DeepSkyBlue,TrWipe<100>,Blinking<Black,Blue,100,500>,TrWipe<200>>,EFFECT_STUN>,
//    LockupTrL<Layers<
//      TransitionLoopL<TrConcat<TrWipe<50>,Red,TrWipe<100>>>,
//      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<150>>>,
//      TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<150>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<150>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,0,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
//
//// muzzle
//  StylePtr<Layers<
//    Black,
//    TransitionEffectL<TrConcat<TrDelay<25>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
//    TransitionEffectL<TrConcat<TrDelay<100>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
//    LockupTrL<Layers<
//      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
//	  
//// accent -- red to green meter on idle
//  StylePtr<Layers<
//  TransitionLoop<Black,TrConcat<TrWipeIn<1500>,Gradient<Green,Yellow,Red>,TrWipe<1500>>>,
//    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Rgb<180,130,0>,TrFade<300>>,EFFECT_FIRE>,
//    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
//    LockupTrL<Layers<
//      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
//},

{ "EE-3", "tracks/EE-3.wav",
// barrel
StylePtr<Layers<
  Black,
  TransitionEffectL<TrConcat<TrDelay<100>,Red,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
  TransitionEffectL<TrConcat<TrWipe<25>,Red,TrWipe<25>,Black,TrWipe<25>,Red,TrWipe<25>,Black,TrWipe<25>,Red,TrWipe<25>,Black,TrWipe<25>>,EFFECT_STUN>,
  LockupTrL<Layers<
    TransitionLoopL<TrConcat<TrInstant,Black,TrFade<25>,Black,TrFade<25>>>>,TrInstant,TrConcat<TrInstant,Rgb<0,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// muzzle
StylePtr<Layers<
  Black,
  TransitionEffectL<TrConcat<TrDelay<100>,Red,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
  TransitionEffectL<TrConcat<TrWipe<25>,Red,TrWipe<25>,Black,TrWipe<25>,Red,TrWipe<25>,Black,TrWipe<25>,Red,TrWipe<25>,Black,TrWipe<25>>,EFFECT_STUN>,
  LockupTrL<Layers<
    TransitionLoopL<TrConcat<TrInstant,Black,TrFade<25>,Black,TrFade<25>>>>,TrInstant,TrConcat<TrInstant,Rgb<0,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
	
// accent
  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrJoinR<TrWipe<500>,TrWipeIn<500>>,Coral,TrJoin<TrWipe<500>,TrWipeIn<500>>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accent
  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrJoinR<TrWipe<500>,TrWipeIn<500>>,Coral,TrJoin<TrWipe<500>,TrWipeIn<500>>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accent
  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrJoinR<TrWipe<500>,TrWipeIn<500>>,Coral,TrJoin<TrWipe<500>,TrWipeIn<500>>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accent
  StylePtr<Layers<
    TransitionLoop<Black,TrConcat<TrJoinR<TrWipe<500>,TrWipeIn<500>>,Coral,TrJoin<TrWipe<500>,TrWipeIn<500>>>>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,DeepSkyBlue,TrFade<200>,Blinking<Black,Blue,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

},

{ "DLT-19", "tracks/DLT-19.wav",
// barrel
StylePtr<Layers<
  Black,
  TransitionEffectL<TrConcat<TrWipe<100>,DarkOrange,TrWipe<100>,Black,TrWipe<200>>,EFFECT_FIRE>,
  TransitionEffectL<TrConcat<TrWipe<25>,DarkOrange,TrWipe<25>,Black,TrWipe<25>,DarkOrange,TrWipe<25>,Black,TrWipe<25>,DarkOrange,TrWipe<25>,Black,TrWipe<25>>,EFFECT_STUN>,
  LockupTrL<Layers<
    TransitionLoopL<TrConcat<TrWipe<30>,DarkOrange,TrWipe<30>>>,
    TransitionLoopL<TrConcat<TrInstant,AlphaL<DarkOrange,Bump<Int<0>,Int<18000>>>,TrFade<100>>>,
    TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<15000>>>,TrFade<30>>>>,TrConcat<TrInstant,Rgb<255,100,100>,TrFade<200>>,TrJoin<TrConcat<TrInstant,AlphaL<Rgb<50,25,0>,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeX<Int<400>>,TrWaveX<Rgb<50,0,0>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// muzzle
StylePtr<Layers<
  Black,
  TransitionEffectL<TrConcat<TrDelay<100>,DarkOrange,TrFade<200>,Black,TrFade<300>>,EFFECT_FIRE>,
  TransitionEffectL<TrConcat<TrWipe<25>,DarkOrange,TrWipe<25>,Black,TrWipe<25>,DarkOrange,TrWipe<25>,Black,TrWipe<25>,DarkOrange,TrWipe<25>,Black,TrWipe<25>>,EFFECT_STUN>,
  LockupTrL<Layers<
    TransitionLoopL<TrConcat<TrInstant,DarkOrange,TrFade<25>,Black,TrFade<25>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// accents
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipeIn<1500>,Gradient<Green,Yellow,Red>,TrWipe<1500>>>,
  TransitionEffectL<TrConcat<TrDelay<0>,DarkOrange,TrFade<200>,DarkOrange,TrFade<300>>,EFFECT_FIRE>,
  TransitionEffectL<TrConcat<TrDelay<0>,DarkOrange,TrFade<200>,Blinking<DarkOrange,Red,100,500>,TrFade<300>>,EFFECT_STUN>,
  LockupTrL<Layers<
    TransitionLoopL<TrConcat<TrInstant,DarkOrange,TrFade<25>,Red,TrFade<25>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipeIn<1500>,Gradient<Green,Yellow,Red>,TrWipe<1500>>>,
  TransitionEffectL<TrConcat<TrDelay<0>,DarkOrange,TrFade<200>,DarkOrange,TrFade<300>>,EFFECT_FIRE>,
  TransitionEffectL<TrConcat<TrDelay<0>,DarkOrange,TrFade<200>,Blinking<DarkOrange,Red,100,500>,TrFade<300>>,EFFECT_STUN>,
  LockupTrL<Layers<
    TransitionLoopL<TrConcat<TrInstant,DarkOrange,TrFade<25>,Red,TrFade<25>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipeIn<1500>,Gradient<Green,Yellow,Red>,TrWipe<1500>>>,
  TransitionEffectL<TrConcat<TrDelay<0>,DarkOrange,TrFade<200>,DarkOrange,TrFade<300>>,EFFECT_FIRE>,
  TransitionEffectL<TrConcat<TrDelay<0>,DarkOrange,TrFade<200>,Blinking<DarkOrange,Red,100,500>,TrFade<300>>,EFFECT_STUN>,
  LockupTrL<Layers<
    TransitionLoopL<TrConcat<TrInstant,DarkOrange,TrFade<25>,Red,TrFade<25>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents
StylePtr<Layers<
  TransitionLoop<Black,TrConcat<TrWipeIn<1500>,Gradient<Green,Yellow,Red>,TrWipe<1500>>>,
  TransitionEffectL<TrConcat<TrDelay<0>,DarkOrange,TrFade<200>,DarkOrange,TrFade<300>>,EFFECT_FIRE>,
  TransitionEffectL<TrConcat<TrDelay<0>,DarkOrange,TrFade<200>,Blinking<DarkOrange,Red,100,500>,TrFade<300>>,EFFECT_STUN>,
  LockupTrL<Layers<
    TransitionLoopL<TrConcat<TrInstant,DarkOrange,TrFade<25>,Red,TrFade<25>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
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
    Cylon<Pink,5,20,Pink,5,20,1>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,White,TrWipeIn<100>,Black,TrWipeIn<200>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrWipeIn<100>,White,TrWipeIn<100>,Blinking<Black,Black,100,500>,TrWipeIn<200>>,EFFECT_STUN>,
    LockupTrL<Layers<
     TransitionLoopL<TrConcat<TrWipeIn<50>,White,TrWipeIn<150>>>,
     TransitionLoopL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrFade<200>>>,
     TransitionLoopL<TrConcat<TrFade<1600>,AlphaL<White,Bump<Int<0>,Int<25000>>>,TrInstant>>>,TrConcat<TrInstant,Stripes<3500,-2500,White,White,Black,Black>,TrDelay<1600>>,TrJoin<TrConcat<TrInstant,AlphaL<Black,Bump<Int<32768>,Int<60000>>>,TrFade<400>>,TrWipeInX<Int<400>>,TrWaveX<Rgb<225,225,225>,Int<1800>,Int<40>,Int<400>,Int<5000>>>,SaberBase::LOCKUP_AUTOFIRE>>>(),

// accents 1
  StylePtr<Layers<
	StyleFire<Stripes<30000,-100,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,Mix<Int<16384>,Black,Stripes<30000,-100,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>>,0,4>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,31000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrInstant,TrInstant,Black>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Blinking<Black,Black,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents 2
  StylePtr<Layers<
	StyleFire<Stripes<30000,-100,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,Mix<Int<16384>,Black,Stripes<30000,-100,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>>,0,4>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,31000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrInstant,TrInstant,Black>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Blinking<Black,Black,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents 3
  StylePtr<Layers<
	StyleFire<Stripes<30000,-100,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,Mix<Int<16384>,Black,Stripes<30000,-100,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>>,0,4>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,31000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrInstant,TrInstant,Black>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Blinking<Black,Black,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
// accents 4
  StylePtr<Layers<
	StyleFire<Stripes<30000,-100,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,Mix<Int<16384>,Black,Stripes<30000,-100,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,RotateColorsX<Int<5461>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<10922>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<16384>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<21845>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Int<27306>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>>,0,4>,LockupTrL<AlphaL<TransitionEffect<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Int<300>>,TrExtend<4000,TrInstant>,TrFade<4000>,EFFECT_DRAG_BEGIN>,SmoothStep<Scale<TwistAngle<>,IntArg<DRAG_SIZE_ARG,31000>,Int<30000>>,Int<3000>>>,TrWipeIn<200>,TrWipe<200>,SaberBase::LOCKUP_DRAG,Int<1>>,LockupTrL<AlphaL<Stripes<2000,4000,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,Mix<Sin<Int<50>>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,Mix<Int<4096>,Black,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<HumpFlicker<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>,RotateColorsX<Int<3000>,Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,68,0>>>>>,100>,SmoothStep<Scale<TwistAngle<>,IntArg<MELT_SIZE_ARG,26000>,Int<30000>>,Int<3000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT,Int<1>>,InOutTrL<TrInstant,TrInstant,Black>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Red,TrFade<300>>,EFFECT_FIRE>,
    TransitionEffectL<TrConcat<TrDelay<0>,White,TrFade<200>,Blinking<Black,Black,100,500>,TrFade<300>>,EFFECT_STUN>,
    LockupTrL<Layers<
      TransitionLoopL<TrConcat<TrInstant,White,TrFade<50>,Red,TrFade<150>>>>,TrInstant,TrConcat<TrInstant,Rgb<50,0,0>,TrFade<400>>,SaberBase::LOCKUP_AUTOFIRE>>>(),
},

};

BladeConfig blades[] = {
{ 0, 
	SubBlade(9, 19, WS281XBladePtr<20, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >()), /* muzzle */
	SubBlade(0, 8, NULL), /* barrel */
	SubBlade(0, 15, DimBlade(8.0, WS281XBladePtr<64, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin4> >())), /* accent line 1 */
		SubBladeReverse(16, 31, NULL), /* accent line 2 */
		SubBlade(32, 47, NULL), /* accent line 3 */
		SubBladeReverse(48, 63, NULL), /* accent line 4 */
CONFIGARRAY(presets) },
};

#endif

#ifdef CONFIG_BUTTONS
Button FireButton(BUTTON_FIRE, powerButtonPin, "fire");
Button ModeButton(BUTTON_MODE_SELECT, auxPin, "modeselect");

#endif