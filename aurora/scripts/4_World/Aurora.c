class Aurora extends NVGoggles{
	
	protected ref Timer 				m_Timer;
	protected ref AuroraHUD 			HUD;

	void Aurora(){}
	
	override void OnWorkStart()
	{
		if( GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			PlayerBase player_this = PlayerBase.Cast( GetGame().GetPlayer() );
			PlayerBase player_owner = PlayerBase.Cast( GetHierarchyRootPlayer() );
			
			if ( player_this == player_owner )
			{
				StartPeriodicMeasurement();
			}
		}
	}
	
	override void OnWorkStop()
	{
		HUD.Stop();

		if( GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			PlayerBase player_this = PlayerBase.Cast( GetGame().GetPlayer() );
			PlayerBase player_owner = PlayerBase.Cast( GetHierarchyRootPlayer() );
			
			if ( player_this == player_owner )
			{
				StopPeriodicMeasurement();
			}
		}
	}
	
	void StartPeriodicMeasurement()
	{
		if( !m_Timer )
		{
			m_Timer = new Timer( CALL_CATEGORY_GAMEPLAY );
		}

		if(!HUD)
		{
			HUD = new AuroraHUD(this);	
		}
			
		HUD.Start();
				
		m_Timer.Run( 0.1, HUD, "Update", null, true);
	}
	
	void StopPeriodicMeasurement()
	{
		if( m_Timer )
		{
			m_Timer.Stop();
		}
		
		if (HUD.IsWorking())
		{
			HUD.Stop();
		}
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		RemoveAction(ActionViewOptics);
		AddAction(ActionViewBinoculars);
	}
};