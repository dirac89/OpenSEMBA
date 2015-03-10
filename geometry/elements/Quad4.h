/*
 * Quad4.h
 *
 *  Created on: Apr 10, 2014
 *      Author: luis
 */

#ifndef QUAD4_H_
#define QUAD4_H_

#include "Quad.h"

class Quad4: public Quad {
public:
    Quad4();
	Quad4(const CoordinateGroup<>&,
          const ElementId id,
          const CoordinateId vId[4],
          const LayerId layerId = LayerId(0),
          const MatId   matId   = MatId(0));
    Quad4(const Quad4& rhs);
	virtual ~Quad4();
    
	ClassBase* clone() const;
    
	UInt numberOfCoordinates() const { return 4; }
    
	UInt numberOfSideCoordinates(const UInt f = 0) const { return 2; }
	
    const CoordR3* getV    (const UInt i) const { return v_[i]; }
	const CoordR3* getSideV(const UInt f,
                            const UInt i) const;
    
	const CoordR3* getVertex    (const UInt i) const;
	const CoordR3* getSideVertex(const UInt f,
                                 const UInt i) const;
    
    void setV(const UInt i, const CoordR3*);
    
	void printInfo() const;
	void check() const;

private:
	const CoordR3* v_[4];
};

#endif /* QUAD4_H_ */
