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
	class NVGoggles;
	class HMDAurora : NVGoggles
	{
		scope = 2;
		displayName = "Head Mounted Aurora";
		descriptionShort = "The SIONYX Aurora is a color digital night vision camera. It's ultra low light sensor technology empowers the viewer to see in full color down to 2 milllilux or near moonless starlight conditions";
		model = "AB-SiOnyx-Aurora\Aurora\Models\HMDAurora\HMDAurora.p3d";
		inventorySlot[] = {"NVG"};
		itemSize[] = {3, 3};
		weight = 400;
		AuroraOptic = 1;
		repairCosts[] = {50.0};
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