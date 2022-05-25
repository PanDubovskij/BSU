dat <- read.table("input.txt", dec = ",")
d<-dat[,1]
d
mean(d)
disp <- var(d) 
disp 
sd(d)
which.max(table(d))
median(d)
library(timeDate) 
skewness(d)
kurtosis(d)
truncated_mean <- mean(d, trim = 0.125)
the_coefficient_of_variation <- sqrt(disp) / mean(d) * 100
mean_linear_deviation <- sum(abs(d - mean)) / length(d)
relative_linear_deviation <- mean_linear_deviation / mean(d) * 100
