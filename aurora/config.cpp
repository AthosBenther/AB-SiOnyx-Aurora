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
    class Aurora : NVGoggles
    {

        scope = 2;
		displayName = "SiOnyx Aurora";
        descriptionShort = "The SIONYX Aurora is a color digital night vision camera. It's ultra low light sensor technology empowers the viewer to see in full color down to 2 milllilux or near moonless starlight conditions";
		model = "AB-SiOnyx-Aurora\aurora\aurora.p3d";
		inventorySlot[] = {"NVG","aurora"};
		itemSize[] = {3,3};
		weight = 1300;
		AuroraOptic = 1;
		repairCosts[] = {50.0};
    };
    class Aurora_Black : Aurora
    {
        displayName = "SiOnyx Aurora Black";
    };
    class Aurora_Sport : Aurora
    {
        displayName = "SiOnyx Aurora Sport";
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