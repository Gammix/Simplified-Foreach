//Simplified foreach - By Gammix
//foreachc.inc

#if ! defined FOREACH_MAX_ENTRIES
	#define FOREACH_MAX_ENTRIES (2024)
#endif

#define Foreach(%1,%2) for (new %1, _%1 = t_ForeachSize[%2]; %1 < _%1; %1++)

new
	t_Foreach[ForeachType][FOREACH_MAX_ENTRIES],
	t_ForeachSize[ForeachType]
;

stock Foreach_Add(add, ForeachType:type)
{
	t_Foreach[type][t_ForeachSize[type]++] = add;
}

stock Foreach_Remove(value, ForeachType:type)
{
	new
	    bool:down
	;
	for (new i; i < t_ForeachSize[type]; i++)
	{
	    if (! down)
	    {
			if (t_Foreach[type][i] == value)
			{
			    down = true;
			    
			    continue;
			}
		}
		else
		{
		    t_Foreach[type][i - 1] = t_Foreach[type][i];
		}
	}
	t_ForeachSize[type]--;
}

stock Foreach_GetSize(ForeachType:type)
{
	return t_ForeachSize[type];
}

stock Foreach_GetValue(index, ForeachType:type)
{
	return t_Foreach[type][index];
}

stock Foreach_GetIndex(value, ForeachType:type)
{
	for (new i; i < t_ForeachSize[type]; i++)
	{
	    if (t_Foreach[type][i] == value)
	    {
	        return i;
	    }
	}
	
	return -1;
}
