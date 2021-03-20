modded class DayZPlayerCameraOptics : DayZPlayerCameraIronsights
{	
	override void SetCameraPP(bool state,DayZPlayerCamera launchedFrom)
	{
		//Print("SetCameraPP - optics");
		if (!state || !m_opticsUsed || (PlayerBase.Cast(m_pPlayer) && launchedFrom != PlayerBase.Cast(m_pPlayer).GetCurrentPlayerCamera()))
		{
			PPEffects.ResetPPMask();
			PPEffects.SetLensEffect(0, 0, 0, 0);
			PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
			PPEffects.SetBlurOptics(0);
			
		    if (IsCameraNV())
		    {
		    	if (IsEntityAurora(m_opticsUsed))
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
			
			if (m_weaponUsed)
			{
				m_weaponUsed.HideWeaponBarrel(false);
			}
		}
		else
		{
			PPEffects.ResetPPMask();
			
			// 1x scopes only
			if (m_opticsUsed.AllowsDOF() && !NVGoggles.Cast(m_opticsUsed))
			{
				PPEffects.SetLensEffect(0, 0, 0, 0);
				if (m_weaponUsed)
				{
					if (m_opticsUsed.GetOpticsDOF().Count() == 6)
					{
						temp_array = m_opticsUsed.GetOpticsDOF();
					}
					else
					{
						temp_array = m_weaponUsed.GetWeaponDOF(); //TODO should some optics have own DOF settings (different eye point)?
					}
					
					if (temp_array.Count() == 6)
					{
						PPEffects.OverrideDOF(temp_array[0],temp_array[1],temp_array[2],temp_array[3],temp_array[4],temp_array[5]);
					}
				}
				else
					PPEffects.OverrideDOF(false, 0, 0, 0, 0, 1);
				
				// optics NV mode
				if (m_opticsUsed.IsNVOptic())
				{
					if (m_opticsUsed.IsWorking())
					{
						SetCameraNV(true);
						if(IsEntityAurora(m_opticsUsed)) SetNVPostprocess(99);
                        else SetNVPostprocess(NVTypes.NV_OPTICS_ON);
					}
					else
					{
						SetCameraNV(false);
						SetNVPostprocess(NVTypes.NV_OPTICS_OFF);
					}
				}
				else
				{
					if (IsCameraNV())
					{
						if (IsEntityAurora(m_opticsUsed))
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
				}
			}
			else //magnifying scopes
			{
				// optics mask
				if (m_opticsUsed.GetOpticsPPMask() && m_opticsUsed.GetOpticsPPMask().Count() == 4)
				{
					temp_array = m_opticsUsed.GetOpticsPPMask();
					
					PPEffects.AddPPMask(temp_array[0], temp_array[1], temp_array[2], temp_array[3]);
					//PPEffects.AddPPMask(0.5, 0.5, 0.4, 0.05);
				}
				
				//optics lens
				if (m_opticsUsed.GetOpticsPPLens() && m_opticsUsed.GetOpticsPPLens().Count() == 4)
				{
					temp_array = m_opticsUsed.GetOpticsPPLens();
					
					PPEffects.SetLensEffect(temp_array[0], temp_array[1], temp_array[2], temp_array[3]);
					//PPEffects.SetLensEffect(1, 0.15, 0, 0 );
				}
				else
				{
					PPEffects.SetLensEffect(0, 0, 0, 0);
				}
				
				//optics blur
				if (m_opticsUsed.GetOpticsPPBlur() != 0)
				{
					PPEffects.SetBlurOptics(m_opticsUsed.GetOpticsPPBlur());
				}
				else
					PPEffects.SetBlurOptics(0);
				
				// optics NV mode
				if (m_opticsUsed.IsNVOptic())
				{
                    
                    					
						if (m_opticsUsed.IsWorking())
						{
							SetCameraNV(true);
							if(IsEntityAurora(m_opticsUsed)) SetNVPostprocess(99);
                            else SetNVPostprocess(NVTypes.NV_OPTICS_ON);
						}
						else
						{
							SetCameraNV(false);
							SetNVPostprocess(NVTypes.NV_OPTICS_OFF);
						}
				}
				else
				{
					SetNVPostprocess(NVTypes.NONE);
				}
			}
			
			if (m_weaponUsed)
			{
				m_weaponUsed.HideWeaponBarrel(true);
			}
		}
	}	
	//different handling in optics; no NV outside designated NV scopes
	override void UpdateCameraNV(PlayerBase player)
	{
		if ( !m_opticsUsed || (m_opticsUsed && !m_opticsUsed.IsNVOptic()) )
		{
			if (m_opticsUsed && m_opticsUsed.AllowsDOF()) //1x scopes
			{
				super.UpdateCameraNV(player);
			}
			else if ( IsCameraNV() )
			{
				super.UpdateCameraNV(player);
				SetCameraNV(false);
			}
		}
	}
};
