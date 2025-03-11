/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.12

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GainAudioProcessorEditor::GainAudioProcessorEditor (GainAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    gainSlider.reset (new juce::Slider ("Gain Slider"));
    addAndMakeVisible (gainSlider.get());
    gainSlider->setRange (-30, 30, 0.1);
    gainSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    gainSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    gainSlider->addListener (this);

    gainSlider->setBounds (128, 64, 239, 24);

    gainLabel.reset (new juce::Label ("Gain Label",
                                      TRANS ("Gain [db]")));
    addAndMakeVisible (gainLabel.get());
    gainLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    gainLabel->setJustificationType (juce::Justification::centredLeft);
    gainLabel->setEditable (false, false, false);
    gainLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    gainLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    gainLabel->setBounds (16, 64, 150, 24);

    thresholdSlider.reset (new juce::Slider ("Threshold Slider"));
    addAndMakeVisible (thresholdSlider.get());
    thresholdSlider->setRange (0, 60, 0.1);
    thresholdSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    thresholdSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    thresholdSlider->addListener (this);

    thresholdSlider->setBounds (128, 96, 238, 24);

    thresholdLabel.reset (new juce::Label ("Threshold Label",
                                           TRANS ("Threshold [dB]")));
    addAndMakeVisible (thresholdLabel.get());
    thresholdLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    thresholdLabel->setJustificationType (juce::Justification::centredLeft);
    thresholdLabel->setEditable (false, false, false);
    thresholdLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    thresholdLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    thresholdLabel->setBounds (16, 96, 150, 24);

    clipSlider.reset (new juce::Slider ("Clip Slider"));
    addAndMakeVisible (clipSlider.get());
    clipSlider->setRange (0, 100, 1);
    clipSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    clipSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    clipSlider->addListener (this);

    clipSlider->setBounds (128, 128, 238, 24);

    clipLabel.reset (new juce::Label ("Clip Label",
                                      TRANS ("Clip [%]")));
    addAndMakeVisible (clipLabel.get());
    clipLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    clipLabel->setJustificationType (juce::Justification::centredLeft);
    clipLabel->setEditable (false, false, false);
    clipLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    clipLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    clipLabel->setBounds (16, 128, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 200);


    //[Constructor] You can add your own custom stuff here..
    getProcessor()->RequestUIUpdate(); //pointer la partea de procesare
    startTimer(200);
    //[/Constructor]
}

GainAudioProcessorEditor::~GainAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    gainSlider = nullptr;
    gainLabel = nullptr;
    thresholdSlider = nullptr;
    thresholdLabel = nullptr;
    clipSlider = nullptr;
    clipLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GainAudioProcessorEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff357493));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GainAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GainAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    GainAudioProcessor* ourProcessor = getProcessor();      //slider-ul updateaza codul
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == gainSlider.get())
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
        float normValueGain = powf(10.f, (float)gainSlider->getValue() / 20.f);
        ourProcessor->setParameter(GainAudioProcessor::gain, normValueGain);
        //[/UserSliderCode_gainSlider]
    }
    else if (sliderThatWasMoved == thresholdSlider.get())
    {
        //[UserSliderCode_thresholdSlider] -- add your slider handling code here..
        float normValueThr = powf(10.f, (float)thresholdSlider->getValue() / 20.f);
        ourProcessor->setParameter(GainAudioProcessor::thr, normValueThr);
        //[/UserSliderCode_thresholdSlider]
    }
    else if (sliderThatWasMoved == clipSlider.get())
    {
        //[UserSliderCode_clipSlider] -- add your slider handling code here..
        float normValueClip = 1 + ( (float)clipSlider->getValue() / 100) * (10 - 1);
        ourProcessor->setParameter(GainAudioProcessor::clip, normValueClip);
        //[/UserSliderCode_clipSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void GainAudioProcessorEditor::timerCallback()
{
    GainAudioProcessor* ourProcessor = getProcessor();
 //se schimba datele dorite intre elementele interfetei grafice si modulul “ourProcessor”

    if (ourProcessor->NeedsUIUpdate())      //se updateaza sliderul daca se schimba ceva
    {
        float dbValueGain = 20.f * log10(ourProcessor->getParameter(GainAudioProcessor::gain));
        gainSlider->setValue(dbValueGain, juce::dontSendNotification);

        float dbValueThr = 20.f * log10(ourProcessor->getParameter(GainAudioProcessor::thr));
        thresholdSlider->setValue(dbValueThr, juce::dontSendNotification);

        float valNorm = ourProcessor->getParameter(GainAudioProcessor::clip);
        float val = (valNorm - 1.f) / (10.f - 1.f) * 100.f;
        clipSlider->setValue(val, juce::dontSendNotification);

        //frecvSlider->setValue(val, juce::dontSendNotification);



        ourProcessor->ClearUIUpdateFlag();
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GainAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="GainAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="400" initialHeight="200">
  <BACKGROUND backgroundColour="ff357493"/>
  <SLIDER name="Gain Slider" id="aad3f340f5984b55" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="128 64 239 24" min="-30.0"
          max="30.0" int="0.1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Gain Label" id="7946995c4fda6c3a" memberName="gainLabel"
         virtualName="" explicitFocusOrder="0" pos="16 64 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Gain [db]" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Threshold Slider" id="8b9394ef4c65e5e5" memberName="thresholdSlider"
          virtualName="" explicitFocusOrder="0" pos="128 96 238 24" min="0.0"
          max="60.0" int="0.1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Threshold Label" id="e2e15c5bdfcd6bd2" memberName="thresholdLabel"
         virtualName="" explicitFocusOrder="0" pos="16 96 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Threshold [dB]" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Clip Slider" id="39e804a999079818" memberName="clipSlider"
          virtualName="" explicitFocusOrder="0" pos="128 128 238 24" min="0.0"
          max="100.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Clip Label" id="4089bc90a928912e" memberName="clipLabel"
         virtualName="" explicitFocusOrder="0" pos="16 128 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Clip [%]" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

