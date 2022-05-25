library(MASS)
#"Дубовский" - 9 букв
#Моделируем данные
dat_1 = cbind(rnorm(20, 0 , 9 / 3), rnorm(20, 0 ,  9 /3))
dat_2 = cbind(rnorm(10, 9 , 9 / 3), rnorm(10, 9 ,  9 /3))

dat = rbind(dat_1, dat_2)

#Кластерный анализ cl
cl = kmeans(scale(dat), 2)
sapply(1:2, function(i) cl$centers[,i] * sd(dat[,i]) + mean(dat[,i]))


#Дискриминантный анализ № 1
n = length(dat[,1])

n.train = floor(n * 0.7)
n.test = n - n.train

idx.train = sample(1:n, n.train) 
data.train = dat[idx.train, ]
idx.test = setdiff(1:n, idx.train)
data.test = dat[idx.test, ]


cl.train = factor(cl[["cluster"]][idx.train])
cl.test = factor(cl[["cluster"]][idx.test])

#Обучение полученой тестовой выборки
mod = qda(data.train, cl.train)
cl.test_est = predict(mod, data.test)$class

#Оценка ошибки классификации
sum(cl.test_est != cl.test) / n.test
idx.wrong = idx.test[cl.test_est != cl.test] 

#Строим первый график
plot(dat, col = c("blue", "green")[cl$cluster], pch = 20, cex = 2, xlab = "X", ylab = "Y", main = "plot_1")
legend("topleft", legend = c("1", "2"), fill = c("blue", "green"))
points(dat[idx.wrong, 1], dat[idx.wrong, 2], col = "red", pch = 4, cex = 2, lwd = 3) 
points(dat[idx.train,],pch = 2, cex = 2)

#Меняем номер кластера в 20% выборки
idx.new = sample(1:n, n*0.2)
for (i in 1:length(idx.new)) {
  if(cl[["cluster"]][idx.new[i]] == 1){
    cl[["cluster"]][idx.new[i]] = 2}
  else{
    cl[["cluster"]][idx.new[i]] = 1
  }
}


#Дискриминантный анализ № 2
cl_train = factor(cl[["cluster"]][idx.train])
cl_test = factor(cl[["cluster"]][idx.test])

#Обучение полученой тестовой выборки
mod2 = qda(data.train, cl.train)
cl.test_est2 = predict(mod2, data.test)$class

#Оценка ошибки классификации
sum(cl.test_est2 != cl.test) / n.test
idx.wrong2 = idx.test[cl.test_est2 != cl.test] 

#Строим второй график
plot(dat, col = c("blue", "green")[cl$cluster], pch = 20, cex = 2, xlab = "X", ylab = "Y", main = "plot_2")
legend("topleft", legend = c("1", "2"), fill = c("blue", "green"))
points(dat[idx.wrong2, 1], dat[idx.wrong2, 2], col = "red", pch = 4, cex = 2, lwd = 3)
points(dat[idx.new, ], pch = 3, cex = 2, lwd = 2)

