### 0)C++入門

##### 請先安裝C++編寫程式，如Visual Studio 2022、Code::Blocks等等

教程裡標註==課外內容==為學校沒有提到的部分，可視情況學習

#####目標:照著輸出==Hello world!==，先不必理會程式碼的意思

1. std::cout 向控制台輸出內容的指令。 

2. << 輸出的運算子。 

3. "" 字串內容的邊界符。 

4. \n 輸出一個換行。

5. 分號「;」為C++語句結束的標誌。

   ```c++
   #include <iostream>
   
   int main(int argc, char** argv) //現階段用不到
   {
       std::cout << "Hello World!\n";
       return 0; //在每個程式中可加可不加，現階段還沒差別
   }
   ```
   
   

###1)資料的分類

1. __數字__:直接書寫，如:100、18.52、0、5、9

2. __字元__:用半形的單引號包含，如'A'、'Z'、'0'、'9'、'~'

3. __字串__:用半形的雙引號包含,如:"Hello World"、"你好"、"cpp"、"100"、"X"

   ```c++
   int main()
   {
       std::cout << 5 << std::endl ;
       std::cout << 'a' << std::endl;
       std::cout << "Hello World!\n";
   }
   ```

### 2)輸出資料

● std::cout 可以輸出各種類型的資料; 

● <<操作符可以拼接多個資料項目;

● std::endl 也可以用於換行; 

● using namespace std;指定默認的命名空間。

```c++
#include <iostream>
using namespace std;
int main()
{
    cout << 5 << endl ;
    cout << 'a' << endl;
    cout << "Hello World!\n";
}
```

####2.1)注釋

__註釋分為單行註釋與全段註釋__

- // 用於單行註釋，//以後的欄位都會被忽略
- /* */ 用於全段註釋
- 多行註釋與單行註釋可以互相注釋==(不建議)==，沒用的冷知識，考試可能會考

==Ctrl+k+c== : 批量注釋

==Ctrl+k+u== : 批量解除注釋

直接上範例

```C++
//這是一段單行註釋
/*
這是全段註釋
註釋內的字會自動被程式忽視
*/

//這是一段單行註釋/*
此多行註釋已失效*/
  
/*//*/單行註釋已失效
  
//但是 //同類型的註釋不能互相註釋
/*/*多行註釋也是一樣*/*/
```

#### 2.2)變數

聲明(定義)變數

語法:==資料類型 變數名;==

資料類型:==整數(int) 浮點數(float和double) 字元(char) 字串(string) 布林(bool)==

```C++
#include <iostream>
using namespace std;
int main()
{
  int a=8, b=45;
  float c=12.3;
  double d=45.6;
  char e='@';
  string f="Hello World!"; //string字串並非基本資料類型，前面省略std::string
  bool g=true;
  cout << a << endl << b << endl << c << endl <<
    d << endl << e<< endl << f << endl << g << endl;
}
```

==注意:==裡面有些尚未補充的其他資料類型，之後會提到

#### 2.3)常量

#####	2.3.1)宏常量

​	一般在 main 函數的上面聲明,用大寫命名。 

​	語法:==#define 常量名 值==

```c++
#include <iostream>
using namespace std;
#define week 7 
#define year 365 //注意定義宏常量，後面不帶分號
int main() //main函數
{
  cout << week << endl;
	cout << year;
}
```

##### 	2.3.2)const 修飾

​	在程式的任何地方都可以聲明

​	語法: ==const 資料類型 常量名=值;==

```C++
#include <iostream>
using namespace std;

int main() //main函數
{
  const int week=7;
  const int year=365;
  cout << week << endl << year << endl;
}
```

__註:程式中不允許改變常量的值,否則編譯的時候會報錯。__

###3)輸入資料

用std::cin輸入資料

語法:==std::cin >> 變數名;== //注意箭頭方向與cout相反

```C++
#include <iostream>
using namespace std;
int main()
{
  int a, b;
  cout << "連續輸入兩個數字";
  cin >> a >> b;  //可利用箭頭連接連續多個輸入
  cout << "你輸入的第一個數是:" << a << endl <<
    "你輸入的第二個數是:" << b << endl;
}
```

一些前面沒提到的小細節==(必看)==:

a)布林型變數的值在電腦內部用1(true)和0(false)存儲

b)程式中可以書寫 true 和 false,也可以書寫1和0,其它值將強制轉換成1

c)用 cin 輸入時可以填1和0,其它值也 強制轉換成 1

d)用 cout 輸出時只顯示1和0,不顯示 true 和 false。

e)如果輸入的資料與變數的資料類型不匹配,會__==導致行為的不確定性==__

### 4)算數運算

能夠使用算數運算的數數值型別為 整數(int) 或浮點數(float 或 double)

\+ 兩數相加

\- 兩數相減

\* 兩數相乘

/ 兩數相除

% 取兩數相除後的餘數

```C++
#include <iostream>
using namespace std;
int main()
{
  int a=0, b=2, c=5, d=10;
  double e=2.5, f=0;
  cout << a+e << endl << d-c << endl << d*f << endl;
  cout << a/a << endl; //此行程式會導致程序異常，提前終止
  cout << f/a << endl;
  cout << c/b << endl; //兩整數相除，將捨棄餘數
  cout << c%b << endl;
  cout << e/b << endl;
  cout << e%b << endl; //浮點數不可參與取餘計算!
}
```

==注意:==

● 整數進行除法運算時,如果分母為0,程式將異常退出

● 浮點數進行除法運算時,如果分母為0.0,將得到inf(infinite,無窮大)

● 兩個整數進行除法運算時,將舍去小數部分,得到一個整數 

● 整數與浮點數進行除法運算時,得到的結果是浮點數

● 在整數前面加(float)或(double)可以將整數轉換為 float 或 double 類型。

● 取模運算只能用於整數(分母也不能為0)

####4.1)賦值運算

c+=a; //相當於c=c+a;

c-=a; //相當於c=c-a;

c*=a;  //相當於c=c\*a;

c/=a; //相當於c=c/a;

c%=a; //相當於c=c%a;

```C++
#include <iostream>
using namespace std;
int main()
{
	int a = 8, b = 16;
  string str1 = "Hello World!", str2, str3;
	b+=a;
  str2 = str3 = str1;  
  //注意: 賦值運算子是由右向左運算，將str1寫最前面，str2會回傳空值
	cout << "b變數的新值為:" << b << endl;
  cout << "字串2的值為:" << str2 << endl;
}
```

注意:

- ==字串(string)只能使用等號(=)賦值,不能使用其它的設定運算子==

- 浮點數不能使用%=運算子;

- 等號(=)設定運算子可以連續使用;

- 如果等號兩邊運算元的資料類型不同,C++將自動轉換資料類型,可能會損失精度,也可以超出取值範圍,如果轉換不成功,編譯時會報錯。

####4.2)C++11 初始化賦值 (課外內容)(不實用)

- 把值寫在小括弧中,等於號可以省略(C++標準)

int a=(15); // 聲明變數a,初始化值為 15。 

int b(20); // 聲明變數b,初始化值為 20。

- 把值寫在花括弧中,等於號也可以省略(C++11 標準),統一初始化列表。

int a={15}; // 聲明變數a,初始化值為15。

int b{20}; // 聲明變數b,初始化值為 20。

```C++
#include <iostream>
using namespace std;
int main()
{
	int a(10);
	int b = (10);
	int c{ 10 };
	int d={ 10 };
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
	cout << "d:" << d << endl;
}
```

#### 4.3)關係運算(同python)

等於   == 

不等於  != 

小於   <

小於等於 <=

大於   >

大於等於 >=

注意:由於關係運算子優先順序小於輸出運算子(<<)，所以書寫時務必帶上括弧

==後面會提到運算優先順序==

字串(string)常用的關係運算子為 == 或 !=，但不代表其他運算子不能使用

```C++
#include <iostream>
using namespace std;
int main()
{
  bool x, y, z;
  int a=0, b=3;
  char c='a', d='A';
  x=(a<b);  //凡是不確定運算優先級，加括號就對了
  y=(a==b); //務必分清楚賦值運算(=)與關係運算(==)，等號數量不要寫錯了
  z=(c>=d); //ascii碼表: A=65 a=97
  cout << "x:" << x << endl;
  cout << "y:" << y << endl;
  cout << "z:" << z << endl;
}
```

#### 4.4)邏輯運算(重點)

根據給定的邏輯因數(運算式或值)返回一個新的邏輯因數。

&& and 

|| or

!  not

```C++
#include <iostream>
using namespace std;
int main()
{
  bool x, y, z;
  int a=0, b=3;
  char c='a', d='A';
  x=(a<b);  //凡是不確定運算優先級，加括號就對了
  y=(a==b); //務必分清楚賦值運算(=)與關係運算(==)，等號數量不要寫錯了
  z=(c>=d); //ascii碼表: A=65 a=97
//書接上回，已知x=1, y=0, z=1
  cout << (x||y&&z||!z) << endl;
}
```

注意:

- ==not優先於and，再優先於or==

- 邏輯運算子的兩邊可以是數值,也可以是運算式;

- 用std::cout 輸出邏輯運算運算式時,邏輯運算式要加括弧;

- 在實際開發中,邏輯運算的多重組合是重點。

####4.5)逗號運算(前面用過，現在系統的介紹)

把一行語句中的多個運算式連接起來,程式將從左到右執行運算式。

語法:==運算式一,運算式二,運算式 n;==

逗號運算常用於聲明多個變數，當然也可以用於其它語句中

int a,b;   //聲明變數a和b。 

int a=10,b=20;   //聲明變數a和b並初始化。 

但是，逗號運算子是所有運算子中級別最低的，以下兩個運算式的效果是不同的

```c++
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	b = a = 2, a * 2;  
  //在第六行，a先賦值為2，b再賦值為a，後面的a*2純屬無意義，因為沒有程序接收該值
	cout << a << endl << b << endl;
  //結果:a=2, b=2
}
```



```C++
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	b = (a = 2, a * 2);
  //在第六行，a先賦值為2，b再賦值a*2，因此現在的a還是2，但b卻變成了4
	cout << a << endl << b << endl;
  //結果:a=2, b=4
}
```

###5)運算優先順序(前面已提過)

__一個運算式可以包含多個運算子,運算子的優先順序決定了運算式各部分的執行順序。__

例如,按照數學的運算規則, \*的優先順序比+高,所以的b*c將先執行:

如果一個運算式中操作符的優先順序相同,那麼它們的結合律(associativity)決定了它們的執行順序(從左到右或從右到左)。

例如,==算數運算==的組合方式是==從左到右==,==賦值運算==則是==從右到左==。如下:

| 運算式 | 結合律   | 組合方式 |
| ------ | -------- | -------- |
| a/b%c  | 從右到左 | (a/b)%c  |
| a=b=c  | 從左到右 | a=(b=c)  |

優先順序和結合律==不必死背==

- 如果不確定運算子的優先順序,可以加括弧

- 多用括弧。讓代碼的可讀性更好

###6)if 語句的基本結構(==重要==)

語法: 

if (運算式)

{

  // 運算式為真時執行的語句。

}

else

{

   //運算式為假時執行的語句。

}

```C++
#include <iostream>
using namespace std;
int main()
{
  int a, b;
  cin >> a >> b ;
  if (a>b) //記得加上括號
  {
    cout << "a大於b\n";
  }  
  else
    ;
}
```

注意:

- if (運算式)之間的空格可以不寫

- 運算式==必須使用括弧==

- 運算式可以是具體的值

- 運算式一般是關係運算和邏輯運算運算式,也可以是賦值運算或其它的運算式。 

- 可以沒有 else 分支

- 如果花括弧內的代碼可以有多行,也可以只有一行,==如果只有一行,花括弧可以不書寫==

- if (運算式)和 else 後不能加分號,因為==分號表示空語句==

####6.1)三元運算(課外)

三元運算也叫條件運算或三目運算,可以實現簡單 if 語句的功能,但是書寫更簡潔。 

語法: ==運算式一?運算式二:運算式三==

先計算運算式一的值

如果為==真==,整個運算式的結果就為==運算式二的值==

如果為==假==,整個運算式的結果就為==運算式三的值==

三元運算與if語句比較，以判斷閏年為例

```C++
#include <iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	cout << ((a % 4 == 0 && a % 100 != 0 || a % 400 == 0)?"閏年":"平年") 
    << endl;
}
```

```C++
#include <iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		cout << "閏年";
	else
		cout << "平年";
}
```

#### 6.2)switch語句(課外)

switch 也是一種選擇結構的語句，主要==用來比較數值或字元==，可以代替簡單的多條件的 if 語句。

語法:

switch (數值) 

{

case 值一: 

語句一; 

break; 

case 值二: 

語句二; 

break; 
...
case 值n: 

語句 n; 

break; 

default: 

上述條件都不滿足時執行的語句;

}

以成績分類為例

```C++
#include <iostream>
using namespace std;
int main() 
{ 
    int score; 
    cout << "輸入成績:"; 
    cin >> score; 
    switch(score / 10) 
    { 
        case 10: case 9: 
            cout << "優" << endl; 
            break; 
        case 8: 
            cout << "甲" << endl; 
            break; 
        case 7: 
            cout << "乙" << endl; 
            break; 
        case 6: 
            cout << "丙" << endl; 
            break; 
        default: 
            cout << "丁" << endl; 
            break;
    } 
    return 0;
}
```

### 7)迴圈

#### 7.1)while迴圈語句

語法: 

while (運算式) 

{

語句塊

}

先計算運算式的值,如果為真就執行語句塊,執行完語句塊後,回到迴圈首部再次計算運算式的 值,如果為真又執行一次語句塊,這個過程會一直重複,直到運算式的值為假時不再執行語句塊。

以數1~10為例

```C++
#include <iostream>
using namespace std;
int main() 
{ 
  int counting=1;
  while(counting<=10)
  {
    cout << counting++ << endl;
  }
}
```

#### 7.2)迴圈的跳轉

break 和 continue 兩個關鍵字用於控制循環體中代碼的執行流程。 

break 跳出(中止)當前迴圈語句。 continue 回到當前迴圈語句的首部。

####7.3)for 迴圈語句

語法:

for (語句一;運算式;語句二)   

{

語句塊

}

1) 迴圈開始的時候,先執行語句一,在整個迴圈過程中語句一隻會被執行一次。 
2) 計算運算式的值,如果為真,就執行一次循環體中的語句塊。
3) 執行完語句塊後,執行一次語句二。

4. 重複第2步和第3步,直到運算式的值不為真才結束 for 迴圈。

一樣以數1~10為例

```C++
#include <iostream>
using namespace std;
int main() 
{ 
  int counting;
  for(counting=1;counting<=10;counting++)
  {
    cout << counting << endl;
  }
  return 0;
}
//注意中間以分號連接
```

- for迴圈可以理解為帶個計數器的while迴圈，不過==本質上沒有區別==，兩者都可以互通
- for 迴圈一般需要一個相當於計數器的變數
- 在for 迴圈中,==語句一、運算式和語句二都可以為空==,for(;;)等同於 while (true)
- continue和 break 兩個關鍵字也可以用在 for 循環體中

####7.4)do...while迴圈語句(不常用)

語法:

do

{

 語句塊

} while (運算式);

功能與 while 語句類似，不同的是:

- 進入迴圈時,先執行一次語句塊，再計算運算式的值。 

- 迴圈的首部書寫在迴圈的尾部，(運算式)後面還有一個分號。

還是以數1~10為例

```C++
#include <iostream>
using namespace std;
int main() 
{ 
  int counting=1;
  do
  {
    cout << counting++ << endl;
  }while (counting<=10); 
  return 0;
}
```

###8)go to語句(不常用)



###10)sizeof函數

sizeof 運算子用於求資料類型或變數佔用的記憶體空間。

語法:

==sizeof(資料類型) sizeof 資料類型==

```C++
#include <iostream>
using namespace std;
int main() 
{ 
  int a;
  cout << "整數所佔用的記憶體空間為" << sizeof a << "個位元組" << endl;
  cout << "字串所佔用的記憶體空間為" << sizeof(string) << "個位元組" << endl; //字串非基本資料類型，所佔的記憶體空間並不準確
 return 0;
}
```

### 11)整數

在聲明整型變量的時候可在int關鍵字前加

signed, unsigned, short, long, long long

四種修飾符

總共可以組成6種類型，分別為:

| 類型簡寫           | 類型全稱           | 長度    | 取值範圍(註:不適用於linux)               |
| ------------------ | ------------------ | ------- | ---------------------------------------- |
| short              | signed short int   | 2位元組 | -32768~32767                             |
| unsigned short     | unsigned short int | 2位元組 | 0~65535                                  |
| int                | signed int         | 4位元組 | -2147483648~2147483647                   |
| unsigned int       | unsigned int       | 4位元組 | 0~4294967295                             |
| long               | signed long in     | 4位元組 | -2147483648~2147483647                   |
| unsigned long      | unsigned long int  | 4位元組 | 0~4294967295                             |
| long long          | 略                 | 8位元組 | -9223372036854775808~9223372036854775807 |
| unsigned long long | 略                 | 8位元組 | 0~18446744073709551615                   |

```C++
#include <iostream>
using namespace std;
int main()
{
	cout << "long long所佔用的記憶體空間為" << sizeof(long long) << "個位元組" << endl;
	cout << "unsigned short所佔用的記憶體空間為" << sizeof(unsigned short) << "個位元組" << endl;
	return 0;
}
```

__可以根據類型所佔用的內存大小判斷取值的範圍__

注意:

- 一個字節8個位，取值範圍為2^8^-1，即255

- 如果占用的是四個字節，無符號型的取值範圍是2⁸*2⁸*2⁸*2⁸-1 

- 如果占用的是八個字節，無符號型的取值範圍是2⁸*2⁸*2⁸*2⁸*2⁸*2⁸*2⁸*2⁸-1 

- 如果有符號，取值範圍減半，因為符號佔一個位

- 為防止超出取值範圍，應保證有足夠的空間

####11.1)整數的書寫

#####二進制

二進制由0 和 1兩個數字組成，書寫必須以0b 或0B開頭。

例如

int a = 0b01      //換算成十進制為 5

int b = -0b110010 //換算成十進制為 -50

int c = 0B100001 //換算成十進制為 33

#####八進制

八進制由 0~7 八個數字組成，，書寫必須以 0 開頭。

int a = 015     //換算成十進制為 13

int b = -0101   //換算成十進制為 -65

int c = 0177777 //換算成十進制為 65535

#####十六進制

十六進制由 0~9, 字母A~F 或 a~f 組成(不區分大小寫)，書寫必須以0x 或0X開頭。

###12)浮點數

浮點數有三種類型

float      // 7位有效數字 (聲明變量結尾要加F或f，否則會被強制轉換)

double    //15位有效數字

long double //不低於double

```C++
#include <iostream>
using namespace std;
int main()
{
  const float pi=3.14159F;
  cout << pi;
}
```



### 13)轉義符

形成原因:

- 控制字符沒有字號，無法書寫，只能用其他符號代替

- 某些符號以被C++使用，與義衝突，所以只能用其他符號代替

| 常用ASCII碼值 | 轉義字符 | 字符意義 |
| ------------- | -------- | -------- |
| 0             | \0       | 空值     |
| 10            | \n       | 換行(LF) |
| 13            | \r       | 回車(CR) |
| 9             | \t       | 製表(HT) |
| 92            | \\\      |          |
| 34            | \\"      |          |
| 39            | \\'      |          |

換行(LF):和std::endl類似

回車(CR):將指針移到本行首，具體看下面代碼演示

製表(HT):補滿一列(八個空格)的寬度，如果前面字串剛好滿一列，會再多補一列

```C++
#include <iostream>
using namespace std;
int main()
{
	cout << "000123\r456\n";
	cout << "000123\r\n456\n";
	cout << "000123\t456\n";
	cout << "12300000\t456\n";
}
```

### 14)類型轉換
+ 較低類型會自動轉往較高類型
+ 當表達式中含有浮點數，所有操作將轉為浮點數
+ 賦值運算右值類型與左值不一致時，右值轉換為左值類型，所得結果可能毫無意義

強制轉換語法:==(目標類型)表達式==

```C++
#include <iostream>
using namespace std;
int main()
{
	float a = float(1.234);
  //賦值float後面沒寫F會有警告，強制轉換後警告就消失了
	cout << a;
}
```

####14.1)數據類型別名

創建書寫類型有兩個目的:

1. 為名稱複雜的類型創建別名，便於書寫
2. 創建與平台無關的數據類型，提高程序兼容性

語法:==typedef 數據類型名 別名;==

```C++
#include <iostream>
using namespace std;
int main()
{
    typedef unsigned long long ull;
    ull a = 18446744073709551615;
    ull b = 18446744073709551610;
    cout << a - b << endl;
}
```

