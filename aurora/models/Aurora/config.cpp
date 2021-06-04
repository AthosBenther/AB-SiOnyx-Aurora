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
	class AuroraCamera : NVGoggles
	{
		scope = 2;
		displayName = "SiOnyx Aurora";
		descriptionShort = "The SIONYX Aurora is a color digital night vision camera. It's ultra low light sensor technology empowers the viewer to see in full color down to 2 milllilux or near moonless starlight conditions";
		model = "AB-SiOnyx-Aurora\Aurora\Models\Aurora\Aurora.p3d";
		attachments[] = {"BatteryD"};
		animClass = "Binoculars";
		simulation = "itemoptics";
		memoryPointCamera = "eyeScope";
		cameraDir = "cameraDir";
		inventorySlot[] = {};
		itemSize[] = {2, 1};
		weight = 230;
		AuroraOptic = 1;
		NVOptic = 1;
		simpleHiddenSelections[] = {"hide", "zbytek"};
		repairCosts[] = {50.0};
		class OpticsInfo
		{
			memoryPointCamera = "eyeScope";
			cameraDir = "cameraDir";
			useModelOptics = 1;
			modelOptics = "AB-SiOnyx-Aurora\Aurora\Models\Aurora\HUD.p3d";
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