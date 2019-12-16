


class NCB_CFVector
{
public:
	NCB_CFVector();
	~NCB_CFVector();

	void NCB_vSetX( float x );
	void NCB_vSetY( float y );
	void NCB_vSetZ( float z );
	void NCB_vSet( float x, float y, float z );

	float* NCB_oGetDataX( void );
	float* NCB_oGetDataY( void );
	float* NCB_oGetDataZ( void );
	float* NCB_oGetData( void );

	float* NCB_oGetNormal( void );
	
protected:
	float m_fData[3];
	float m_fNormal[3];
};