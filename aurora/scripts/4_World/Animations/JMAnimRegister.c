modded class JMAnimRegister
{
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
    	super.RegisterOneHanded(pType, pBehavior);
	
	    pType.AddItemInHandsProfileIK("AuroraCamera", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior, "dz/anims/anm/player/ik/attachments/optic/optic_longrange.anm");
	    pType.AddItemInHandsProfileIK("RISAurora", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior, "dz/anims/anm/player/ik/attachments/optic/optic_longrange.anm");
    }	
};