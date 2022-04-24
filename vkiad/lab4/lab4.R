dat = read.table(file = "input.txt", dec = ",")

#Строим ряд динамики (Временной ряд)
myts = ts(dat[,1], start = c(2017,8), end = c(2018,7), frequency = 12)

#Средний уровень ряда динамики
mn = (sum(dat[,1]) - ((dat[1,1] + dat[length(dat),1]) / 2)) / (length(dat[,1]) - 1)

#Определяем наличие тренда
n <- length(dat[,1])
avery <-(sum(dat[1]) - dat[1,1]/2 - dat[1, length(dat[1])]/2)/(length(dat[,1])-1)
averr <- (length(dat[,1]) + 1)/2
sigmar <- sqrt(averr-1)/2
t <- 2
(averr+1 - t*sqrt(n-1))/2
avery
(averr+1 + t*sqrt(n-1))/2

#Сглаживание ряда методом скользящей средней
library("pracma")
dat[,2] = movavg(dat[,1], 3, type = "s")

#Сглаживание ряда методом аналитического выравнивания
center = round(length(dat[,1]) / 2)

if(mod(length(dat[,1]), 2) == 1){
  dat[center,3] = 0
  for(i in 1:(center - 1)){
    dat[center - i,3] = -i
    dat[center + i,3] = i
  }
}else{
  for(i in 0:(center - 1)){
    dat[center - i,3] = -(1 + 2*i)
    dat[center + i + 1,3] = (1 + 2*i)
  }
}

a_0 = (sum(dat[,1]) / length(dat[,1]))
a_1 = 0
for (i in 1:length(dat[,1])) {
  a_1 = a_1 + dat[i,1]*dat[i,3]
}
a_1 = a_1 / sum((dat[3])^2)

for (i in 1:length(dat[,1])) {
  dat[i,4] = a_0 + dat[i,3]*a_1
}

#Прогнозируем следующее значение
y_next = a_0 + a_1*((dat[length(dat[,3]), 3] - dat[length(dat[,3]) - 1, 3]) + dat[length(dat[,3]),3])

#Наносим всё на график
plot(myts, lwd = 3, col = "green", main="Time series", ylab = "Value")
lines(ts(dat[,2], start = c(2017,8), end = c(2018,7), frequency = 12), col = "red", lwd = 3)
lines(ts(dat[,4], start = c(2017,8), end = c(2018,7), frequency = 12), col = "blue", lwd = 3)
legend("bottomleft", legend = c("1", "2", "3"), fill = c("green", "red", "blue"))

