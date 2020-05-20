// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
   
    double kek1=5, kek2=239, arg1 = 5, arg2 = 239,result=0, arctg1 = 0, arctg2 = 0, pi, den = 1, a = 4;
    __asm
    {
        fld1					
        fld kek1				
        FPATAN
        fst kek1
       

        emms

        fld1					
        fld kek2				

        FPATAN
        fst kek2

        emms
        fld a
        fld kek2
        fld kek1
        fmul st(0), st(2)
        fsub st(0), st(1)

        fmul st(0), st(2)
        fst kek1


        emms

        fld arg1				//стек arg1
        fld1					//стек 1, arg1
        fdiv st(0), st(1)		//стек 1/arg1
        fst arg1                // вывод в память

        fld arg2				//стек arg2
        fld1					//стек 1, arg2
        fdiv st(0), st(1)		//стек 1/arg2
        fst arg2                // вывод в память 
        ///////////////////////////////////
        mov cx, 1   // для цикла
        mov bx, 9  //степень 
        mov ax, 0

        emms          		
        fld den  
        fld arg1
        fld arg1
       
        //cтек arg1 arg1 arctg1  den 
        Arctg1Cal:
            mov dx, 0
            
            fdiv st(0),st(2)
            fld arctg1          // arctg1 ,arg1,1,den
            fchs
            fadd st(0),st(1)
            fst arctg1          // вывод в память            
            CMP cx, bx          //сравниваем значение регистра cx с bx
                
                jnl L
                add cx, 2
                
                emms
                fld den             // den
                fld1                //1 den
                fadd st(0), st(1)   //1+den den
                fld1                //1 1+den den
                fadd st(0), st(1)   /// 1+1+den 1 1+den +den
                fst den             // вывод в память       
                fld arg1            ///arg1 1+1+den 1 1+den +den
                fld arg1            ///arg1 arg1 1+1+den 1 1+den +den
                
            jmp Degree1              
            Degree1:   
        add dx, 1
        CMP dx, cx //сравниваем значение регистра dx с cx
        jnl Arctg1Cal
       
        fmul st(0), st(1)
            fst result//    
        jmp Degree1
       ////////////////////////
    L:
            mov cx, 1   // для цикла
            mov bx, 9  //степень 
            mov ax, 0

            emms
            fld1
            fst den        
            fld arg2
            fld arg2

            //cтек arg1 arg1 arctg1  den 
            Arctg2Cal :
        mov dx, 0

            fdiv st(0), st(2)
            fld arctg2          // arctg1 ,arg1,1,den
            fchs
            fadd st(0), st(1)
            fst arctg2
            CMP cx, bx //сравниваем значение регистра cx с bx
            jnl Exit
            add cx, 2
            emms
            fld den//1 den
            fld1
            fadd st(0), st(1)
            fld1
            fadd st(0), st(1)
            fst den
            fld arg2
            fld arg2

            jmp Degree2
            Degree2 :
        add dx, 1
            CMP dx, cx //сравниваем значение регистра dx с cx
            jnl Arctg2Cal

            fmul st(0), st(1)
            fst result//    
            jmp Degree2
    //////////////////////////////////
        Exit:
       
        emms

            fld a
            fld arctg2
            fld arctg1
            fmul st(0),st(2)                
            fsub st(0),st(1)

            fmul st(0),st(2)
            fst arg1
            fldpi 
            fst pi

  
          
    }
 
    cout.precision(15);
  

    cout << "Taylor\t"<< arg1 << endl;
    cout <<"PI:\t "<< pi << endl;
    cout <<"FPATAN:\t "<< kek1 << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
