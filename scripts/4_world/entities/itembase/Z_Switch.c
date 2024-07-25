class Z_Switch: Inventory_Base
{
    Z_InteriorLamp lamp;
    int index = -1;
    bool sw_state = false;

    void Z_Switch() 
    {
        Print("[SWITCH] Constructor()");
    }

    void initLamp(Z_InteriorLamp _lamp, int index)
    {
        this.lamp = _lamp;
        this.index = index;
        Print("[DEBUG] Init Lamp["+index+"]: " + this.lamp.ClassName()) 
    }
    override void EEInit()
    {
        super.EEInit();  
        this.setState(false);
    }
    override void EOnInit(IEntity other, int extra)
    {
        if(GetGame().IsServer())
        {
            SetSynchDirty();
        }
    }

    void setState(bool target)
    {
        this.sw_state = target;
        if(target)
        {
            this.DisplaySwitchOn();
            Print("[LIGHT:"+this.index+"] " + this.lamp.ToString());       
            if(this.lamp){ 
                Print("[DEBUG:"+this.index+"] " + this.lamp.ClassName()); 
                this.lamp.setSWState(true); 
            };
        }
        else
        {
            this.DisplaySwitchOff();
            if(this.lamp){ 
                Print("[DEBUG:"+this.index+"] " + this.lamp.ClassName()); 
                this.lamp.setSWState(false); 
            };
        }
    }
    bool getState()
    {
        return this.sw_state;
    }
    override void SetActions()
    {        
        AddAction(ActionSwitchToOn);
        AddAction(ActionSwitchToOff); 
    }
    void DisplaySwitchOn()
    {
        ShowSelection("switchOn");
        HideSelection("switchOff");
    }
    void DisplaySwitchOff()
    {
        ShowSelection("switchOff");
        HideSelection("switchOn");
    }
}