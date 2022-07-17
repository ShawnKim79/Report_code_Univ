// AI_Robot.h: interface for the CAI_Robot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AI_ROBOT_H__1B133B5D_D8AC_4127_839D_9B6545836B6A__INCLUDED_)
#define AFX_AI_ROBOT_H__1B133B5D_D8AC_4127_839D_9B6545836B6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//##ModelId=40DB3A5F002F
struct pos{
	//##ModelId=40DB3A5F0039
	unsigned int x_pos;
	//##ModelId=40DB3A5F0042
	unsigned int y_pos;
};

//////////////////////////////////////////////////////////////////////
//##ModelId=40DB3A5F0056
class CAI_Robot  
{
public:
	//##ModelId=40DB3A5F0060
	static CAI_Robot* Instance();

protected:
	//##ModelId=40DB3A5F006B
	CAI_Robot();
	//##ModelId=40DB3A5F006C
	virtual ~CAI_Robot();

	//##ModelId=40DB3A5F0075
	void Move();
	//void Back();
	//##ModelId=40DB3A5F007E
	void Scan_condition();
	//##ModelId=40DB3A5F0088
	void Set_course();

private:
	friend class CAI_State;
	//##ModelId=40DB3A5F0089
	void ChangeState(CAI_State*);

public:
	//##ModelId=40DB3A5F0094
	CAI_State* _state;
	
public:
	//##ModelId=40DB3A5F00A0
	CAI_Robot* _Instance;

public:
	// 로봇의 좌표와 이동 경로 정보.
	//##ModelId=40DB3A5F00B1
	pos m_Position;
	//##ModelId=40DB3A5F00BB
	pos m_PosArray[100];
	//##ModelId=40DB3A5F00C4
	int m_Robotstate;
	//##ModelId=40DB3A5F00CE
	int move_count;
};

//////////////////////////////////////////////////////////////////////
//##ModelId=40DB3A5F00E2
class CAI_State
{
public:
	//##ModelId=40DB3A5F00EC
	virtual void Move(CAI_Robot*);
	//virtual void Back(CAI_Robot*);
	//##ModelId=40DB3A5F00F8
	virtual void Scan_condition(CAI_Robot*);
	//##ModelId=40DB3A5F010C
	virtual void Set_course(CAI_Robot*);

protected:
	//##ModelId=40DB3A5F0115
	void ChangeState(CAI_Robot*, CAI_State*);
};

//////////////////////////////////////////////////////////////////////
//##ModelId=40DB3A5F0129
class CAI_rightway:public CAI_State
{
public:
	//##ModelId=40DB3A5F0134
	static CAI_State* Instance();

	//##ModelId=40DB3A5F013E
	virtual void Move(CAI_Robot*);
	//##ModelId=40DB3A5F0147
	virtual void Scan_condition(CAI_Robot*);
};

//////////////////////////////////////////////////////////////////////
//##ModelId=40DB3A5F0151
class CAI_leftway:public CAI_State
{
public:
	//##ModelId=40DB3A5F0165
	static CAI_State* Instance();

	//##ModelId=40DB3A5F0167
	virtual void Move(CAI_Robot*);
	//##ModelId=40DB3A5F0171
	virtual void Scan_condition(CAI_Robot*);
};

//////////////////////////////////////////////////////////////////////
//##ModelId=40DB3A5F0183
class CAI_upway:public CAI_State
{
public:
	//##ModelId=40DB3A5F018E
	static CAI_State* Instance();

	//##ModelId=40DB3A5F0197
	virtual void Move(CAI_Robot*);
	//##ModelId=40DB3A5F019A
	virtual void Scan_condition(CAI_Robot*);
};

//////////////////////////////////////////////////////////////////////
//##ModelId=40DB3A5F01AB
class CAI_downway:public CAI_State
{
public:
	//##ModelId=40DB3A5F01B6
	static CAI_State* Instance();

	//##ModelId=40DB3A5F01C0
	virtual void Move(CAI_Robot*);
	//##ModelId=40DB3A5F01C9
	virtual void Scan_condition(CAI_Robot*);
};

//////////////////////////////////////////////////////////////////////
//##ModelId=40DB3A5F01D3
class CAI_Crash:public CAI_State
{
public:
	//##ModelId=40DB3A5F01E7
	static CAI_State* Instance();
	
	//##ModelId=40DB3A5F01E9
	virtual void Move(CAI_Robot*);
	//##ModelId=40DB3A5F01F2
	virtual void Scan_condition(CAI_Robot*);
};

#endif // !defined(AFX_AI_ROBOT_H__1B133B5D_D8AC_4127_839D_9B6545836B6A__INCLUDED_)
