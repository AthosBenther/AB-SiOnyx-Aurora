class HMDAurora2 extends NVGoggles
{

	void HMDAurora2()
	{
		RotateGoggles(true);
		m_WorkCheckTimer = new Timer;
	}

	override void RotateGoggles(bool state)
	{
		SetAnimationPhase("rotate",!state);
		Print(GetAnimationPhase("rotate"));
		m_IsLowered = !state;
		
		if (GetHierarchyRootPlayer())
		{
			PlayerBase.Cast(GetHierarchyRootPlayer()).SetNVGLowered(m_IsLowered);
		}
		
		if ( GetCompEM() )
		{
			if ( !state && GetCompEM().CanWork() )
				GetCompEM().SwitchOn();
			else
				GetCompEM().SwitchOff();
		}
	}
}