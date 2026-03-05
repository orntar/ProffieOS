// ProffieOS8 Config File
#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 5
#define NUM_BUTTONS 2
#define VOLUME 1000
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 1.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_OFF_TIME 60 * 15 * 1000
#define NO_REPEAT_RANDOM
#define DISABLE_BASIC_PARSER_STYLES
#define DISABLE_DIAGNOSTIC_COMMANDS
#define ENABLE_ALL_EDIT_OPTIONS
#define FETT263_DISABLE_CHANGE_FONT
#define FETT263_DISABLE_CHANGE_STYLE
#define FETT263_DISABLE_COPY_PRESET
#endif

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
   { "Glados;common", "tracks/StillAlive.wav",
    StylePtr<Layers<Pulsing<Mix<Int<10000>,Black,Red>,Black,2000>,TransitionEffectL<TrConcat<TrExtendX<WavLen<EFFECT_BLAST>,TrInstant>,Pulsing<Red,Black,1000>,TrFade<600>>,EFFECT_BLAST>,InOutTrL<TrFade<400>,TrFade<800>>>>(),
    StylePtr<Layers<Pulsing<Mix<Int<10000>,Black,Yellow>,Black,2000>,TransitionEffectL<TrConcat<TrExtendX<WavLen<EFFECT_BLAST>,TrInstant>,Pulsing<Yellow,Black,500>,TrFade<600>>,EFFECT_BLAST>,TransitionPulseL<TrDoEffect<TrInstant,EFFECT_TRANSITION_SOUND,0>,ThresholdPulseF<SwingSpeed<200>,Int<30000>>>,InOutTrL<TrFade<400>,TrFade<800>>,TransitionPulseL<TrDoEffectAlways<TrInstant,EFFECT_SOUND_LOOP,0>,ThresholdPulseF<Sum<EffectPulseF<EFFECT_BOOT>,EffectPulseF<EFFECT_NEWFONT>,EffectPulseF<EFFECT_RETRACTION>,EffectPulseF<EFFECT_IGNITION>>,Int<30000>>>>>(),
    StylePtr<Layers<Pulsing<Mix<Int<10000>,Black,Yellow>,Black,2000>,TransitionEffectL<TrConcat<TrExtendX<WavLen<EFFECT_BLAST>,TrInstant>,Pulsing<Yellow,Black,500>,TrFade<600>>,EFFECT_BLAST>,TransitionPulseL<TrDoEffect<TrInstant,EFFECT_TRANSITION_SOUND,0>,ThresholdPulseF<SwingSpeed<200>,Int<30000>>>,InOutTrL<TrFade<400>,TrFade<800>>,TransitionPulseL<TrDoEffectAlways<TrInstant,EFFECT_SOUND_LOOP,0>,ThresholdPulseF<Sum<EffectPulseF<EFFECT_BOOT>,EffectPulseF<EFFECT_NEWFONT>,EffectPulseF<EFFECT_RETRACTION>,EffectPulseF<EFFECT_IGNITION>>,Int<30000>>>>>(),
    StylePtr<Layers<Pulsing<Mix<Int<10000>,Black,Red>,Black,2000>,TransitionEffectL<TrConcat<TrExtendX<WavLen<EFFECT_BLAST>,TrInstant>,Pulsing<Red,Black,1000>,TrFade<600>>,EFFECT_BLAST>,InOutTrL<TrFade<400>,TrFade<800>>>>(),
    StylePtr<Layers<Pulsing<Mix<Int<10000>,Black,Red>,Black,2000>,TransitionEffectL<TrConcat<TrExtendX<WavLen<EFFECT_BLAST>,TrInstant>,Pulsing<Red,Black,1000>,TrFade<600>>,EFFECT_BLAST>,InOutTrL<TrFade<400>,TrFade<800>>>>(),
    "G"},
    { "Potato;common", "tracks/WantYouGone.wav",
    StylePtr<InOutSparkTip<EASYBLADE(BLUE, WHITE), 300, 800> >(),
    StylePtr<InOutSparkTip<EASYBLADE(BLUE, WHITE), 300, 800> >(),
	StyleNormalPtr<CYAN, WHITE, 300, 800>(),
    StyleNormalPtr<CYAN, WHITE, 300, 800>(),
    StylePtr<InOutSparkTip<EASYBLADE(BLUE, WHITE), 300, 800> >(),
    "P"},
};

BladeConfig blades[] = {
 { 0, SubBlade(0, 0, WS281XBladePtr<24, bladePin, Color8::GRB, PowerPINS<bladePowerPin2>>()),	//upper single
    SubBlade(1, 20, NULL),  //eye ring
	SubBlade(21, 21, NULL),  //eye center
    SubBlade(22, 22, NULL),  //thing upper
    SubBlade(23, 23, NULL),  //thing lower
    CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif
