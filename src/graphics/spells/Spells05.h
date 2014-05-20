/*
 * Copyright 2011-2012 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Arx Libertatis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arx Libertatis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Arx Libertatis.  If not, see <http://www.gnu.org/licenses/>.
 */
/* Based on:
===========================================================================
ARX FATALIS GPL Source Code
Copyright (C) 1999-2010 Arkane Studios SA, a ZeniMax Media company.

This file is part of the Arx Fatalis GPL Source Code ('Arx Fatalis Source Code'). 

Arx Fatalis Source Code is free software: you can redistribute it and/or modify it under the terms of the GNU General Public 
License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Arx Fatalis Source Code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Arx Fatalis Source Code.  If not, see 
<http://www.gnu.org/licenses/>.

In addition, the Arx Fatalis Source Code is also subject to certain additional terms. You should have received a copy of these 
additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Arx 
Fatalis Source Code. If not, please request a copy in writing from Arkane Studios at the address below.

If you have questions concerning this license or the applicable additional terms, you may contact in writing Arkane Studios, c/o 
ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.
===========================================================================
*/

#ifndef ARX_GRAPHICS_SPELLS_SPELLS05_H
#define ARX_GRAPHICS_SPELLS_SPELLS05_H

#include "graphics/effects/SpellEffects.h"
#include "graphics/particle/ParticleSystem.h"

// Done By : did
class CRuneOfGuarding : public CSpellFx {
public:
	Vec3f eSrc;
	Vec3f eTarget;
	TextureContainer * tex_p2;
	
	CRuneOfGuarding();
	~CRuneOfGuarding();
	
	void SetPos(Vec3f);
	
	void Create(Vec3f, float afBeta = 0);
	void Kill();
	void Update(unsigned long);
	void Render();
};

// Done By : Sébastien Scieux
class CLevitate : public CSpellFx {
private:
	short key;
	short def;
	Vec3f pos;
	float rbase, rhaut, hauteur, scale;
	float ang;
	int currdurationang;
	int currframetime;
	TextureContainer * tsouffle;
	
	struct T_CONE {
		int conenbvertex;
		int conenbfaces;
		Vec3f * conevertex;
		TexturedVertex * coned3d;
		unsigned short * coneind;
	};
	
	T_CONE cone[2];
	
	EERIE_3DOBJ * stone[2];
	
	struct T_STONE {
		short actif;
		short numstone;
		Vec3f pos;
		float yvel;
		Anglef ang;
		Anglef angvel;
		Vec3f scale;
		int time;
		int currtime;
	};
	
	int timestone;
	int nbstone;
	T_STONE tstone[256];
	
	void AddStone(Vec3f * pos);
	void DrawStone();
	
	void CreateConeStrip(float rout, float rhaut, float hauteur, int def, int numcone);
	
public:
	CLevitate();
	~CLevitate();
	
	void ChangePos(Vec3f * pos)
	{
		this->pos = *pos;
	};
	
	void Create(int def, float rout, float rhaut, float hauteur, Vec3f * pos, unsigned long);
	void Update(unsigned long);
	void Render();
};

// Done By : Didier Pédreno
class CCurePoison : public CSpellFx {
public:
	Vec3f eSrc;
	ParticleSystem * pPS;

	CCurePoison();
	~CCurePoison();

	void Create();
	void Update(unsigned long);
	void Render();
	
	long spellinstance;
};

// Done By : Didier Pédreno
class CPoisonProjectile: public CSpellFx {
	
public:
	float fTrail;
	bool  bOk;
	
	Vec3f eSrc;
	Vec3f eCurPos;
	Vec3f eMove;
	TexturedVertex pathways[40];
	ParticleSystem pPS;
	ParticleSystem pPSStream;

	float lightIntensityFactor;
	
	CPoisonProjectile();
	
	// surcharge
	void Create(Vec3f, float afBeta = 0);
	void Update(unsigned long);
	void Render();
	
	long spellinstance;
};

class CMultiPoisonProjectile : public CSpellFx {

private:
	unsigned int uiNumber;
	CPoisonProjectile ** pTab;
	void AddPoisonFog(Vec3f * pos, float power);
	
public:
	explicit CMultiPoisonProjectile(long nb);
	~CMultiPoisonProjectile();
	
	void Create(Vec3f srcPos, float);
	void Kill();
	void Update(unsigned long);
	void Render();
	
	long spellinstance;
};

// Done By : did
class CRepelUndead : public CSpellFx {
public:
	Vec3f eSrc;
	Vec3f eTarget;
	TextureContainer * tex_p2;
	
	CRepelUndead();
	~CRepelUndead();
	
	void SetPos(Vec3f);
	
	void Create(Vec3f, float afBeta = 0);
	void Kill();
	void Update(unsigned long);
	void Render();
	
	long spellinstance;
};

#endif // ARX_GRAPHICS_SPELLS_SPELLS05_H
