'Практическая работа 5, вариант 7

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
    if arr(i) < arr(i + 1) then
      MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i)
    else
      MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i + 1)
    End if
      i = i + 4
  else
    if arr(i) < arr(i + 1) then
      MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i)
    else
      MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i + 1)
    End if
      i = i + 2
  End if
Wend



'Попарный максимум Аргументов
MsgBox "Попарный максимум Аргументов"

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

'Попарная разность аргументов
MsgBox "Попарная разность аргументов"

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
    MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i) - arr(i + 1)
    i = i + 4
  else
    MsgBox "(" & i & "|" & i+1 & ")" & " = " & arr(i) - arr(i + 1)
    i = i + 2
  End if
Wend

'Минимальный нечетный аргумент
MsgBox "Минимальный нечетный аргумент"

Dim d, e, f

d = 3
e = 5
f = 7

Min d, e, f

'Вывести нечетные аргу по возрастанию
MsgBox "Вывести нечетные аргу по возрастанию"

Wane d, e, f

Sub Wane (a, b, c)
  if a < b then
    if a < c then
      MsgBox a
    elseif b < c then
      MsgBox b
    else
    Msgbox c
    Msgbox b
    End if
  elseif b < c then
   MsgBox b
  else
   MsgBox c
   MsgBox b
   Msgbox a
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
