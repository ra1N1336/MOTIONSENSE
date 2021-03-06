

#pragma once

// Our stuff
#include "Entities.h"
#include "offsets.h"
#include "ClientRecvProps.h"
#include "BaseClient.h"
#include "EngineClient.h"
#include "MiscClasses.h"
#include "Surface.h"
#include "Materials.h"


// Valve
#include "Vector.h"
#include "Vector2D.h"
#include "bspflags.h"

// Management Classes
#include "Interfaces.h"

// Functions
#include "UTIL Functions.h"
#include "MathFunctions.h"

extern CUserCmd*		m_cmd;
extern Vector			m_position;
extern Vector			m_size;
extern IClientEntity*	m_player;
