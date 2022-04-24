dat <- read.table("input.txt",dec=",")
dat
plot(dat,type="p",main="Корреляционное поле",xlab="X", ylab="Y")
sr <- mean(dat[,1])
sigma <- sd(dat[,1])
rows <- paste0("(", round(sr - (1:3) * sigma, 2), ", ", round(sr + (1:3) * sigma, 2), ")")
tab1 <- rep(0, 3*4)
dim(tab1) <- c(3,4)
tab1<- as.data.frame(tab1)
tab1[,1] = rows
tab1[1,4] = 68.3
tab1[2,4] = 95.4
tab1[3,4] = 99.7
for(i in 1:3){
  counter = 0
  for (variable in dat[,1]) {
    if(sr - i * sigma < variable && sr + i * sigma > variable){
      counter = counter + 1
    }
  }
  tab1[i,2] = counter
  tab1[i,3] = (counter / length(dat[,1])*100)
}
colnames(tab1) = c("Интервалы значений признака фактора",
                   "Число единиц, входящих в интервал",
                   "Удельный вес единиц, входящих в интервал в их общем числе, %",
                   "Удельный вес единиц, входящих в интервал, при нормальном распределении, %")
k = 1 + round(log(length(dat[,1]), 2), 0)
h = (max(dat[,1]) - min(dat[,1])) / k
tab2 = rep(0, k*4)
dim(tab2) = c(k,4)
tab2 = as.data.frame(tab2)
rows2 = paste("(", min(dat[,1]) + (1:k) * h - h, ", ", min(dat[,1]) + (1:k) * h, ")", sep = "")
tab2[,1] = rows2
for(i in 1:(k-1)){
  counter = 0
  sm = 0
  for(j in 1:length(dat[,1])){
    if(min(dat[,1]) + (i - 1) * h <= dat[j,1] && min(dat[,1]) + i * h > dat[j,1]){
      counter = counter + 1
      sm = sm + dat[j,2]
    }
  }
  tab2[i,2] = counter
  tab2[i,3] = sm
}
counter = 0
sm = 0
for(variable in dat[,1]){
  if(min(dat[,1]) + (k - 1) * h <= variable && min(dat[,1]) + k * h >= variable){
    counter = counter + 1
    sm = sm + dat[j,2]
  }
}
tab2[k,2] = counter
tab2[k,3] = sm
for (i in 1:k) {
  tab2[i,4] = tab2[i,3] / tab2[i,2]
}
colnames(tab2) = c("Интервалы", 
                     "Число вариант, попавших в i-ый интервал",
                     "Сумма результирующего фактора i-ого интервала",
                     "Средняя величина результирующего фактора в группе")
r = cor(dat[,1], dat[,2])
r 
t = abs(r) * sqrt((length(dat[,1]) - 2) / (1 - r ^ 2))
t
t_tab = 2.539
x = dat[,1]
y = dat[,2]
lm(y ~ x)
abline(lm(y ~ x))
