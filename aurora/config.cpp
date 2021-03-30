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
				"DZ_Scripts"};
	};
};
class cfgVehicles
{
	class Inventory_Base;
	class Switchable_Base;
	class NVGoggles;
	class KazuarOptic;
	class BUISOptic;
	class Aurora : NVGoggles
	{
		scope = 2;
		displayName = "SiOnyx Aurora";
		descriptionShort = "The SIONYX Aurora is a color digital night vision camera. It's ultra low light sensor technology empowers the viewer to see in full color down to 2 milllilux or near moonless starlight conditions";
		model = "AB-SiOnyx-Aurora\Aurora\Aurora.p3d";
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
			modelOptics = "AB-SiOnyx-Aurora\Aurora\hud.p3d";
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
	class RISAurora : KazuarOptic
	{
		scope = 2;
		displayName = "RIS Adapted Aurora";
		descriptionShort = "The SIONYX Aurora is a color digital night vision camera. It's ultra low light sensor technology empowers the viewer to see in full color down to 2 milllilux or near moonless starlight conditions. Mounted on a Camera RIS adapter, can me attached to weapons.";
		model = "AB-SiOnyx-Aurora\Aurora\RISAurora.p3d";
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
			modelOptics = "AB-SiOnyx-Aurora\Aurora\hud.p3d";
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
			PPMaskProperties[] = {0.5, 0.5, 0.4, 0.05};
			PPLensProperties[] = {1, 0.15, 0, 0};
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
	class HMDAurora2 : NVGoggles
	{
		scope = 2;
		displayName = "Head mounted dual SiOnyx Aurora";
		descriptionShort = "The SIONYX Aurora is a color digital night vision camera. It's ultra low light sensor technology empowers the viewer to see in full color down to 2 milllilux or near moonless starlight conditions";
		model = "AB-SiOnyx-Aurora\Aurora\HMDAurora2.p3d";
		inventorySlot[] = {"NVG"};
		itemSize[] = {3, 3};
		weight = 600;
		AuroraOptic = 1;
		repairCosts[] = {100.0};
	};
	class HMDAurora : NVGoggles
	{
		scope = 2;
		displayName = "Head mounted single SiOnyx Aurora";
		descriptionShort = "The SIONYX Aurora is a color digital night vision camera. It's ultra low light sensor technology empowers the viewer to see in full color down to 2 milllilux or near moonless starlight conditions";
		model = "AB-SiOnyx-Aurora\Aurora\HMDAurora.p3d";
		inventorySlot[] = {"NVG"};
		itemSize[] = {3, 3};
		weight = 400;
		AuroraOptic = 1;
		repairCosts[] = {50.0};
	};
	class RISCameraAdapter : BUISOptic
	{
		displayName = "RIS Camera Adapter";
		model = "AB-SiOnyx-Aurora\Aurora\RIS.p3d";
		attachments[] = {};
		descriptionShort = "An adapter to mount standard cameras that uses the 1/4 screw to RIS rails";
		inventorySlot[] = {"weaponOpticsHunting", "weaponOptics", "sniperOptics"};
		weight = 90;
	};
	class RhinoMount : NVGoggles
	{
		displayName = "Rhino Mount";
		desctriptionShort = "A NVG mount";
		model = "AB-SiOnyx-Aurora\Aurora\rhino.p3d";
		attachments[] = {};
		itemSize[] = {2, 1};
		animClass = "Knife";
		simulation = "ItemSuppressor";
		NVOptic = 0;
		AuroraOptic = 0;
		weight = 150;
	};
	class PreloadAurora : Inventory_Base
	{
		scope = 0;
		model = "AB-SiOnyx-Aurora\Aurora\hud.p3d";
	};
};
class CfgMods
{
	class Aurora
	{
		dir = "Aurora";
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