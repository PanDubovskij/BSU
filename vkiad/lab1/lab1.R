setwd("D:/vkiad/lab1")
dat <- read.table("f.txt", dec=".")
dat
d <- dat[,1]
d
d<-as.numeric(dat[,1])
d
a <- table(dat)
a
f<-as.data.frame(a)
f
f[,3]<- 100*a/(sum(a))
f
f[,4]<- cumsum(a)
f
colnames(f)<-c("значение","частота","частость","накопленная частота")
f
f[,5]<- cumsum(f[,3])
f
colnames(f)<-c("значение","частота","частость","накопленная частота","накопленная частость")
f
plot(a,type="l",main="Полигон частот",xlab="значение", ylab="частота")
v<-sort(d)
v
x<-unique(v)
x
y<-as.numeric(f[,4])
y
plot(x,y,type="l",xlab="значение",ylab="накопленная частота", main= "Кумулята 
+ абсолютных частот")
plot(x,z,type="l",xlab="значение",ylab="накопленная частота", main= "кумулята относительных частот")