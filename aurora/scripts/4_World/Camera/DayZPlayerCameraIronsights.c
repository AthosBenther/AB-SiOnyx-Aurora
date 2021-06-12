
//! this is main camera class 
modded class DayZPlayerCameraIronsights extends DayZPlayerCameraBase
{
	// sets PP for ironsights and optics (override) cameras
	override void SetCameraPP(bool state, DayZPlayerCamera launchedFrom)
	{
		Print("SetCameraPP - ADS");
		if (!state || !m_weaponUsed || (PlayerBase.Cast(m_pPlayer) && launchedFrom != PlayerBase.Cast(m_pPlayer).GetCurrentPlayerCamera()))
		{
			PPEffects.ResetPPMask();
			PPEffects.SetLensEffect(0, 0, 0, 0);
			PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
			PPEffects.SetBlurOptics(0);
			

			if(IsCameraNV()){
				Print("Camera is NVG");
				if (IsCameraDualAurora())
				{
					SetNVPostprocess(99);
				}
				else if(IsCameraSingleAurora())
				{
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
		}
		else
		{
			PPEffects.ResetPPMask();
			//PPEffects.AddPPMask(0.5, 0.5, 0.3, 0.05);
			PPEffects.SetLensEffect(0, 0, 0, 0);
			if (m_weaponUsed.GetWeaponDOF() || (m_opticsUsed && m_opticsUsed.GetOpticsDOF()))
			{
				if (m_opticsUsed && m_opticsUsed.GetOpticsDOF().Count() == 6)
				{
					temp_array = m_opticsUsed.GetOpticsDOF();
				}
				else
				{
					temp_array = m_weaponUsed.GetWeaponDOF();
				}
				if (temp_array.Count() == 6)
					PPEffects.OverrideDOF(temp_array[0],temp_array[1],temp_array[2],temp_array[3],temp_array[4],temp_array[5]);
			}
			else
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
		}
		
		if (m_weaponUsed)
		{
			m_weaponUsed.HideWeaponBarrel(false);
		}
	}
}
