class AuroraHUD{
	protected Widget			m_Root;
	
    protected TextWidget		m_Clock;
	protected TextWidget		m_Time;
	protected TextWidget		m_EV;
	protected TextWidget		m_Coord0;
	protected TextWidget		m_Coord1;
	protected TextWidget		m_HDG;
	protected TextWidget		m_HDGICO;
	protected TextWidget		m_DInfo1;
	protected TextWidget		m_DInfo2;
	protected ImageWidget		m_Needle;
	
	protected ImageWidget		m_Crosshair;
	protected ImageWidget		m_Roll;
	protected ImageWidget		m_Pitch;
	
	protected World				world;
	protected PoweredOptic_Base	parent;
	protected PlayerBase 		Player;
	protected int				Updates;
	protected int				LazyUpdates;


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
		m_Time = TextWidget.Cast(m_Root.FindWidget("Time"));
		m_DInfo1 = TextWidget.Cast(m_Root.FindWidget("DInfo1"));
		m_DInfo2 = TextWidget.Cast(m_Root.FindWidget("DInfo2"));
		m_EV = TextWidget.Cast(m_Root.FindWidget("EV"));
		m_Needle = ImageWidget.Cast(m_Root.FindWidget("Needle"));
		
		m_Crosshair = ImageWidget.Cast(m_Root.FindWidget("Crosshair"));
		m_Roll = ImageWidget.Cast(m_Crosshair.FindWidget("Roll"));
		m_Pitch = ImageWidget.Cast(m_Crosshair.FindWidget("Pitch"));

		m_Coord0.SetText("- - - N");
		m_Coord1.SetText("- - - W");

		world = GetGame().GetWorld();
		Updates = 0;
		LazyUpdates = 100; // every 10 seconds;
		LazyUpdate();
	}

	void Stop(){
		delete 		m_Root;
	}

	void Update(){
		if(m_Root){			
			//Battery
			//Print(parent.GetCompEM().GetEnergyLevel());


			//Pitch, Yaw, Roll
			vector angles = parent.GetOrientation();
			m_HDG.SetText(AngleToCardinal(angles[0]));
			
			//Update m_Roll
			float angle = angles[1];
			angle = Math.Clamp(angle, -49.5, 49.5);
			m_Roll.SetRotation(0,0,angle);
			
			//Update m_Pitch
			float px, py;
			m_Pitch.GetPos(px,py);
			float Pitch;
			
			if(RISAurora.Cast(parent)){
				Print("Parent is RISAurora");
				Pitch = angles[2] + 90.0;
			}
			else
			{
				Pitch = (angles[2] - 90.0) * -1.0;
			}
			
			Pitch = Math.Clamp(Pitch, -50, 50);
			float pitchPercent = Pitch * 2;
			float finalPitch = (0.1725/100) * pitchPercent;
			m_Pitch.SetPos(0.425,finalPitch,true);
			
			if(Updates >= LazyUpdates){
				LazyUpdate();
				Updates = 0;
			}
			
			Updates++;
		}
	}
	
	void LazyUpdate(){
			//Clocks
			int year, month, day, hour, minute;
			GetGame().GetWorld().GetDate( year, month, day, hour, minute );
			m_Clock.SetText(hour.ToString()+":"+minute.ToString());
			int rhour, rminute, rsecond;
			GetHourMinuteSecond(rhour,rminute,rsecond);
			
			string shour = rhour.ToString();
			string sminute = rminute.ToString();
			
			if(shour.Length() == 1) shour = "0" + shour;
			if(sminute.Length() == 1) sminute = "0" + sminute;
			
			m_Time.SetText(shour+ ":" + sminute);

			//Exposure
			//m_EV.SetText("+6");
			
			
			//Coordinates
			float Long, Lat;
			Long = world.GetLongitude();
			Lat = world.GetLatitude();
			
			vector pos = GetGame().GetPlayer().GetPosition();
			
			Long = Long + 30.00;
			Lat = 56.00 - Lat;
			
			float XDD = MeterToDD(pos[2]);
			float YDD = MeterToDD(pos[0],Long);
			m_Coord0.SetText(DDtoDMS(Long + XDD) + "N");
			m_Coord1.SetText(DDtoDMS(Lat + YDD) + "E");
		
			// FPS info
			string fps;
			fps = ((int)(0.1/GetGame().GetFps())).ToString() + "0 FPS";
			m_DInfo1.SetText(fps);
			
			//Screen Size
			int x,y;
			GetScreenSize(x,y);
			m_DInfo2.SetText(x.ToString() + "P");
	}
	
	string DDtoDMS(float DD){
		int d = (int)DD;
		int  m = (int)((DD-d)*60);
		float s = (DD-d-((float)(m)/60))*3600;
		return d.ToString() + "° " + m.ToString()+ "' " + s.ToString().Substring(0,5) + "\" ";
	}
	
	float MeterToDD(float distance, float long = 0, float EarthCircumference = 40075){
		float DegDistAtEqu = EarthCircumference / 360;
		float rads = DegToRad(long);
		float cos = Math.Cos(rads);
		float DegDistAtLong = DegDistAtEqu * cos;
		float DD = distance / 1000 / DegDistAtLong;
		return DD;
	}
	
	float DegToRad(float degrees){
		return degrees * (3.14159 / 180);
	}
	
	void UpdateNeedle(float direction){
		m_Needle.SetRotation(0,0,direction,true);
	}
	
	void UpdateRoll(float angle){
		
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