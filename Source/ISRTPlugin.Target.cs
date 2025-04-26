// Made by Inexhaustible Snake

using UnrealBuildTool;
using System.Collections.Generic;

public class ISRTPluginTarget : TargetRules
{
	public ISRTPluginTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "ISRTPlugin" } );
	}
}
