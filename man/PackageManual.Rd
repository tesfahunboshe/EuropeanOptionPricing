\name{EuropeanStyleCallOptionPricing-package}
\alias{EuropeanStyleCallOptionPricing-package}
\alias{EuropeanStyleCallOptionPricing}
\docType{package}
\title{
  The package calculates the european style call option price
}
\description{
The EuropeanStyleCallOptionPricing calculates the European style call option price  using simple Monte Carlo simulation. 
Rccp package was used to create the package. 
}
\details{
  To install the package, use devtools package's install_github() function. The package is available at github repository
  "tesfahunboshe/EuropeanStyleCallOptionPricing". 
  The package has 1 function 'getSimpleMonteCarloPrice', which takes parameters (current price So, strike price K, volatility, risk-free rate r, time to maturity t, numberofrepetitions)
  in the mentioned order. The function returns the calculated mean option price. 
}
\author{
Tesfahun Tegene Boshe

Maintainer: Tesfahun Tegene Boshe>
}
\references{
  The professor's lecture material also available at https://github.com/pawelsakowski/AF-RCPP-2021-2022.
}
\keyword{ package }

\examples{
  \dontrun{
     ##  most important functions
     {EuropeanOptionPricing::getSimpleMonteCarloPrice(105, 100, 95, 0.22, 0.05, 0.5, 1000)}   
  }
}
