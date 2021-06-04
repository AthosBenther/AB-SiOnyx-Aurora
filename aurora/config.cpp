class CfgPatches
{
	class AuroraCamera
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
			{
				"DZ_Data",
				"DZ_Scripts"};
	};
};
class CfgMods
{
	class AuroraCamera
	{
		dir = "Aurora";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "SiOnyx Aurora";
		credits = "Athos Benther";
		author = "Athos Benther";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {
					"AB-SiOnyx-Aurora/Aurora/scripts/4_World"};
			};
			class gameScriptModule
			{
				value = "";
				files[] =
					{
						"AB-SiOnyx-Aurora/Aurora/scripts/3_Game"};
			};
		};
	};
};