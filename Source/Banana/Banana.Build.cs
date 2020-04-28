using System;
using System.IO;
using UnrealBuildTool;

public class Banana : ModuleRules
{
    public Banana(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Http",
                "Json",
            }
        );
    }
}
