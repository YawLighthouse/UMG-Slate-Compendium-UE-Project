// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WidgetUtilities.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogWidgetUtilities, Log, All);

/**
 * 
 */
UCLASS()
class UMG_SLATE_TEMPLATE_API UWidgetUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	/**
	 * Handles drawing the inputted UMG Widget as a render target 2D texture at the specified size.	 
	 * @param Widget The Widget to draw as a render target 2D texture.
	 * @param DrawSize The draw size of the texture, recommend playing with the desired size and/or the cached absolute/local size to get the intended results.
	 * @param bUseGamma True will use gamma when drawing the widget as a texture. False will not use gamma. Depending on the version of Unreal you're using, gamma might be not be implemented!
	 * @return The rendered widget, or NULL if failed to do so.
	 */
	static UTextureRenderTarget2D* DrawSlateWidgetToRenderTarget2D(const TSharedRef<SWidget>& Widget,
		const FVector2D DrawSize, const bool bUseGamma);

	/**
	 * Handles drawing the inputted UMG Widget as a render target 2D texture at the specified size.
	 * @param OutTarget The rendered widget, will be NULL if failed to do so.
	 * @param WidgetToRender The UMG Widget to draw as a render target 2D texture.
	 * @param DrawSize The draw size of the texture, recommend playing with the desired size and/or the cached absolute/local size to get the intended results.
	 * @param bUseGamma True will use gamma when drawing the widget as a texture. False will not use gamma. Depending on the version of Unreal you're using, gamma might be not be implemented!
	 * @return True if successfully drew widget as a render target 2D texture. False if failed to do so.
	 */
	UFUNCTION(BlueprintCallable, Category ="Widget Utilities",
		meta = (ExpandBoolAsExecs = "ReturnValue"))
	static bool DrawWidgetToRenderTarget2D(UTextureRenderTarget2D*& OutTarget,
		UWidget* WidgetToRender, const FVector2D DrawSize, const bool bUseGamma);

	/**
	 * Handles using the engine's built in screenshot system to take a screenshot of the in-game viewport including UMG/Slate elements.
	 * This screenshot will be automatically placed into the Saved/Screenshots folder of the project.
	 */
	UFUNCTION(BlueprintCallable, Category = "Widget Utilities",
		meta = (DisplayName = "(Generic) Request Screenshot with UI"))
	static void Generic_RequestScreenshotWithUI();

	/**
	 * Handles using the engine's built in screenshot system to take a screenshot of the in-game viewport including UMG/Slate elements.
	 * This screenshot will be automatically placed into the Saved/Screenshots folder of the project.
	 * @param Filename The name of the file.
	 * @param bAddFilenameSuffix Whether an auto-generated unique suffix should be added to the supplied filename.
	 */
	UFUNCTION(BlueprintCallable, Category = "Widget Utilities")
	static void RequestScreenshotWithUI(const FString Filename, const bool bAddFilenameSuffix);
	
};
