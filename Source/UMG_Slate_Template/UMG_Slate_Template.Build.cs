// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UMG_Slate_Template : ModuleRules
{
	public UMG_Slate_Template(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		// PublicDependencyModuleNames.AddRange(new string[]
		// {
		// });
		
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay", 
			"EnhancedInput",
			"RenderCore",
			"UMG",
			"Slate",
			"SlateCore",
		});
	}
}
