class CfgPatches
{
	class Aurora
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
			{
				"DZ_Data",
				"DZ_Scripts"
				};
	};
};
class cfgVehicles
{
	class KazuarOptic;
	class RISAurora : KazuarOptic
	{
		scope = 2;
		displayName = "RIS Adapted Aurora";
		descriptionShort = "The SIONYX Aurora is a color digital night vision camera. It's ultra low light sensor technology empowers the viewer to see in full color down to 2 milllilux or near moonless starlight conditions. Mounted on a Camera RIS adapter, can me attached to weapons.";
		model = "AB-SiOnyx-Aurora\Aurora\Models\RISAurora\RISAurora.p3d";
		attachments[] = {"BatteryD"};
		animClass = "Binoculars";
		simulation = "itemoptics";
		memoryPointCamera = "eyeScope";
		cameraDir = "cameraDir";
		inventorySlot[] = {"weaponOpticsHunting", "weaponOptics", "sniperOptics"};
		itemSize[] = {2, 1};
		weight = 250;
		AuroraOptic = 1;
		NVOptic = 1;
		repairCosts[] = {50.0};
		class OpticsInfo
		{
			memoryPointCamera = "eyeScope";
			cameraDir = "cameraDir";
			useModelOptics = 1;
			modelOptics = "AB-SiOnyx-Aurora\Aurora\Models\Aurora\hud.p3d";
			preloadOpticType = "PreloadAurora";
			opticsDisablePeripherialVision = 0.0;
			opticsFlare = 0;
			opticsPPEffects[] = {};
			opticsZoomMin = 0.5236;
			opticsZoomMax = 0.5236;
			opticsZoomInit = 0.5236;
			distanceZoomMin = 100;
			distanceZoomMax = 100;
			discreteDistance[] = {100};
			discreteDistanceInitIndex = 0;
			PPMaskProperties[] = {0.5, 0.5, 0.4, 0.05};
			PPLensProperties[] = {0, 0, 0, 0};
			PPBlurProperties = 0;
		};
		class AnimationSources
		{
			class hide
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
		};
	};
};