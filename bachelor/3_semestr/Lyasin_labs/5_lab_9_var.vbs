'Практическая работа 5, вариант 9

'Попарный максимум элементов

MsgBox "Попарный максимум Аргументов"

Dim i
Dim arr(9)
i = 0
MsgBox "Исходный массив"
While i < 9
  arr(i) = i + 5
  MsgBox arr(i)
  i = i + 1
Wend
MsgBox "Попарные максимумы"
i = 0
While i < 10
  if i = 8 then
    i = i - 1
    if arr(i) > arr(i + 1) then
      MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i)
    else
      MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i + 1)
    End if
      i = i + 4
  else
    if arr(i) > arr(i + 1) then
      MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i)
    else
      MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i + 1)
    End if
      i = i + 2
  End if
Wend


'Максимальный аргумент
MsgBox "Максимальный аргумент"
Dim d, e, f
d = 20
e = 40
f = 70

Max d, e, f

'Максимальный нечетный аргумент
MsgBox "Максимальный нечетный аргумент"
d = 3
e = 5
f = 7

Max d, e, f

'Вывести аргументы по убаванию
d = 3
e = 5
f = 7
Wane d, e, f

'Попарное произведение аргументов

i = 0
MsgBox "Исходный массив"
While i < 9
  arr(i) = i + 3
  MsgBox arr(i)
  i = i + 1
Wend

i = 0

While i < 10
  if i = 8 then
    i = i - 1
    MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i) * arr(i + 1)
    i = i + 4
  else
    MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i) * arr(i + 1)
    i = i + 2
  End if
Wend

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
