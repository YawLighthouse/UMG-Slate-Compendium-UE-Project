// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class UMG_Slate_TemplateTarget : TargetRules
{
	public UMG_Slate_TemplateTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		CppStandard = CppStandardVersion.Cpp20;
		ExtraModuleNames.Add("UMG_Slate_Template");
	}
}
