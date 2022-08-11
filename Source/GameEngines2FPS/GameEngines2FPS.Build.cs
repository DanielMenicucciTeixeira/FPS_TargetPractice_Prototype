// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameEngines2FPS : ModuleRules
{
	public GameEngines2FPS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
