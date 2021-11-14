import numpy as np

nums = np.array([4, 6, 1, 12, 10]) 
print(type(nums))
nums=np.arange(4,12)
print(nums)


nums=np.ones((6,3)) 
print(nums)

nums=np.zeros((6,3)) 
print(nums)

nums=np.linspace(1,10,5) 
print(nums)

nums=np.eye(4) 
print(nums)

nums = np.random.rand(2,3) 
print(nums)

num=np.arange(1,17) 
num2=num.reshape(4,4) 
print(num2)

random=np.random.randint(1,100,5) 
print(random)
minValue=random.min() 
print(minValue)
maxValue=random.max() 
print(maxValue)
