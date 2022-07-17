// AI_Robot.cpp: implementation of the CAI_Robot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Short_Mouse.h"
#include "AI_Robot.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

int iMap_Array[12][12] = {1,1,1,1,1,1,1,1,1,1,1,1,
 					      1,0,0,0,1,1,0,0,0,0,3,1,
						  1,0,0,0,0,0,0,0,0,0,0,1,
						  1,0,0,0,0,0,0,1,0,0,0,1,
						  1,1,0,0,1,1,1,1,1,0,0,1,
						  1,0,0,0,0,0,1,0,1,0,0,1,
						  1,0,0,1,0,0,1,0,0,0,0,1,
						  1,0,0,1,0,0,1,0,0,0,0,1,
						  1,0,0,1,0,0,1,0,0,0,0,1,
						  1,0,1,1,0,0,0,1,1,1,0,1,
						  1,4,0,0,1,0,0,0,0,1,0,1,
						  1,1,1,1,1,1,1,1,1,1,1,1};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// CAI_Robot
//##ModelId=40DB3A5F006B
CAI_Robot::CAI_Robot()
{
	m_Position.x_pos = 1;
	m_Position.y_pos = 10;
	move_count = 0;
	
	_state = CAI_upway::Instance();
	//return new CAI_Robot;
}

//##ModelId=40DB3A5F006C
CAI_Robot::~CAI_Robot()
{
	_Instance = NULL;
}

//##ModelId=40DB3A5F0060
CAI_Robot* CAI_Robot::Instance()
{
	/*
	if(_Instance == NULL)
	{
		_Instance = new CAI_Robot;
	}
	return _Instance;
	*/
	return new CAI_Robot;
}

//##ModelId=40DB3A5F0089
void CAI_Robot::ChangeState(CAI_State* s)
{
	_state = s;
}
//////////////////////////////////////////////////////////////////////
// CAI_State
//void CAI_State::Back(CAI_Robot*){}
//##ModelId=40DB3A5F00EC
void CAI_State::Move(CAI_Robot*){}
//##ModelId=40DB3A5F00F8
void CAI_State::Scan_condition(CAI_Robot*){}
//##ModelId=40DB3A5F010C
void CAI_State::Set_course(CAI_Robot*){}

//##ModelId=40DB3A5F0115
void CAI_State::ChangeState(CAI_Robot* r, CAI_State* s)
{
	r->ChangeState(s);
}

//////////////////////////////////////////////////////////////////////
// CAI_rightway
//##ModelId=40DB3A5F0134
CAI_State* CAI_rightway::Instance()
{
	return new CAI_rightway;
}

//##ModelId=40DB3A5F013E
void CAI_rightway::Move(CAI_Robot* r)
{
	// ·Îº¿ÀÇ ÁÂÇ¥ ÀÌµ¿.
	//r->m_Robotstate = Scan_condition(r);
	
	r->m_Position.x_pos = r->m_Position.x_pos+1;
}

//##ModelId=40DB3A5F0147
void CAI_rightway::Scan_condition(CAI_Robot* r)
{
	unsigned int temp_x = r->m_Position.x_pos;
	unsigned int temp_y = r->m_Position.y_pos;

	if((iMap_Array[temp_x+1][temp_y]==1) && (iMap_Array[temp_x][temp_y+1]==0))
	{
		ChangeState(r, CAI_downway::Instance());
	}
	else if((iMap_Array[temp_x+1][temp_y]==1) && (iMap_Array[temp_x][temp_y+1]==1))
	{
		ChangeState(r, CAI_upway::Instance());
	}

	else if((iMap_Array[temp_x+1][temp_y]==1) && (iMap_Array[temp_x][temp_y+1]==1))
	{
		ChangeState(r, CAI_Crash::Instance());
	}
}

//////////////////////////////////////////////////////////////////////
// CAI_leftway
//##ModelId=40DB3A5F0165
CAI_State* CAI_leftway::Instance()
{
	
	return new CAI_leftway;

}

//##ModelId=40DB3A5F0167
void CAI_leftway::Move(CAI_Robot* r)
{
	r->m_Position.x_pos = r->m_Position.x_pos-1;
}

//##ModelId=40DB3A5F0171
void CAI_leftway::Scan_condition(CAI_Robot* r)
{
	unsigned int temp_x = r->m_Position.x_pos;
	unsigned int temp_y = r->m_Position.y_pos;

	if((iMap_Array[temp_x-1][temp_y]==1) && (iMap_Array[temp_x][temp_y-1]==0))
	{
		ChangeState(r, CAI_upway::Instance());
	}
	else if((iMap_Array[temp_x-1][temp_y]==1) && (iMap_Array[temp_x][temp_y-1]==1))
	{
		ChangeState(r, CAI_downway::Instance());
	}
	else if((iMap_Array[temp_x-1][temp_y]==1) && (iMap_Array[temp_x][temp_y-1]==1))
	{
		ChangeState(r, CAI_Crash::Instance());
	}
}

//////////////////////////////////////////////////////////////////////
// CAI_upway
//##ModelId=40DB3A5F018E
CAI_State* CAI_upway::Instance()
{
	return new CAI_upway;
}

//##ModelId=40DB3A5F0197
void CAI_upway::Move(CAI_Robot* r)
{
	r->m_Position.y_pos = r->m_Position.y_pos-1;
}

//##ModelId=40DB3A5F019A
void CAI_upway::Scan_condition(CAI_Robot* r)
{
	unsigned int temp_x = r->m_Position.x_pos;
	unsigned int temp_y = r->m_Position.y_pos;
	
	if((iMap_Array[temp_x][temp_y-1]==1) && (iMap_Array[temp_x+1][temp_y]==0))
	{
		ChangeState(r, CAI_rightway::Instance());
	}
	else if((iMap_Array[temp_x][temp_y-1]==1) && (iMap_Array[temp_x+1][temp_y]==1))
	{
		ChangeState(r, CAI_leftway::Instance());
	}
	else if((iMap_Array[temp_x][temp_y-1]==1) && (iMap_Array[temp_x+1][temp_y]==1))
	{
		ChangeState(r, CAI_Crash::Instance());
	}
}

//////////////////////////////////////////////////////////////////////
// CAI_downway
//##ModelId=40DB3A5F01B6
CAI_State* CAI_downway::Instance()
{
	return new CAI_downway;
}

//##ModelId=40DB3A5F01C0
void CAI_downway::Move(CAI_Robot* r)
{
	r->m_Position.y_pos = r->m_Position.y_pos+1;
}

//##ModelId=40DB3A5F01C9
void CAI_downway::Scan_condition(CAI_Robot* r)
{
	// ·Îº¿ÀÇ ÇöÀç »óÅÂ È®ÀÎ.
	unsigned int temp_x = r->m_Position.x_pos;
	unsigned int temp_y = r->m_Position.y_pos;
	
	
	if((iMap_Array[temp_x][temp_y+1]==1) && (iMap_Array[temp_x-1][temp_y]==0) && (iMap_Array[temp_x+1][temp_y]==0))
	{
		ChangeState(r, CAI_leftway::Instance());
	}
	else if((iMap_Array[temp_x][temp_y+1]==1) && (iMap_Array[temp_x-1][temp_y]==1) && (iMap_Array[temp_x+1][temp_y]==0))
	{
		ChangeState(r, CAI_rightway::Instance());

	}
	else if((iMap_Array[temp_x][temp_y+1]==1) && (iMap_Array[temp_x-1][temp_y]==1) && (iMap_Array[temp_x+1][temp_y]==1))
	{
		ChangeState(r, CAI_Crash::Instance());

	}
}

//////////////////////////////////////////////////////////////////////
// CAI_Crash
//##ModelId=40DB3A5F01E7
CAI_State* CAI_Crash::Instance()
{
	return new CAI_Crash;
}

//##ModelId=40DB3A5F01E9
void CAI_Crash::Move(CAI_Robot* r)
{

	int temp_x = r->m_Position.x_pos;
	int temp_y = r->m_Position.y_pos;

	//À§¾Æ·¡·Î ¸·ÇûÀ»¶§
	if(iMap_Array[temp_x][temp_y+1] == 1)
	{
		// ÁÂÇ¥ À§·Î.
		while((iMap_Array[temp_x-1][temp_y]==1) && (iMap_Array[temp_x+1][temp_y]==1))
		{
			--temp_y;
		}
		r->m_Position.x_pos = temp_x;
		r->m_Position.y_pos = temp_y;
		
		ChangeState(r, CAI_upway::Instance());
	}

	if(iMap_Array[temp_x][temp_y-1] == 1)
	{
		// ÁÂÇ¥ ¾Æ·¡·Î.
		while((iMap_Array[temp_x-1][temp_y]==1) && (iMap_Array[temp_x+1][temp_y]==1))
		{
			++temp_y;
		}
		r->m_Position.x_pos = temp_x;
		r->m_Position.y_pos = temp_y;
		ChangeState(r, CAI_downway::Instance());
	}
	
	// ÁÂ¿ì·Î ¸·ÇûÀ» ¶§
	// ¿ì°¡ ¸·È÷¸é
	if(iMap_Array[temp_x+1][temp_y] == 1)
	{
		// ÁÂÇ¥ ÁÂ·Î.
		while((iMap_Array[temp_x][temp_y-1]==1) && (iMap_Array[temp_x][temp_y+1]==1))
		{
			--temp_x;
		}
		r->m_Position.x_pos = temp_x;
		r->m_Position.y_pos = temp_y;
		
		ChangeState(r, CAI_leftway::Instance());
	}
	// ÁÂ°¡ ¸·È÷¸é
	if(iMap_Array[temp_x-1][temp_y] == 1)
	{
		// ÁÂÇ¥ ¿ì·Î.
		while((iMap_Array[temp_x][temp_y-1]==1) && (iMap_Array[temp_x][temp_y+1]==1))
		{
			++temp_x;
		}
		r->m_Position.x_pos = temp_x;
		r->m_Position.y_pos = temp_y;
		
		ChangeState(r, CAI_rightway::Instance());
	}
}

//##ModelId=40DB3A5F01F2
void CAI_Crash::Scan_condition(CAI_Robot* r)
{
	
}
