# EuropeanStyleCallOptionPricing

This simple package allows calculating the theoretical price of options and also plotting the relation between the price and volatility as well as the price and expiry time, also called time to maturity. 

### Installing and Loading the Package
To install from this repository, you will need 'devtools' package and run the following command on RStudio. 

```ruby
if(!require("EuropeanOptionPricing")) install_github("tesfahunboshe/EuropeanOptionPricing", force = TRUE)
library(EuropeanOptionPricing)
```

### Testing out the package

Call the *getSimpleMonteCarloPrice* function to calculate the European style call price of a chosen set of parameters. 

```ruby
EuropeanOptionPricing::getSimpleMonteCarloPrice(105, 100, 95, 0.22, 0.05, 0.5, 1000)

```
