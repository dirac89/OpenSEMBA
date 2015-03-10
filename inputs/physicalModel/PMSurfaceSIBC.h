/*
 * PMSurface.h
 *
 *  Created on: May 27, 2014
 *      Author: luis
 */

#ifndef PMSURFACESIBC_H_
#define PMSURFACESIBC_H_

#include "PMSurface.h"
#include "../../math/StaMatrix.h"

class PMSurfaceSIBC : public PMSurface {
	friend class DGSIBC;
public:
	PMSurfaceSIBC();
	PMSurfaceSIBC(
	 const MatId id,
	 const string& name,
	 const MatR22& Zinfinite,
	 const MatR22& Zstatic,
	 const vector<Real>& pole,
	 const vector<MatR22>& Z);
	virtual ~PMSurfaceSIBC();

    ClassBase* clone() const;

	virtual PMSurfaceSIBC&
     operator=(const PMSurfaceSIBC &param);
	void setZInfinity(const MatR22& Zinf);
	void setZStatic(const MatR22& Zsta);
	virtual void addPole(const Real pole, const MatR22& Z);
    virtual UInt getNumberOfPoles() const;
	virtual void printInfo() const;
protected:
	MatR22 ZInfinity_, ZStatic_;
	vector<Real> pole_; // Impedance poles.
	vector<MatR22> Z_; // Impedance residuals.
};

#endif /* PMSURFACE_H_ */
