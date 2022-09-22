#pragma once
#include <Unigine.h>
#include <vector>

class PathMaker : public Unigine::ComponentBase{

public:
	COMPONENT_DEFINE(PathMaker, ComponentBase)
		PROP_PARAM(Node, ObjToMove)
		PROP_PARAM(Float, DurationTime)
		PROP_ARRAY(Node, PathPoints)

		void InitPath();
		void ObjectToMove(Unigine::NodePtr Object);
		void RenderPath();
		void MoveAlongPath();
		Unigine::Math::vec3 GetCurrentPathPosition();


private:

	float Weight = 0;
	int num = 0;
	Unigine::SplineGraphPtr Path;
};