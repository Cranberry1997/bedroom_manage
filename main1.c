#!/usr/bin/python
# -*- coding: UTF-8 -*-

studentinformations=[]

def recover():
	global studentinformations
	f=open("f1.txt",'r')
	content1 = f.read()
	studentinformations=eval(content1)
	f.close()
	zhuye()

def zhuye():
	while True:
		printmenu()
		key=int(input("请输入功能对应的数字:"))
		if key==1:
			addstudentinformations()
		elif key==2:
			delstudentinformations()
		elif key==3:
			modifystudentinformations()
		elif key==4:
			displaystudentinformations()
		elif key==5:
			printbedroominformations()
		elif key==6:
			saveallinformations()
		elif key==7:
			print("退出系统")
			exit()
		else:
			print("抱歉，你输入的信息有误，请重新输入")
			
			
			
def addstudentinformations():
	global studentinformations
	global newinformation
	newinformation={}
	studentname=input("请输入学生姓名：")
	studentphone=int(input("请输入手机号码："))
	studentage=int(input("请输入学生的年龄："))
	studentid=int(input("请输入学生的学号："))
	for i in studentinformations:
		n=int(i['id'])
		if studentid==n:
			print("你输入的学号已经存在了")
			zhuye()
		else:
			None
	studentsex=input("请输入学生的性别：")
	if studentsex=='男':
		print("男生的寝室有100、101、102")
		studentbedid=int(input("请输入学生的寝室号："))
		if studentbedid==100 or studentbedid==101 or studentbedid==102:
			i=0
			for y in studentinformations:
				n=int(y['bedid'])
				if studentbedid==n:
					i=i+1
				else:
					None
			if i>=4:
				zhuye()
			else:
				None	
		else:
			print("你输入的信息有误，请重新输入")
			zhuye()
	else:
		print("女生的寝室有200、201、202")
		studentbedid=int(input("请输入学生的寝室号："))
		if studentbedid==200 or studentbedid==201 or studentbedid==202:
			i=0
			for y in studentinformations:
				n=int(y['bedid'])
				if studentbedid==n:
					i=i+1
				else:
					None
			if i>=4:
				print("抱歉，该寝室已经满员")
				zhuye()
			else:
				None	
		else:
			print("你输入的信息有误，请重新输入")
			zhuye()
	newinformation['name'] = studentname
	newinformation['phone']=  studentphone
	newinformation['id']=studentid
	newinformation['sex']= studentsex
	newinformation['age']= studentage
	newinformation['bedid']= studentbedid
	studentinformations.append(newinformation)
	print("信息添加成功")

def displaystudentinformations():
	print("="*30)
	print("学生的信息如下；")
	print("序号    姓名         性别        手机号码     寝室号       学生号")
	i=1
	for tempinfo in studentinformations:
		print("%d%12s%12s%12d%12d%12d" %(i, tempinfo['name'], tempinfo['sex'], tempinfo['phone'], tempinfo['bedid'],tempinfo['id']))
		i =i+1
	print("="*30)

def printbedroominformations():
	print("="*30)
	c=int(input("请输入寝室号:"))
	print("寝室      姓名           性别        电话        年龄")
	for i in studentinformations:
		y=int(i['bedid'])
		if c==y :
			print("%d%12s%12s%12d%12d" %(i['bedid'], i['name'], i['sex'], i['phone'],i['age'] ))
		else:
			None
	print("="*30)

def printmenu():
	print("="*30)
	print("     学生管理系统     ")
	print("1.添加学生信息")
	print("2.删除学生信息")
	print("3.修改学生信息")
	print("4.显示所有学生信息")
	print("5.打印寝室成员列表")
	print("6.保存所有信息")
	print("7.退出系统")
	print("="*30)
	
def saveallinformations():
	f=open('f1.txt','w')
	f.write(str(studentinformations))
	print("------存储完毕--------")
	f.close()
	
def delstudentinformations():
	c=int(input("请输入要删除的序号："))
	studentinformations.pop(c-1)


def modifystudentinformations():
	c=int(input("更换单人寝室请按1，双人对换请按2:"))
	if c==1:
		l=int(input("请输入你的序号"))
		studentsex=studentinformations[l-1]['sex']
		if studentsex=='男':
			print("男生的寝室有100、101、102")
			studentbedid=int(input("请输入你要更换的寝室："))
			if studentbedid==100 or studentbedid==101 or studentbedid==102:
				i=0
				for y in studentinformations:
					n=int(y['bedid'])
					if studentbedid==n:
						i=i+1
					else:
						studentinformations[l-1]['bedid']=studentbedid
				if i>=4:
					zhuye()
				else:
					None	
			else:
				print("你输入的信息有误，请重新输入")
				zhuye()
		else:
			print("女生的寝室有200、201、202")
			studentbedid=int(input("请输入你要更换的寝室："))
			if studentbedid==200 or studentbedid==201 or studentbedid==202:
				i=0
				for y in studentinformations:
					n=int(y['bedid'])
					if studentbedid==n:
						i=i+1
					else:
						None
				if i>=4:
					print("抱歉，该寝室已经满员")
					zhuye()
				else:
					studentinformations[l-1]['bedid']=studentbedid	
			else:
				print("你输入的信息有误，请重新输入")
				zhuye()
		studentinformations[l-1]['bedid']=studentbedid
	else:
		i=int(input("请输入一个序号："))
		y=int(input("请输入另一个序号："))
		m=int(studentinformations[i-1]['bedid'])
		n=int(studentinformations[y-1]['bedid'])
		if studentinformations[i-1]['sex']==studentinformations[y-1]['sex']:
			studentinformations[i-1]['bedid']=n
			studentinformations[y-1]['bedid']=m
			print("更换寝室成功")
		else:
			print("抱歉，你输入的信心错误")
			zhuye()


recover()	
print(studentinformations)
zhuye()