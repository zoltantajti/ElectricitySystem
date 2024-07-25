class ActionSwitchToOn: ActionInteractBase
{
    void ActionSwitchToOn()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_Text = "Turn ON";
    }
    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item)
    {
        Z_Switch zs = Z_Switch.Cast(target.GetObject());
        if(zs)
        {
            if(!zs.getState())
            {
                return true;
            };
        };
        return false;
    }
    override void OnExecuteServer(ActionData action_data)
    {
        Object targetObject = action_data.m_Target.GetObject();
		if (targetObject)
		{
            Z_Switch zs = Z_Switch.Cast(targetObject);
            zs.setState(true);
		}
    }
    override void OnExecuteClient(ActionData action_data)
    {
        Object targetObject = action_data.m_Target.GetObject();
		if (targetObject)
		{
            Z_Switch zs = Z_Switch.Cast(targetObject);
            zs.setState(true);
		}
    }
}