static Object ObjToObj(Object ParentObj, string ChildObjName, vector offset = "0.0 0.0 0.0")
{
	Object NewObj = GetGame().CreateObject(ChildObjName, vector.Zero);
	NewObj.SetPosition(NewObj.GetPosition() + offset);
	ParentObj.AddChild(NewObj, -1, false);
	NewObj.Update();
	return NewObj;
}
static Object SpawnObject(string type, vector pos, vector ori)
{
	auto obj = GetGame().CreateObject(type, vector.Zero);
	obj.SetPosition(pos);
	obj.SetOrientation(ori);
	obj.SetOrientation(obj.GetOrientation());
	obj.Update();
	return obj;
}
