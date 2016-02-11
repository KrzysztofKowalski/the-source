/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "FxPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FxPanel::FxPanel (SynthParams &p)
    : PanelBase(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (feedbackSlider = new MouseOverKnob ("Feedback"));
    feedbackSlider->setRange (0, 1, 0);
    feedbackSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    feedbackSlider->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    feedbackSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff2b3240));
    feedbackSlider->addListener (this);

    addAndMakeVisible (dryWetSlider = new MouseOverKnob ("Wet"));
    dryWetSlider->setRange (0, 1, 0);
    dryWetSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    dryWetSlider->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    dryWetSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff2b3240));
    dryWetSlider->addListener (this);

    addAndMakeVisible (timeSlider = new MouseOverKnob ("Time"));
    timeSlider->setRange (1, 5000, 1);
    timeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    timeSlider->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    timeSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff2b3240));
    timeSlider->addListener (this);
    timeSlider->setSkewFactor (0.33);

    addAndMakeVisible (syncToggle = new ToggleButton ("syncToggle1"));
    syncToggle->setButtonText (TRANS("Sync"));
    syncToggle->addListener (this);

    addAndMakeVisible (dividend = new IncDecDropDown ("delayDividend"));
    dividend->setTooltip (TRANS("Dividend"));
    dividend->setEditableText (false);
    dividend->setJustificationType (Justification::centred);
    dividend->setTextWhenNothingSelected (TRANS("1"));
    dividend->setTextWhenNoChoicesAvailable (TRANS("1"));
    dividend->addItem (TRANS("1"), 1);
    dividend->addItem (TRANS("2"), 2);
    dividend->addItem (TRANS("3"), 3);
    dividend->addItem (TRANS("4"), 4);
    dividend->addItem (TRANS("5"), 5);
    dividend->addItem (TRANS("6"), 6);
    dividend->addItem (TRANS("7"), 7);
    dividend->addItem (TRANS("8"), 8);
    dividend->addListener (this);

    addAndMakeVisible (divisor = new IncDecDropDown ("delayDivisor"));
    divisor->setTooltip (TRANS("Divisor"));
    divisor->setEditableText (false);
    divisor->setJustificationType (Justification::centred);
    divisor->setTextWhenNothingSelected (TRANS("4"));
    divisor->setTextWhenNoChoicesAvailable (TRANS("4"));
    divisor->addItem (TRANS("1"), 1);
    divisor->addItem (TRANS("2"), 2);
    divisor->addItem (TRANS("3"), 3);
    divisor->addItem (TRANS("4"), 4);
    divisor->addItem (TRANS("8"), 5);
    divisor->addItem (TRANS("16"), 6);
    divisor->addItem (TRANS("32"), 7);
    divisor->addItem (TRANS("64"), 8);
    divisor->addListener (this);

    addAndMakeVisible (cutoffSlider = new MouseOverKnob ("Cutoff"));
    cutoffSlider->setRange (1, 20000, 1);
    cutoffSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    cutoffSlider->setTextBoxStyle (Slider::TextBoxBelow, true, 80, 20);
    cutoffSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff2b3240));
    cutoffSlider->addListener (this);
    cutoffSlider->setSkewFactor (0.33);

    addAndMakeVisible (tripTggl = new ToggleButton ("tripTggl1"));
    tripTggl->setButtonText (TRANS("Triplet"));
    tripTggl->addListener (this);

    addAndMakeVisible (filtTggl = new ToggleButton ("filtTggl1"));
    filtTggl->setButtonText (TRANS("Record Cutoff"));
    filtTggl->addListener (this);

    addAndMakeVisible (revTggl = new ToggleButton ("revTggl"));
    revTggl->setButtonText (TRANS("Reverse"));
    revTggl->addListener (this);


    //[UserPreSize]
    registerSlider(feedbackSlider, &params.delayFeedback);
    registerSlider(dryWetSlider, &params.delayDryWet);
    registerSlider(timeSlider, &params.delayTime);
    registerSlider(cutoffSlider, &params.delayCutoff);


    dividend->setText(String("1"));
    divisor->setText(String("4"));
    dividend->setEnabled(false);
    divisor->setEnabled(false);
    tripTggl->setEnabled(false);
    //[/UserPreSize]

    setSize (330, 200);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

FxPanel::~FxPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    feedbackSlider = nullptr;
    dryWetSlider = nullptr;
    timeSlider = nullptr;
    syncToggle = nullptr;
    dividend = nullptr;
    divisor = nullptr;
    cutoffSlider = nullptr;
    tripTggl = nullptr;
    filtTggl = nullptr;
    revTggl = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FxPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff2b3240));

    //[UserPaint] Add your own custom painting code here..
    drawGroupBorder(g, "delay", 0, 0,
                    this->getWidth(), this->getHeight() - 22, 25.0f, 20.0f, 5.0f, 3.0f, SynthParams::fxColour);
    //[/UserPaint]
}

void FxPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    feedbackSlider->setBounds (172, 38, 64, 64);
    dryWetSlider->setBounds (17, 38, 64, 64);
    timeSlider->setBounds (96, 38, 64, 64);
    syncToggle->setBounds (15, 110, 63, 24);
    dividend->setBounds (15, 140, 64, 16);
    divisor->setBounds (90, 140, 64, 16);
    cutoffSlider->setBounds (249, 38, 64, 64);
    tripTggl->setBounds (168, 136, 63, 24);
    filtTggl->setBounds (232, 136, 63, 24);
    revTggl->setBounds (224, 104, 63, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FxPanel::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    handleSlider(sliderThatWasMoved);
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == feedbackSlider)
    {
        //[UserSliderCode_feedbackSlider] -- add your slider handling code here..
        //[/UserSliderCode_feedbackSlider]
    }
    else if (sliderThatWasMoved == dryWetSlider)
    {
        //[UserSliderCode_dryWetSlider] -- add your slider handling code here..
        //[/UserSliderCode_dryWetSlider]
    }
    else if (sliderThatWasMoved == timeSlider)
    {
        //[UserSliderCode_timeSlider] -- add your slider handling code here..
        //[/UserSliderCode_timeSlider]
    }
    else if (sliderThatWasMoved == cutoffSlider)
    {
        //[UserSliderCode_cutoffSlider] -- add your slider handling code here..
        //[/UserSliderCode_cutoffSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void FxPanel::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == syncToggle)
    {
        //[UserButtonCode_syncToggle] -- add your button handler code here..
        timeSlider->setEnabled(!timeSlider->isEnabled());
        dividend->setEnabled(!dividend->isEnabled());
        divisor->setEnabled(!divisor->isEnabled());
        tripTggl->setEnabled(!tripTggl->isEnabled());

        if (divisor->isEnabled()) {
            params.delaySync.setStep(eOnOffToggle::eOn);
            params.delayTime.set(params.delayTime.get() + 0.0000001f); //dirty hack
            params.delayTime.set(params.delayTime.get() - 0.0000001f); //dirty hack
        }
        else {
            params.delaySync.setStep(eOnOffToggle::eOff);
            timeSlider->setValue(params.delayTime.get());
            params.delayTime.setUI(static_cast<float>(params.delayTime.get()));
        }

        //[/UserButtonCode_syncToggle]
    }
    else if (buttonThatWasClicked == tripTggl)
    {
        //[UserButtonCode_tripTggl] -- add your button handler code here..
        if (params.delayTriplet.getStep() == eOnOffToggle::eOff) {
            params.delayTriplet.setStep(eOnOffToggle::eOn);
        }
        else { params.delayTriplet.setStep(eOnOffToggle::eOff); }
        //[/UserButtonCode_tripTggl]
    }
    else if (buttonThatWasClicked == filtTggl)
    {
        //[UserButtonCode_filtTggl] -- add your button handler code here..
        if (params.delayRecordFilter.getStep() == eOnOffToggle::eOff) {
            params.delayRecordFilter.setStep(eOnOffToggle::eOn);
        }
        else { params.delayRecordFilter.setStep(eOnOffToggle::eOff); }
        //[/UserButtonCode_filtTggl]
    }
    else if (buttonThatWasClicked == revTggl)
    {
        //[UserButtonCode_revTggl] -- add your button handler code here..
        if (params.delayReverse.getStep() == eOnOffToggle::eOff) {
            params.delayReverse.setStep(eOnOffToggle::eOn);
        }
        else { params.delayReverse.setStep(eOnOffToggle::eOff); }
        //[/UserButtonCode_revTggl]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void FxPanel::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == dividend)
    {
        //[UserComboBoxCode_dividend] -- add your combo box handling code here..
        params.delayDividend.set(dividend->getText().getFloatValue());
        //[/UserComboBoxCode_dividend]
    }
    else if (comboBoxThatHasChanged == divisor)
    {
        //[UserComboBoxCode_divisor] -- add your combo box handling code here..
        params.delayDivisor.set(divisor->getText().getFloatValue());
        //[/UserComboBoxCode_divisor]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FxPanel" componentName=""
                 parentClasses="public PanelBase" constructorParams="SynthParams &amp;p"
                 variableInitialisers="PanelBase(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="330"
                 initialHeight="200">
  <BACKGROUND backgroundColour="ff2b3240"/>
  <SLIDER name="Feedback" id="9c0383d8383ea645" memberName="feedbackSlider"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="172 38 64 64"
          rotarysliderfill="ff2b3240" min="0" max="1" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Wet" id="38a3801ec95e842b" memberName="dryWetSlider" virtualName="MouseOverKnob"
          explicitFocusOrder="0" pos="17 38 64 64" rotarysliderfill="ff2b3240"
          min="0" max="1" int="0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Time" id="5ac27dc9db375d94" memberName="timeSlider" virtualName="MouseOverKnob"
          explicitFocusOrder="0" pos="96 38 64 64" rotarysliderfill="ff2b3240"
          min="1" max="5000" int="1" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="0.33000000000000001554"/>
  <TOGGLEBUTTON name="syncToggle1" id="103062bcdc341811" memberName="syncToggle"
                virtualName="" explicitFocusOrder="0" pos="15 110 63 24" buttonText="Sync"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <COMBOBOX name="delayDividend" id="f2c88d87f26bec88" memberName="dividend"
            virtualName="IncDecDropDown" explicitFocusOrder="0" pos="15 140 64 16"
            tooltip="Dividend" editable="0" layout="36" items="1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8"
            textWhenNonSelected="1" textWhenNoItems="1"/>
  <COMBOBOX name="delayDivisor" id="182e27201e78c23e" memberName="divisor"
            virtualName="IncDecDropDown" explicitFocusOrder="0" pos="90 140 64 16"
            tooltip="Divisor" editable="0" layout="36" items="1&#10;2&#10;3&#10;4&#10;8&#10;16&#10;32&#10;64"
            textWhenNonSelected="4" textWhenNoItems="4"/>
  <SLIDER name="Cutoff" id="4e89be5035a6b485" memberName="cutoffSlider"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="249 38 64 64"
          rotarysliderfill="ff2b3240" min="1" max="20000" int="1" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.33000000000000001554"/>
  <TOGGLEBUTTON name="tripTggl1" id="805f456c4a709e07" memberName="tripTggl"
                virtualName="" explicitFocusOrder="0" pos="168 136 63 24" buttonText="Triplet"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="filtTggl1" id="14d5d3ba9ac30e1f" memberName="filtTggl"
                virtualName="" explicitFocusOrder="0" pos="232 136 63 24" buttonText="Record Cutoff"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="revTggl" id="abad5a425656f18e" memberName="revTggl" virtualName=""
                explicitFocusOrder="0" pos="224 104 63 24" buttonText="Reverse"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
