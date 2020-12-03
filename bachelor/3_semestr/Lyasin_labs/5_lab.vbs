'Практическая работа 5, вариант 2

'Произведение Аргументов
Dim a, b, c
MsgBox "Произведение Аргументов"
a = 10
b = 20
c = a * b
MsgBox c


'Вывести нечетные аргументы по убыванию
MsgBox "Вывести нечетные аргументы по убыванию"
Dim d, e, f

d = 3
e = 5
f = 7

Max d, e, f



'Попарный минимум Аргументов

MsgBox "Максимальный аргумент"

 d = 20
 e = 40
 f = 70

 Max d, e, f

 Sub Wane (a, b, c)
   if a > b then
     if a > c then
       MsgBox a
     elseif b > c then
       MsgBox b
     else
     Msgbox c
     Msgbox b
     End if
   End if
 End Sub

 Sub Max (a, b, c)
  if a > b then
    if a > c then
      MsgBox a
    else
      MsgBox c
    End if
  elseif b > c then
    MsgBox b
  else
    MsgBox c
  End if
End Sub

'Минимальный нечетный аргумент
