#include "gsAudio.h"


#include "Audiere\audiere.h"
#include "gsMacros.h"

using namespace audiere;
#define CHANNEL_COUNT 16


struct gsChannelWrarper {
	OutputStreamPtr gsChannelStream;
	bool running;

	gsChannelWrarper() { running = false; }
};


AudioDevicePtr gDevice;
gsChannelWrarper gChannels[CHANNEL_COUNT];

void gsAudio::init() {
	gDevice = AudioDevicePtr(OpenDevice());
}
void gsAudio::update() {
	for (int i = 0; i < CHANNEL_COUNT; i++)
	{
		if (gChannels[i].running == true) {
			if (!gChannels[i].gsChannelStream->isPlaying()) {
				gChannels[i].running = false;
			}
		}
	}
}
void gsAudio::dispose() {
	for (int i = 0; i < CHANNEL_COUNT; i++)
	{
		if (gChannels[i].running == true) {
			gChannels[i].gsChannelStream->stop();
		}
	}
}

gsChannel gsAudio::play(const char* path, bool repeat, float volume, float pan) {
	for (int i = 0; i < CHANNEL_COUNT; i++)
	{
		if (gChannels[i].running == false) {
			gChannels[i].gsChannelStream = OutputStreamPtr(OpenSound(gDevice, path, false));
		}
		gChannels[i].gsChannelStream->stop();
		gChannels[i].gsChannelStream->play();
		gChannels[i].gsChannelStream->setRepeat(repeat);
		gChannels[i].gsChannelStream->setVolume(volume);
		gChannels[i].gsChannelStream->setPan(pan);

		gChannels[i].running = true;

		return i;
	}
	gsAssert(0); // Not enough channels
	return -1;
}
void gsAudio::stop(gsChannel channel) {
	if (gChannels[channel].running == true) {
		gChannels[channel].gsChannelStream->stop();

		gChannels[channel].running = false;
	}
}