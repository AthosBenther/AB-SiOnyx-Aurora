modded class DayZPlayerCameraBase extends DayZPlayerCamera
{
	

	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		super.OnUpdate(pDt, pOutResult);
		StdFovUpdate(pDt, pOutResult);
		if(IsCameraAurora()){
			UpdateCameraAurora(PlayerBase.Cast(m_pPlayer));
		}
		else{
			UpdateCameraNV(PlayerBase.Cast(m_pPlayer));
		}
		InitCameraOnPlayer();
	}

	bool IsCameraAurora()
	{
		Entity playerEnt = GetGame().GetPlayer();
		PlayerBase Player = (PlayerBase)playerEnt;
		NVGoggles nvg;

		if (Player.FindAttachmentBySlotName("Eyewear"))
		{
			nvg = NVGoggles.Cast(Player.FindAttachmentBySlotName("Eyewear").FindAttachmentBySlotName("NVG"));
		}
		else if (Player.FindAttachmentBySlotName("Headgear"))
		{
			nvg = NVGoggles.Cast(Player.FindAttachmentBySlotName("Headgear").FindAttachmentBySlotName("NVG"));
		}

		return nvg.ConfigGetBool("AuroraOptic");
	}

	void SetCameraAurora(bool aurora)
	{
		m_IsAurora = aurora;
	}

	void UpdateCameraAurora(PlayerBase player)
	{
		if ( !player )
			return;
		
		if ( player.IsNVGWorking() != IsCameraAurora() )
		{
			SetCameraAurora(player.IsNVGWorking());
			SetCameraPP(true, this);
		}
	}

	//! by default sets camera PP to zero, regardless of parameter. Override if needed.
	override void SetCameraPP(bool state, DayZPlayerCamera launchedFrom)
	{
		PPEffects.ResetPPMask();
		PPEffects.SetLensEffect(0, 0, 0, 0);
		PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
		PPEffects.SetBlurOptics(0);

		if (IsCameraNV())
		{
			if (IsCameraAurora())
			{
				SetNVPostprocess(99);
			}
			else
			{
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

	void SetNVPostprocess(int NVtype)
	{
		//Print("+++Setting NV type: " + NVtype + " +++");
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
		case 99:
			PPEffects.SetEVValuePP(6);
			PPEffects.SetColorizationNV(1,0.5,1);
			PPEffects.SetNVParams(3.0, 2.0, 9.0, 1.0);
			break;
		}

		if (PlayerBaseClient.Cast(m_pPlayer))
		{
			PlayerBaseClient.Cast(m_pPlayer).SwitchPersonalLight(NVtype < 1); //TODO
		}
	}
	protected bool m_IsAurora;
}
