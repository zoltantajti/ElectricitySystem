class ActionSwitchToOff: ActionInteractBase
{
    void ActionSwitchToOff()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_Text = "Turn OFF";
    }
    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        Z_Switch zs = Z_Switch.Cast(target.GetObject());
        if(zs)
        {
            if(zs.getState())
            {
                return true;
            };
        }else{
            Print("[ESSWITCH] HIBA VAN!!!")
        }
        return false;
    }
    override void OnExecuteServer(ActionData action_data)
    {
        Object targetObject = action_data.m_Target.GetObject();
		if (targetObject)
		{
            Z_Switch zs = Z_Switch.Cast(targetObject);
            zs.setState(false);
		}
    }
}