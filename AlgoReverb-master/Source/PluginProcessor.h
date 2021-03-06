/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "FractionalDelay.hpp"
#include "FractionalDelay.hpp"
#include "APF.hpp"
#include "Schroeder.hpp"
#include "EarlyReflections.h"

//==============================================================================
/**
*/
class AlgoReverbAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AlgoReverbAudioProcessor();
    ~AlgoReverbAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    float predelayMS = 0.f;
    float wet = 0.5f;
    float timeValue = 0.5f;
    float modValue = 1.f;
    float diffusionValue = 0.5f;
    
private:
    
    FractionalDelay predelay;
    //FDN fdn;
    //APF apf1{240.f, 0.8321f};
    //APF apf2{82.f , 0.9640f};
    
    Schroeder schroeder;
    EarlyReflections EF;
    
    int tapTimes[18] = {190,949,993,1183,1192,1315,2021,2140,2524,2590,2625,2700,3119,3123,3202,3268,3321,3515};
    
    float Fs = 48000.0f;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AlgoReverbAudioProcessor)
};
