VERSION 5.00
Begin VB.Form Form1 
   ClientHeight    =   330
   ClientLeft      =   60
   ClientTop       =   405
   ClientWidth     =   930
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   330
   ScaleWidth      =   930
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.Label Label1 
      Height          =   255
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Load()
Dim i As Integer
Randomize
i = Int(Rnd * 46) + 1
While True
If i = 9 Then
i = Int(Rnd * 46) + 1
Else
GoTo 1
End If
Wend
1 Label1.Caption = i
End Sub
