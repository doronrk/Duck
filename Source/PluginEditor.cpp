/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
DuckEditor::DuckEditor (DuckProcessor& owner)
    : AudioProcessorEditor(owner)
{
    addAndMakeVisible (triggerNoteNumComboBox = new ComboBox ("trigger note num"));
    triggerNoteNumComboBox->setEditableText (false);
    triggerNoteNumComboBox->setJustificationType (Justification::centredLeft);
    triggerNoteNumComboBox->setTextWhenNothingSelected (TRANS("[select trigger note]"));
    triggerNoteNumComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    triggerNoteNumComboBox->addListener (this);

    addAndMakeVisible (triggerNoteLabel = new Label ("trigger note label",
                                                     TRANS("trigger note")));
    triggerNoteLabel->setFont (Font (15.00f, Font::plain));
    triggerNoteLabel->setJustificationType (Justification::centredLeft);
    triggerNoteLabel->setEditable (false, false, false);
    triggerNoteLabel->setColour (TextEditor::textColourId, Colours::black);
    triggerNoteLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    for (int noteNum = 0; noteNum < 128; noteNum++)
    {
        String midiNote = MidiMessage::getMidiNoteName(noteNum, true, true, 3);
        triggerNoteNumComboBox->addItem(midiNote, noteNum + 1);
    }
    //[/Constructor]
}

DuckEditor::~DuckEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    triggerNoteNumComboBox = nullptr;
    triggerNoteLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void DuckEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void DuckEditor::resized()
{
    triggerNoteNumComboBox->setBounds (328, 16, 150, 24);
    triggerNoteLabel->setBounds (328 + -80, 16 + 0, 72, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void DuckEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    DuckProcessor &processor = getDuckProcessor();
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == triggerNoteNumComboBox)
    {
        //[UserComboBoxCode_triggerNoteNumComboBox] -- add your combo box handling code here..
        int midiNoteSelected = triggerNoteNumComboBox->getSelectedItemIndex();
        processor.setTriggerNoteNum(midiNoteSelected);
        //[/UserComboBoxCode_triggerNoteNumComboBox]
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

<JUCER_COMPONENT documentType="Component" className="DuckEditor" componentName=""
                 parentClasses="public AudioProcessorEditor" constructorParams="DuckProcessor&amp; owner"
                 variableInitialisers="AudioProcessorEditor(owner)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <COMBOBOX name="trigger note num" id="ee545961234b17e0" memberName="triggerNoteNumComboBox"
            virtualName="" explicitFocusOrder="0" pos="328 16 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="[select trigger note]"
            textWhenNoItems="(no choices)"/>
  <LABEL name="trigger note label" id="4df15c6b3b654fb4" memberName="triggerNoteLabel"
         virtualName="" explicitFocusOrder="0" pos="-80 0 72 24" posRelativeX="ee545961234b17e0"
         posRelativeY="ee545961234b17e0" edTextCol="ff000000" edBkgCol="0"
         labelText="trigger note" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
