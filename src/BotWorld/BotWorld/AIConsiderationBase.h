#pragma once

#include "AICreationData.h"
#include "AIWeightValues.h"

// Evalutes a single aspect of the current situation
// Distance (How far to X?)
// Picker (Which enemy should I pick?) (Which X should I pick?)
// Execution History (What actions have I done in the past?)

// Note: Many of these shouldn't need to be calculated with every update
// They can be cached or queried from another system that updates these 
// on other threads at appropriate time.

class AIConsiderationBase {
public:
    AIConsiderationBase();
    ~AIConsiderationBase();

public:
    // Load the configuration.
    virtual bool Init(const AICreationData& cd) = 0;
    // Called once per decision cycle, allows the
    // consideration to evaluate the situation and

    // determine what to return.
    virtual void Calculate() = 0;


    // These are GAIA's weight values. They return the
    // results computed by Calculate().
    virtual float GetAddend() const;
    virtual float GetMultiplier() const;
    virtual float GetRank() const;
	// older approach?
	const AIWeightValues& GetResults() { return m_weights; }
protected:
	AIWeightValues m_weights;


public:
    // Certain considerations need to know if/when they are
    // selected or deselected.
    virtual void Select() {}
    virtual void Deselect() {}

	// older version?
	// Some functions need to know when the associated option is 
	// selected/deselected (for example, to store timing information). 
	virtual void Select(AIContext* /*pContext*/) {} 
	virtual void Deselect(AIContext* /*pContext*/) {}

};
