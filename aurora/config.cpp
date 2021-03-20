class CfgPatches
{
    class Aurora
    {
        units[] = {'sionyx_aurora'};
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
    class Aurora : NVGoggles
    {

        scope = 2;
		displayName = "SiOnyx Aurora";
        descriptionShort = "The SIONYX Aurora is a color digital night vision camera. It's ultra low light sensor technology empowers the viewer to see in full color down to 2 milllilux or near moonless starlight conditions";
		model = "AB-SiOnyx-Aurora\aurora\aurora.p3d";
		simulation = "itemoptics";
		animClass = "Binoculars";
		inventorySlot[] = {"NVG","aurora"};
		itemSize[] = {3,3};
		weight = 1300;
		rotationFlags = 1;
		memoryPointCamera = "eyeScope";
		cameraDir = "cameraDir";
		class OpticsInfo
		{
			memoryPointCamera = "eyeScope";
			cameraDir = "cameraDir";
			modelOptics = "-";
			distanceZoomMin = 500;
			distanceZoomMax = 500;
			opticsZoomMin = 0.5236;
			opticsZoomMax = 0.5236;
			opticsZoomInit = 0.5236;
		};
		attachments[] = {"BatteryD"};
		NVOptic = 1;
		AuroraOptic = 1;
		simpleHiddenSelections[] = {"hide"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0},{0.7},{0.5},{0.3},{0.0}};
				};
			};
		};
		repairableWithKits[] = {7};
		repairCosts[] = {50.0};
		class EnergyManager
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.015;
			plugType = 1;
			attachmentAction = 1;
		};
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
    class Aurora_black : Aurora
    {
        displayName = "SiOnyx Aurora Black";
    };
    class Aurora_sport : Aurora
    {
        displayName = "SiOnyx Aurora Sport";
    };
    class Rhino : NVGoggles
    {

        scope = 2;
		displayName = "Rhino Mount";
        descriptionShort = "Rhino Mount to attach head mounted displays";
		model = "AB-SiOnyx-Aurora\aurora\rhino.p3d";
		simulation = "itemoptics";
		animClass = "Binoculars";
		inventorySlot[] = {"NVG"};
		itemSize[] = {2,3};
		weight = 300;
		rotationFlags = 1;
		class OpticsInfo
		{
			memoryPointCamera = "eyeScope";
			cameraDir = "cameraDir";
			modelOptics = "-";
			distanceZoomMin = 500;
			distanceZoomMax = 500;
			opticsZoomMin = 0.5236;
			opticsZoomMax = 0.5236;
			opticsZoomInit = 0.5236;
		};
		attachments[] = {"HMD","HMD"};
		simpleHiddenSelections[] = {"hide"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0},{0.7},{0.5},{0.3},{0.0}};
				};
			};
		};
		repairableWithKits[] = {7};
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

class CfgNonAIVehicles
{

	class ProxyAttachment;
	class Aurora_proxy: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "aurora";
		model="AB-SiOnyx-Aurora\aurora\aurora.p3d";
	};
	class ProxyAurora: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"NVG"};
		model = "AB-SiOnyx-Aurora\aurora\aurora.p3d";
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