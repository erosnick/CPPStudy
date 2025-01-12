// ConsoleApplication.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include "Stack.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "Queue.h"
#include "String.h"
#include "BinaryTree.h"
#include "Graph.h"
#include "Array.h"
#include "Algorithm.h"
#include <vld.h>
#include <windows.h>

using namespace std;

class Point
{
public:

	virtual ~Point() {}

	static Point P;
	float X;
	float Y;
	float Z;
};

class Concrate1
{
public:
	virtual void foo() { std::cout << "Concrate1" << std::endl; }

private:
	int Value;
	char A;
};

class Concrate2 : public Concrate1
{
private:
	virtual void foo() { std::cout << "Concrate2" << std::endl; }
	char B;
};

class Concrate3 : public Concrate2
{
private:
	char C;
};

struct Base1
{
	int Val1;
};

struct Base2
{
	int Val2;
};

struct Derived : Base1, Base2
{

};

class Abstract
{
public:

	virtual void Foo() const = 0
	{
	}

protected:

	int DataMember;
};

class Concrate : public Abstract
{
public:

	void Foo() const
	{
		Abstract::Foo();
	}
};

class Object
{
public:
	Object()
	{

	}

	~Object()
	{
		printf("I'm dead!\n");
	};

private:

};

int main()
{
	std::vector<int> SearchArray;

	for (auto i = 1; i <= 1000; i++)
	{
		SearchArray.push_back(i);
	}

	auto Index = BinarySearch(SearchArray, 1000);

	Stack<int> IntStack;

	IntStack.Push(10);

	Print(IntStack.Size());

	IntStack.Push(20);

	Print(IntStack.Size());

	Print(IntStack.Pop());

	Print(IntStack.Size());

	Print(IntStack.Pop());

	Print(IntStack.Size());

	Print(sizeof(Concrate1));
	Print(sizeof(Concrate2));
	Print(sizeof(Concrate3));

	Concrate2 C2;
	Concrate1* PC1 = &C2;
	PC1->foo();
	Point P;

	Concrate C;
	C.Foo();

	LinkedList<int> List;

	List.Append(-100);
	List.Append(1000);
	List.Append(50);
	List.Append(300);
	List.Append(10);

	LinkedList<int> Result;

	SelectionSort(List, Result);

	Print("Selection sort test.");

	Result.Print();

	for (int i = 1; i <= 10; i++)
	{
		Print(Fibonacci(i));
	}

	Print("*****Call Stack*****");
	Print(Factorial(5));

	std::vector<int> IntArray = { 1, 2, 100, 4, 5, 6, 7, 8, 9, 10 };

	Print(Counter(IntArray));

	Print(Sum(IntArray));

	Print(Max(IntArray));

	Print(Divide(2000, 1000));

	std::vector<int> SortArray = { 1, 5, 3, 2, 0 };

	SortArray = QuickSort(SortArray);

	Print("Quick sort test.");

	DoubleLinkedList<int> First;

	First.Append(10);
	First.Append(20);
	First.Append(30);

	DoubleLinkedList<int> Second;

	Second.Append(40);
	Second.Append(50);
	Second.Append(60);

	//First.Insert(Second);

	Print("Insert list test.");
	First.Print();
	First.Print(false);

	DoubleLinkedList<int> MergeResult;
	
	Merge(First, Second, MergeResult);

	Print("DoubleLinkeList merge test.");

	MergeResult.Print();

	std::string Subfix = Infix2Suffix("9+(3-1)*3+9/2");

	Print(Calculate(Subfix));

	Print("Queue test.");

	Queue<int> IntQueue;

	IntQueue.Enqueue(100);
	IntQueue.Enqueue(200);
	IntQueue.Enqueue(300);
	
	IntQueue.Print();

	IntQueue.Dequeue();
	IntQueue.Dequeue();
	IntQueue.Dequeue();
	IntQueue.Print();

	Print("String test.");

	String Message = String("ABCDeFG");

	Message.ToLower();

	std::cout << Message << std::endl;

	Message.Assign("1234567");

	std::cout << Message << std::endl;

	String S1 = String("lost");

	String S2 = String("lose");

	std::cout << S1.Compare(S2) << std::endl;

	String Append = S1.Append(S2.Str());

	String SubString = Message.SubString(0, 10);

	std::cout << SubString << std::endl;

	String Assign = "AhahaAhahAha";

	if (Assign.Search("ahah"))
	{
		std::cout << "Find it!" << std::endl;
	}

	Assign.Replace("Aha", "OO");

	String Origin = "Song";

	Origin.Insert(1, "Li ");

	String DeleteString = "Hello World!";

	DeleteString.Delete(5, 6);

	//Print("BinaryTree test.");

	//BinaryTree<int> BT;

	// -1表示左/右结点为空。
	//std::vector<int> Data = { 1, 2, 3, -1, -1, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1 };

	//BT.Create(Data);

	//Print("PreOrderTraverse");

	//BT.PreOrderTraverse([](BTNode<int>* Node) { Print(Node->Data); });

	//Print("InOrderTraverse");

	//BT.InOrderTraverse([](BTNode<int>* Node) { Print(Node->Data); });

	//Print("PostOrderTraverse");

	//BT.PostOrderTraverse([](BTNode<int>* Node) { Print(Node->Data); });

	//Print("InOrderTraverseThreading test.");

	//BT.InThreading();

	//BT.InOrderTraverseThreading();

	//Print("Graph test.");

	//AdjacentListGraph AdjacentGraph;

	//AdjacentGraph.Create();

	//AdjacentMatrixGraph MatrixGraph;

	//MatrixGraph.Create();

	Print("Array test.");

	Array<int> MyArray = {1, 2, 3, 4, 5};

	std::unique_ptr<Object[], std::default_delete<Object[]>> ObjectArray(new Object[10]);

	return 0;
} 