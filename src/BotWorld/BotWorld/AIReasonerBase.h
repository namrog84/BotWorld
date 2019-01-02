#pragma once

#include "AICreationData.h"
#include "AIOptionBase.h"

// Implement this reasoner for 
// AIReasoner_UtilityBased
// AIReasoner_RuleBased
// AIReasoner_SequenceBased
// AIReasoner_FiniteStateMachineBased
// Should this implement public AIBase? and what is AIBase?

class AIReasonerBase {
public:
    AIReasonerBase();
    ~AIReasonerBase();

public:
    // Load the configuration.
    virtual bool Init(const AICreationData& cd);
	
    // Used by the picker to add/remove options
    void AddOption(AIOptionBase& option);
    void Clear();
    // Enable/Disable the reasoner. Called when containing
    // action is selected or deselected, or when brain is
    // enabled/disabled.
    void Enable();
    void Disable();
    bool IsEnabled() const;

    // Sense, Think, and Act.
    // NOTE: Subclasses should not overload this. Instead,
    // they should overload Think() (ideally they shouldn't
    // have to do anything to Sense() or Act()).
    void Update();

    // Get the current selected option, if any. Used by the
    // picker.
    AIOptionBase* GetSelectedOption();

    // Most reasoners are considered to be done if they
    // don't have a selected option, either because they failed
    // to pick one or because they have no options.
    virtual bool IsDone();

protected:
    // other
    // Run any reasoner-specific sensors, where does this AIContext originate from?
	// Ideally sense should be a consideration?
	// Act should be part of The option's action?
    void Sense(AIContext* pContext);


    void Sense();
    virtual void Think();
    void Act();
};
