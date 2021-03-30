class AuroraHUD{

    protected TextWidget		m_Clock;
	protected TextWidget		m_EV;
	protected TextWidget		m_Coord0;
	protected TextWidget		m_Coord1;
	protected TextWidget		m_HDG;
	protected TextWidget		m_HDGICO;
	protected TextWidget		m_DInfo1;
	protected TextWidget		m_DInfo2;
	protected ImageWidget		m_Needle;
	protected Widget			m_Root;
	protected World				world;
	protected PoweredOptic_Base	parent;
	protected PlayerBase 		Player;


	void AuroraHUD(PoweredOptic_Base Parent){
		parent = Parent;
		Player = PlayerBase.Cast( GetGame().GetPlayer() );
	}

	bool IsWorking(){
		if(m_Root)
		return true;
		return false;
	}

    void Start(){
		m_Root = Widget.Cast(GetGame().GetWorkspace().CreateWidgets("AB-SiOnyx-Aurora/aurora/gui/aurora_hud.layout"));
		m_Coord0 = TextWidget.Cast(m_Root.FindWidget("Coord0"));
		m_Coord1 = TextWidget.Cast(m_Root.FindWidget("Coord1"));
		m_HDG = TextWidget.Cast(m_Root.FindWidget("HDG"));
		m_HDGICO = TextWidget.Cast(m_Root.FindWidget("HDGICO"));
		m_Clock = TextWidget.Cast(m_Root.FindWidget("Clock"));
		m_DInfo1 = TextWidget.Cast(m_Root.FindWidget("DInfo1"));
		m_DInfo2 = TextWidget.Cast(m_Root.FindWidget("DInfo2"));
		m_EV = TextWidget.Cast(m_Root.FindWidget("EV"));
		m_Needle = ImageWidget.Cast(m_Root.FindWidget("Needle"));

		m_Coord0.SetText("- - - N");
		m_Coord1.SetText("- - - W");

		world = GetGame().GetWorld();
	}

	void Stop(){
		delete 		m_Root;
	}

	void Update(){
		if(m_Root){
			count = count + 1;
			
			int year, month, day, hour, minute;
			GetGame().GetWorld().GetDate( year, month, day, hour, minute );
			m_Clock.SetText(hour.ToString()+":"+minute.ToString());

			m_EV.SetText(world.GetEyeAccom().ToString());
			
			float Long, Lat;
			Long = world.GetLongitude();
			Lat = world.GetLatitude();
			vector pos = GetGame().GetPlayer().GetPosition();
			m_Coord0.SetText(pos[0].ToString());
			m_Coord1.SetText(pos[1].ToString());

			
			vector angles = parent.GetOrientation();
			
			
			Log("Angle: " + ((int)(angles[0]+0)).ToString());
			Log("Float: " + ((int)((angles[0] - 22.5)/45)).ToString());
			
			


			//UpdateNeedle(angles[0]);
			m_HDG.SetText(AngleToCardinal(angles[0]));
			
			string info = "alala";
			int x,y;
			GetScreenSize(x,y);
			
			info = ((int)(0.1/GetGame().GetFps())).ToString() + "0 FPS";
			
			m_DInfo1.SetText(info);
			m_DInfo2.SetText(x.ToString() + "P");
		}
	}
	
	void UpdateNeedle(float direction){
		m_Needle.SetRotation(0,0,direction,true);
	}

	string AngleToCardinal(float HDG){
		if(HDG == 0){
			UpdateNeedle(90);
			return "W";
		}
		
		float mod = 22.5;
		
		if(HDG < 0) mod = mod * -1;

		int hdg = (int)((HDG + mod)/45);

		switch(hdg){
			case -4:
				UpdateNeedle(90);
				return "W";
			case -3:
				UpdateNeedle(132);
				return "NW";
			case -2:
				UpdateNeedle(180);
				return "N";
			case -1:
				UpdateNeedle(-135);
				return "NE";
			case 0:
				UpdateNeedle(-90);
				return "E";
			case 1:
				UpdateNeedle(-45);
				return "SE";
			case 2:
				UpdateNeedle(0);
				return "S";
			case 3:
				UpdateNeedle(45);
				return "SW";
			case 4:
				UpdateNeedle(90);
				return "W";
			default:
				UpdateNeedle(HDG+90);
				return "OOR";

		}

		return "ERR";

	}
}