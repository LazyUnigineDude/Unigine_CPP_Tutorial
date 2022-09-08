#pragma once
#include <Unigine.h>

class CameraFollower : public Unigine::ComponentBase
{

public:

	COMPONENT_DEFINE(CameraFollower, ComponentBase)
		COMPONENT_INIT(Init)
		COMPONENT_UPDATE(Update)
		bool isAiming = false;
		
	enum CAMERASTATE { Normal, Aiming };
	void SetState(CAMERASTATE STATE);

protected:
	void Init();
	void Update();

private:

	Unigine::PropertyParameterPtr Parameter;

	Unigine::NodePtr MainCamera, ObjectFollow;
	Unigine::Math::Vec3 NPoint;
	Unigine::Math::Vec3 CPoint;
	int HorInv, VerInv;

	float Angle, Height, HeightValue, Weight, Radius, CamRadius, RotSpeedV, RotSpeedH, MinHeight, MaxHeight; 
	CAMERASTATE PREV_STATE = CAMERASTATE::Normal, STATE = CAMERASTATE::Normal;

	void UpdateCamera();
	void InvertCheck();
	void LerpLayer(CAMERASTATE STATE);
	void LerpValues(Unigine::PropertyParameterPtr PREV_STATE, Unigine::PropertyParameterPtr STATE);
};

