#pragma once

#include "AICreationData.h"


class AIConsiderationSet
{
public:
	AIConsiderationSet();
	~AIConsiderationSet();

public:
        bool Init(const AICreationData& cd);
        // Evaluate all of the considerations and calculate the
        // overall addend, multiplier, weight, and rank.
        void Calculate();
        // Sets the best rank and weight currently under
        // consideration. These don't change the calculated
        // values, but they will change the values returned by
        // GetRank() and GetWeight().
        void SetScreeningWeight(float bestWeight);
        void SetScreeningRank(float bestRank);
        // Get the rank and weight. GetWeight() returns 0 if
        // the screening rank or screening weight checks fail.
        float GetWeight() const;
        float GetRank() const;
        // Get the raw values, unscreened.
        float GetAddend() const;
        float GetMultiplier() const;
        float GetWeightUnscreened() const;
        float GetRankUnscreened() const;

};

