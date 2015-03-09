/*
 * Waveport.cpp
 *
 *  Created on: Jun 28, 2013
 *      Author: luis
 */

#include "Waveport.h"

Waveport::Waveport(
 const vector<unsigned int>& elem,
 const MagnitudeGaussian* magnitude,
 const bool input,
 const Shape shape,
 const ExcitationMode excMode,
 const pair<unsigned int,unsigned int> mode) : EMSource(elem, magnitude) {
	input_ = input;
	shape_ = shape;
	excitationMode_ = excMode;
	mode_ = mode;
}

Waveport::~Waveport() {

}

ClassBase* Waveport::clone() const {
    return new Waveport(*this);
}


Waveport::Shape
Waveport::getShape() const {
	return shape_;
}

Waveport::ExcitationMode
Waveport::getExcitationMode() const {
	return excitationMode_;
}


pair<unsigned int, unsigned int>
Waveport::getMode() const {
	return mode_;
}

void
Waveport::printInfo() const {
	cout << "--- Waveport info ---" << endl;
	EMSource::printInfo();
	if (input_) {
		cout << "- Is input_." << endl;
	} else {
		cout << "- Is output." << endl;
	}
}
