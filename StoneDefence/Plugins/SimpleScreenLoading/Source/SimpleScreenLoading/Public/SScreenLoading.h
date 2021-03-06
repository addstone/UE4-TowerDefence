#pragma once

#include "Widgets/SCompoundWidget.h"

class SScreenLoading : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SScreenLoading)
	{}
	SLATE_END_ARGS();

	void Construct(const FArguments &InArgs, const FString &InMapName);

public:

	TOptional<float> GetProgress() const;

	FString MapName;
};