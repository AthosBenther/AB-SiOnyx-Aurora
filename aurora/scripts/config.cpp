
class CfgPatches
{
	class aurora_Scripts
	{
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Scripts"};
	};
};

class CfgMods 
{
	class DZ_aurora
	{
		name = "AB SiOnyx Aurora";
		dir = "aurora";
		credits = "";
		author = "";
		creditsJson = "aurora/Scripts/Data/Credits.json";
		versionPath = "aurora/scripts/Data/Version.hpp";
		inputs = "aurora/Scripts/Data/Inputs.xml";
		type = "mod";
		dependencies[] =
		{
			"Game", "World", "Mission"
		};
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"aurora/gui/imagesets/dayz_editor_gui.imageset"
				};
			};
			class engineScriptModule
			{
				value = "";
				files[] =
				{
					"aurora/scripts/common",
					"aurora/scripts/1_core"
				};
			};

			class gameScriptModule
			{
				value="";
				files[] = 
				{
					"aurora/scripts/common",
					"aurora/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[] = 
				{
					"aurora/scripts/common",
					"aurora/scripts/4_World"
				};
			};

			class missionScriptModule 
			{
				value="";
				files[] = 
				{
					"aurora/scripts/common",
					"aurora/scripts/5_Mission"
				};
			};
		};
	};
};
