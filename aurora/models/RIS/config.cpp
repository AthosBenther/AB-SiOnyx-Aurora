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
	class BUISOptic;
	class RISCameraAdapter : BUISOptic
	{
		displayName = "RIS Camera Adapter";
		model = "AB-SiOnyx-Aurora\Aurora\Models\RIS\RIS.p3d";
		attachments[] = {};
		descriptionShort = "An adapter to mount standard cameras that uses the 1/4 screw to RIS rails";
		inventorySlot[] = {"weaponOpticsHunting", "weaponOptics", "sniperOptics"};
		weight = 90;
	};
};
