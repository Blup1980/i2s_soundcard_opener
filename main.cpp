#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <alsa/asoundlib.h>
#include <chrono>
#include <thread>
#include "Config.h"


static snd_pcm_t *handle;
static snd_pcm_stream_t stream = SND_PCM_STREAM_PLAYBACK;
static struct {
    snd_pcm_format_t format;
    unsigned int channels;
    unsigned int rate;
} hwparams, rhwparams;
static int open_mode = 0;

int main(int argc, char *argv[])
{
    int err;
    char *pcm_name = "dmixer";
    rhwparams.channels = 2;
    rhwparams.rate = 44100;
    rhwparams.format = SND_PCM_FORMAT_S16_LE;

    err = snd_pcm_open(&handle, pcm_name, stream, open_mode);
    if (err < 0) {
        exit(EXIT_FAILURE); 
    }

    while(1){
        std::this_thread::sleep_for(std::chrono::milliseconds(750));
    };
    
    exit(EXIT_SUCCESS);
}
