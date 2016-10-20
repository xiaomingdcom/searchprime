#include <stdio.h>
#include <iostream>
#include <String>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#define Ns 2040000000/3
#define No 100000000//这里没有定义为1亿，导致debug时数组不够长
using namespace std;
char prime[Ns];
int s_prime[No];
int searchprime(int N) {
	int i = 0;
	int j = 0;
	int k = 2;
	int l = 0;
	int pro = 0;
	s_prime[0] = 2;
	s_prime[1] = 3;//因为筛选的为6k+1，6k-1，2和3是特例，单独列出
	if (N == 1) {
		return 2;
	}
	if (N == 2) {
		return 3;
	}
	for (i = 0; i < Ns; i++) {
		if (i % 2 == 1) {
			l = (i + 1) * 3 + 1;//奇数位存6k+1
		}
		if (i % 2 == 0) {
			l = i * 3 + 5;//偶数位存6k-1
		}
		if (prime[i] != 1) {
			s_prime[k] = l;
			k++;
		}

		if (k == N) {
			return l;
		}
		for (j = 0; j < k; j++) {
			pro = l*s_prime[j];
			if (pro < 0 || pro >= (Ns * 3-6)) {
				break;
			}
			if (pro % 6 == 1) {
				prime[(pro - 1) / 3 - 1] = 1;//6k+1放在对应位置
			}
			else
				if ((pro + 2) % 6 == 1) {
					prime[(pro - 5) / 3] = 1;//6k-1
				}
			if (l%s_prime[j] == 0) {
				break;//防止重复判断
			}
		}
	}
	return 0;
}

void main()
{
	int k = 0;
	bool i = 0;
	int N = 0;
	long start;
	long end;
	/*for (i = 0; i < Ns; i++) {
		prime[i] = 0;
	}
	for (i = 0; i < No; i++) {
		s_prime[i] = 0;
	}*/
	while (1) {
		cout << "请输入N" << endl;
		cin >> N;
		if (cin.fail() || N<1 || N>100000000) {
			cout << "输入错误" << endl;
			cin.clear();//改变错误位
			cin.ignore(1024, '\n');//清除缓存
			continue;
		}
		else {
			break;
		}
	}
	start = clock();
	k = searchprime(N);//求第N个素数的子函数
	cout << "第" << N << "个素数为" << k << endl;
	end = clock();
	cout << "运行时间" << end - start << "ms" << endl;
	system("pause");
}