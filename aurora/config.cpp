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
        };
    };
};
class cfgVehicles
{
    class Inventory_Base;
    class Switchable_Base;
    class NVGoggles;
	class KazuarOptic;
	class Aurora : KazuarOptic
	{
		scope = 2;
		displayName = "SiOnyx Aurora";
        descriptionShort = "The SIONYX Aurora is a color digital night vision camera. It's ultra low light sensor technology empowers the viewer to see in full color down to 2 milllilux or near moonless starlight conditions";
		model = "AB-SiOnyx-Aurora\aurora\aurora.p3d";
		attachments[] = {"BatteryD"};
		animClass = "Binoculars";
		simulation = "itemoptics";
		memoryPointCamera = "eyeScope";
		cameraDir = "cameraDir";
		inventorySlot[] = {};
		itemSize[] = {2,1};
		weight = 230;
		AuroraOptic = 1;
		NVOptic = 1;
		repairCosts[] = {50.0};
		class OpticsInfo
		{
			memoryPointCamera = "eyeScope";
			cameraDir = "cameraDir";
			useModelOptics = 1;
			modelOptics = "AB-SiOnyx-Aurora\aurora\hud.p3d";
			preloadOpticType = "PreloadAurora";
			opticsDisablePeripherialVision = 0.67;
			opticsFlare = 1;
			opticsPPEffects[] = {};
			opticsZoomMin = 0.5236;
			opticsZoomMax = 0.5236;
			opticsZoomInit = 0.5236;
			distanceZoomMin = 100;
			distanceZoomMax = 100;
			discreteDistance[] = {100};
			discreteDistanceInitIndex = 0;
			PPMaskProperties[] = {0.5,0.5,0.4,0.05};
			PPLensProperties[] = {1,0.15,0,0};
			PPBlurProperties = 1;
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
	class RISAurora : Aurora
	{
		displayName = "RIS Adapter mounted SiOnyx Aurora";
		model = "AB-SiOnyx-Aurora\aurora\risaurora.p3d";
		inventorySlot[] = {"weaponOpticsHunting","weaponOptics","sniperOptics"};
		weight = 250;
	};
    class HMDAurora2 : NVGoggles
    {
        scope = 2;
		displayName = "Head mounted dual SiOnyx Aurora";
        descriptionShort = "The SIONYX Aurora is a color digital night vision camera. It's ultra low light sensor technology empowers the viewer to see in full color down to 2 milllilux or near moonless starlight conditions";
		model = "AB-SiOnyx-Aurora\aurora\hmdaurora2.p3d";
		inventorySlot[] = {"NVG"};
		itemSize[] = {3,3};
		weight = 600;
		AuroraOptic = 1;
		repairCosts[] = {50.0};
    };
	class HMDAurora : HMDAurora2
	{
		displayName = "Head mounted single SiOnyx Aurora";
		model = "AB-SiOnyx-Aurora\aurora\hmdaurora.p3d";
		attachments[] = {"BatteryD","BatteryD"};
		weight = 400;
	};
	class PreloadAurora: Inventory_Base
	{
		scope = 0;
		model = "AB-SiOnyx-Aurora\aurora\hud.p3d";
	};
};
class CfgMods
{
	class Aurora
	{
		dir = "aurora";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Aurora";
		credits = "Athos Benther";
		author = "Athos Benther";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"AB-SiOnyx-Aurora/aurora/scripts"};
			};
		};
	};
};