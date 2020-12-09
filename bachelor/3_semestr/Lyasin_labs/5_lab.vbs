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

Wane d, e, f



'Попарный минимум Аргументов

MsgBox "Попарный минимум Аргументов"

Dim i
Dim arr(9)
i = 0
MsgBox "Исходный массив"
While i < 9
  arr(i) = i + 4
  MsgBox arr(i)
  i = i + 1
Wend
MsgBox "Попарные минимумы"
i = 0
While i < 10
  if i = 8 then
    i = i - 1
  else
    if arr(i) < arr(i + 1) then
      MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i)
    else
      MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i + 1)
    End if
      i = i + 2
  End if
Wend

MsgBox "Максимальный аргумент"

 d = 20
 e = 40
 f = 70

 Max d, e, f

 'Минимальный нечетный аргумент

MsgBox "Минимальный нечетный аргумент"

d = 3
e = 5
f = 7

Min d, e, f

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
   elseif b > c then
    MsgBox b
   else
    MsgBox c
    MsgBox b
    Msgbox a
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

Sub Min (a, b, c)
 if a < b then
   if a < c then
     MsgBox a
   else
     MsgBox c
   End if
 elseif b < c then
   MsgBox b
 else
   MsgBox c
 End if
End Sub
