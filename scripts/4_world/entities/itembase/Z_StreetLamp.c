class Z_StreetLamp extends Inventory_Base
{
	Object _Parent;
	vector LocalPos;
	vector LocalOri;
	bool electricity = false;
	
	void AttachOnMemPoint(Object parent, string memory_point_start, string memory_point_target = "")
	{
		if(memory_point_start != "")
		{
			LocalPos = parent.GetMemoryPointPos(memory_point_start) + "0 -0.23 0";
			vector local_ori;
			if(memory_point_target != "")
			{
				vector target_pos = parent.GetSelectionPositionLS(memory_point_target);
				target_pos = vector.Direction(LocalPos, target_pos);
				local_ori = target_pos.VectorToAngles();
			}
			AttachOnObject(parent,LocalPos,local_ori);
		}else{
			Print("[ES] Not valid memory point found for lamp attachment");
		}
	}
	void AttachOnObject(Object parent, vector local_pos = "0 0 0", vector local_ori = "0 0 0")
	{
		if(!parent)
		{
			if(_Parent)
			{
				_Parent.RemoveChild(this);
			}
			return;
		}else{
			if(_Parent)
			{
				_Parent.RemoveChild(this);
			}
		};
		
		_Parent = parent;
		LocalPos = local_pos;
		LocalOri = local_ori;
		SetOrientation(local_ori);
		SetPosition(local_pos);
		parent.AddChild(this, -1);
		parent.Update();
	}
	void setElectricity(bool state)
	{
		this.electricity = state;
        if(state)
        {
            this.turnOn();
        }else{
            this.turnOff();
        }
	}
	bool hasElectricity()
	{
		return this.electricity;
	}
	void turnOn()
	{
		SetPilotLight(true);
		SetIsHologram(true);
	}
	void turnOff()
	{
		SetPilotLight(false);
		SetIsHologram(false);
	}
	
	void Z_Lamp()
	{
	}
	
	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		turnOff();
		this.Delete();
	}
	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		if(GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			Particle.Play(ParticleList.IMPACT_METAL_RICOCHET, this.GetPosition() + Vector(0, -0.5, 0)).SetOrientation("0.0 180.0 0.0");
			Particle.Play(ParticleList.IMPACT_GLASS_EXIT, this.GetPosition() + Vector(0, -0.5, 0)).SetOrientation("0.0 180.0 0.0");
			SEffectManager.PlaySound("offroad_hit_window_small_SoundSet", this.GetPosition());
		}
	}
}