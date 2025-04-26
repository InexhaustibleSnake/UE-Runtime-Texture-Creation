// Made by Inexhaustible Snake

using UnrealBuildTool;
using System.Collections.Generic;

public class ISRTPluginEditorTarget : TargetRules
{
	public ISRTPluginEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "ISRTPlugin" } );
	}
}
