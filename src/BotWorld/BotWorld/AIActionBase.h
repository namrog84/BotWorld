#pragma once

#include "AICreationData.h"


// When an option is selected, do this action
// Move
// Fire Weapon
// another SubReasoner can be contained here

// a custom sub reasoner implements AIAction but contains an specific implementation of AIReasonerBase? 
// 

class AIActionBase {
public:
    AIActionBase();
    ~AIActionBase();

public:
    // Load the configuration.
    virtual bool Init(const AICreationData& cd) = 0;
    // Called when the action starts/stops execution.
    virtual void Select() {}
    virtual void Deselect() {}
    // Called every frame while the action is selected.
    virtual void Update() {}
    // Check whether this action is finished executing.
    // Some actions (such as a looping animation) are never done,
    // but others (such as moving to a position) can be
    // completed.
    virtual bool IsDone()
    {
        return true;
    }
};
