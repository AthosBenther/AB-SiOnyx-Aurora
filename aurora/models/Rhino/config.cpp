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
class cfgVehicles
{
	class ItemOptics;
	class RhinoMount : ItemOptics
	{
		scope = 2;
		displayName = "Rhino Mount";
		desctriptionShort = "A NVG mount";
		model = "AB-SiOnyx-Aurora\Aurora\Models\Rhino\Rhino.p3d";
		simulation = "itemoptics";
		animClass = "Knife";
		inventorySlot[] = {"NVG"};
		itemSize[] = {2, 1};
		rotationFlags = 1;
		simpleHiddenSelections[] = {"hide"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0, {}}, {0.7, {}}, {0.5, {}}, {0.3, {}}, {0.0, {}}};
				};
			};
		};

		NVOptic = 0;
		AuroraOptic = 0;
		weight = 150;
		class AnimationSources
		{
			class hide
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class rotate
			{
				source = "user";
				animPeriod = 0.3;
				initPhase = 0;
			};
		};
	};
};
