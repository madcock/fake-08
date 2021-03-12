#pragma once

#include <stdio.h>
#include <vector>
#include <string>
#include "hostVmShared.h"
#include "Audio.h"

enum StretchOption {
  PixelPerfect,
  PixelPerfectStretch,
  StretchToFit,
  StretchToFill,
  StretchAndOverflow
};

class Host {
    public:
    Host();

    void oneTimeSetup(Color* paletteColors, Audio* audio);
    
    void setTargetFps(int targetFps);

    bool shouldRunMainLoop();

    InputState_t scanInput();
    bool shouldQuit();

    void changeStretch();
    
    void waitForTargetFps();

    void drawFrame(uint8_t* picoFb, uint8_t* screenPaletteMap);

    bool shouldFillAudioBuff();
    void* getAudioBufferPointer();
    size_t getAudioBufferSize();
    void playFilledAudioBuffer();

    void oneTimeCleanup();

    double deltaTMs();

    std::vector<std::string> listcarts();

    const char* logFilePrefix();

    std::string customBiosLua();
};
