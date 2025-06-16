// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using UnrealBuildTool.Rules;

public class Testovoe : ModuleRules
{
	public Testovoe(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput", 
			"AIModule", 
			"NavigationSystem",
            "GameplayAbilities",
            "GameplayTasks",
            "GameplayTags",
            "UMG"
        });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.Add("AI");
        PublicIncludePaths.Add("GameplayAbilities");

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
