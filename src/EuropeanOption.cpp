#include<iostream>
#include<cmath>
#include"getOneGaussianByBoxMueller.h"
#include"EuropeanOption.h"


//definition of constructor
EuropeanOption::EuropeanOption(
	int nInt_,
	double strike_,
	double spot_,
	double vol_,
	double r_,
	double expiry_){
		nInt = nInt_;
		strike = strike_;
		spot = spot_;
		vol = vol_;
		r = r_;
		expiry = expiry_;
		generatePath();
}

//method definition
void EuropeanOption::generatePath(){
	double thisDrift = (r * expiry - 0.5 * vol * vol * expiry) / double(nInt);
	double cumShocks = 0;
	thisPath.clear();

	for(int i = 0; i < nInt; i++){
		cumShocks += (thisDrift + vol * sqrt(expiry / double(nInt)) * getOneGaussianByBoxMueller());
		thisPath.push_back(spot * exp(cumShocks));
	}
}


//method definition
double EuropeanOption::getMonteCarloMean(int nReps){

	double variance = vol * vol * expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedSpot = spot * exp(r * expiry + itoCorrection);
	double thisSpot;
	double runningSum = 0;

	for (unsigned long i = 0; i < nReps; i++) {
		double thisGaussian = getOneGaussianByBoxMueller();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		double thisPayoff = thisSpot - strike;
    	// thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
    	if (thisPayoff>0) runningSum += thisPayoff;
	}

	double mean = runningSum / nReps;
	// mean *= exp(-r * Expiry);
	mean = mean * exp(-r * expiry);
	return mean;

}


//method definition
double EuropeanOption::getSimpleMonteCarloPrice(int nReps){

	double rollingSum = 0.0;
	double thisMean = 0.0;

	for(int i = 0; i < nReps; i++){
		generatePath();
		thisMean=getMonteCarloMean(nReps);
		rollingSum += (thisMean < strike) ? 0 : (strike - thisMean);
	}

	return exp(-r*expiry)*rollingSum/double(nReps);

}



