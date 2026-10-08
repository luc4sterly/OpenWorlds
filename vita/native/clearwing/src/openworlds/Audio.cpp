// The sound output of net.openworlds.awt.NativeAudioDevice: an SDL2 audio
// device (PulseAudio or ALSA on Linux, sceAudioOut on the PSVita) fed with
// SDL_QueueAudio. Only built when the program uses it.
#if __has_include("net/openworlds/awt/NativeAudioDevice.h")
#include "net/openworlds/awt/NativeAudioDevice.h"
#include "java/lang/String.h"
#include <string>
#define SDL_MAIN_HANDLED
#include <SDL.h>

static SDL_AudioDeviceID device;
static std::string error;

extern "C" {

jbool SM_net_openworlds_awt_NativeAudioDevice_nativeOpen_int_int_R_boolean(jcontext ctx, jint rate, jint frames) {
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
        error = SDL_GetError();
        return false;
    }
    SDL_AudioSpec want{}, have{};
    want.freq = rate;
    want.format = AUDIO_S16SYS;
    want.channels = 2;
    want.samples = (Uint16) frames;
    // no changes allowed: SDL converts to whatever the hardware wants
    device = SDL_OpenAudioDevice(nullptr, 0, &want, &have, 0);
    if (!device) {
        error = SDL_GetError();
        SDL_QuitSubSystem(SDL_INIT_AUDIO);
        return false;
    }
    return true;
}

jobject SM_net_openworlds_awt_NativeAudioDevice_nativeError_R_java_lang_String(jcontext ctx) {
    return (jobject) stringFromNative(ctx, error.c_str());
}

void SM_net_openworlds_awt_NativeAudioDevice_nativePlay_Array1_short_int(jcontext ctx, jobject block, jint frames) {
    auto data = (jshort *) ((jarray) NULL_CHECK(block))->data;
    Uint32 bytes = (Uint32) frames * 4;
    SDL_QueueAudio(device, data, bytes);
    if (SDL_GetAudioDeviceStatus(device) != SDL_AUDIO_PLAYING)
        SDL_PauseAudioDevice(device, 0);
    // the mixer's pace: return once no more than three blocks wait to be played
    ctx->suspended = true;
    while (SDL_GetQueuedAudioSize(device) > 3 * bytes)
        SDL_Delay(2);
    ctx->suspended = false;
    SAFEPOINT();
}

void SM_net_openworlds_awt_NativeAudioDevice_nativeIdle(jcontext ctx) {
    // nothing to do: the queue plays out and SDL then plays silence
}

}
#endif
