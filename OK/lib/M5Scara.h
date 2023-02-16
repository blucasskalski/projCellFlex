#if defined (_WIN32)

#ifndef WINAPI
	#define WINAPI __stdcall
#endif

#ifdef M5SCARA_EXPORTS
	#define M5SCARA_API __declspec(dllexport)
#else
	#define M5SCARA_API __declspec(dllimport)
#endif
#endif

#if !defined(AMTEC_M5SCARA)
#define AMTEC_M5SCARA

//Defines
//=================================================================
#define M5SCARA_RETURN_OK													0
#define M5SCARA_RETURN_POSITION_NOT_REACHABLE			-1
#define M5SCARA_RETURN_M5DLL_FUNCTION_FAILED			-2
#define M5SCARA_RETURN_TIMER_FAILED								-3
#define M5SCARA_RETURN_SCARA_NOT_READY						-4

#define M5SCARA_STATE_ERROR				0x00000001L
#define M5SCARA_STATE_HOMEOK			0x00000002L
#define M5SCARA_STATE_MOVE				0x00000004L
#define M5SCARA_STATE_MOVELINE		0x00000008L
#define M5SCARA_STATE_HALT				0x00000010L

//TODO
//defines Auslagen

//Structurs
//=================================================================
struct SCARA_POSITION
// Discribes a Position in kathesischen Coordinates
{
	float fX;
	float fY;
	float fZ;
	float fRX;
	float fRY;
	float fRZ;
};

struct SCARA_MOTIONDESCRIPTOR
// Discribes the form of the motion
{
	float fVel;
	float fAcc;
	float fDel;
};


#ifdef __cplusplus
extern "C" {
#endif

//Functions
//====================================================================
M5SCARA_API int WINAPI M5Scara_Init( char *strInitFile, int iDeviceID );
M5SCARA_API int WINAPI M5Scara_GetPos( SCARA_POSITION *pScaraPos , int *piAuslage );

M5SCARA_API int WINAPI M5Scara_MovePTP( SCARA_POSITION ScaraPos, SCARA_MOTIONDESCRIPTOR ScaraMotion, int iAuslage );
M5SCARA_API int WINAPI M5Scara_MoveStep( SCARA_POSITION ScaraPos, unsigned short usTime, int iAuslage ); //usTime [ms]
M5SCARA_API int WINAPI M5Scara_MoveLine( SCARA_POSITION ScaraPos, SCARA_MOTIONDESCRIPTOR ScaraMotion );
M5SCARA_API int WINAPI M5Scara_ChangeElbow( SCARA_MOTIONDESCRIPTOR ScaraMotion );
M5SCARA_API int WINAPI M5Scara_TurnTCP( SCARA_POSITION ScaraPos, SCARA_MOTIONDESCRIPTOR ScaraMotion );

M5SCARA_API int WINAPI M5Scara_Halt( );
M5SCARA_API int WINAPI M5Scara_Reset( );

M5SCARA_API int WINAPI M5Scara_GetState( unsigned long *pulState );
M5SCARA_API int WINAPI M5Scara_SetGlobalRZOffset( float fOffset );
M5SCARA_API int WINAPI M5Scara_GetGlobalRZOffset( float *pfOffset );
M5SCARA_API int WINAPI M5Scara_GetLastError( int *piError, int *piModuleID );

#ifdef __cplusplus
	}
#endif

//TODO
//360° Erweiterungen
#endif // !defined(AMTEC_M5SCARA)