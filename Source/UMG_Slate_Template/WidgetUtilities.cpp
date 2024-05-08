// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetUtilities.h"

#include "Components/Widget.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Slate/WidgetRenderer.h"

DEFINE_LOG_CATEGORY(LogWidgetUtilities);

UTextureRenderTarget2D* UWidgetUtilities::DrawSlateWidgetToRenderTarget2D(const TSharedRef<SWidget>& Widget,
	const FVector2D DrawSize, const bool bUseGamma)
{
	// Valid check the size
	{
		const bool bIsXInvalid = DrawSize.X <= 0;
		const bool bIsYInvalid = DrawSize.Y <= 0;
		// Valid check that our draw sizes are not less than zero!
		if(bIsXInvalid || bIsYInvalid)
		{
			UE_LOG(LogWidgetUtilities, Error, TEXT("Cannot draw when DrawSize(%s) Axis(%s) is Negative or Zero!"),
				*DrawSize.ToString(),
				(bIsXInvalid) ? TEXT("X") : TEXT("Y"));
			return nullptr;
		}
	}

	// Create our widget renderer which turns it into a texture(this is used with UWidgetComponent, an Scene Component)
	FWidgetRenderer* renderer = new FWidgetRenderer(bUseGamma, false);
	// Valid check that it was created properly, if this breaks something else is broken in the engine :p
	check(renderer);
	// Tell the renderer to draw our widget to a render target 2D texture
	UTextureRenderTarget2D* outRenderTarget = renderer->DrawWidget(Widget, DrawSize);
	// Forces the renderer to finish what it has to render before cleaning up
	FlushRenderingCommands();
	// Since its a generic C++ pointer that hooks into UE's garbage collection, this tells it to be cleaned up properly 
	BeginCleanup(renderer);
	
	// We actually rendered the widget!!
	return outRenderTarget;
}

bool UWidgetUtilities::DrawWidgetToRenderTarget2D(UTextureRenderTarget2D*& OutTarget,
	UWidget* WidgetToRender, const FVector2D DrawSize, const bool bUseGamma)
{
	// Reset the pointer to avoid recalling the function in Blueprint and the previous result being locally cached.
	OutTarget = nullptr;
	// Valid check that we're using a valid UWidget
	if(!IsValid(WidgetToRender))
	{
			UE_LOG(LogWidgetUtilities, Error, TEXT("Inputted NULL WidgetToRender"));
		return false;
	}
	// WidgetToRender->TakeWidget basically gets the Slate widget from our UWidget.
	OutTarget = DrawSlateWidgetToRenderTarget2D(WidgetToRender->TakeWidget(), DrawSize, bUseGamma);
	return IsValid(OutTarget);
}

void UWidgetUtilities::Generic_RequestScreenshotWithUI()
{
	FScreenshotRequest::RequestScreenshot(true);
}

void UWidgetUtilities::RequestScreenshotWithUI(const FString Filename, const bool bAddFilenameSuffix)
{
	FScreenshotRequest::RequestScreenshot(Filename, true, bAddFilenameSuffix);
}