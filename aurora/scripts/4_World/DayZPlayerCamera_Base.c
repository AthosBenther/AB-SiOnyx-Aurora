modded class DayZPlayerCameraBase extends DayZPlayerCamera
{
	bool IsCameraSingleAurora()
	{
		Entity playerEnt = GetGame().GetPlayer();
		PlayerBase Player = (PlayerBase)playerEnt;
		HMDAurora aurora;

		if (Player.FindAttachmentBySlotName("Eyewear"))
		{
			aurora = HMDAurora.Cast(Player.FindAttachmentBySlotName("Eyewear").FindAttachmentBySlotName("NVG"));
			if(aurora) return true;
		}
		else if (Player.FindAttachmentBySlotName("Headgear"))
		{
			aurora = HMDAurora.Cast(Player.FindAttachmentBySlotName("Headgear").FindAttachmentBySlotName("NVG"));
			if(aurora) return true;

		}
		else if (Player.FindAttachmentBySlotName("Hands"))
		{
			aurora = HMDAurora.Cast(Player.FindAttachmentBySlotName("Hands"));
			if(aurora) return true;
		}
		return false;
	}

	bool IsCameraDualAurora()
	{
		Entity playerEnt = GetGame().GetPlayer();
		PlayerBase Player = (PlayerBase)playerEnt;
		HMDAurora2 aurora;

		if (Player.FindAttachmentBySlotName("Eyewear"))
		{
			aurora = HMDAurora2.Cast(Player.FindAttachmentBySlotName("Eyewear").FindAttachmentBySlotName("NVG"));
			if(aurora) return true;
		}
		else if (Player.FindAttachmentBySlotName("Headgear"))
		{
			aurora = HMDAurora2.Cast(Player.FindAttachmentBySlotName("Headgear").FindAttachmentBySlotName("NVG"));
			if(aurora) return true;
		}
		else if (Player.FindAttachmentBySlotName("Hands"))
		{
			aurora = HMDAurora2.Cast(Player.FindAttachmentBySlotName("Hands"));
			if(aurora) return true;
		}
		return false;
	}

	bool IsEntityAurora(EntityAI optics){
		HMDAurora hmdaurora = HMDAurora.Cast(optics);
		HMDAurora2 hmdaurora2 = HMDAurora2.Cast(optics);
		Aurora aurora = Aurora.Cast(optics);
		RISAurora risaurora = RISAurora.Cast(optics);
		if(hmdaurora || hmdaurora2 || aurora || risaurora){
			return true;
		}
		return false;
	}

	//! by default sets camera PP to zero, regardless of parameter. Override if needed.
	override void SetCameraPP(bool state, DayZPlayerCamera launchedFrom)
	{
		PPEffects.ResetPPMask();
		PPEffects.SetLensEffect(0, 0, 0, 0);
		PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
		PPEffects.SetBlurOptics(0);

		if(IsCameraNV()){
			if (IsCameraDualAurora())
			{
				SetNVPostprocess(99);
			}
			else if(IsCameraSingleAurora()){
				SetNVPostprocess(98);
			}
			else{
			SetNVPostprocess(NVTypes.NV_GOGGLES);
			}
		}
		else
		{
			SetNVPostprocess(NVTypes.NONE);
		}

		m_weaponUsed = Weapon_Base.Cast(m_pPlayer.GetHumanInventory().GetEntityInHands());
		if (m_weaponUsed)
		{
			m_weaponUsed.HideWeaponBarrel(false);
		}
	}

	override void SetNVPostprocess(int NVtype)
	{
		Print("+++Setting NV type: " + NVtype + " +++");
		switch (NVtype)
		{
		case NVTypes.NONE:
			PPEffects.SetEVValuePP(0);
			PPEffects.SetColorizationNV(1.0, 1.0, 1.0);
			PPEffects.SetNVParams(1.0, 0.0, 2.35, 2.75); //default values
			break;
		case NVTypes.NV_OPTICS_ON:
			PPEffects.SetEVValuePP(7);
			PPEffects.SetColorizationNV(0.0, 1.0, 0.0);
			PPEffects.SetNVParams(3.0, 2.0, 9.0, 1.0);
			break;
		case NVTypes.NV_OPTICS_OFF:
			PPEffects.SetEVValuePP(-10);
			PPEffects.SetColorizationNV(0.0, 0.0, 0.0);
			PPEffects.SetNVParams(1.0, 0.0, 2.35, 2.75); //default values
			break;
		case NVTypes.NV_GOGGLES:
			PPEffects.SetEVValuePP(7);
			PPEffects.SetColorizationNV(0.0, 1.0, 0.0);
			PPEffects.SetNVParams(2.0, 1.0, 10.0, 1.0);
			break;
		case 98:
			PPEffects.SetEVValuePP(3); // Single hmdaurora
			PPEffects.SetColorizationNV(1,0.5,1);
			PPEffects.SetNVParams(2.0, 1.0, 10.0, 1.0);
			break;
		case 99:
			PPEffects.SetEVValuePP(6); // Double hmdaurora
			PPEffects.SetColorizationNV(1,0.5,1);
			PPEffects.SetNVParams(2.0, 1.0, 10.0, 1.0);
			break;
		}

		if (PlayerBaseClient.Cast(m_pPlayer))
		{
			PlayerBaseClient.Cast(m_pPlayer).SwitchPersonalLight(NVtype < 1); //TODO
		}
	}
}
